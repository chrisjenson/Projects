#include "project.h"
#include "home_screen.h"

//Declaring a Global Structure
struct SPI_parameters
{
    uint8_t BrianReg;
    uint8_t ChrisReg;
    uint8_t ShannonReg;
    
    uint8_t VersionID;
    uint16_t Trigger;
    uint8_t TriggerMode;    
    uint8_t TriggerCode;    
    int8_t signedTriggerCode;    
    uint8_t TriggerSlope;
    uint8_t TriggerEvent;
    uint8_t onBit;
    uint8_t Armed;
    uint8_t Reset;
    int16_t Offset;
    
    //saves where in the buffer we are for display;
    int windowPos; 
    
    uint8_t HoriScale;
    uint8_t VertScale;
    uint8_t Gain;       //goes to Shannon
    
    //Actual Buffers
    uint16_t TxBuffer[8];  //Commands To be Sent
    int16_t RxBuffer[32];  // Read data in, SIZE SHOULD BE EQUAL TO NUM_TO_WRITE in main_cm4.c
    int8_t RamReadBuffer[2048];  // Ram Read data after being split can be 2048
};
struct SPI_parameters cm4;

