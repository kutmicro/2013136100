
//Serial0 모니터를 사용할 때, 
//이 시리얼 모니터는
//rx0이 메가 디지털 핀0
//tx이 메가 디지털 핀1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello!");
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
  // Serial –> Data –> BT
  if (Serial.available()) {
    Serial1.write(Serial.read());
 }
}


/////////RX : 0, TX = 1
