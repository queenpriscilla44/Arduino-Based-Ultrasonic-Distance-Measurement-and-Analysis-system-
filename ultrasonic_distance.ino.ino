#include <Servo.h>
#include <LiquidCrystal.h>

Servo myservo;
LiquidCrystal lcd(8,9,10,11,12,13); // LCD pins: rs, enable, d4, d5, d6, d7

int pos = 0;
const int trigPin = A4;
const int echoPin = A5;
const int moteur = 3;
const int buzzer = 7;
const int ledPin1 = 2;
const int ledPin2 = 3;
float distanceCm, DistanceSec, duration;

void setup() {
  Serial.begin(9600);
  myservo.attach(moteur);
  lcd.begin(16,2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  DistanceSec = 20; // threshold distance
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm = duration * 0.034 / 2;

    if (distanceCm <= DistanceSec) {
      if (distanceCm <= DistanceSec/2) {
        Serial.println("1");
        tone(buzzer, 10);
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, HIGH);
        delay(700);
        noTone(buzzer);
      } else {
        digitalWrite(buzzer, HIGH);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin1, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
      }
    } else {
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
    }

    lcd.setCursor(0,0);
    lcd.print("Distance: ");
    lcd.print(distanceCm);
    lcd.print(" cm ");
    lcd.setCursor(0,1);
    lcd.print("Angle : ");
    lcd.print(pos);
    lcd.print(" deg ");
    delay(80);
  }

  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm = duration * 0.034 / 2;

    if (distanceCm <= DistanceSec) {
      if (distanceCm <= DistanceSec/2) {
        Serial.println("1");
        tone(buzzer, 10);
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, HIGH);
        delay(700);
        noTone(buzzer);
      } else {
        digitalWrite(buzzer, HIGH);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin1, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
      }
    } else {
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
    }

    lcd.setCursor(0,0);
    lcd.print("Distance: ");
    lcd.print(distanceCm);
    lcd.print(" cm ");
    lcd.setCursor(0,1);
    lcd.print("Angle : ");
    lcd.print(pos);
    lcd.print(" deg ");
    delay(80);
  }
}
