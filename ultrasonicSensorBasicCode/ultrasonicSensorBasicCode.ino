
int trigPin = 8;
int echoPin = 9;
float distance;
float duration;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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


  Serial.print("duration = ");
  Serial.print(duration);
  Serial.print(" Mili Sec. ");
  Serial.println("");

  Serial.print("distance  = ");
  Serial.print(distance);
  Serial.print(" cm ");
 Serial.println("");
  delay(500);
}
