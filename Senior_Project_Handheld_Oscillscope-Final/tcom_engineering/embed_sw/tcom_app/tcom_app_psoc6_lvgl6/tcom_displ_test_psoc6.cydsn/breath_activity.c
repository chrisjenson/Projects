#include <stdio.h>
#include "project.h"
#include "lvgl.h"

#define HOLD_SECS   (10)
#define EXHALE_SECS (15)

void btn_anime(lv_task_t * task);

static int volatile btn_anime_state = 0;

static lv_task_t *breath_task;

void breath_activity_action(lv_obj_t * btn, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        //lv_task_create(task_cb, period_ms, LV_TASK_PRIO_OFF/LOWEST/LOW/MID/HIGH/HIGHEST, user_data).
        breath_task = lv_task_create(btn_anime, 1000 /*ms*/, LV_TASK_PRIO_HIGHEST, NULL);
    }
}


//void task(lv_task_t * task)
void btn_anime(lv_task_t * task)
{
    static lv_obj_t     *my_label = NULL;
    static lv_obj_t     *time_label = NULL;
    static lv_obj_t     *my_btn = NULL;
    static lv_style_t   btn_style;
    static lv_style_t   lbl_style;

    static lv_style_t   style_led;
    static lv_obj_t     *led_arr[10];

    static lv_obj_t     *init_screen;
    static lv_obj_t     *scr1;
    
    static char time_left[8] = {0};
        
    if (btn_anime_state == 0)
    {
        init_screen = lv_scr_act();
        scr1 = lv_obj_create(NULL, NULL);
        lv_scr_load(scr1);

        my_btn = lv_obj_create(lv_scr_act(), NULL);
        lv_obj_set_size(my_btn, 320, 480);                        /*Set its size*/

        lv_style_copy(&btn_style, lv_obj_get_style(my_btn));
        btn_style.body.main_color.full = 0x40C0FF;
        btn_style.body.grad_color.full = btn_style.body.main_color.full;
        btn_style.body.opa = LV_OPA_COVER;
        lv_obj_set_style( my_btn, &btn_style );
        
        my_label = lv_label_create(my_btn, NULL);
        lv_style_copy(&lbl_style, lv_obj_get_style(my_label));
        lv_label_set_text( my_label, "Hold breath for\n10 seconds ...\n\n... then breathe\ninto device\nslowly for\n15 seconds" );
        lv_obj_align( my_label, NULL, LV_ALIGN_IN_TOP_LEFT, 5,100 );
        lv_label_set_long_mode(my_label, LV_LABEL_LONG_EXPAND);
        lbl_style.text.font = &lv_font_roboto_16;
        lv_label_set_style(my_label, LV_LABEL_STYLE_MAIN, &lbl_style);

        time_label = lv_label_create(my_btn, NULL);
        lv_style_copy(&lbl_style, lv_obj_get_style(time_label));
        lv_label_set_static_text( time_label, "" );
        lv_obj_align( time_label, NULL, LV_ALIGN_IN_TOP_LEFT, 120,400 );
        lbl_style.text.font = &lv_font_roboto_16;
        lv_label_set_style(time_label, LV_LABEL_STYLE_MAIN, &lbl_style);

        lv_style_copy(&style_led, &lv_style_pretty_color);
        style_led.body.radius       = LV_RADIUS_CIRCLE;
        style_led.body.main_color   = LV_COLOR_MAKE(0x04, 0x0f, 0xb5);
        style_led.body.grad_color   = LV_COLOR_MAKE(0x02, 0x07, 0x50);
        style_led.body.border.color = LV_COLOR_MAKE(0x00, 0x0f, 0xfa);
        style_led.body.border.width = 3;
        style_led.body.border.opa   = LV_OPA_30;
        style_led.body.shadow.color = LV_COLOR_MAKE(0x04, 0x0f, 0xb5);
        style_led.body.shadow.width = 10;

            /*Create a LED and switch it ON*/
        int i = 0;
        led_arr[i] = lv_led_create(my_btn, NULL);
        lv_obj_set_size(led_arr[i], 25, 25);
        lv_obj_set_style(led_arr[i], &style_led);
        lv_obj_align(led_arr[i], NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 50);
        lv_led_set_bright( led_arr[i], 100 );
        for (i = 1; i < HOLD_SECS; ++i)
        {
            /*Copy the previous LED and set a brightness*/
            led_arr[i] = lv_led_create(lv_scr_act(), led_arr[0]);
            lv_obj_set_size(led_arr[i], 25, 25);
            lv_obj_align(led_arr[i], led_arr[i-1], LV_ALIGN_OUT_BOTTOM_MID, 0, 15);
            lv_led_set_bright( led_arr[i], 100 );
        }
    }
    
    if (btn_anime_state < HOLD_SECS)
    {
        int led_num;
    
        led_num = btn_anime_state;
        
        lv_led_on(led_arr[led_num]);
        ++btn_anime_state;
    }
    else if (btn_anime_state < HOLD_SECS+EXHALE_SECS)
    {
        sprintf( time_left, "%2d", HOLD_SECS+EXHALE_SECS-btn_anime_state );
        lv_label_set_static_text( time_label, time_left );

        ++btn_anime_state;
    }
    else
    {        
        lv_obj_del(lv_scr_act());
        lv_scr_load(init_screen);
        lv_task_del(task);
        
        btn_anime_state = 0;
    }
}    

