

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "std_types.h"

#ifndef NULL
#define NULL (void *)0
#endif


void PushButton(void * pvparam);
#define PushButtonPr (1)

void Led(void * pvparam);
#define LedPr (2)

void init(void);

/*** Global Variable ****/
u8 ButtonState = 1;

 int main(void)
{

	 /* Creation of the Task*/
	 xTaskHandle PushHandle  = NULL;
	 xTaskCreate(PushButton,(const signed char*)"Push Button",85,NULL,PushButtonPr,&PushHandle);

	 xTaskHandle LedHandle = NULL ;
	 xTaskCreate(Led,(const signed char*)"Led ",85,NULL,LedPr,&LedHandle);

	 /*Init Function*/
	 init();

	/*start Scheduler */
	vTaskStartScheduler();



	/*Never Enter Here */
	return 0;
}

void init(void){
	DDRA = 0xFF;

	DDRD = 0x00;

	PORTD = 0xFF;

}
 void PushButton(void * pvparam){
	 portTickType Freq = 50;
	 portTickType Start = xTaskGetTickCount();
	 while (1){
		 /* if the Push Button is Pressed */
		 if ((PIND>>7 & 0x01) == 0){
			 ButtonState = 0;
		 }

		 /*Make the Task Periodic with Period 50 Tick */
		 vTaskDelayUntil(&Start,Freq);
	 }

 }


 void Led(void * pvparam){
	 portTickType Freq = 50;
	 portTickType Start = xTaskGetTickCount();
	 while (1){
		 /* if the Push Button is Pressed */
		 if (ButtonState == 0){
			 PORTA ^= 0x20;
			 ButtonState = 1;
		 }
		 /*Make the Task Periodic with Period 50 Tick */
		 vTaskDelayUntil(&Start,Freq);
	 }


 }
