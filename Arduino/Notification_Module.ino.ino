// Notification Unit with LCD + Buzzer
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const int buzzerPin = 3;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int zoneLimit = 30; // Example value received from RF
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Speed Limit:");
  lcd.setCursor(0, 1);
  lcd.print(zoneLimit);
  lcd.print(" km/h");

  // Alert driver
  tone(buzzerPin, 1000, 300);
  delay(3000);
}
