/*
 * The following code reads and displays weight value.
 * 
 * Author: Suwetha I G
 */
 
#include "HX711.h"  

//Pin and variable initialisation

#define DOUT  15  //Data pin
#define CLK  14   //Clock pin
HX711 scale(DOUT, CLK);

float calibration_factor = +196520; // Set to value according to CALIBRATE_LOAD_CELL.ino code
float weight1;

void setup()
{
  //Initialise serial monitor
  Serial.begin(115200);
  
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  scale.set_offset(98481);
}

void loop()
{
  weight1 = scale.get_units();
  
  Serial.print("Weight:");
  Serial.println(scale.get_units(), 4);//Displays weight upto 4 decimal points
  delay(1000);
}
