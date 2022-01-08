/*
 * The following code can be used to read MLX Temperature sensor and One wire sensor at the same time.
 */
 
//One wire sensor headers
#include <OneWire.h>
#include <DallasTemperature.h>

//MLX temperature sensor headers
#include <Wire.h>
#include <Adafruit_MLX90614.h>

//One wire data pin
const int oneWireBus = 18 ;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

//MLX I2C Address 
Adafruit_MLX90614 mlx = Adafruit_MLX90614(0x5A);

void setup()
{
  //Initialise serial monitor
  Serial.begin(115200);  

  //Start the DS18B20 sensor
  sensors.begin();

  //Start the mlx sensor
  Serial.println("Adafruit MLX90614 test");
  mlx.begin();
}

void loop()
{
  //Get the DSB temperature sensor readings
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  Serial.print("DS18B20 : ");
  Serial.print(temperatureC);
  Serial.print("ºC");

  //Get the MLX temperature sensor readings
  Serial.print("\t\tMLX90614 : "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("ºC");
  
  delay(1000);
}
