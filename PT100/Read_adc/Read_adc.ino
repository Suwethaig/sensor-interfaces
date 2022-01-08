
#define adc_pin 13
float read_value = 0;
float  a, x;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
  read_value = analogRead(adc_pin);
  a = read_value * 0.0008056;
  x = (100 / 2.893) * a;

  Serial.print("a_value is :");
  Serial.println(a);
  Serial.print("x_value in ohms is :");
  Serial.println(x);
  delay(500);
}
