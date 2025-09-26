#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
#include <stdio.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define button1 A0
#define button2 A1

#define servo1 0

int num_servo1 =  180;// numero da possição inicial do servo1

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pwm.begin();
  pwm.setPWMFreq(60);
}

void loop() {
  int buttonState1 = analogRead(button1);
  int value_button1 = map(buttonState1, 0, 1023, 1, 0);
  int buttonState2 = analogRead(button2);
  int value_button2 = map(buttonState2, 0, 1023, 1, 0);

  if(value_button1 == 1){
    num_servo1++;
    delay(50);//delay define a velocidade do servo
  }
  if(value_button2 == 1){
    num_servo1--;
    delay(50);//delay define a velocidade do servo
  }

  if(num_servo1 >= 180 && num_servo1 <= 400)
  {
  pwm.setPWM(servo1, 0, num_servo1);
  Serial.print(num_servo1);
  }
  else{
    Serial.print("servo 1 no limite");
    delay(1000);
  }

}