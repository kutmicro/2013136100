void loop() {
  while(mySerial.available())  //mySerial에 전송된 값이 있으면
  {
     value = mySerial.read(); //전송값 읽음
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
  
}
