/***Program to display temperature from both analog and digital sensors and the humidity from the digital sensor***/

//included libraries
#include <Arduino.h>
#include<DHT.h>

#define DHTPIN 16       // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // Type of the DHT sensor

DHT dht(DHTPIN, DHTTYPE); // Initialize the DHT sensor.

int analogPin = 26; // potentiometer wiper (middle terminal) connected to GPIO26
                    // outside leads to ground and +3.3V
int val = 0;        // variable to store the value read

float voltage = 0;  // variable to store the ADC's output calculated in Volts
float temp = 0;     // variable to store the calculated temperature

void setup() {
 Serial.begin(9600);                  //Setting baud rate
 delay(5000);
 Serial.println("SYS START");
 dht.begin();
}

void loop() {
  val = analogRead(analogPin);        // Reading and printing the ADC's output
  Serial.print("MCP9701: ");
  Serial.print("Adc value: ");
  Serial.print(val);
  Serial.print('\t');          

  voltage = val * 3.3 / 1024;         // Value in the ADC's output in Volts

  Serial.print("Adc voltage: ");      // Printing the ADC's output in Volts with 3 digits after the decimal
  Serial.print(voltage, 3); 
  Serial.print('\t');   

  temp =  (voltage - 0.4)/0.0195;     // Calculating the temperature

  Serial.print("Temperature in C: "); // Printing the temperature    
  Serial.println(temp);
  Serial.print('\t');
  
  float h = dht.readHumidity();       // Reading humidity
  float t = dht.readTemperature();    // Read temperature as Celsius (the default)

  Serial.print("DHT11: ");            //Printing DHT11's temperature and humidity
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print('\t');
  Serial.print(F("%  Temperature: "));
  Serial.println(t);

  delay(1000);
}
