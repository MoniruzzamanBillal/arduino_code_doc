#include <AFMotor.h>
#include <SoftwareSerial.h>
// D10 is connected to Servo 1, whereas D9 is connected to Servo 2.
SoftwareSerial bluetoothSerial(9, 10);  // RX, TX

//initial motors pin
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int speed = 200;

char command;

// for led and buzzer
int buzzer = A5;
int led = A1;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  bluetoothSerial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop() {
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();

    Serial.println(command);

    Stop();  //initialize with motors stoped

    if (command == 'F') {
      forward();

    } else if (command == 'B') {
      back();

    } else if (command == 'L' || command == 'G' || command == 'J') {
      left();

    } else if (command == 'R' || command == 'I' || command == 'H') {
      right();
    } else if (command == 'V') {

      Horn();
    } else if (command == 'v') {

      Horn();
    } else if (command == 'W') {
      digitalWrite(led, HIGH);
    } else if (command == 'w') {
      digitalWrite(led, LOW);
    }
  }
}

void forward() {
  motor1.setSpeed(speed);  //Define maximum velocity
  motor1.run(FORWARD);     //rotate the motor clockwise
  motor2.setSpeed(speed);  //Define maximum velocity
  motor2.run(FORWARD);     //rotate the motor clockwise
  motor3.setSpeed(speed);  //Define maximum velocity
  motor3.run(FORWARD);     //rotate the motor clockwise
  motor4.setSpeed(speed);  //Define maximum velocity
  motor4.run(FORWARD);     //rotate the motor clockwise
}

void back() {
  motor1.setSpeed(speed);  //Define maximum velocity
  motor1.run(BACKWARD);    //rotate the motor anti-clockwise
  motor2.setSpeed(speed);  //Define maximum velocity
  motor2.run(BACKWARD);    //rotate the motor anti-clockwise
  motor3.setSpeed(speed);  //Define maximum velocity
  motor3.run(BACKWARD);    //rotate the motor anti-clockwise
  motor4.setSpeed(speed);  //Define maximum velocity
  motor4.run(BACKWARD);    //rotate the motor anti-clockwise
}

void left() {
  motor1.setSpeed(speed);  //Define maximum velocity
  motor1.run(BACKWARD);    //rotate the motor anti-clockwise
  motor2.setSpeed(speed);  //Define maximum velocity
  motor2.run(BACKWARD);    //rotate the motor anti-clockwise
  motor3.setSpeed(speed);  //Define maximum velocity
  motor3.run(FORWARD);     //rotate the motor clockwise
  motor4.setSpeed(speed);  //Define maximum velocity
  motor4.run(FORWARD);     //rotate the motor clockwise
}

void right() {
  motor1.setSpeed(speed);  //Define maximum velocity
  motor1.run(FORWARD);     //rotate the motor clockwise
  motor2.setSpeed(speed);  //Define maximum velocity
  motor2.run(FORWARD);     //rotate the motor clockwise
  motor3.setSpeed(speed);  //Define maximum velocity
  motor3.run(BACKWARD);    //rotate the motor anti-clockwise
  motor4.setSpeed(speed);  //Define maximum velocity
  motor4.run(BACKWARD);    //rotate the motor anti-clockwise
}

void Stop() {
  motor1.setSpeed(0);   //Define minimum velocity
  motor1.run(RELEASE);  //stop the motor when release the button
  motor2.setSpeed(0);   //Define minimum velocity
  motor2.run(RELEASE);  //rotate the motor clockwise
  motor3.setSpeed(0);   //Define minimum velocity
  motor3.run(RELEASE);  //stop the motor when release the button
  motor4.setSpeed(0);   //Define minimum velocity
  motor4.run(RELEASE);  //stop the motor when release the button
}

void Horn() {
  digitalWrite(buzzer, HIGH);
  delay(800);
  digitalWrite(buzzer, LOW);
}


// I for front right
// G for front left
// V for buzer on , v for buzzer off
// W for front led on , w for led off
// U for front led on , u for led off
