#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2,3); 

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello!");
  
  BTSerial.begin(9600); //set the data rate for the BT
  
}

void loop()
{
  //BT -> Data -> Serial
  if(BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  //Serial -> Data -> BT
  if(Serial.available()){
    BTSerial.write(Serial.read());
  }
}
