/*
 * app.c
 *
 *  Created on: Oct 21, 2023
 *      Author: user
 */


//#include "driver_7segment.h"
#include"LCD.h"
#include"util/delay.h"
#include "ADC.h"
#include "DIO_interface.h"
#include "driver_7segment.h"

#include "EXTI.h"


	//EXTI_CONFIG exti_object;



							/***********************EXTI DRIVER TESTING*******************************/
void led_on()
{
	//DIO_voidSetPinDirection(PORTA,PIN5_ID,OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_HIGH);
	//DIO_voidSetPinValue(PORTA,PIN5_ID,LOGIC_HIGH);
	_delay_ms(1000);
	DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_LOW);
	_delay_ms(1000);

	//DIO_voidSetPinValue(PORTA,PIN5_ID,LOGIC_LOW);

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
		H_LCD_void_Init();
		//H_LCD_void_sendString("yasso mogrem   ");

		ADC_ConfigType ADC_Object;

		ADC_Object.ref_volt=Internal_AREF;
		ADC_Object.prescaler=Div_Factor128;
		ADC_Object.AutoTrigger=0;
	//	ADC_Object.EnableOrDisable=DISABLE;

		ADC_init(&ADC_Object);
		uint16 value=0;
	//	DIO_voidSetPinDirection(PORTB,PIN7_ID,OUTPUT);
	//	DIO_voidSetPinDirection(PORTA,PIN4_ID,OUTPUT);
	//	DIO_voidSetPinDirection(PORTA,PIN6_ID,OUTPUT);

		DIO_voidSetPinDirection(PORTA,PIN6_ID,OUTPUT);

	while(1)
	{


		ADC_getDigitalValueAsynchCallBack(channel_1,led_on);













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
};


