#ifndef SimpleButton_h
#define SimpleButton_h

#include "Arduino.h"

class Button {
  public:
    Button(int COL_A, int ROW_2, int ROW_3, int* value, int* tare);
    void begin();
  private:
    int _COL_A;
    int _ROW_2;
    int _ROW_3;
    static int* ptr_value;
    static int* ptr_tare;
    static void buttonZero();
    static void buttonTare();
};

#endif
