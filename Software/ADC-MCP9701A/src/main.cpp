/***Program to display temperature from analog sensor***/

#include <Arduino.h>

int analogPin = 26; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;        // variable to store the value read

float voltage = 0;  // variable to store the ADC's output calculated in Volts
float temp = 0;     // variable to store the calculated temperature

void setup() {
 Serial.begin(9600);                  // Setting baud rate
 delay(5000);
 Serial.println("SYS START");
}

void loop() {
  val = analogRead(analogPin);        // Reaing the ADC's output
  Serial.print("Adc value: ");        // Printing the ADC's output
  Serial.println(val);          

  voltage = val * 3.3 / 1024;         // Value in the ADC's output in Volts
  Serial.print("Adc voltage: ");      // Printing the ADC's output in Volts with 3 digits after the decimal
  Serial.println(voltage, 3);    

  temp =  (voltage - 0.4)/0.0195;     // Calculating the temperature
  Serial.print("Temperature in C: "); // Printing the temperature   
  Serial.println(temp);
  delay(1000);
}
