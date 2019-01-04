int motor1Pin1 = 3;             //left motor
int motor1Pin2 = 4; 
int motor2Pin1 = 11;           //right motor
int motor2Pin2 = 10;

int motor1en = 5;              //left motor enable
int motor2en = 9;              //right motor enable

int state;

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0)
  {
    state = Serial.read();
  }   

  switch(state)
  {
  case 'F':                                   //go forward
          digitalWrite(motor1Pin1, HIGH);
          digitalWrite(motor1Pin2, LOW); 
          digitalWrite(motor2Pin1, HIGH);
          digitalWrite(motor2Pin2, LOW);

          analogWrite(motor1en, 110);
          analogWrite(motor2en, 160);
        
          Serial.println('F');
          break;
  
  case 'B':                                   //go backward
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH); 
          digitalWrite(motor2Pin1, LOW);
          digitalWrite(motor2Pin2, HIGH);

          analogWrite(motor1en, 130);
          analogWrite(motor2en, 160);
        
          Serial.println('B');
          break;
          
  case 'L':                                    //go left
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH); 
          digitalWrite(motor2Pin1, HIGH);
          digitalWrite(motor2Pin2, LOW);

          analogWrite(motor1en, 130);
          analogWrite(motor2en, 160);
        
          Serial.println('L');
          break;
          
  case 'R':                                      //go right
          digitalWrite(motor1Pin1, HIGH); 
          digitalWrite(motor1Pin2, LOW); 
          digitalWrite(motor2Pin1, LOW);
          digitalWrite(motor2Pin2, HIGH);

          analogWrite(motor1en, 110);
          analogWrite(motor2en, 160);
        
          Serial.println('R');
          break;
          
  case 'S':                                      //stop
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, LOW); 
          digitalWrite(motor2Pin1, LOW);
          digitalWrite(motor2Pin2, LOW);

          analogWrite(motor1en, 0);
          analogWrite(motor2en, 0);
        
          Serial.println('S');
          break;
  }
}
