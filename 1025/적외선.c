#include<IRremote.h> // 적외선 송수신을 하기 위해서 IRremot 라이브러리 사용

IRsend irsend;

void setup(){
  serial.begin(9600);
}

void loop(){
  for(int i=0; i<3; i++){
  irsend.sendSony(0xa90, 12);
  delay(40);
  }
//한번에 3번씩 16진수 a90을 전송

  delay(2000);
 }
