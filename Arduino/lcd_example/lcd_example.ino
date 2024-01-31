#include <LiquidCrystal.h>
#include <TinyGPS.h>
#define sensorDigital 11
#define LED 3
#define buzzer 12
#define sensorAnalog A4
 
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
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.print("Alcohol Not");
    lcd.setCursor(0,2);
    lcd.print("Detected");
    delay(2000);
    lcd.clear();
    lcd.print("Driver is fit ");
    lcd.setCursor(0,2);
    lcd.print("and fine");
    delay(3000);
    
    
  }
  Serial.println();
  delay(1000);
 
}
