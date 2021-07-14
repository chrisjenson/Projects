#include <stdio.h>

#include "project.h"
#include "globalStruct.h"
#include "lvgl.h"
#include "home_screen.h"
#include "slider_activity.h"
#include "math.h"
#include "string.h"

#define RAM_READ_SIZE       (2048)  //the size of the buffer holding incoming samples
#define RAM_READ_SPLIT      (1024)  //Ram_read_size divided by 2

const uint8_t tcnj_blue[] = { 41, 63, 111 };
const uint8_t tcnj_gold[] = { 166, 122, 0 };
const uint display_leftAlign = 20; 

static lv_obj_t * offsetLabel;
static lv_obj_t * triggerLabel;
static lv_obj_t * horiLabel1;
static lv_obj_t * vertLabel1;

int startup = 0;

//function that builds the chart
void chart_actions()
{    
    const int chart_width = 280;
    const int chart_heigth = 200;
    
    int windowSize;
    
    static lv_obj_t *chart1;        //declaring the chart
    if(startup == 1){
        lv_obj_del(chart1);
    }   
    
    /* Display chart                         */        
    chart1 = lv_chart_create(lv_scr_act(), NULL);                     //Add a chart to the current screen
    lv_obj_set_pos(chart1, display_leftAlign, 50); 
    lv_obj_set_size(chart1, chart_width, chart_heigth);               /*Set its size*/ 
    
    //sets the grid lines, hori, verti
    lv_chart_set_div_line_count(chart1, 7, 5);
    
    //determine the vertical limits of the chart
    switch(cm4.VertScale){
        case 3 :
            lv_chart_set_range(chart1, 475, 525);
            break;
        case 4 :
            lv_chart_set_range(chart1, 450, 550);
            break;
        case 5 :
            lv_chart_set_range(chart1, 375, 625);
            break;
        case 6 :
            lv_chart_set_range(chart1, 250, 750);
            break;
        case 7 :
            lv_chart_set_range(chart1, 0, 1000);
            break;
        default:
            lv_chart_set_range(chart1, 0, 100);
            break;
    }
    
    //determine horizontal limits of the chart 
    switch(cm4.HoriScale){
        case 5 :
            windowSize = 100;
            break;
        case 6 :
            windowSize = 200;
            break;
        case 7 :
            windowSize = 500;
            break;
        case 8 :
            windowSize = 1000;
            break;
        case 9 :
            windowSize = 2000;
            break;
        default:
            windowSize = 500;
            break;
    }    
    lv_chart_set_point_count(chart1, windowSize);                  //setting the number of points on the chart
    lv_chart_set_type(chart1, LV_CHART_TYPE_LINE);                    //set graph to points, as opposed to lines    
    
    //Add series to the chart
    lv_chart_series_t * s1 = lv_chart_add_series(chart1, lv_color_hex(0x01a2b1));
    lv_chart_series_t * s2 = lv_chart_add_series(chart1, lv_color_hex(0xCC));
    
    lv_chart_clear_serie(chart1, s1);
    lv_chart_clear_serie(chart1, s2);
    lv_chart_refresh(chart1);
    
    // Need to calculate the desired indexes in RxBuffer, Based on HoriScale => window size
    int bufferFirst = cm4.windowPos - windowSize/2;
    int bufferLast = cm4.windowPos + windowSize/2;
    
    //handle negative edge cases
    if(bufferFirst < 0){
        bufferLast = windowSize;
        bufferFirst = 0;
    }
    
    //handle overflow edge cases
    if(bufferLast > RAM_READ_SIZE){
        bufferFirst = RAM_READ_SIZE - windowSize;
        bufferLast = RAM_READ_SIZE;
    }    

    double voltage = 0; //convert the code from brian to voltage using:
    //FUNCTION: voltage = ((code*0.5)/128)+1.45
    double triggerLine = 0;
    
    double triggerTemp = cm4.Trigger/100;
    cm4.signedTriggerCode = round((((triggerTemp-1.45)/0.5)*128)); //convert the voltage from trigger to code using:
    cm4.TriggerCode = 0b00000000 | cm4.signedTriggerCode;
    //FUNCTION: triggerCode = ((voltage -1.45)/0.5)*128

    //draw the series
    for(int i = bufferFirst; i < bufferLast; ++i){
        /*        |------code to voltage equation-------|* show decimals| */
        voltage = (((cm4.RamReadBuffer[i]*0.5)/128)+1.45)*100;
        
        /*       |orginal|+|user offset|+|internal offset to account for negatives|*/
        voltage = voltage + cm4.Offset/15 + 355;
        triggerLine = cm4.Trigger + 355 + cm4.Offset/15;
        
        lv_chart_set_next(chart1, s1, voltage);
        lv_chart_set_next(chart1, s2, triggerLine);
    }   
    startup = 1;
}

