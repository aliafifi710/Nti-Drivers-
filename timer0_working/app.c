/*
 * app.c
 *
 *  Created on: Oct 21, 2023
 *      Author: user
 */


//#include "driver_7segment.h"
#include <Timer0.h>
#include"LCD.h"
#include"util/delay.h"
#include "ADC.h"
#include "DIO_interface.h"
#include "driver_7segment.h"
#include "EXTI.h"


//EXTI_CONFIG exti_object;


static uint8 flag=0;
/***********************EXTI DRIVER TESTING*******************************/
void led_on(void)
{
	//	DIO_voidSetPinValue(PORTA,PIN4_ID,LOGIC_HIGH);
	//	_delay_ms(1000);


	//DIO_voidSetPinDirection(PORTA,PIN5_ID,OUTPUT);
	//DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_HIGH);
	//DIO_voidSetPinValue(PORTA,PIN5_ID,LOGIC_HIGH);

	//_delay_ms(1000);
	flag ++;
	if(flag == 1)
	{
		DIO_voidSetPinValue(PORTB,PIN7_ID,LOGIC_HIGH);
		_delay_ms(100);
	}
	if(flag == 10)
	{
		DIO_voidSetPinValue(PORTB,PIN7_ID,LOGIC_LOW);
		_delay_ms(100);
		flag = 0;
	}

}
//void EXTI_INIT()
//{
//	exti_object.INT_ID = EXTI_INT1;
//	exti_object.trigger_type = falling_edge;
//	exti_object.ptr_call_back=led_on;
//	EXTI_ENABLE(&exti_object);
//
//}

/***********************EXTI DRIVER TESTING*******************************/





int main ()
{
	SET_BIT(SREG,PIN7_ID);

	/*********************TIMER0_TESTING_DRIVER****************************/

	//	DIO_voidSetPinDirection(PORTB,PIN3_ID,OUTPUT);
	//	DIO_voidSetPinDirection(PORTB,PIN7_ID,OUTPUT);//red
	//	DIO_voidSetPinDirection(PORTA,PIN4_ID,OUTPUT);//green
	//	DIO_voidSetPinDirection(PORTA,PIN5_ID,OUTPUT);//blue
	//	DIO_voidSetPinDirection(PORTA,PIN6_ID,OUTPUT);//yellow
		//DIO_voidSetPinValue(PORTA,PIN5_ID,OUTPUT);
//		TIMER0_CONFIG timer;
//		timer.TIMER0_MODES =NORMAL_MODE;
//		timer.VALUE=0;
//		timer.PRESCALER=CLK_DIV_1024;
//		timer.NON_PWM_MODE = NORMAL_1;
//		Timer_Init(&timer);
//		EnableInt(&timer,led_on);

	/*********************TIMER0_TESTING_DRIVER****************************/



	//setFastPWM(50,NON_INVERTING_MODE);
	/***********************EXTI DRIVER TESTING*******************************/

	//	EXTI_INIT();
	//_delay_ms(10000);
	//EXTI_DISABLE(&exti_object);                                          //not working till now

	/***********************EXTI DRIVER TESTING*******************************/


	/*******************************TESTING_7_SEGMENT_DRIVER******************************************/
	//		uint8 counter;
	//		segment_init(_4_channels);

	/*******************************TESTING_7_SEGMENT_DRIVER******************************************/

	//segment_init(channel_0);
	//	H_LCD_void_Init();
	//H_LCD_void_sendString("yasso mogrem   ");

	/************************ADC_TESTING_DRIVER***************************/
	//	ADC_ConfigType ADC_Object;
	//
	//	ADC_Object.ref_volt=Internal_AREF;
	//	ADC_Object.prescaler=Div_Factor128;
	//	ADC_Object.AutoTrigger=0;
	//	ADC_init(&ADC_Object);
	//	uint16 value=0;
	/************************ADC_TESTING_DRIVER***************************/



	//	DIO_voidSetPinDirection(PORTB,PIN7_ID,OUTPUT);
	//	DIO_voidSetPinDirection(PORTA,PIN4_ID,OUTPUT);
	//	DIO_voidSetPinDirection(PORTA,PIN6_ID,OUTPUT);

	//DIO_voidSetPinDirection(PORTA,PIN6_ID,OUTPUT);

	while(1)
	{
		/***********************TIMER0_TESTING******************/
//		setFastPWM(50,NON_INVERTING_MODE);
//		_delay_ms(2000);
//
//		setFastPWM(100,NON_INVERTING_MODE);
//		_delay_ms(2000);
//
//		setFastPWM(0,NON_INVERTING_MODE);
//		_delay_ms(2000);

		/***********************TIMER0_TESTING******************/




		//DIO_voidSetPinValue(PORTA,PIN4_ID,LOGIC_LOW);

		//DIO_voidSetPinValue(PORTA,PIN4_ID,LOGIC_LOW);

		//DIO_voidSetPinValue(PORTB,PIN7_ID,LOGIC_HIGH);

		/************************ADC_TESTING_DRIVER***************************/
		//ADC_getDigitalValueAsynchCallBack(channel_1,led_on);
		/************************ADC_TESTING_DRIVER***************************/



		//				value=ADC_getDigitalValueSynchNonBlocking(channel_1);
		//				H_LCD_void_sendIntNum(value);
		//				_delay_ms(500);
		//				H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);

		//H_LCD_void_sendString("yasso gamed");
		//_delay_ms(1000);
		//	H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);


		/*******************************TESTING_7_SEGMENT_DRIVER******************************************/

		//				for(counter =0;counter<=9;counter++)
		//				{
		//					segment_num(counter);
		//					_delay_ms(1000);
		//
		//				}

		/*******************************TESTING_7_SEGMENT_DRIVER******************************************/


		/*******************************TESTING_GPIO_DRIVER**********************************************/


		//		DIO_voidSetPinValue(PORTB,PIN7_ID,LOGIC_HIGH);
		//		_delay_ms(1000);
		//		DIO_voidSetPinValue(PORTA,PIN4_ID,LOGIC_HIGH);
		//		_delay_ms(1000);
		//		DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_HIGH);
		//		_delay_ms(1000);
		//
		//		DIO_voidSetPinValue(PORTB,PIN7_ID,LOGIC_LOW);
		//		_delay_ms(1000);
		//		DIO_voidSetPinValue(PORTA,PIN4_ID,LOGIC_LOW);
		//		_delay_ms(1000);
		//		DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_LOW);


		/*******************************TESTING_GPIO_DRIVER********************************************/

	}
}


