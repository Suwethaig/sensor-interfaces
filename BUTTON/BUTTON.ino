/*
   The following code snippet can be used to read button state continously.
   If button is High it displays ON, else it displays OFF

   Author: Suwetha I G
*/

const int buttonPin = 12; //Change to the appropriate digital pin which you want to read
int buttonState = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    Serial.println("ON");
  }
  else
  {
    Serial.println("OFF");
  }
}
