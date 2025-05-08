


int trigPin = A0;
int echoPin = A1;
float distance;
float duration;
int relayPin = 10;
// relay_pin low = on



void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
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
  } else if (distance <= 2) {
    digitalWrite(relayPin, HIGH);
    Serial.println("Water Full - Pump OFF");
  } else if (distance >= 6 && distance <= 7) {
    Serial.println("Water Moderate");
  }





  delay(500);
}
