
#include "project.h"

int flag=0;

void level_up_2();
void level_up_1();
void level_down_2();
void level_down_1();
void level0();

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    CapSense_CSD_Start();	
    CapSense_CSD_InitializeAllBaselines();
    
    for(;;)
    {
     CapSense_CSD_UpdateEnabledBaselines();
        CapSense_CSD_ScanEnabledWidgets();
        while(CapSense_CSD_IsBusy() != 0)
		{
		}
       
    uint32 state1= CapSense_CSD_CheckIsWidgetActive(CapSense_CSD_SENSOR_BUTTON0__BTN);
    uint32 state2= CapSense_CSD_CheckIsWidgetActive(CapSense_CSD_SENSOR_BUTTON1__BTN);
    uint32 state3= CapSense_CSD_CheckIsWidgetActive(CapSense_CSD_SENSOR_BUTTON2__BTN);
    uint32 state4= CapSense_CSD_CheckIsWidgetActive(CapSense_CSD_SENSOR_BUTTON3__BTN);
    uint32 state5= CapSense_CSD_CheckIsWidgetActive(CapSense_CSD_SENSOR_BUTTON4__BTN);
       
    if(state1==1u){  level_up_2(); }
    if(state2==1u){  level_up_1(); }
    if(state3==1u){  level0(); }
    if(state4==1u){  level_down_1(); }
    if(state5==1u){  level_down_2(); }
        
    }

}

void level0(){ 
    LED_1_Write(0u);
    LED_2_Write(0u);
    LED_3_Write(0u);
    LED_4_Write(0u);
}

void level_up_1(){
 LED_3_Write(1u);
 LED_4_Write(0u);
}
void level_up_2(){
 LED_3_Write(1u);
 LED_4_Write(1u);
}

void level_down_1(){
    LED_2_Write(1u);
    LED_1_Write(0u);
}
void level_down_2(){
    LED_2_Write(1u);
    LED_1_Write(1u);    
}
