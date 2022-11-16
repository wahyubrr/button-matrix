#include "SimpleButton.h"
#define COL_A 32
#define ROW_2 18
#define ROW_3 4

// example weight value
int value = 0, tare = 0;
Button button(COL_A, ROW_2, ROW_3, &value, &tare);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Initialize...");
  // enable interrupt
  button.begin();
  Serial.println("Initializing done");
}

void loop() {
  // example weight printed to serial
  Serial.print("value: ");
  Serial.print(value++);
  Serial.print(" tare: ");
  Serial.println(tare);
  delay(1000);
}
