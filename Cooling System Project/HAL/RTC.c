/*
 * RTC.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Ali Afifi
 */

#include "RTC_interface.h"
#include "RTC_private.h"

#include "std_types.h"
#include "common_macros.h"
#include "TWI.h"




//time_t time_res;
//year_t date_res;

/* this function should initialize TWI with the speed required to operate RTC -> */
void RTC_voidInit(void){

	/* enable the oscillator (CH bit = 0) during initial configuration */
	//CLEAR_BIT(SECONDS_REG,PIN7_ID);
	TWI_ConfigType TWI_obj;
	TWI_obj.prescalar=F_CPU64;
	TWI_obj.speed=TWI_SPEED_100;
	TWI_init(&TWI_obj);

}

///* this function should take time in (hours minutes seconds )and if the time is (AM or PM),
//   it should configure RTC initial time with it ->*/
//void RTC_voidSetTime(time_t* copy_time){
//
//	// algorithm to send data
//
//
//	/* start sending data */
//
//	TWI_sendStart();
//
//	TWI_sendByte(RTC_Slave_Address_W);
//
//	TWI_sendByte(SECONDS_REG);
//
//	TWI_sendByte(0x41);
//
//	TWI_sendByte();
//
//	TWI_sendByte();
//
//	TWI_sendStop();
//}
//
///* this function should return the time in (hours minutes seconds) and if the time is (AM or PM)-> */
//void  RTC_GetTime(time_t * ptr_time){
//
//	/* start Receiving data */
//
//	TWI_sendStart();
//
//	TWI_sendByte(0xD0);
//
//	TWI_sendByte(0x00);
//
//	I2C_Master_u8ReStartCondition();
//
//	TWI_sendByte(0xD1);
//
//	uint8 ptr_time_receive;
//
//	TWI_receiveByte_ACK();
//
//	uint8 time_sec = ptr_time_receive;
//
//	TWI_receiveByte_ACK();
//
//	uint8 time_min = ptr_time_receive;
//
//	TWI_receiveByte_NoACK();
//
//	uint8 time_HR = ptr_time_receive;
//
//	I2C_Master_u8StopCondition();
//
//	/* Data handling to return time */
//
//	uint8 temp= time_sec >> 4;
//	temp*= 10;
//	time_sec= (time_sec & 0x0f) + temp;
//
//	temp= time_min >> 4;
//	temp*= 10;
//	time_min= (time_min & 0x0f) + temp;
//
//	temp= time_HR >> 4;
//	temp*= 10;
//	time_HR= (time_HR & 0x0f) + temp;
//
//
//	ptr_time->second = time_sec;
//
//	ptr_time->minute = time_min;
//
//	ptr_time->hour = time_HR;
//
//	if( (GET_BIT(time_HR,6) == 1) ){
//
//		ptr_time->time_format = time_format_12;
//
//		if( (GET_BIT(time_HR,5) == 1) ){
//
//			ptr_time->time_mode = PM;
//
//		}
//		else if( ( GET_BIT(time_HR,5) == 0 ) ) {
//			ptr_time->time_mode = AM;
//		}
//		else{
//
//			// do nothing , error type
//		}
//	}
//
//	else if( (GET_BIT(time_HR,6) == 0) ){
//
//		ptr_time->time_format = time_format_24;
//		ptr_time->time_mode = No_TYPE;
//	}
//
//}
//
///* this function should take date in (year month day )and should configure RTC with it -> */
//void RTC_SetDate(year_t* copy_year){
//
//	/* Data year handling */
//
//	uint8 day_res_send = RTC_dayFormat(copy_year->day);
//
//	uint8 date_res_send = RTC_dateFormat(copy_year->date);
//
//	uint8 month_res_send = RTC_MonthFormat(copy_year->month);
//
//	uint8 year_res_send = RTC_yearFormat(copy_year->year);
//
//
//	/* start sending data */
//
//	TWI_sendStart();
//
//	TWI_sendByte(0xD0);
//
//	TWI_sendByte(0x03);
//
//	TWI_sendByte(day_res_send);
//
//	TWI_sendByte(date_res_send);
//
//	TWI_sendByte(month_res_send);
//
//	TWI_sendByte(year_res_send);
//
//	I2C_Master_u8StopCondition();
//
//
//}
//
///* this function should return the data in (year month day)-> */
//year_t  RTC_GetDate(void){
//
//
//	/* start Receiving data */
//
//	TWI_sendStart();
//
//	TWI_sendByte(0xD0);
//
//	TWI_sendByte(0x03);
//
//	I2C_Master_u8ReStartCondition();
//
//	TWI_sendByte(0xD1);
//	uint8 ptr_date_receive;
//
//	I2C_Master_u8ReadDataByte_ACK(&ptr_date_receive);
//
//	uint8 date_day = ptr_date_receive;
//
//	I2C_Master_u8ReadDataByte_ACK(&ptr_date_receive);
//
//	uint8 date = ptr_date_receive;
//
//	I2C_Master_u8ReadDataByte_ACK(&ptr_date_receive);
//
//	uint8 date_month = ptr_date_receive;
//
//	I2C_Master_u8ReadDataByte_NOTACK(&ptr_date_receive);
//
//	uint8 date_year = ptr_date_receive;
//
//	I2C_Master_u8StopCondition();
//
//	/* Data handling to return date */
//
//	date_res.day = date_day;
//	date_res.date = date;
//	date_res.month = date_month;
//	date_res.year = date_year;
//
//	return date_res;
//
//}
//
//uint8 RTC_TimeSecFormat(uint8 copy_time_sec){
//
//	uint8 local_sec_time = 0;
//
//	CLEAR_BIT(local_sec_time,7);
//
//	uint8 Sec_format[2];
//
//	uint8 temp = copy_time_sec;
//
//	//Sec_format[0] = temp % 10;
//	//Sec_format[1] = temp / 10;
//
//	for(uint8 i=0;i<2;i++){
//
//		Sec_format[i] = temp % 10;
//
//		temp = temp / 10;
//
//	}
//	//
//	//		 uint8 mask1 = 0b00001111;
//	//
//	//		 local_sec_time |= (mask1 & sec_format[0] );
//	//
//	//		 uint8 mask2 = 0b01110000;
//	//
//	//		 local_sec_time |= (mask2 & sec_format[1]);
//
//	local_sec_time |=  Sec_format[0]  | ( Sec_format[1]<<4);
//
//	return local_sec_time;
//
//
//}

