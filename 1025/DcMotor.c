//아두이노 핀3번이 트랜지스터를 on/off하는데 사용되어 motorPin이라고 명명
int motorPin = 3;

void setup()
{
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while(! Serial);
  Serial.println("Speed 0 to 255");
}

//loop함수에서는 Serial.parseInt함수가 시리얼 모니터에 입력된 숫자를 스트링형태로 읽어 int 타입으로 변환
//시리얼 모니터창에는 아무 숫자나 입력하여도 loop함수내의 if문에서 0~255사이의 값만 analogwrite합니다.
void loop()
{
  if(Serial.available())
  {
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin, speed);
    }
  }
}

