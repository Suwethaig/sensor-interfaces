/*
 * The following code can be used to read two onewire sensors connected to the same data pin.
 * Obtain the address using ONEWIRE_ADDRESS_TEST.ino code
 */
 
//One wire headers
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4//Data pin
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

DeviceAddress sensor1 = { 0x28, 0xFF, 0x6D, 0xCC, 0x60, 0x17, 0x5, 0x86 };
DeviceAddress sensor2 = { 0x28, 0xAA, 0xFB, 0x57, 0x13, 0x13, 0x2, 0xAE };

void setup(void)
{
  //Initialise serial monitor
  Serial.begin(115200);

  //Initialise one wire sensor
  sensors.begin();
}

void loop(void)
{
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.println("DONE");

  Serial.print("Sensor 1(*C): ");
  Serial.print(sensors.getTempC(sensor1));
  //  Serial.print(" Sensor 1(*F): ");
  //  Serial.println(sensors.getTempF(sensor1));

  Serial.print("Sensor 2(*C): ");
  Serial.print(sensors.getTempC(sensor2));
  //  Serial.print(" Sensor 2(*F): ");
  //  Serial.println(sensors.getTempF(sensor2));

  delay(1000);
}
