/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA0 aliases
#define DHT11_TRIS                 TRISAbits.TRISA0
#define DHT11_LAT                  LATAbits.LATA0
#define DHT11_PORT                 PORTAbits.RA0
#define DHT11_WPU                  WPUAbits.WPUA0
#define DHT11_OD                   ODCONAbits.ODCA0
#define DHT11_ANS                  ANSELAbits.ANSA0
#define DHT11_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define DHT11_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define DHT11_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define DHT11_GetValue()           PORTAbits.RA0
#define DHT11_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define DHT11_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define DHT11_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define DHT11_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define DHT11_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define DHT11_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define DHT11_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define DHT11_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)
// get/set IO_RB6 aliases
#define UART_TX_TRIS                 TRISBbits.TRISB6
#define UART_TX_LAT                  LATBbits.LATB6
#define UART_TX_PORT                 PORTBbits.RB6
#define UART_TX_WPU                  WPUBbits.WPUB6
#define UART_TX_OD                   ODCONBbits.ODCB6
#define UART_TX_ANS                  ANSELBbits.ANSB6
#define UART_TX_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define UART_TX_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define UART_TX_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define UART_TX_GetValue()           PORTBbits.RB6
#define UART_TX_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define UART_TX_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define UART_TX_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define UART_TX_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define UART_TX_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define UART_TX_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define UART_TX_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define UART_TX_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)
// get/set IO_RB7 aliases
#define UART_RX_TRIS                 TRISBbits.TRISB7
#define UART_RX_LAT                  LATBbits.LATB7
#define UART_RX_PORT                 PORTBbits.RB7
#define UART_RX_WPU                  WPUBbits.WPUB7
#define UART_RX_OD                   ODCONBbits.ODCB7
#define UART_RX_ANS                  ANSELBbits.ANSB7
#define UART_RX_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define UART_RX_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define UART_RX_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define UART_RX_GetValue()           PORTBbits.RB7
#define UART_RX_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define UART_RX_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define UART_RX_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define UART_RX_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define UART_RX_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define UART_RX_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define UART_RX_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define UART_RX_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)
// get/set IO_RD0 aliases
#define LED0_TRIS                 TRISDbits.TRISD0
#define LED0_LAT                  LATDbits.LATD0
#define LED0_PORT                 PORTDbits.RD0
#define LED0_WPU                  WPUDbits.WPUD0
#define LED0_OD                   ODCONDbits.ODCD0
#define LED0_ANS                  ANSELDbits.ANSD0
#define LED0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LED0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LED0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LED0_GetValue()           PORTDbits.RD0
#define LED0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LED0_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define LED0_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define LED0_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define LED0_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define LED0_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define LED0_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)
// get/set IO_RD1 aliases
#define LED1_TRIS                 TRISDbits.TRISD1
#define LED1_LAT                  LATDbits.LATD1
#define LED1_PORT                 PORTDbits.RD1
#define LED1_WPU                  WPUDbits.WPUD1
#define LED1_OD                   ODCONDbits.ODCD1
#define LED1_ANS                  ANSELDbits.ANSD1
#define LED1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LED1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LED1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LED1_GetValue()           PORTDbits.RD1
#define LED1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LED1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/