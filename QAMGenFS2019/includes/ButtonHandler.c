/*
 * ButtonHandler.c
 *
 * Created: 21.06.2017 12:50:56
 *  Author: mburger
 */ 
 #include <avr/io.h>
 #include "ButtonHandler.h"

 #define Button1_Value (PORTF.IN & PIN4_bm) >> PIN4_bp
 #define Button2_Value (PORTF.IN & PIN5_bm) >> PIN5_bp
 #define Button3_Value (PORTF.IN & PIN6_bm) >> PIN6_bp
 #define Button4_Value (PORTF.IN & PIN7_bm) >> PIN7_bp

 #define BUTTON_PRESS_SHORT			10
 #define BUTTON_PRESS_LONG			500

 

 void initButtons(void) {
	PORTF.DIRCLR = PIN4_bm; //SW1
	PORTF.DIRCLR = PIN5_bm; //SW2
	PORTF.DIRCLR = PIN6_bm; //SW3
	PORTF.DIRCLR = PIN7_bm; //SW4
 }

 button_press_t b1Status;
 button_press_t b2Status;
 button_press_t b3Status;
 button_press_t b4Status;

 void updateButtons(void) {
	static uint16_t b1Count = 0;
	static uint16_t b2Count = 0;
	static uint16_t b3Count = 0;
	static uint16_t b4Count = 0;
	if(Button1_Value == 0) 
	{
		if(b1Count < 60000) 
		{
			b1Count++;
		}
	} 
	else 
	{
		if(b1Count > (BUTTON_PRESS_SHORT / (1000/BUTTON_UPDATE_FREQUENCY_HZ))) 
		{
			//Button was pressed Short	
			b1Status = ePRESSED;
		}
		else 
		{
			b1Status = eNOT_PRESSED;
		}
		b1Count = 0;
	}
	if(Button2_Value == 0) {
		if(b2Count < 60000) {
			b2Count++;
		}
	} 
	else 
	{
		if(b2Count > (BUTTON_PRESS_SHORT / (1000/BUTTON_UPDATE_FREQUENCY_HZ))) 
		{
				//Button was pressed Short
				b2Status = ePRESSED;
		
		} 
		else 
		{
			b2Status = eNOT_PRESSED;			
		}
		b2Count = 0;
	}
	if(Button3_Value == 0) 
	{
		if(b3Count < 60000)
		 {
			b3Count++;
		}
	}
	else 
	{
		if(b3Count > (BUTTON_PRESS_SHORT / (1000/BUTTON_UPDATE_FREQUENCY_HZ))) 
		{
			//Button was pressed Short
			b3Status = ePRESSED;
			
		} 
		else 
		{
			b3Status = eNOT_PRESSED;
		}
		b3Count = 0;
	}
	if(Button4_Value == 0)
	 {
		if(b4Count < 60000)
		 {
			b4Count++;
		}
	} 
	else 
	{
		if(b4Count > (BUTTON_PRESS_SHORT / (1000/BUTTON_UPDATE_FREQUENCY_HZ))) 
		{
				//Button was pressed Short
				b4Status = ePRESSED;
	
		} 
		else
		{
			b4Status = eNOT_PRESSED;
		}
		b4Count = 0;
	}
 }

 button_press_t getButtonPress(button_t button) {
	switch(button) {
		case eBUTTON1:
			return b1Status;
		break;
		case eBUTTON2:
			return b2Status;
		break;
		case eBUTTON3:
			return b3Status;
		break;
		case eBUTTON4:
			return b4Status;
		break;
	}
	return eNOT_PRESSED;
 }