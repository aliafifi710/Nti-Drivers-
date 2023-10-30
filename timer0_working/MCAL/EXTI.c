/*
 * EXTI.c
 *
 *  Created on: Oct 22, 2023
 *      Author: user
 */
#include "EXTI.h"

void (* EXT_INT_POINTERS [3] )(void);  			//array of 3 pointers to functions that take void and return void
static ERROR_STATE status;

/****************************ENABLE THE EXTERNAL INTERRUPT MODULE****************************/

ERROR_STATE EXTI_ENABLE(EXTI_CONFIG* ptr_config)
{

	GIE_Disable();											//DISABLE GLOBAL INT BIT (I-BIT)
	SET_BIT(EXTI->GICR.Reg,ptr_config->INT_ID);				//ENABLE WHICH INT TO BE USED


	if(ptr_config->INT_ID != EXTI_INT0 || ptr_config->INT_ID != EXTI_INT1 || ptr_config->INT_ID != EXTI_INT2)
	{
		status= OUT_OF_RANGE_VALUE;
	}
	//	else if(ptr_config=='NULL')      //ana kda bkaren address b integer 3awz akaren eza kan l pointer da byshawer 3la null wlla la
	//	{
	//		status=NULL_POINTER;
	//	}

	SET_BIT(EXTI->GICR.Reg,ptr_config->INT_ID);				//ENABLE WHICH INT TO BE USED

	switch(ptr_config->INT_ID)
	{
	case EXTI_INT0:
		EXTI->MCUCR.Reg &= 0b11111100;						//CONFIGURE THE TRIGGER TYPE AND SET CALL BACK FUNCTION FOR INT0
		EXTI->MCUCR.Reg |= ptr_config->trigger_type;
		EXT_INT_POINTERS[0] = ptr_config->ptr_call_back;
		status= NO_ERROR;
		break;

	case EXTI_INT1:
		EXTI->MCUCR.Reg &= 0b11110011;						//CONFIGURE THE TRIGGER TYPE AND SET CALL BACK FUNCTION FOR INT1
		EXTI->MCUCR.Reg |=(ptr_config->trigger_type) <<2;
		EXT_INT_POINTERS[1] = ptr_config->ptr_call_back;
		status= NO_ERROR;
		break;

	case EXTI_INT2:

		EXTI->MCUCSR.Reg &=0b11011111;						//CONFIGURE THE TRIGGER TYPE AND SET CALL BACK FUNCTION FOR INT2
		EXTI->MCUCSR.Reg |=(ptr_config->trigger_type-2) <<PIN6_ID;
		EXT_INT_POINTERS[2] = ptr_config->ptr_call_back;
		status= NO_ERROR;
		break;
	}
	GIE_Enable();											//DON'T FORGET TO ENABLE THE GLOBAL I-BIT AFTER CONFIGURING THE EXTI

	return status;
}


/********************************DISABLE THE EXTI MODULE****************************/

ERROR_STATE EXTI_DISABLE(EXTI_CONFIG* ptr_config)
{
	if(ptr_config->INT_ID != EXTI_INT0 || ptr_config->INT_ID != EXTI_INT1 || ptr_config->INT_ID != EXTI_INT2)
	{
		status= OUT_OF_RANGE_VALUE;
	}
//	else if(ptr_config=='NULL')
//	{
//		status=NULL_POINTER;
//	}
	else
	{
		switch(ptr_config->INT_ID)
		{
		case EXTI_INT0:
			EXTI->GICR.Reg &= ~1<<EXTI_INT0; //disable interrupt 0
			status=NO_ERROR;
			break;

		case EXTI_INT1:
			EXTI->GICR.Reg &= ~(1<<EXTI_INT1); //disable interrupt 1
			status=NO_ERROR;
			break;

		case EXTI_INT2:
			EXTI->GICR.Reg &= ~1<<EXTI_INT2; //disable interrupt 2
			status=NO_ERROR;
			break;
		}
	}
	return status;

}

/****************************ISR FOR INT0**********************/
void __vector_1 (void)
{
	CLEAR_BIT(SREG,PIN7_ID);
	EXT_INT_POINTERS[0]();
}

/****************************ISR FOR INT1**********************/

void __vector_2 (void){
	CLEAR_BIT(SREG,PIN7_ID);
	EXT_INT_POINTERS[1]();

}
/****************************ISR FOR INT2**********************/

void __vector_3 (void){
	CLEAR_BIT(SREG,PIN7_ID);
	EXT_INT_POINTERS[2]();

}




