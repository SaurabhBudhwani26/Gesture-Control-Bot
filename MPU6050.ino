 #include <Wire.h>

 long acx,acy,acz;
 float gfx,gfy,gfz;
 long gyx,gyy,gyz;
 float rx,ry,rz;

 void setup()
{
  Serial.begin(38400);
  Wire.begin();// #include <Wire.h>

 long acx,acy,acz;
 float gfx,gfy,gfz;
 long gyx,gyy,gyz;
 float rx,ry,rz;

 void setup()
{
  Serial.begin(38400);
  Wire.begin();//initialize i2c commuication
  setupMPU();
 
}
void loop()
{
  recordAccelRegisters();
  recordGyroRegisters();
  printData();

  delay(500);
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

void recordGyroRegisters()
{
  Wire.beginTransmission(0b1101000);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6);
  while(Wire.available()<6);
  gyx=Wire.read()<<8|Wire.read();
  gyy=Wire.read()<<8|Wire.read();
  gyz=Wire.read()<<8|Wire.read();
  processGyroData();
}
 void processGyroData()
 {
  rx=gyx/131;
  ry=gyy/131;
  rz=gyz/131;
 }

 void printData()
 {
  Serial.print("Gyro (deg)");
  Serial.print("X=");
  Serial.print(rx);
  Serial.print("Y=");
  Serial.print(ry);
  Serial.print("Z=");
  Serial.print(rz);
  Serial.print("Accel (g)");
  Serial.print("X=");
  Serial.print(gfx);
  Serial.print("Y=");
  Serial.print(gfy);
  Serial.print("Z=");
  Serial.println(gfz);
  
 
initialize i2c commuication
  setupMPU();
 
}
void loop()
{
  recordAccelRegisters();
  recordGyroRegisters();
  printData();

  delay(500);
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

void recordGyroRegisters()
{
  Wire.beginTransmission(0b1101000);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6);
  while(Wire.available()<6);
  gyx=Wire.read()<<8|Wire.read();
  gyy=Wire.read()<<8|Wire.read();
  gyz=Wire.read()<<8|Wire.read();
  processGyroData();
}
 void processGyroData()
 {
  rx=gyx/131;
  ry=gyy/131;
  rz=gyz/131;
 }

 void printData()
 
 {
  Serial.print("Gyro (deg)");
  Serial.print("X=");
  Serial.print(rx);
  Serial.print("Y=");
  Serial.print(ry);
  Serial.print("Z=");
  Serial.print(rz);
  Serial.print("Accel (g)");
  Serial.print("X=");
  Serial.print(gfx);
  Serial.print("Y=");
  Serial.print(gfy);
  Serial.print("Z=");
  Serial.println(gfz);
  
 }
