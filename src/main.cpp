#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

#define button1 A0
#define button2 A1
void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}
void loop() {
  int buttonState1 = analogRead(button1);
  int buttonState2 = analogRead(button2);
  Serial.print("Button 1: ");
  Serial.print(buttonState1);
  Serial.print(" - Button 2: ");
  Serial.println(buttonState2);
  delay(500);
}