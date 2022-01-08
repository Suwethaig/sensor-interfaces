/*
 * The following code is used to read temperature in K Type Thermocouple sensor
 * 
 * Author: Suwetha I G
 */
 
#include <max6675.h>


//Pins and variables initialisation
int thermo1_SO = 27;
int thermo1_CS = 14;   //Chip select pin
int thermo1_CLK = 12;  //Clock pin

MAX6675 thermo1(thermo1_CLK, thermo1_CS, thermo1_SO);

void setup()
{
  //Initialise serial monitor
  Serial.begin(115200);
  
  delay(500);
}

void loop()
{
  float DC_thermo1 = thermo1.readCelsius(); // Read temperature as Celsius
  Serial.print("sensor 1 in C: ");
  Serial.print(DC_thermo1);
  Serial.print("*C");

  float DF_thermo1 = thermo1.readFahrenheit(); // Read temperature as Fahrenheit
  Serial.print("\t\tsensor 1 in F: ");
  Serial.print(DF_thermo1);
  Serial.println("*F");

  delay(500);
}
