
#include <LiquidCrystal.h>

// LiquidCrystal lcd(rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);



int trigPin = 8;
int echoPin = 9;
int buzzer = 10;
float distance;
float duration;



void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {


  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.034;

  
  lcd.setCursor(0, 0);
  lcd.print("dist = " + String(distance) + " cm");


  if (distance <= 30) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }


  delay(1000);
}
