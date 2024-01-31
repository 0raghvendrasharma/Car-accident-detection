#include <LiquidCrystal.h>
#include <TinyGPS.h>
#define sensorDigital 11
#define LED 3
#define buzzer 12
#define sensorAnalog A4

float temp,a=100;//high a

 
LiquidCrystal lcd(2,3,4, 5, 6, 7);
void setup() {
  lcd.begin(16, 2);
  lcd.print("ACCIDENT ALERT");
  lcd.setCursor(3,2);
  lcd.print("SYSTEM");
  delay(3000);
  lcd.clear();
    lcd.print("All Sensor ");
    lcd.setCursor(4,2);
    lcd.print("Initialized");
    delay(3000);
    lcd.clear();
    lcd.print("Blow air for");
    lcd.setCursor(0,2);
    lcd.print("Alcohol test");
    delay(5000);
   pinMode(sensorDigital, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  bool digital = digitalRead(sensorDigital);
  int analog = analogRead(sensorAnalog);
  const int xpin = A1;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A3;                  // z-axis (only on 3-axis models)
int x,y,z;
 
  Serial.print("Analog value : ");
  Serial.print(analog);
  Serial.print("\t");
  Serial.print("Digital value :");
  Serial.println(digital);
 
  if (digital == 0) {
    digitalWrite(LED, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.print("Alchohol Detected");
    lcd.clear();
    lcd.print("Alcohol");
    lcd.setCursor(0,2);
    lcd.print("Detected");
    delay(3000);
    lcd.clear();
    lcd.print("driver is unfit");
    lcd.setCursor(0,2);
    lcd.print("to drive");
    delay(3000);
    digitalWrite(buzzer, LOW);
    exit(0); 
     
    Serial.println();
  } else {
    digitalWrite(LED, LOW);
    
    lcd.clear();
    lcd.print("Alcohol Not");
    lcd.setCursor(0,2);
    lcd.print("Detected");
    delay(2000);
    lcd.clear();
    lcd.print("Driver is fit ");
    lcd.setCursor(0,2);
    lcd.print("to drive");
    delay(3000);
    Serial.print(analogRead(xpin));
  x=analogRead(xpin);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  y=analogRead(ypin);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(zpin));
  z=analogRead(zpin);
  Serial.println();
  //**********************

   temp = analogRead(A0);
  //set to present temp -- trigger when morethan 20
  temp = temp-810;
  
  Serial.print("TEMPERATURE :");
  Serial.print(temp);
  Serial.print(" C :");
  Serial.println();
  
  //y=360 z=300 increase  50 for z
  //*********************************************************
  if(z>=350 || temp >= 100)
  {
    digitalWrite(buzzer, HIGH);
    if(z>=350)
    {
      Serial.println("Crash Detected");
      lcd.clear();
    lcd.print("Vehicle");
    lcd.setCursor(0,2);
    lcd.print("Crashed");
    delay(3000);
      }
     if(temp >=100)
    {
      Serial.println("Fire Detected");
      lcd.clear();
    lcd.print("Vehicle");
    lcd.setCursor(0,2);
    lcd.print("In Fire");
    delay(3000);
      }
      digitalWrite(buzzer, LOW);
      a=temp+5;
     
  Serial.println("Accident detected");
  lcd.clear();
    lcd.print("Accident");
    lcd.setCursor(0,2);
    lcd.print("detected");
    delay(3000);
    lcd.clear();
    lcd.print("SMS sent to ");
    lcd.setCursor(0,2);
    lcd.print("EMERGENCY UNITS!");
    delay(3000);
    lcd.clear();
    lcd.print("GPS triggered");
    lcd.setCursor(0,2);
    lcd.print("Vehicle Located at");
    delay(3000);
    lcd.clear();
    lcd.print("LAT: 13.13346752");
    lcd.setCursor(0,2);
    lcd.print("LON: 77.56742397");
    delay(3000);
    exit(0);
  }
  //************************************************************

  }
  Serial.println();
  delay(1000);
 
}
