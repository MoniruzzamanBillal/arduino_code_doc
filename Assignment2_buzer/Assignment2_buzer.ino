#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int trigPin = 8;
int echoPin = 9;
int relayPin = 10;
// relay_pin low = on
int buzzer = A0;


float distance;
float duration;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.034;


  Serial.print("distance  = ");
  Serial.print(distance);
  Serial.print(" cm ");
  Serial.println("");

  if (distance >= 14) {
    lcd.clear();
    digitalWrite(relayPin, LOW);
    Serial.println("Water Low - Pump ON");
    lcd.setCursor(0, 0);
    lcd.print("Water Level-Low");
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(4, 1);
    lcd.print("Pump On");

  } else if (distance <= 3.4) {
    lcd.clear();
    digitalWrite(buzzer, LOW);
    digitalWrite(relayPin, HIGH);
    Serial.println("Water Full - Pump OFF");
    lcd.setCursor(0, 0);
    lcd.print("Water Level-Full");
    lcd.setCursor(4, 1);
    lcd.print("Pump OFF");

  } else if (distance >= 3.6 && distance <= 8) {
    lcd.clear();
    Serial.println("Water Moderate");
    lcd.setCursor(2, 0);

    lcd.print("Water Level - ");
    lcd.setCursor(4, 1);
    lcd.print("Medium");

    digitalWrite(buzzer, LOW);
  }


  delay(500);
}
