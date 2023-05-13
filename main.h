#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// #include <ctype.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"

#define isdigit(c) (c >= '0' && c <= '9')
#define Pi 3.14159265

#define FINAL_X 0
#define FINAL_Y 0

void PortF_Init(void);
void PortB_Init(void);
void PortE_Init(void);
void RED_LED (float distance);

double distance_twoPoints(double X1, double Y1, double X2, double Y2);
double Total_distance(double X1, double Y1, double X2, double Y2);

void delay(int delay);
void Config_LCD(unsigned char configuration);
void Display_on_LCD (void);
void write_Data_LCD(unsigned char data);
void write_string_LCD(char *array);
void Position_into_LCD(unsigned char x,unsigned char y);

void Light_Leds(float distance);

void UART5_init (void);
char UART_InChar(void);

double atof1(const char *s);
void Parsing_GPS(double *lat , double *lon);


#define LCD GPIOB    		//LCD port with Tiva C 
#define RS 0x01				 	//RS -> PB0 (0x01)
#define RW 0x02         //RW -> PB1 (0x02)
#define EN 0x04  		 	 	//EN -> PB2 (0x04)


//Functions Declaration
void delayUs(int);   														   //Delay in Micro Seconds
void delayMs(int);   														   //Delay in Milli Seconds
void LCD4bits_Init(void);		 											 //Initialization of LCD Dispaly
void LCD_Write4bits(unsigned char, unsigned char); //Write data as (4 bits) on LCD
void LCD_WriteString(char*);											 //Write a string on LCD 
void LCD4bits_Cmd(unsigned char);									 //Write command 
void LCD4bits_Data(unsigned char);								 //Write a character

#endif