//roller for trigger slope: rising, falling, threshold
static void roller1_event(lv_obj_t * obj, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        
        if(strcmp("Rising", buf) == 0){
            cm4.TriggerSlope = 0b00000000;
        }
        else if(strcmp("Falling", buf) == 0){
            cm4.TriggerSlope = 0b00000001;
        }
        else if(strcmp("Threshold", buf) == 0){
            cm4.TriggerSlope = 0b00000011;
        }
        else{
            cm4.TriggerSlope = 0b00000000; //assume rising if there is an error
        }
    }
}

//roller for trigger mode: single, auto, normal
static void roller2_event(lv_obj_t * obj, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        
        //NOTE THAT THESE VALUES NEVER GET WRITEN TO THE SPI COMMAND BECAUSE ONLY SINGLE IS CURRENTLY SUPPORTED
        if(strcmp("Single", buf) == 0){
            cm4.TriggerMode = 0b00000000;
        }
        else if(strcmp("Auto", buf) == 0){
            cm4.TriggerMode = 0b00000001;
        }
        else if(strcmp("Normal", buf) == 0){
            cm4.TriggerMode = 0b00000011;
        }
        else{
            cm4.TriggerMode = 0b00000000; //assume single if there is an error
        }
    }
}

//switch for if the sweep should be armed or not
static void sw_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        //printf("State: %s\n", lv_sw_get_state(obj) ? "Run" : "Stop");
        cm4.Armed = lv_sw_get_state(obj);
        //cm4.Armed = !cm4.Armed;
    }
}

//NOTE: this function does not scale correctly
static void offset_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        static char buf[8]; /* max 3 bytes for number plus 1 null terminating byte */
        static char units[4] = "mV";
        snprintf(buf, 8, "%d", lv_slider_get_value(slider)-1000);
        strcat(buf, units);
        lv_label_set_text(offsetLabel, buf);
        cm4.Offset = lv_slider_get_value(slider)-1000;
        chart_actions();    //call to update the chart
    }
}
static void trigger_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        static char buf[8]; /* max 3 bytes for number plus 1 null terminating byte */
        static char units[4] = "mV";
        snprintf(buf, 8, "%u", lv_slider_get_value(slider));
        strcat(buf, units);
        lv_label_set_text(triggerLabel, buf);
        cm4.Trigger = lv_slider_get_value(slider)/10; //scaled down for the chart
        chart_actions();    //call to update the chart
    }
}
static void hori_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        static char buf[10]; /* max 3 bytes for number plus 1 null terminating byte */
        //snprintf(buf, 10, "%u", lv_slider_get_value(slider));
        //lv_label_set_text(horiLabel1, buf);
        cm4.HoriScale = lv_slider_get_value(slider);
        
        switch(cm4.HoriScale){

            case 5 :
                snprintf(buf, 10, "100mS");
                break;
            case 6 :
                snprintf(buf, 10, "200mS");
                break;
            case 7 :
                snprintf(buf, 10, "500mS");
                break;            
            case 8 :
                snprintf(buf, 10, "1S");
                break;
            case 9 :
                snprintf(buf, 10, "2S");
                break;
            default:
                snprintf(buf, 10, "Hello World");
                break;
        }        
        lv_label_set_text(horiLabel1, buf);
        chart_actions();    //call to update the chart
    }
}
static void verti_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        static char buf[10]; /* max 3 bytes for number plus 1 null terminating byte */
        cm4.VertScale = lv_slider_get_value(slider);
        switch(cm4.VertScale){
            case 3 :
                snprintf(buf, 10, "100mV");
                break;
            case 4 :
                snprintf(buf, 10, "200mV");
                break;
            case 5 :
                snprintf(buf, 10, "500mV");
                break;
            case 6 :
                snprintf(buf, 10, "1V");
                break;
            case 7 :
                snprintf(buf, 10, "2V");
                break;
            default:
                snprintf(buf, 10, "Hello World");
                break;
        }
        lv_label_set_text(vertLabel1, buf);
        chart_actions();    //call to update the chart
    }
}
static void window_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        cm4.windowPos = lv_slider_get_value(slider);
        chart_actions();    //call to update the chart
    }
}

