
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // SoftwareSerial(RX, TX)
byte buffer[1024]; // 데이터를 수신 받을 버퍼
int bufferPosition; // 버퍼에 데이타를 저장할 때 기록할 위치

void setup(){
  BTSerial.begin(9600); 
  Serial.begin(9600); 
  bufferPosition = 0; // 버퍼 위치 초기화
}

void loop(){
  int temp = analogRead(A0);
  Serial.println(temp);
  BTSerial.println(temp);
  delay(500);
}
