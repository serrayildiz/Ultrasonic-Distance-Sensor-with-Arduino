#include "NewPing.h"
#define echoPin 6
#define trigPin 7
#define buzzerPin 8
#include <LCD_I2C.h>
#define MAX_DISTANCE 400 
#define MIN_RANGE 0
#include <SoftwareSerial.h>
float duration, distance;
SoftwareSerial BTSerial(10,11); //rx,tx
LCD_I2C lcd(0x27);
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
   Serial.begin(9600);
   BTSerial.begin(9600);  
    lcd.begin();
    lcd.backlight();
}

void loop() {
 distance = sonar.ping_cm();
if (distance >= 300 || distance <= 0) {
      distance = 0;
      lcd.clear();
     
    }
    else {
      
      if (distance >= 200) {
        
        lcd.clear();
      }
      else if (distance <= 200 && distance > 100) {
       
        lcd.clear();
        BTSerial.println(distance);
        BTSerial.println("cm\n");
        lcd.print("Please keep away");
        BTSerial.println("Please keep away");
        lcd.setCursor(0, 1);
        lcd.print("Distance:");
        lcd.print(distance);
        lcd.print("cm");
      }
      else if (distance <= 100 && distance > 50) {
        
        lcd.clear();
        BTSerial.println(distance);
        BTSerial.println("cm\n");
        lcd.print("Keep away");
        BTSerial.println("Keep away");
        lcd.setCursor(0, 1);
        lcd.print("Distance:");
        lcd.print(distance);
        lcd.print("cm");
        delay(200);
        digitalWrite(buzzerPin, HIGH);
       
        delay(100);
        digitalWrite(buzzerPin, LOW);
       
        delay(100);
      }
      else if (distance <= 50) {
       
        lcd.clear();
        BTSerial.println(distance);
        BTSerial.println("cm\n");
        lcd.print("STAY AWAY!");
        BTSerial.println("STAY AWAY!");
        lcd.setCursor(0, 1);
        lcd.print("Distance:");
        lcd.print(distance);
        lcd.print("cm");
        delay(200);
        digitalWrite(buzzerPin, HIGH);
       
        delay(200);
        digitalWrite(buzzerPin, LOW);
       
        delay(200);
        digitalWrite(buzzerPin, HIGH);
       
        delay(200);
        digitalWrite(buzzerPin, LOW);
       
      }
    }
  
  delay (700);
}
