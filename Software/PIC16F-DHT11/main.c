 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"

/*
    Main application
*/

void DHT11_Start();         //Sends Start pulse to DHT11 sensor
void DHT11_CheckResponse(); //Check if the DHT11 sensor is responding
char DHT11_ReadData();      //Reads data from the DHT11 sensor

int main(void)
{
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    //INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

    /*Variables*/
    char RH_Decimal, RH_Integral, T_Decimal, T_Integral;
    char Checksum;
    
    //Setting both LED colors to High
    LED0_SetHigh();
    LED1_SetHigh();
    
    __delay_ms(5000);
    
    printf("sys start!\n");

    while(1)
    {
        /*******LED blink*********/
        LED0_Toggle();
        __delay_ms(500);
        LED0_Toggle();
        __delay_ms(500);
        
        LED1_Toggle();
        __delay_ms(500);
        LED1_Toggle();
        __delay_ms(500);
        
        DHT11_Start();  			/* send start pulse to DHT11 module */
    	DHT11_CheckResponse();  	/* wait for response from DHT11 module */
    	
    	/* read 40-bit data from DHT11 module */
    	RH_Integral = DHT11_ReadData();  /* read Relative Humidity's integral value */
    	RH_Decimal = DHT11_ReadData();   /* read Relative Humidity's decimal value */
    	T_Integral = DHT11_ReadData();   /* read Temperature's integral value */
    	T_Decimal = DHT11_ReadData();    /* read Relative Temperature's decimal value */
    	Checksum = DHT11_ReadData();     /* read 8-bit checksum value */
    	
    	/* convert humidity value to ascii and send it to display*/    
    	printf("Humidity: %d", RH_Integral);
    	printf(".%d ", RH_Decimal);
    	printf("%%, ");
    	
    	/* convert temperature value to ascii and send it to display*/
    	printf("Temperature: %d",T_Integral);
    	printf(".%d",T_Decimal);
    	printf("C, ");
    	
    	printf("Checksum: %d, ",Checksum);
    	
    	/* check addition of humidity and temperature value equals to checksum */
    	if(Checksum != (RH_Integral + RH_Decimal + T_Integral + T_Decimal))
        	printf("Error\n");
    	else
        	printf("No Error\n");
        
        __delay_ms(1000);
    }    
}

char DHT11_ReadData()
{
  char i, data = 0;  
    for(i=0; i<8; i++)
    {
        while(!(DHT11_PORT & 1));   /* wait till 0 pulse, this is start of data pulse */
        __delay_us(30);         
        if(DHT11_PORT & 1)          /* check whether data is 1 or 0 */    
          data = ((data<<1) | 1); 
        else
          data = (data<<1);  
        while(DHT11_PORT & 1);
    }
  return data;
}

void DHT11_Start()
{    
    DHT11_TRIS = 0;  /* set as output port */
    DHT11_LAT = 0;  /* send low pulse of min. 18 ms width */
    __delay_ms(18);
    DHT11_LAT = 1;  /* pull data bus high */
    __delay_us(20);
    DHT11_TRIS = 1;  /* set as input port */    
}

void DHT11_CheckResponse()
{
    while(DHT11_PORT & 1);      /* wait till bus is High */     
    while(!(DHT11_PORT & 1));   /* wait till bus is Low */
    while(DHT11_PORT & 1);      /* wait till bus is High */
}