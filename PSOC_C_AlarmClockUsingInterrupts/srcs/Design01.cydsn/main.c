#include "project.h"
#include "stdio.h"

int main(void)
{
    PWM_1_Start(); // Configure and enable timer
    Clock_1_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Start();
    Driver_Start();     //the tens place of seconds
    Driver1_Start();    //the ones place of seconds
    LCD_Position(0,0);
    LCD_PrintString("Welcome!");
    CyDelay(1000);
    
    int seconds = 0;
    char str1[15];
    
    //initializing the LCD display to show the seconds
    LCD_ClearDisplay();
    LCD_Position(0,0);
    sprintf(str1, "%d", seconds);
    LCD_PrintString(str1);
    
    //setting the inital display to show all zeros
    Driver_Write7SegDigitDec(0, 0);
    Driver1_Write7SegDigitDec(0, 0);

    for(;;)
    {
        //increment seconds by 1 when button two is pressed
        if (SW_Read() == 0)
        {
            LCD_ClearDisplay();
            LCD_Position(0,0);

            //while seconds is still less than 60, continue counting up 
            //if seconds is at 60, then stop incrementing
            if (seconds <= 60)
            {
                //update the LCD
                seconds = seconds + 1;
                sprintf(str1, "%d", seconds);
                LCD_PrintString(str1);
                
                //display the ones place of seconds and a 0 for the tens place
                if (seconds < 10)
                {
                    Driver_Write7SegDigitDec(0, 0);
                    Driver1_Write7SegDigitDec(seconds, 0);
                }
                
                //when seconds is in the double digits
                else 
                {            
                    Driver_Write7SegDigitDec((seconds / 10), 0); //divide by ten to get the tens digit and truncate the ones
                    Driver1_Write7SegDigitDec((seconds % 10), 0); //modulo by 10 to be left with the ones
                }      
            }
        }
        CyDelay(500);   //delay to give the user time to add more seconds
        
        //this is the count down section of the code
        //trigger when the user is not adding more input and there are more than 0 seconds
        if ((SW_Read() != 0) && (seconds > 0))
        {
            //trigger the first interrupt once user input is complete, this turns the motor the first direction
            //see isr_1.c for the code 
            isr_1_Start();
            
            //after the first interrupt has completed
            //this decrements the seconds every 1000ms or 1s while there is > 0 seconds
            while (seconds > 0)
            {
                //begin countdown
                //wait the 1000ms or 1s
                CyDelay(1000);
                
                //update the LCD
                seconds = seconds - 1;
                LCD_ClearDisplay();
                sprintf(str1, "%d", seconds);
                LCD_PrintString(str1);
                
                //display the ones place of seconds and a 0 for the tens place
                if (seconds < 10)
                {
                    Driver_Write7SegDigitDec(0, 0);
                    Driver1_Write7SegDigitDec(seconds, 0);
                }
                
                //when seconds is in the double digits
                else 
                {            
                    Driver_Write7SegDigitDec((seconds / 10), 0); //divide by ten to get the tens digit and truncate the ones
                    Driver1_Write7SegDigitDec((seconds % 10), 0); //modulo by 10 to be left with the ones
                }  
            }
            //trigger the second interrupt once the countdown finishes, this turns the motor back
            //see isr_2.c for the code
            isr_2_Start();
        }
    }
}

