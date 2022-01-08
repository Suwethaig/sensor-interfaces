/***************************************************
  This is a library for the Adafruit PT100/P1000 RTD Sensor w/MAX31865

  Designed specifically to work with the Adafruit RTD Sensor
  ----> https://www.adafruit.com/products/3328

  This sensor uses SPI to communicate, 4 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Adafruit_MAX31865.h>

// Use software SPI: CS, DI, DO, CLK
//Adafruit_MAX31865 thermo = Adafruit_MAX31865(14, 23, 19, 18);
// use hardware SPI, just pass in the CS pin
Adafruit_MAX31865 thermo = Adafruit_MAX31865(14);
Adafruit_MAX31865 thermo_2 = Adafruit_MAX31865(25);

// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      430.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0

void setup() 
{
  Serial.begin(115200);
  Serial.println("Adafruit MAX31865 PT100 Sensor Test!");

  thermo.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary
  thermo_2.begin(MAX31865_2WIRE);
}


void loop()
{
  uint16_t rtd = thermo.readRTD();
  uint16_t rtd_2 = thermo_2.readRTD();

  //Serial.print("RTD value: "); Serial.println(rtd);
  float ratio = rtd;
  float ratio_2 = rtd_2;
  ratio /= 32768;
  ratio_2 /= 32768;

  //Serial.print("Ratio = "); Serial.println(ratio,8);
  //Serial.print("Resistance = "); Serial.println(RREF*ratio,8);
  Serial.print("Temperature of 1 = ");
  Serial.println(thermo.temperature(RNOMINAL, RREF));
  Serial.print("Temperature of 2 = ");
  Serial.println(thermo_2.temperature(RNOMINAL, RREF));

  // Check and print any faults
  uint8_t fault = thermo.readFault();
  if (fault) {
    Serial.print("Fault 0x"); 
    Serial.println(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH) 
    {
      Serial.println("RTD High Threshold");
    }
    if (fault & MAX31865_FAULT_LOWTHRESH) 
    {
      Serial.println("RTD Low Threshold");
    }
    if (fault & MAX31865_FAULT_REFINLOW)
    {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (fault & MAX31865_FAULT_REFINHIGH) 
    {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (fault & MAX31865_FAULT_RTDINLOW)
    {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (fault & MAX31865_FAULT_OVUV)
    {
      Serial.println("Under/Over voltage");
    }
    thermo.clearFault();
  }
  
  // Check and print any faults
  uint8_t fault_2 = thermo_2.readFault();
  if (fault_2) {
    Serial.print("Fault 0x"); 
    Serial.println(fault_2, HEX);
    if (fault_2 & MAX31865_FAULT_HIGHTHRESH)
    {
      Serial.println("RTD High Threshold");
    }
    if (fault_2 & MAX31865_FAULT_LOWTHRESH)
    {
      Serial.println("RTD Low Threshold");
    }
    if (fault_2 & MAX31865_FAULT_REFINLOW)
    {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (fault_2 & MAX31865_FAULT_REFINHIGH) 
    {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (fault_2 & MAX31865_FAULT_RTDINLOW) 
    {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (fault_2 & MAX31865_FAULT_OVUV)
    {
      Serial.println("Under/Over voltage");
    }
    thermo_2.clearFault();
  }
  
  Serial.println();
  delay(1000);
}
