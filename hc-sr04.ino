
#define ECHO_PIN 2
#define TRIG_PIN 3
#include <LiquidCrystal.h>

const int rs = 7;    
const int en = 6;   
const int d4 = 12;
const int d5 = 10;
const int d6 = 9;   
const int d7 = 8;   
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lcd.begin(16, 2);
}

float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  float distance = readDistanceCM();

  //bool isNearby = distance < 300;
  if(distance<300)
  {
  bool isNearby = distance < 300;
  digitalWrite(LED_BUILTIN, isNearby);
  lcd.setCursor(0, 0);
  lcd.print("Indian Railways!!");
  lcd.setCursor(0, 1);
  lcd.print("Warning!!! ");
  }
  else if(distance>=300)
  { bool isNearby = distance < 300;
    digitalWrite(LED_BUILTIN, isNearby);
    lcd.clear();
  }
  Serial.print("Measured distance: ");
  Serial.println(readDistanceCM());

  delay(100);
}