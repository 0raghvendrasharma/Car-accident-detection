#define sensorDigital 11
#define LED 3
#define buzzer 12
#define sensorAnalog A4
 
void setup() {
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
  Serial.print("t");
  Serial.print("Digital value :");
  Serial.println(digital);
 
  if (digital == 0) {
    digitalWrite(LED, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.print("Alchohol Detected");
    delay(3000);
    Serial.println();
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW);
  }
  Serial.println();
  delay(1000);
}
