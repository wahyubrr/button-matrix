#include "Arduino.h"
#include "SimpleButton.h"

void setExternalValue(int* value, int* tare, int i);
void setExternalTare(int* value, int* tare);

Button::Button(int COL_A, int ROW_2, int ROW_3, int* value, int* tare) {
  _COL_A = COL_A;
  _ROW_2 = ROW_2;
  _ROW_3 = ROW_3;
  ptr_value = value;
  ptr_tare = tare;
}

void Button::begin() {
  pinMode(_COL_A, OUTPUT);
  digitalWrite(_COL_A, HIGH);
  pinMode(_ROW_2, INPUT_PULLDOWN);
  pinMode(_ROW_3, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(_ROW_2), buttonZero, RISING);
  attachInterrupt(digitalPinToInterrupt(_ROW_3), buttonTare, RISING);
}

int* Button::ptr_value;
int* Button::ptr_tare;

// interrupt routine, modify here
void Button::buttonZero() {
  setExternalValue(ptr_value, ptr_tare, 0);
}

void Button::buttonTare() {
  setExternalTare(ptr_value, ptr_tare);
}

void setExternalValue(int* value, int* tare, int i) {
  *value = i;
  *tare = i;
}

void setExternalTare(int* value, int* tare) {
  *tare = *value;
}
