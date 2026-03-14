#include <Servo.h>

Servo myServo;

int trig = 10;
int echo = 11;

long duration;
float distance;

int buzzer = 9;

//Assignments for RGB LED
int r = 4;
int g = 5;
int b = 6;

void setup() {
  Serial.begin(9600);
  myServo.attach(3);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}
void loop() {
  for (int deg = 0; deg < 180; deg++) {
    myServo.write(deg);
    delay(10);

    digitalWrite(trig, LOW);
    delay(10);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);
    distance = duration * 0.017;

    // If nothing is in close range light is green and buzzer is off
    if (distance > 40) {
      digitalWrite(g, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(b, LOW);
      noTone(buzzer);
    }
    // If distance is less than 40 millimeters but greater than 10 millimeters then light turns yellow
    else if (distance > 10) {
      digitalWrite(g, HIGH);
      digitalWrite(r, HIGH);
      digitalWrite(b, LOW);
      tone(buzzer, 100);  //Buzzer sounds at low frequency--100hz
    }
    // If something is in close range (less than 10 millimeters), trigger alert mode. LED flashes red and buzzer sounds
    else {
      digitalWrite(r, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(b, LOW);
      tone(buzzer, 500);  // Buzzer sounds at high frequency--500hz
    }
  }
  for (int deg = 180; deg > 0; deg--) {
    myServo.write(deg);
    delay(10);

    digitalWrite(trig, LOW);
    delay(10);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);
    distance = duration * 0.017;

    // If nothing is in close range light is green and buzzer is off
    if (distance > 40) {
      digitalWrite(g, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(b, LOW);
      noTone(buzzer);
    }
    // If distance is less than 40 millimeters but greater than 10 millimeters then light turns yellow
    else if (distance > 10) {
      digitalWrite(g, HIGH);
      digitalWrite(r, HIGH);
      digitalWrite(b, LOW);
      tone(buzzer, 100);  //Buzzer sounds at low frequency--100hz
    }
    // If something is in close range (less than 10 millimeters), trigger alert mode. LED flashes red and buzzer sounds
    else {
      digitalWrite(r, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(b, LOW);
      tone(buzzer, 500);  // Buzzer sounds at high frequency--500hz
    }
  }
}
