
#include <LiquidCrystal.h>

// LiquidCrystal lcd(rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);



int trigPin = 8;
int echoPin = 9;
float distance;
float duration;



void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  lcd.print("dur = " + String(duration) + " mili" );

  lcd.setCursor(0, 1);
  lcd.print("dist = " + String(distance) + " cm");


  delay(1000);
}
