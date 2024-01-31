float temp,a=100;
void setup() {
  Serial.begin(9600);

}

void loop() {
  temp = analogRead(A0);
  //set to present temp -- trigger when morethan 20
  temp = temp-810;
  
  Serial.print("TEMPERATURE :");
  Serial.print(temp);
  Serial.print(" C :");
  Serial.println();
  if(temp >= a)
  {
      Serial.print("Fire detected");
      Serial.println();
      delay(3000);
  }
  a=temp+20;
  delay(1000);

}
