
int trigPin = A0;
int echoPin = A1;
int redLed = A2;
int blueLed = A3;
int greenLed = A4;
int buzzer = A5;
float distance;
float duration;
int relayPin = 10;
// relay_pin low = on

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
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
    digitalWrite(relayPin, LOW);
    Serial.println("Water Low - Pump ON");
    setOutputStates(true, false, false, true);

  } else if (distance <= 2.6) {
    digitalWrite(relayPin, HIGH);
    Serial.println("Water Full - Pump OFF");
    setOutputStates(false, true, false, false);

  } else if (distance >= 3.4 && distance <= 8) {
    Serial.println("Water Moderate");
    setOutputStates(false, false, true, false);
  }


  delay(300);
}


// * function for changing the state of led and buzzer
void setOutputStates(bool red, bool green, bool blue, bool buzz) {
  digitalWrite(redLed, red ? HIGH : LOW);
  digitalWrite(greenLed, green ? HIGH : LOW);
  digitalWrite(blueLed, blue ? HIGH : LOW);
  digitalWrite(buzzer, buzz ? HIGH : LOW);
}
