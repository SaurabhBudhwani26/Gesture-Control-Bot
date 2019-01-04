 #include <Wire.h>

 long acx,acy,acz;
 float gfx,gfy,gfz;

 void setup()
{
  Serial.begin(9600);
  Wire.begin();//initialize i2c commuication
  setupMPU();
 
}
void loop()
{
  recordAccelRegisters();
  //printData();

  sendData();
  
  delay(100);
}
void setupMPU()
{
  Wire.beginTransmission(0b1101000);//i2c address of mpu for logic pin AD0 low
  Wire.write(0x6B); //acess to register 6B 
  Wire.write(0b0000000);//sleep register to zero
  Wire.endTransmission();
  Wire.beginTransmission(0b1101000);
  Wire.write(0x1B);
  Wire.beginTransmission(0b1101000);
  Wire.write(0x1C);
  Wire.write(0b0000000);
  Wire.endTransmission();
}
void recordAccelRegisters()
{
  Wire.beginTransmission(0b1101000);
  Wire.write(0x3B);//register for accel readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6);
  while(Wire.available()<6);
  acx=Wire.read()<<8|Wire.read();
  acy=Wire.read()<<8|Wire.read();
  acz=Wire.read()<<8|Wire.read();  
  processAccelData();
}

void processAccelData()
{
  gfx=acx/16384.0;
  gfy=acy/16384.0;
  gfz= acz/16384.0;  
}

/* void printData()
{
  Serial.print("X=");
  Serial.print(gfx);
  Serial.print("Y=");
  Serial.print(gfy);
  Serial.print("Z=");
  Serial.println(gfz);
}*/
void sendData()
{
  if (gfy<-0.50)  //forward
    Serial.write('F');
  else if (gfy>0.5) //backward
    Serial.write('B');
  else if (gfx>0.5)  //left
    Serial.write('L');
  else if (gfx<-0.5)  //right
    Serial.write('R');
  else
    Serial.write('S'); //stop
}
