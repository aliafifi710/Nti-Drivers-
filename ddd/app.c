/*
 * app.c
 *
 *  Created on: Oct 21, 2023
 *      Author: user
 */


//#include "driver_7segment.h"
#include "Timer0.h"
#include"util/delay.h"
//#include "ADC.h"
//#include "DIO_interface.h"
#include "LM35.h"
#include "Motor.h"
#include"LCD.h"
//#include "driver_7segment.h"
//#include "EXTI.h"
//#include "UART.h"
//#include "WatchDog.h"
#include "common_macros.h"
//#include "FingerPrint.h"
//#include "MCU_HW.h"
//#include <avr/io.h>
//extern const char ShackHand[];


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
	//	DIO_voidSetPinValue(PORTB,PIN7_ID,LOGIC_LOW);
	flag ++;
	if(flag == 30 || flag==60|| flag==90 || flag==120 || flag==150 || flag==180)
	{
		if(BIT_IS_CLEAR(PORTC->PORT.Reg,PIN5_ID))
		{
			_delay_ms(30);
			if(BIT_IS_CLEAR(PORTC->PORT.Reg,PIN5_ID))
			{
				TOGGLE_BIT(PORTA->PORT.Reg,PIN5_ID);

			}
		}

	}
	if(flag == 60 ||flag == 120 ||flag == 180)
	{
		TOGGLE_BIT(PORTB->PORT.Reg,PIN7_ID);

	}
	if(flag == 180)
	{
		TOGGLE_BIT(PORTA->PORT.Reg,PIN4_ID);
		flag = 0;

	}
	//	else if(flag == 120)
		//	{
	//		//DIO_voidSetPinValue(PORTB,PIN7_ID,LOGIC_LOW);
	//
	//	}

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

	//	/**********************************WATCHDOG_TESTING*******************************/
	//
	//	//	DIO_voidSetPinDirection(PORTB,PIN7_ID,OUTPUT);
	//	//	DIO_voidSetPinDirection(PORTA,PIN4_ID,OUTPUT);
	//	//	DIO_voidSetPinDirection(PORTA,PIN6_ID,OUTPUT);
	//
	//	//	DIO_voidSetPinDirection(PORTA,PIN6_ID,OUTPUT);
	//	//	DIO_voidSetPinDirection(PORTA,PIN5_ID,OUTPUT);
	//	//	DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_HIGH);
	//	//	_delay_ms(2000);
	//	//	DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_LOW);
	//	//	WDT_sleep(_2100_ms);
	//	//	WDT_Enable();
	//
	//	/************************************WATCHDOG_TESTING***********************************/
	//
	//
	//
	//
	//	/*****************************UART_TESTING_DRIVER***********************/
	//
	//	//	UART_configType UART_OBJ;
	//	//	UART_OBJ.size=BIT_8;
	//	//	UART_OBJ.stop=ONE_BIT;
	//	//	UART_OBJ.parity=DISABLED;
	//	//	UART_init(57600,&UART_OBJ);
	//	//UART_sendByte('9');
	//
	//
	//
	//	/*****************************UART_TESTING_DRIVER***********************/
	//
	//
	//	//SET_BIT(SREG,PIN7_ID);
	//
	//	/*********************TIMER0_TESTING_DRIVER****************************/
	//
	//	//	DIO_voidSetPinDirection(PORTB,PIN3_ID,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN7_ID,OUTPUT);//red
	DIO_voidSetPinDirection(PORTA,PIN4_ID,OUTPUT);//green
	DIO_voidSetPinDirection(PORTA,PIN5_ID,OUTPUT);//blue

	DIO_voidSetPinDirection(PORTC,PIN5_ID,INPUT);
	DIO_voidSetPinValue(PORTC,PIN5_ID,LOGIC_HIGH);

	H_LCD_void_Init();
	H_LCD_void_sendString("ABIDO IS MKALBZ");
	//	DIO_voidSetPinValue(PORTB,PIN7_ID,LOGIC_HIGH);
	//	DIO_voidSetPinValue(PORTA,PIN4_ID,LOGIC_HIGH);
	//	DIO_voidSetPinValue(PORTA,PIN5_ID,LOGIC_HIGH);
	//	//	DIO_voidSetPinDirection(PORTA,PIN6_ID,OUTPUT);//yellow
	TIMER0_CONFIG timer;
	timer.TIMER0_MODES =NORMAL_MODE;
	timer.VALUE=0;
	timer.PRESCALER=CLK_DIV_1024;
	timer.NON_PWM_MODE = NORMAL_1;
	Timer_Init(&timer);
	EnableInt(&timer,led_on);


	//
	//	/*********************TIMER0_TESTING_DRIVER****************************/
	//
	//
	//
	//	setFastPWM(50,NON_INVERTING_MODE);
	//	/***********************EXTI DRIVER TESTING*******************************/
	//
	//	//	EXTI_INIT();
	//	//_delay_ms(10000);
	//	//EXTI_DISABLE(&exti_object);                                          //not working till now
	//
	//	/***********************EXTI DRIVER TESTING*******************************/
	//
	//
	//	/*******************************TESTING_7_SEGMENT_DRIVER******************************************/
	//	//		uint8 counter;
	//	//		segment_init(_4_channels);
	//
	//	/*******************************TESTING_7_SEGMENT_DRIVER******************************************/
	//
	//	//segment_init(channel_0);
	//	//	H_LCD_void_Init();
	//	//H_LCD_void_sendString("yasso mogrem   ");
	//
	//	/************************ADC_TESTING_DRIVER***************************/
	//	Init_temp();
	//	uint16 value=0;
	//	//	/************************ADC_TESTING_DRIVER***************************/
	//
	//
	//	/**********************************aura_testing**********************/
	//	//	UART_configType UART_OBJ;
	//	//	UART_OBJ.size=BIT_8;
	//	//	UART_OBJ.stop=ONE_BIT;
	//	//	UART_OBJ.parity=DISABLED;
	//	//	UART_init(57600,&UART_OBJ);
	//	//
	//	//	FingerPS_handShake();
	//	//Aura_blue();
	//
	//	//DIO_voidSetPinDirection(PORTA,PIN6_ID,OUTPUT);
	//
	//	//	uint8 temp;
	//	//	uint8 temp_arr[20]={0};
	//	//	H_LCD_void_IniT();
	//	//	_delay_ms(30);
	//	uint16 tempratue;
	//	//	//LCD_init();
	//	//	//LCD_clearScreen();
	//	//	//DcMotor_Init();
	//	H_LCD_void_Init();
	//	H_LCD_void_sendString("starting the app.");
	//	_delay_ms(1000);
	//	//
	//	//	ADC_ConfigType obj;
	//	//	obj.ref_volt=Internal_AREF;
	//	//	obj.prescaler=Div_Factor128;
	//	//	obj.AutoTrigger=OFF;
	//	//	ADC_init(&obj);
	//	DIO_voidSetPinDirection(PORTA,PIN1_ID,INPUT);

	/***********************
	 * ************************************COOLING SYSTEM PROJECT***********
	 * **********************************************************************************************************/

	//	DIO_voidSetPinDirection(PORTA,PIN0_ID,INPUT);
	//
	//	Init_temp();
	//	H_LCD_void_Init();
	//	DcMotor_Init();
	//
	//	uint8 temperature=0;
	//	H_LCD_void_sendString("starting the app.");
	//	_delay_ms(1000);
	//	H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);
	//	H_LCD_void_sendString("current temp = ");

	/***********************
	 * ************************************COOLING SYSTEM PROJECT***********
	 * **********************************************************************************************************/
	while(1)
	{

	//	H_LCD_void_sendString("X2");
		/***********************
		 * ************************************COOLING SYSTEM PROJECT***********
		 * **********************************************************************************************************/

		//		H_LCD_void_gotoXY(1,0);
		//		temperature=Read_Temp();
		//		H_LCD_void_sendIntNum(temperature);
		//		_delay_ms(250);
		//
		//
		//		if(temperature<=25)
		//		{
		//			DcMotor_Rotate(Stop,0);
		//			DIO_voidSetPinValue(PORTA,PIN4_ID,LOGIC_HIGH);
		//
		//		}
		//		else if(temperature>25 && temperature <35)
		//		{
		//			DcMotor_Rotate(Anti_Clockwise,50);
		//			DIO_voidSetPinValue(PORTA,PIN5_ID,LOGIC_HIGH);
		//
		//		}
		//		else if(temperature >=35)
		//		{
		//			DcMotor_Rotate(Anti_Clockwise,80);
		//			DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_HIGH);
		//
		//		}

		/***********************
		 * ************************************COOLING SYSTEM PROJECT***********
		 * **********************************************************************************************************/


		//LCD_displayString("alooo");

		//	H_LCD_void_sendData(8);

		//		//
		//		H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);
		//		//		H_LCD_void_sendString("fuck this LCD.");
		//		//		_delay_ms(1000);
		//		//		H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);
		//		//		H_LCD_void_sendString("putta.");
		//		//		_delay_ms(1000);
		//
		//		H_LCD_void_sendString("currnt temp = ");
		//		_delay_ms(500);
		//		tempratue=Read_Temp();
		//		H_LCD_void_sendIntNum(tempratue);
		//		_delay_ms(500);


		//UART_sendString("foofa");
		//temp=UART_recieveByte_Polling();
		//		UART_sendByte(temp);

		//	UART_sendString(ShackHand);
		//UART_receiveString_Polling(temp_arr);
		//		Aura_blue();
		//		H_LCD_void_sendString("yooooh");
		//
		//		H_LCD_void_sendIntNum(12);
		//
		//
		//		H_LCD_void_sendString(temp_arr);
		//		_delay_ms(1000);
		//		_delay_ms(1000);
		//		UART_sendString(temp_arr);

		//		FingerPS_handShake();
		//		Aura_blue();
		//		_delay_ms(1000);
		//		DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_HIGH);

		/************************************WATCHDOG_TESTING***********************************/
		//		TOGGLE_BIT((PORTA->PORT.Reg),PIN5_ID);
		//		_delay_ms(1500);
		//		WDT_refresh();



		/************************************WATCHDOG_TESTING***********************************/


		/***********************TIMER0_TESTING******************/
		//				setFastPWM(50,NON_INVERTING_MODE);
		//				_delay_ms(2000);
		//
		//				setFastPWM(100,NON_INVERTING_MODE);
		//				_delay_ms(2000);
		//
		//				setFastPWM(0,NON_INVERTING_MODE);
		//				_delay_ms(2000);

		/***********************TIMER0_TESTING******************/


		//		UART_sendString("548");
		//		_delay_ms(1000);
		//		UART_sendString("Duck ");
		//		_delay_ms(1000);

		//DIO_voidSetPinValue(PORTA,PIN4_ID,LOGIC_LOW);

		//DIO_voidSetPinValue(PORTA,PIN4_ID,LOGIC_LOW);

		//DIO_voidSetPinValue(PORTB,PIN7_ID,LOGIC_HIGH);

		/************************ADC_TESTING_DRIVER***************************/
		//ADC_getDigitalValueAsynchCallBack(channel_1,led_on);
		/************************ADC_TESTING_DRIVER***************************/



		//		value=ADC_getDigitalValueSynchNonBlocking(channel_1);
		//		H_LCD_void_sendIntNum(value);
		//		_delay_ms(500);
		//		H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);

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