//uint8 RTC_TimeMinFormat(uint8 copy_time_min){
//
//	uint8 local_Min_time = 0;
//
//	CLEAR_BIT(local_Min_time,7);
//
//	uint8 Min_format[2];
//
//	uint8 temp = copy_time_min;
//
//	for(uint8 i=0;i<2;i++){
//
//		Min_format[i] = temp % 10;
//
//		temp = temp / 10;
//
//	}
//
//	//	 uint8 mask1 = 0b00001111;
//	//
//	//	 local_Min_time |= (mask1 & Min_format[0] );
//	//
//	//	 uint8 mask2 = 0b01110000;
//	//
//	//	 local_Min_time |= (mask2 & Min_format[1]);
//
//	local_Min_time = ( Min_format[0] | ( Min_format[1] <<4) );
//
//	return local_Min_time;
//
//}
//
//uint8 RTC_TimeHrFormat(uint8 copy_time_HR , uint8 copy_time_format, uint8 copy_time_mode){
//
//	uint8 local_HR_time =0;
//
//	CLEAR_BIT(local_HR_time,7);
//
//	uint8 HR_format[2];
//
//	uint8 temp = copy_time_HR;
//
//	for(uint8 i=0;i<2;i++){
//
//		HR_format[i] = temp % 10;
//
//		temp = temp / 10;
//	}
//
//	switch(copy_time_format){
//
//	case time_format_12:
//
//		SET_BIT(local_HR_time,6);
//
//		switch(copy_time_mode){
//		case AM:
//			CLEAR_BIT(local_HR_time,5);
//
//			break;
//		case PM:
//			SET_BIT(local_HR_time,5);
//			break;
//		}
//
//		local_HR_time |= ( HR_format[0] | ( HR_format[1] <<4)) ;
//
//		local_HR_time &= 0b00011111;
//		break;
//
//		case time_format_24:
//
//			CLEAR_BIT(local_HR_time,6);
//			CLEAR_BIT(local_HR_time,5);
//			local_HR_time |= ( HR_format[0] | ( HR_format[1] <<4)) ;
//
//			local_HR_time &= 0b00111111;
//			break;
//
//	}
//
//
//
//	//	local_HR_time |= ( HR_format[0] | ( HR_format[1] <<4)) ;
//
//	return local_HR_time;
//
//}
//
//uint8 RTC_dateFormat(uint8 copy_year_date){
//
//	uint8 local_date =0;
//
//	uint8 date_format[2];
//
//	uint8 temp = copy_year_date;
//
//	for(uint8 i=0;i<2;i++){
//
//		date_format[i] = temp % 10;
//
//		temp = temp / 10;
//
//	}
//
//	local_date = date_format[0] | (date_format[1]<<4);
//
//	return local_date;
//}
//
//uint8 RTC_dayFormat(uint8 copy_year_day){
//
//	uint8 local_day = copy_year_day;
//
//	return local_day;
//}
//
//uint8 RTC_MonthFormat(uint8 copy_year_month){
//
//	uint8 month_format[2];
//
//	uint8 temp = copy_year_month;
//
//	for(uint8 i=0;i<2;i++){
//
//		month_format[i] = temp % 10;
//
//		temp = temp / 10;
//
//	}
//
//	uint8 local_month = month_format[0] | (month_format[1] << 4);
//
//	return local_month;
//}
//
//uint8 RTC_yearFormat(uint8 copy_year){
//
//	uint8 year_format[2];
//
//	uint8 temp = copy_year;
//
//	for(uint8 i=0;i<2;i++){
//
//		year_format[i] = temp % 10;
//
//		temp = temp / 10;
//
//	}
//
//	uint8 local_year = year_format[0] | (year_format[1] << 4);
//
//	return local_year;
//}
//
//