void home_screen()
{   
    /* First Slider: Offset */
    lv_obj_t * offsetSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(offsetSlider, display_leftAlign, 290);                         /*Set its position*/
    lv_obj_set_size(offsetSlider, 130, 30);                        /*Set its size*/
    lv_obj_set_event_cb(offsetSlider, offset_slider_event_cb);
    lv_slider_set_range(offsetSlider, 0, 2000);
    lv_slider_set_value(offsetSlider, 1000, LV_ANIM_ON);

            /* Create a label below the slider */
            offsetLabel = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(offsetLabel, "0mV");
            lv_obj_set_auto_realign(offsetLabel, true);
            lv_obj_align(offsetLabel, offsetSlider, LV_ALIGN_OUT_TOP_RIGHT, 0, 0);
        
            /* Create a label above the slider */
        	lv_obj_t* offsetLabel2 = lv_label_create(lv_scr_act(), NULL);
        	lv_obj_set_drag(offsetLabel2, false);
            lv_label_set_text(offsetLabel2, "Offset:");
            lv_label_set_long_mode(offsetLabel2, LV_LABEL_LONG_EXPAND);
            lv_obj_align(offsetLabel2, offsetSlider, LV_ALIGN_OUT_TOP_LEFT, 0, 0);                         /*Set its position*/
    
            
            
    /* Second Slider: Trigger */
    lv_obj_t * triggerSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(triggerSlider, 170, 365);                         /*Set its position*/ // 170,290
    lv_obj_set_size(triggerSlider, 130, 30);                        /*Set its size*/
    lv_obj_set_event_cb(triggerSlider, trigger_slider_event_cb);
    lv_slider_set_range(triggerSlider, 900, 1900);
    lv_slider_set_value(triggerSlider, 1500, LV_ANIM_ON);
            
            /* Create a label below the slider */
            triggerLabel = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(triggerLabel, "1500mV");
            lv_obj_set_auto_realign(triggerLabel, true);
            lv_obj_align(triggerLabel, triggerSlider, LV_ALIGN_OUT_TOP_RIGHT, 0, 0);
            
            /* Create a label above the slider */
        	lv_obj_t* triggerLabel2 = lv_label_create(lv_scr_act(), NULL);
        	lv_obj_set_drag(triggerLabel2, false);
            lv_label_set_text(triggerLabel2, "Trigger: ");
            lv_obj_align(triggerLabel2, triggerSlider, LV_ALIGN_OUT_TOP_LEFT, 0, 0); 

    
            
    /* Third Slider: Hori. Scale */
    lv_obj_t * horiSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(horiSlider, display_leftAlign, 365);                         /*Set its position*/
    lv_obj_set_size(horiSlider, 130, 30);                        /*Set its size*/
    lv_slider_set_value(horiSlider, 7, LV_ANIM_ON);
    lv_obj_set_event_cb(horiSlider, hori_slider_event_cb);
    lv_slider_set_range(horiSlider, 5, 9);                      // 11 options for the 11 different data size posibilites
    
            /* Create a label below the slider */
            horiLabel1 = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(horiLabel1, "500mS");
            lv_obj_set_auto_realign(horiLabel1, true);
            lv_obj_align(horiLabel1, horiSlider, LV_ALIGN_OUT_TOP_RIGHT, 0, 0);
            
            /* Create a label above the slider */
        	lv_obj_t* horiLabel2 = lv_label_create(lv_scr_act(), NULL);
        	lv_obj_set_drag(horiLabel2, false);
            lv_label_set_text(horiLabel2, "H Scale: ");
            lv_obj_align(horiLabel2, horiSlider, LV_ALIGN_OUT_TOP_LEFT, 0, 0);
    
            
            
    /* Fourth Slider: Vert. Scale */
    lv_obj_t * vertSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(vertSlider, 170, 290);                         /*Set its position*/ // 170, 365
    lv_obj_set_size(vertSlider, 130, 30);                        /*Set its size*/
    lv_slider_set_value(vertSlider, 5, LV_ANIM_ON);
    lv_obj_set_event_cb(vertSlider, verti_slider_event_cb);
    lv_slider_set_range(vertSlider, 3, 7);

            /* Create a label below the slider */
            vertLabel1 = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(vertLabel1, "500mV");
            lv_obj_set_auto_realign(vertLabel1, true);
            lv_obj_align(vertLabel1, vertSlider, LV_ALIGN_OUT_TOP_RIGHT, 0, 0);
            
            /* Create a label above the slider */
        	lv_obj_t* vertLabel2 = lv_label_create(lv_scr_act(), NULL);
        	lv_obj_set_drag(vertLabel2, false);
            lv_label_set_text(vertLabel2, "V Scale: ");
            lv_obj_align(vertLabel2, vertSlider, LV_ALIGN_OUT_TOP_LEFT, 0, 0);
    
        
            
    /* Fifth Slider: Horizontal Window      Control Range of Points shown */
    lv_obj_t * windowSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(windowSlider, 20, 10);                         /*Set its position 20, 225*/
    lv_obj_set_size(windowSlider, 280, 30);                        /*Set its size*/
    lv_obj_set_event_cb(windowSlider, window_slider_event_cb);
    lv_slider_set_range(windowSlider, 0, 2048);        
    lv_slider_set_value(windowSlider, cm4.windowPos, LV_ANIM_ON);
    
            
    //Adding an on/off switch 
    lv_obj_t * sw1 = lv_sw_create(lv_scr_act(), NULL);
    lv_obj_align(sw1, NULL, LV_ALIGN_CENTER, 0, -50);
    lv_obj_set_event_cb(sw1, sw_event_handler);
    lv_obj_set_pos(sw1, display_leftAlign, 430);                         /*Set its position*/
    lv_obj_set_size(sw1, 90, 30);               /*Set its size*/ 
    
    lv_obj_t * switchLabel = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(switchLabel, false);
    lv_label_set_text(switchLabel, "Stop\\Run");
    lv_obj_align(switchLabel, sw1, LV_ALIGN_OUT_TOP_MID, 0, 0);
    
    
    
    //Adding a drop down menu for the trigger slope
    lv_obj_t * rollerLabel = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(rollerLabel, false);
    lv_label_set_text(rollerLabel, "Trigger Settings:");
    lv_obj_set_pos(rollerLabel, 155, 410);
    
    lv_obj_t * roller1 = lv_roller_create(lv_scr_act(),NULL);
    lv_roller_set_options(roller1, "Rising\n"
                                   "Falling\n"
                                   "Threshold",
                                   LV_ROLLER_MODE_INIFINITE);
    lv_roller_set_visible_row_count(roller1, 1);
    lv_obj_set_pos(roller1, 200, 425);                         /*Set its position*/
    lv_obj_set_event_cb(roller1, roller1_event);
    
    //Adding a drop down menu for the trigger type
    lv_obj_t * roller2 = lv_roller_create(lv_scr_act(),NULL);
    lv_roller_set_options(roller2, "Single\n"
                                   "Auto\n"
                                   "Normal",
                                   LV_ROLLER_MODE_INIFINITE);
    lv_roller_set_visible_row_count(roller2, 1);
    lv_obj_set_pos(roller2, 115, 425);                         /*Set its position*/
    lv_obj_set_event_cb(roller2, roller2_event);
    
    
    //Draw the ogriginal chart... should be empty or zeroes
    chart_actions();
}