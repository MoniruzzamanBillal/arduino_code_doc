

#include <LiquidCrystal.h>

// LiquidCrystal lcd(rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int trigPin = 8;
int echoPin = 9;
int relaypin = 10;
float distance;
float duration;

// relay_pin low = on 


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relaypin, OUTPUT);
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
    digitalWrite(relaypin, LOW);
  } else {
    digitalWrite(relaypin, HIGH);
  }

  delay(500);
}
