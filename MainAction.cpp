#include <Servo.h>

Servo leftMotor;
Servo rightMotor;

void setup() {
  Serial.begin(9600);

  leftMotor.attach(9);  // Attach left motor to pin 9
  rightMotor.attach(10); // Attach right motor to pin 10
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    // Control the robot based on received command
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'S':
        stop();
        break;
    }
  }
}

void forward() {
  leftMotor.write(180);
  rightMotor.write(0);
}

void backward() {
  leftMotor.write(0);
  rightMotor.write(180);
}

void left() {
  leftMotor.write(0);
  rightMotor.write(0);
}

void right() {
  leftMotor.write(180);
  rightMotor.write(180);
}

void stop() {
  leftMotor.write(90);
  rightMotor.write(90);
}
