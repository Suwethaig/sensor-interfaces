/*
   The following code snippet by Rui Santos can be used to get the One wire sensor address
   Complete Project Details https://randomnerdtutorials.com
*/

#include <OneWire.h>

// Based on the OneWire library example

OneWire ds(4);  //data wire connected to GPIO15

void setup(void) {
  //Initialise serial monitor
  Serial.begin(9600);
}

void loop(void) {
  byte i;
  byte addr[8];

  if (!ds.search(addr)) {
    Serial.println(" No more addresses.");
    Serial.println();
    ds.reset_search();
    delay(250);
    return;
  }
  Serial.print(" ROM =");
  for (i = 0; i < 8; i++) {
    Serial.write(' ');
    Serial.print(addr[i], HEX);
  }
}
