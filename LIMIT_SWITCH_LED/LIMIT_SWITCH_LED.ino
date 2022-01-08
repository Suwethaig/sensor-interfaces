/*
  The LED turns on whenever limit switch is HIGH(pressed), else LED is off.

  Author: Suwetha I G
*/

//Variable and pin declaration
const int buttonPin = 34;//Limit switch pin
const int ledPin =  2;   //Led pin
int buttonState = 0;

void setup()
{
  //Initialises serial monitor
  Serial.begin(115200);

  //Pin initialisation
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  Serial.print("Value of switch read is: ");
  Serial.println(buttonState);
  delay(1000);

  if (buttonState == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
