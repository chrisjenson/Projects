#include <stdio.h>
#include "project.h"
#include "lvgl.h"
#include "time_date_activity.h"

static lv_obj_t *label_dat;
static lv_obj_t *label_tim;

static char *months[] =
{
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

static lv_calendar_date_t   today = 
{
    .year=2021,
    .month=1,
    .day=20
};

const char * day_names[7] = {"Su", "M", "Tu", "W", "Th", "F", "Sa"};

void set_label_dat(lv_obj_t *obj)
{
    label_dat = obj;
}

void set_label_tim(lv_obj_t *obj)
{
    label_tim = obj;
}

static void calendar_event_handler(lv_obj_t * obj, lv_event_t event)
{
    static char date_str[64];
    
    if(event == LV_EVENT_CLICKED) 
    {
        lv_calendar_date_t * date = lv_calendar_get_pressed_date(obj);
        if(date) 
        {
            lv_calendar_set_today_date(obj, date);
            today = *date;

            sprintf( date_str, "%s %2d, %4d", months[today.month-1], today.day, today.year );
            lv_label_set_text( label_dat, date_str );

            lv_obj_del(obj);
        }
    }
}

void date_activity_action(lv_obj_t *obj, lv_event_t event)
{
    lv_obj_t *calendar;

    if (event == LV_EVENT_CLICKED)
    {
        calendar = lv_calendar_create(lv_scr_act(), NULL);
        lv_calendar_set_day_names(calendar, day_names);
        lv_obj_set_size(calendar, 320, 320);
        lv_obj_align(calendar, NULL, LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_event_cb(calendar, calendar_event_handler);

        lv_calendar_set_today_date(calendar, &today);
        lv_calendar_set_showed_date(calendar, &today);
    }
}

static int  time_hr = 12;
static int  time_mn = 00;
static int  time_se = 00;
static char ap_str[3] = "AM";
static char time_str[64];

static lv_obj_t *list_hr;
static lv_obj_t *list_mn;
static lv_obj_t *list_ap;   // am or pm

static void hr_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) 
    {
        sscanf( lv_list_get_btn_text(obj), "%d", &time_hr );
        sprintf( time_str, "%2d:%02d %s", time_hr, time_mn, ap_str );
        lv_label_set_static_text( label_tim, time_str );
    }
}

static void mn_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) 
    {
        sscanf( lv_list_get_btn_text(obj), "%d", &time_mn );
        sprintf( time_str, "%2d:%02d %s", time_hr, time_mn, ap_str );
        lv_label_set_static_text( label_tim, time_str );
    }
}

static void ap_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) 
    {
        const char *str;
        
        str = lv_list_get_btn_text(obj);
        ap_str[0] = str[0];                 // either A or P

        sprintf( time_str, "%2d:%02d %s", time_hr, time_mn, ap_str );
        lv_label_set_static_text( label_tim, time_str );

        lv_obj_del(list_hr);
        lv_obj_del(list_mn);
        lv_obj_del(list_ap);
    }
}


void time_activity_action(lv_obj_t *obj, lv_event_t event)
{
    char    num_str[8];
    int     i;
    
    if (event == LV_EVENT_CLICKED)
    {
        list_hr = lv_list_create(lv_scr_act(), NULL);
        lv_obj_set_size(list_hr, 60, 120);
        lv_obj_set_pos(list_hr, 10, 10);
        
        /*Add buttons*/
        for(i = 0; i < 12; i++) 
        {
            lv_obj_t *btn;
            sprintf( num_str, "%d", ((11+i)%12) + 1 );
            btn = lv_list_add_btn(list_hr, NULL, num_str);
            lv_obj_set_event_cb(btn, hr_event_handler);                           /*Assign event function*/
            lv_btn_set_toggle(btn, true);                                           /*Enable on/off states*/
        }
     
        list_mn = lv_list_create(lv_scr_act(), NULL);
        lv_obj_set_size(list_mn, 60, 120);
        lv_obj_set_pos(list_mn, 70, 10);
        
        /*Add buttons*/
        for(i = 0; i < 60; i++) 
        {
            lv_obj_t *btn;
            sprintf( num_str, "%02d", i);
            btn = lv_list_add_btn(list_mn, NULL, num_str);
            lv_obj_set_event_cb(btn, mn_event_handler);                           /*Assign event function*/
            lv_btn_set_toggle(btn, true);                                           /*Enable on/off states*/
        }

        list_ap = lv_list_create(lv_scr_act(), NULL);
        lv_obj_set_size(list_ap, 60, 120);
        lv_obj_set_pos(list_ap, 130, 10);
        
        /*Add buttons*/
        {
            lv_obj_t *btn;
            btn = lv_list_add_btn(list_ap, NULL, "AM");
            lv_obj_set_event_cb(btn, ap_event_handler);                           /*Assign event function*/
            lv_btn_set_toggle(btn, true);                                         /*Enable on/off states*/
            
            btn = lv_list_add_btn(list_ap, NULL, "PM");
            lv_obj_set_event_cb(btn, ap_event_handler);                           /*Assign event function*/
            lv_btn_set_toggle(btn, true);                                         /*Enable on/off states*/
        }
    }
}