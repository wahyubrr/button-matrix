#define COL_A 32
#define COL_B 33
#define COL_C 25
#define COL_D 26
#define COL_E 27
#define COL_F 14
#define ROW_1 21
#define ROW_2 18
#define ROW_3 4
#define ROW_4 2

static int COLUMN_PIN[] = {14, 27, 26, 25, 33, 32};
static int ROW_PIN[] = {21, 18, 4, 2};
bool ROW_FLAG[] = {false, false, false, false};
bool flag = false;
bool pressed = false;

void setFlag() {
//  ROW_FLAG[3] = true;
  flag = true;
}
//void setFlag1() {
//  ROW_FLAG[0] = true;
//  checkButton(0);
//}
//void setFlag2() {
//  ROW_FLAG[1] = true;
//  checkButton(1);
//}
//void setFlag3() {
//  ROW_FLAG[2] = true;
//  checkButton(2);
//}
//void setFlag4() {
//  ROW_FLAG[3] = true;
//  checkButton(3);
//}
void checkButton() {
  Serial.print("ROW: ");
//  Serial.print(row);
//  Serial.print(" ");
  pressed = false;
  for (int i = 0; i < 4; i++) {
//    Serial.print(digitalRead(ROW_PIN[i]));
    Serial.print(digitalRead(ROW_PIN[i]));
    if (digitalRead(ROW_PIN[i]) == HIGH) {
      pressed = true;
    }
  }
  Serial.print(" COL: ");
  for (int i = 0; i < 6; i++) {
    Serial.print(digitalRead(COLUMN_PIN[i]));
  }
  Serial.println(" ");
  if (!pressed) {
    flag = false;
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Initialize...");
  // define column
  for (int i = 0; i < 6; i++) {
    pinMode(COLUMN_PIN[i], OUTPUT);
//    digitalWrite(COLUMN_PIN[i], HIGH);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(ROW_PIN[i], INPUT_PULLDOWN);
    attachInterrupt(digitalPinToInterrupt(ROW_PIN[i]), setFlag, RISING);
//    attachInterrupt(digitalPinToInterrupt(ROW_PIN[i]), resetFlag, FALLING);
  }
  Serial.println("Initializing done");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!flag) {
    for (int i = 0; i < 6; i++) {
      digitalWrite(COLUMN_PIN[i], HIGH);
      delay(20);
      digitalWrite(COLUMN_PIN[i], LOW);
    }
  } else {
    checkButton();
  }
//    Serial.print("row: ");
//    Serial.print(digitalRead(ROW_PIN[0]));
//    Serial.print(digitalRead(ROW_PIN[1]));
//    Serial.print(digitalRead(ROW_PIN[2]));
//    Serial.print(digitalRead(ROW_PIN[3]));
//    Serial.println(" ");
}
