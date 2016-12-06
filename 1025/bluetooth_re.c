 //char ch = Serial.read();
  //int num=(ch-'0');

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello!");
  Serial1.begin(9600);
 
}

void loop() {
  
  // put your main code here, to run repeatedly:
  if (Serial1.available()) {
    Serial.print("abc");
    Serial.write(Serial1.read());
    delay(50);
  }
  // Serial –> Data –> BT
  if (Serial.available()) {
    Serial.print("first\n");
    Serial.print(Serial.read());
    Serial.print("\n");
    Serial.print("Second\n");
    Serial1.write(Serial.read());
 }
}
