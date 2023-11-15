///*
// * RTC.h
// *
// *  Created on: Nov 3, 2023
// *      Author: Ali Afifi
// */
//
//#ifndef INC_RTC_INTERFACE_H_
//#define INC_RTC_INTERFACE_H_
//
//
//#define RTC_Slave_Address_W   0b11010000
//#define RTC_Slave_Address_R   0b11010001
//
//#define RTC_address_0       0
//#define RTC_address_1       1
//#define RTC_address_2       2
//#define RTC_address_3       3
//#define RTC_address_4       4
//#define RTC_address_5       5
//#define RTC_address_6       6
//#define RTC_address_7       7
//
//typedef enum{
//	time_format_24 = 0,
//	time_format_12 = 1
//}time_format_t;
//
//typedef enum{
//	AM =0,
//	PM =1,
//	No_TYPE =2
//}time_mode_t;
//
//typedef enum
//{
//	E_OK
//}ErrorState_t;
//
//typedef struct{
//	uint8 hour;
//	uint8 minute;
//	uint8 second;
//	time_format_t time_format;
//	time_mode_t time_mode;
//
//}time_t;
//
//typedef struct{
//	uint16 year;
//	uint8 month;
//	uint8 date;
//	uint8 day;
//}year_t;
//
//typedef struct{
//	uint8 sec_res;
//	uint8 min_res;
//	uint8 HR_res;
//}time_res_t;
//
//typedef struct{
//	uint8 day_res;
//	uint8 date_res;
//	uint8 month_res;
//	uint8 year_res;
//}year_res_t;
//
//
//
///* this function should initialize TWI with the speed required to operate RTC . */
//void RTC_voidInit(void);
//
///* this function should take time in (hours minutes seconds )and if the time is (AM or PM),
//	   it should configure RTC initial time with it .*/
//void RTC_voidSetTime(time_t* copy_time);
//
///* this function should return the time in (hours minutes seconds) and if the time is (AM or PM). */
//void RTC_GetTime(time_t * ptr_time);
//
///* this function should take date in (year month day )and should configure RTC with it . */
//void RTC_SetDate(year_t* copy_year);
//
///* this function should return the data in (year month day). */
//year_t  RTC_GetDate(void);
//
//uint8 RTC_TimeSecFormat(uint8 copy_time_sec);
//
//uint8 RTC_TimeMinFormat(uint8 copy_time_min);
//
//uint8 RTC_TimeHrFormat(uint8 copy_time_HR , uint8 copy_time_format, uint8 copy_time_mode);
//
//uint8 RTC_dateFormat(uint8 copy_year_date);
//
//uint8 RTC_dayFormat(uint8 copy_year_day);
//
//uint8 RTC_MonthFormat(uint8 copy_year_month);
//
//uint8 RTC_yearFormat(uint8 copy_year);
//
//
//#endif /* INC_RTC_INTERFACE_H_ */
