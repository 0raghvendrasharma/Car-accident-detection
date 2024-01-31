/*
  ADXL3xx

  Reads an Analog Devices ADXL3xx accelerometer and communicates the
  acceleration to the computer. The pins used are designed to be easily
  compatible with the breakout boards from SparkFun, available from:
  https://www.sparkfun.com/categories/80

  The circuit:
  - analog 0: accelerometer self test
  - analog 1: z-axis
  - analog 2: y-axis
  - analog 3: x-axis
  - analog 4: ground
  - analog 5: vcc

  created 2 Jul 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/ADXL3xx
*/

// these constants describe the pins. They won't change:
//const int groundpin = 18;             // analog input pin 4 -- ground
//const int powerpin = 19;              // analog input pin 5 -- voltage
const int xpin = A1;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A3;                  // z-axis (only on 3-axis models)
int x,y,z;

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);
  

  // Provide ground and power by using the analog inputs as normal digital pins.
  // This makes it possible to directly connect the breakout board to the
  // Arduino. If you use the normal 5V and GND pins on the Arduino,
  // you can remove these lines.
  //pinMode(groundpin, OUTPUT);
  //pinMode(powerpin, OUTPUT);
  //digitalWrite(groundpin, LOW);
  //digitalWrite(powerpin, HIGH);
}

void loop() {
  // print the sensor values:
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
  //y=360 z=300 increase  50 for z
  if(z>=350){
  Serial.println("Accident detected");
  }
  
  // delay before next reading:
  delay(1000);
}