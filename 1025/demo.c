#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

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

 while(Serial1.available())  //Serial1에 전송된 값이 있으면
  {
     value = Serial1.read(); //전송값 읽음
     Serial.print(value);
     
     if(value == 'l'){            //좌회전(강)
       Serial.println("left");
       left();
     }else if(value == 'r'){      //우회전(강)
       Serial.println("right");
       right();
     }else if(value == 'f'){      //전진
       Serial.println("forward");
       forward();
     }else if(value == 'b'){      //후진
       Serial.println("backward");
       backward();
     }else if(value == 'w'){      //우회전(약)
       Serial.println("slow right");
       sRight();
     }else if(value == 'q'){      //좌회전(약)
       Serial.println("slow left");
       sLeft();       
     }else if(value == 's'){      //정지
       Serial.println("stop");    
       stop(); 
     }
  }
/*
  if(Distance_mm <500)
  {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }
  */
  delay(1000); // Wait to do next measurement
}

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
 
