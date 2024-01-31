#include <SoftwareSerial.h>

SoftwareSerial SIM900A(3,2);

void setup()
{
SIM900A.begin(9600); // GSM Module Baud rate – communication speed
Serial.begin(9600); // Baud rate of Serial Monitor in the IDE app
Serial.println (“Text Messege Module Ready & Verified”);
delay(100);
}

void loop()
{


if (SIM900A.available()>0)
Serial.write(SIM900A.read());
}

void SendMessage()
{
Serial.println (“Sending Message please wait….”);
SIM900A.println(“AT+CMGF=1”); //Text Mode initialisation
delay(1000);
Serial.println (“Set SMS Number”);
SIM900A.println(“AT+CMGS=\”+91XXXXXXXXXX\”\r”); // Receiver’s Mobile Number
delay(1000);
Serial.println (“Set SMS Content”);
SIM900A.println(“Bhai kya haal hain? (Brother how are you?) this messege has been sent through Arduino Uno not a mobile phone wink wink “);// Messsage content
delay(100);
Serial.println (“Done”);
SIM900A.println((char)26);// delay(1000);
}
