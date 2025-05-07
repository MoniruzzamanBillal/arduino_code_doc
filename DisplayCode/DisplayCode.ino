

#include <LiquidCrystal.h>

// LiquidCrystal lcd(rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(5, 6, 7, 8, 9, 10);



void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  lcd.setCursor(5, 0);
  lcd.print("IUBAT");
  lcd.setCursor(5, 1);
  lcd.print("2025");
}
