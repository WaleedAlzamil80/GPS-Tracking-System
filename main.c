#include "main.h"

void SystemInit(){}

int main()
	{
    double y1=0;
		double x1=0;
		double lat=0;
		double lon=0;
		char LCD[10];
		char c;
		double TD = 0;

		PortF_Init();
		PortE_Init();
		PortB_Init();
		Display_on_LCD();
		// LCD4bits_Init();
		UART5_init();
		// LCD4bits_Cmd(0x01);								//Clear the display
		// LCD4bits_Cmd(0x80);               //Force the cursor to beginning of 1st line
		// delayMs(500);											//delay 500 ms for LCD (MCU is faster than LCD)
	  // LCD_WriteString("Welcome here ...");
		write_string_LCD("Loading...");

		delayMs(500);
		LCD4bits_Cmd(0x01);

		while(1)
		{
			Config_LCD(0x01);
			Parsing_GPS( &lat , &lon);

			x1 = lat;
			y1 = lon;

			if(x1!=0 && y1!=0){
            TD = distance_twoPoints(x1,y1,FINAL_X,FINAL_Y);
          }
			Light_Leds(TD);
		  while ( TD >= 0 )
				{
					  Position_into_LCD(1,1);
						write_string_LCD("final position reached");
						// LCD_WriteString("Total distance:");
						Position_into_LCD(1,2);
						sprintf(LCD,"%f",TD);
						write_string_LCD(LCD);
						// LCD_WriteString(LCD);
						delay(1000);
				}
			Position_into_LCD(1,1);
			Position_into_LCD(1,2);
			sprintf(LCD,"%f",TD);
			write_string_LCD(LCD);
			// LCD_WriteString(LCD);
				delay(1000);
		}
	}