#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int lled=36;
int rled = 34;

//피에조 부저를 48번 핀으로 설정
int piezo = 48;
//톤 배열 수
int numTones=25;
//비행기
int tones[] = {330, 294, 261, 294, 330, 330, 330, 294, 294, 294, 330, 392, 392, 330, 294, 261, 294, 330, 330, 330,294, 294, 330, 294, 261};
//음계 표준 주파수(4옥타브) : 도, 레, 미, 파, 솔, 라, 시, 도
//{261, 294, 330, 349, 392, 440, 494, 523};

char BT_data;
char MEGA_data;

const int TriggerPin = 41; //Trig pin
const int EchoPin = 43; //Echo pin
//const int led = 13;
long Duration = 0;

char value;

void setup() {
  pinMode(TriggerPin, OUTPUT); // Trigger is an output pin
  pinMode(EchoPin, INPUT); // Echo is an input pin
 // pinMode(led, OUTPUT);

  motor1.setSpeed(250);
  motor2.setSpeed(250);
  Serial.begin(9600); // Serial Output
  Serial1.begin(9600); 

  pinMode(rled, OUTPUT);
  pinMode(lled, OUTPUT);

  pinMode(piezo, OUTPUT);

 
}

void loop() {
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin, HIGH); // Trigger pin to HIGH
  delayMicroseconds(10); // 10us high
  digitalWrite(TriggerPin, LOW); // Trigger pin to HIGH

  Duration = pulseIn(EchoPin, HIGH); // Waits for the echo pin to get high
  // returns the Duration in microseconds


  
  long Distance_mm = Distance(Duration); // Use function to calculate the distance

  Serial.print("Distance = "); // Output to serial
  Serial.print(Distance_mm);
  Serial.println(" mm");

  ////////////////
/*

 if(Distance_mm < 200) {         //장애물 감지 (20cm 이내)
     Serial.println("stop");
     stop();  //정지(1초)
     Serial.println("backward");
     backward();  //후진(0.5초)
     delay(2000);
     int rnd = random(0,2);   //장애물 감지시 좌/우회전 랜덤처리
     if(rnd == 0){
        Serial.println("right");
        right();
     }else{
        Serial.println("left");
        left();
     }
   }else{         //장애물 없음
     Serial.println("forward");
     forward();
   }

*/

  /////

 
 while(Serial1.available())  //Serial1에 전송된 값이 있으면
  {
     value = Serial1.read(); //전송값 읽음
     Serial.print(value);

    switch(value){

      case 'f':
      forward();
      break;

      case 'b':
      backward();
      buzzer();
      break;

      case 's':
      stop();
      break;

      case 'l':
      left();
    digitalWrite(lled, HIGH);
     delay(500);
     digitalWrite(lled, LOW);
      delay(1000);
      forward();
      break;

      case 'r':
      right();
     digitalWrite(rled, HIGH);
     delay(500);
      digitalWrite(rled, LOW);
      delay(1000);
      forward();
      break;

      case 'w':
      sRight();
      delay(1000);
      backward();
      break;

      case 'q':
      sLeft();
      delay(1000);
      backward();
      break;

      case 'p':
      while(1){
        
 if(Distance_mm < 200) {         //장애물 감지 (20cm 이내)
     Serial.println("stop");
     stop();  //정지(1초)
     delay(2000);
     Serial.println("backward");
     backward();  //후진(0.5초)
     delay(2000);
     int rnd = random(0,2);   //장애물 감지시 좌/우회전 랜덤처리
     if(rnd == 0){
        Serial.println("right");
        right();
        delay(1000);
        forward();
        break;
     }else{
        Serial.println("left");
        left();
        delay(1000);
        forward();
        break;
     }
   }else{         //장애물 없음
     Serial.println("forward");
     forward();
     break;
   }
      }
    break;
      
 }

  delay(1000); // Wait to do next measurement
}}
 
long Distance(long time)
{
  // Calculates the Distance in mm
  // ((time)*(Speed of sound))/ toward and backward of object) * 10

  long DistanceCalc; // Calculation variable
  DistanceCalc = ((time / 2.9) / 2); // Actual calculation in mm
  //DistanceCalc = time / 74 / 2; // Actual calculation in inches
  return DistanceCalc; // return calculated value
}

void forward(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
 }
void backward(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD); 
}
void left(){
  motor1.run(RELEASE);
  motor2.run(FORWARD);
 
}
void right(){
  motor1.run(FORWARD);
  motor2.run(RELEASE);

}
void sLeft(){
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
}
void sRight(){
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
} 
void stop(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void buzzer(){
  //피에조 부저가 연결된 핀으로 지정된 파형을 생성하도록 설정
  //도가 261Hz의 주파수를 가지면 1초에 261번의 파형을 발생
  //디지털은 0과 1(high, low)로 표현되므로 1초 동안 0과 1의 변화를 261번 주는 것
  for(int i=0; i<numTones; i++){
    tone(piezo, tones[i]);
    delay(100);
    if(value != 'b'){
    break;
    }
  }
  //피에조 부저가 연결된 핀으로부터 파형 생성 중단
  noTone(piezo);
}
