//M1모터 컨트롤(LEFT)
//A = 정회전   B= 역회전
int M1A1 = 4;//M1모터 정회전
int M1B1 = 5;//M1모터 역회전
 
//M2모터 컨트롤(RIGHT)
int M2A2 = 6;//M2모터 정회전
int M2B2 = 7;//M2모터 역회전
 
void setup() {
  pinMode(M1A1,OUTPUT);
  pinMode(M1B1,OUTPUT);
  pinMode(M2A2,OUTPUT);
  pinMode(M2B2,OUTPUT);
}
 
void loop() {
  bothMotorStart();
  delay(3000);
  turnLeft();
  delay(3000);  
  turnRight();
  delay(3000);
  motorA_Rotation();
  delay(3000);
  motorB_Rotation();
  delay(3000);
  motorA_Reverse();
  delay(3000);
  motorB_Reverse();
  delay(3000);
  stopAllMotor();
  delay(3000);
}
 
//모터A,B 정회전
void bothMotorStart()
{
    digitalWrite(M1A1,HIGH);
    digitalWrite(M1B1,LOW);
    digitalWrite(M2A2,HIGH);
    digitalWrite(M2B2,LOW);
}
 
//모터A,B Stop
void stopAllMotor()
{
    digitalWrite(M1A1,LOW);
    digitalWrite(M1B1,LOW);
    digitalWrite(M2A2,LOW);
    digitalWrite(M2B2,LOW);
}
 
//모터A 역회전, 모터B 정회전
void turnLeft()
{
    digitalWrite(M1A1,LOW);
    digitalWrite(M1B1,HIGH);
    digitalWrite(M2A2,HIGH);
    digitalWrite(M2B2,LOW);
}
 
//모터A 정회전, 모터B 역회전
void turnRight()
{
    digitalWrite(M1A1,HIGH);
    digitalWrite(M1B1,LOW);
    digitalWrite(M2A2,LOW);
    digitalWrite(M2B2,HIGH);
}
 
//모터A 정회전, 모터B Stop
void motorA_Rotation()
{
    digitalWrite(M1A1,HIGH);
    digitalWrite(M1B1,LOW);
    digitalWrite(M2A2,LOW);
    digitalWrite(M2B2,LOW);
}
 
//모터A Stop, 모터B 정회전
void motorB_Rotation()
{
    digitalWrite(M1A1,LOW);
    digitalWrite(M1B1,LOW);
    digitalWrite(M2A2,HIGH);
    digitalWrite(M2B2,LOW);
}
 
//모터A 역회전, 모터B Stop
void motorA_Reverse()
{
    digitalWrite(M1A1,LOW);
    digitalWrite(M1B1,HIGH);
    digitalWrite(M2A2,LOW);
    digitalWrite(M2B2,LOW);
}
 
//모터A Stop, 모터B 역회전
void motorB_Reverse()
{
    digitalWrite(M1A1,LOW);
    digitalWrite(M1B1,LOW);
    digitalWrite(M2A2,LOW);
    digitalWrite(M2B2,HIGH);
}
