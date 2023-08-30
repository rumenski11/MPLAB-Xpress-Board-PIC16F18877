/*
 * File:   OLED.c
 * Author: User
 *
 * Created on August 28, 2023, 1:41 PM
 */


#include <xc.h>
#include "OLED.h"
#include "font.h"

//OLED display initiation
void Oled_Init(void)
{
    ssd1306_command( SSD1306_DISPLAY_OFF);
    ssd1306_command( SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO);
    ssd1306_command( 0x80);
    ssd1306_command( SSD1306_SET_MULTIPLEX_RATIO );
    ssd1306_command( SSD1306_LCDHEIGHT - 1 );
    ssd1306_command( SSD1306_SET_DISPLAY_OFFSET );
    ssd1306_command(0x00);
    ssd1306_command( SSD1306_SET_START_LINE|0x00);  // Line: 0
    ssd1306_command( SSD1306_CHARGE_PUMP );
    ssd1306_command(0x14);
    ssd1306_command( SSD1306_MEMORY_ADDR_MODE );
    ssd1306_command(0x00);  //Hor Addressing Mode is Used (02 is Ver)
    ssd1306_command( SSD1306_SET_SEGMENT_REMAP| 0x01);
    ssd1306_command( SSD1306_COM_SCAN_DIR_DEC );
    ssd1306_command( SSD1306_SET_COM_PINS );
    ssd1306_command( 0x02 );
    ssd1306_command( SSD1306_SET_CONTRAST_CONTROL );
    ssd1306_command(0x8F);
    ssd1306_command( SSD1306_SET_PRECHARGE_PERIOD );
    ssd1306_command( 0xF1 );
    ssd1306_command( SSD1306_SET_VCOM_DESELECT );
    ssd1306_command( 0x40 );
    ssd1306_command( SSD1306_DISPLAY_ALL_ON_RESUME );
    ssd1306_command( SSD1306_NORMAL_DISPLAY );
    ssd1306_command( SSD1306_DEACTIVATE_SCROLL );
    ssd1306_command( SSD1306_DISPLAY_ON );

    printf("OLED init. done!\n");
}

//Function to send commands
void ssd1306_command(uint8_t command) 
{    
    uint8_t data_I2C[2];

    data_I2C[0] = SSD1306_COMMAND  ; 
    data_I2C[1] = command; 

    I2C1_WriteNBytes(SSD1306_ADDR, data_I2C, 2);
}

//Function for sending data
void ssd1306_Data(uint8_t value)
{
  uint8_t data_I2C[2];
  
  data_I2C[0] = SSD1306_DATA_CONTINUE ; 
  data_I2C[1] = value; 
  
  I2C1_WriteNBytes(SSD1306_ADDR, data_I2C, 2);
}

//Function to clear the display
void Oled_Clear(void)
{
    Oled_SelectPage(0);  
    int i =0;
    // OLED 128* 32 pixels = total pixels -> (4096 / 1 byte) = 512 passes.
    // SSD1306_CLEAR_SIZE  = 512 for 128* 32 or 1024  for 128*64
    for (i; i<SSD1306_CLEAR_SIZE ; i++) // clear oled screen
    {
      ssd1306_Data(0x00);   
    }
}

//Function to fill the whole display
void Oled_Fill(void)
{
    Oled_SelectPage(0);  
    int i =0;
    // OLED 128* 32 pixels = total pixels -> (4096 / 1 byte) = 512 passes.
    // SSD1306_CLEAR_SIZE  = 512 for 128* 32 or 1024  for 128*64
    for (i; i<SSD1306_CLEAR_SIZE ; i++) // fill oled screen 
    {
      ssd1306_Data(0xff);  
    }
}

//Select Page (Line) on the OLED display
void Oled_SelectPage(uint8_t page_num)
{
 uint8_t Result =0xB0 | page_num; // Mask or with zero lets everything thru
 ssd1306_command(Result); 
 ssd1306_command(SSD1306_SET_LOWER_COLUMN);
 ssd1306_command(SSD1306_SET_HIGHER_COLUMN); 
}

//function to write a string to OLED, passed string
void Oled_WriteString(char *characters)
{
  while (*characters) Oled_WriteCharacter(*characters++);
}

//function to write a character, passed character
void Oled_WriteCharacter(char character)
{
  for (int i=0; i<5; i++) ssd1306_Data((ASCII[character - 0x20][i]));
  ssd1306_Data(0x00);
}

//Changing the contrast
void Oled_SetContrast( uint8_t contrast )
{
  ssd1306_command(SSD1306_SET_CONTRAST_CONTROL );
  ssd1306_command(contrast);
}