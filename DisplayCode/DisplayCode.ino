

#include <LiquidCrystal.h>

// LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
// LiquidCrystal lcd(rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);





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
