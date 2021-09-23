  int BLUE=8;
  int GREEN=9;
  int RED=10;
  int BUZZER=12;
float SOIL = 0; 
#include <Adafruit_BMP085.h>
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

Adafruit_BMP085 bmp;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }

lcd.print("BOOTING...");
   delay(2000); 
  lcd.clear();
  
lcd.print("RED LED");
digitalWrite(RED, HIGH);
   delay(2000);
digitalWrite(RED, LOW);
  lcd.clear();
  
lcd.print("GREEN LED");
digitalWrite(GREEN, HIGH);
   delay(2000);
digitalWrite(GREEN, LOW);
  lcd.clear();
  
lcd.print("BLUE LED");
digitalWrite(BLUE, HIGH);
   delay(2000);
digitalWrite(BLUE, LOW);
  lcd.clear();

lcd.print("WHITE LED");
digitalWrite(BLUE, HIGH);
digitalWrite(GREEN, HIGH);
digitalWrite(RED, HIGH);
   delay(2000);
digitalWrite(BLUE, LOW);
digitalWrite(GREEN, LOW);
digitalWrite(RED, LOW);
  lcd.clear();

lcd.print("BUZZER TEST");
tone(BUZZER, 1500);
delay(2000);
noTone(BUZZER);
lcd.clear();
  
lcd.print("System ON");
delay(3000);
lcd.clear();
}


void loop() {  
  int Humidity = analogRead(0);
  Serial.println("\t");
  Serial.println("Humidity: ");

  Serial.println(Humidity);
  
  delay(50);

  



for (int i = 0; i <= 100; i++) 
 { 
  SOIL = SOIL + analogRead(1); 
   delay(1); 
 } 
 SOIL = SOIL/100.0; 
 Serial.println("SOIL: ");
 Serial.println(SOIL);
 delay(30); 

//BMP 180
int Temp=bmp.readTemperature();
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

if(Humidity > 300 && Humidity < 800)
     digitalWrite(BLUE, HIGH);
    else
     digitalWrite(BLUE, LOW);
     
if(bmp.readTemperature() < 29 && bmp.readTemperature() > 23)
     digitalWrite(RED, HIGH);
    else
     digitalWrite(RED, LOW);
     
if(SOIL > 200 && SOIL < 900)
     digitalWrite(GREEN, HIGH);
    else
     digitalWrite(GREEN, LOW);
     
if(Humidity > 300 && Humidity < 800)
   noTone(BUZZER);
     else
    if(bmp.readTemperature() < 29 && bmp.readTemperature() > 23)\
       noTone(BUZZER);
         else
        if(SOIL > 200 && SOIL < 900)
          noTone(BUZZER);
            else
          tone(BUZZER, 1500);

          
  lcd.print("A: ");
  lcd.print(Humidity);
  lcd.print(" B: ");
  lcd.print(SOIL);
  lcd.setCursor(0, 2);
  lcd.print("C: ");
  lcd.print(bmp.readTemperature());
  lcd.print(" ");
  lcd.print((char)11011111);
  lcd.print("C");
   delay(2000); 
  lcd.clear();
  


  
}
