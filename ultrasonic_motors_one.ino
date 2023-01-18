#include <IRremote.hpp>

#define echoPin 8
#define trigPin 7
#define pwmA 10
#define pwmB 11
#define enA 12
#define enB 13

long duration;
int distance, dst;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  dst = measureDistance();
  delay(1000);
  dst = measureDistance();
  delay(100);
  Serial.begin(9600);
}
void loop() {
  dst = measureDistance();
  delay(50);

  if (dst < 40) {
    stop();
    delay(500);
    backRight();
    //turnLeft();
  } else {
    forward();
  }
}

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  return distance;
}

void forward() {
  Serial.println("Moving foward");
  digitalWrite(enA, HIGH);
  digitalWrite(enB, LOW);
  analogWrite(pwmA, 150);
  analogWrite(pwmB, 0);
}

void backward() {
  Serial.println("Moving backward");
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  analogWrite(pwmA, 150);
  analogWrite(pwmB, 0);
  delay(1000);
}

void turnLeft() {
  Serial.println("Turning left");
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  analogWrite(pwmA, 150);
  analogWrite(pwmB, 250);
  delay(1000);
}

void turnRight() {
  Serial.println("Turning right");
  digitalWrite(enA, HIGH);
  digitalWrite(enB, LOW);
  analogWrite(pwmA, 150);
  analogWrite(pwmB, 250);
  delay(1000);  
}


void backLeft() {
  Serial.println("Turning left");
  digitalWrite(enA, LOW);
  digitalWrite(enB, HIGH);
  analogWrite(pwmA, 150);
  analogWrite(pwmB, 250);
  delay(1000);
}

void backRight() {
  Serial.println("Turning right");
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  analogWrite(pwmA, 150);
  analogWrite(pwmB, 250);
  delay(1000);  
}

void stop() {
  Serial.println("Stopping");
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  analogWrite(pwmA, 150);
  analogWrite(pwmB, 0);
  delay(50);  
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  analogWrite(pwmA, 0);
  analogWrite(pwmB, 0);
  delay(500);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// const int left_motor_direction = 13;
// const int right_motor_direction = 12;
// const int right_motor_PWM = 10;
// const int left_motor_PWM = 11;
// const int pan_servo_pin = 9;
// const int echoPin = 8;
// const int triggerPin = 7;
// const int buzzer = 4;
// const int tilt_servo_pin = 6;
// const int left_motor_IR_sensor_pin = 2;
// const int right_motor_IR_sensor_pin = 3;