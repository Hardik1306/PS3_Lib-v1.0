#include "PS3.h"
#include "SPI.h"
volatile byte index;
    volatile byte c;
    volatile byte buff[50];
void PS3::begin() 
{
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  index = 0;
  SPI.attachInterrupt();
    buff[17] = 127;
    buff[18] = 127;
    buff[19] = 127;
    buff[20] = 127;
}
void PS3::printButton () 
{
  if(buff[0]){
  	Serial.println("TRIANGLE");
  }if(buff[1]){
  	Serial.println("CIRCLE");
  }if(buff[2]){
  	Serial.println("CROSS");
  }if(buff[3]){
  	Serial.println("SQUARE");
  }if(buff[4]){
  	Serial.println("UP");
  }if(buff[5]){
  	Serial.println("RIGHT");
  }if(buff[6]){
  	Serial.println("DOWN");
  }if(buff[7]){
  	Serial.println("LEFT");
  }if(buff[8]){
  	Serial.println("L1");
  }if(buff[9]){
  	Serial.println("R1");
  }if(buff[10]){
  	Serial.println("L2");
  }if(buff[11]){
  	Serial.println("R2");
  }if(buff[12]){
  	Serial.println("L3");
  }if(buff[13]){
  	Serial.println("R3");
  }if(buff[14]){
  	Serial.println("SELECT");
  }if(buff[15]){
  	Serial.println("START");
  }if(buff[16]){
  	Serial.println("PS");
  }

}
void PS3::printAnalogHat()
{
  Serial.print("LX:" + buff[17]);
  Serial.print("LY:" + buff[18]);
  Serial.print("RX:" + buff[19]);
  Serial.println("RY:" + buff[20]);
}
bool PS3::getButtonPress(int x) {
  return buff[x];
}
bool PS3::getButtonClick(int x) {
  bool a;
  bool buttonstate = buff[x];
  if (buttonstate != lastbuttonstate[x] && buttonstate) {
    a = true;
  }
  else {
    a = false;
  }
  lastbuttonstate[x] = buttonstate;
  return a;
}

bool PS3::getButtonRelease(int x) {
  bool a;
  bool buttonstate = buff[x];
  if (buttonstate != lastbuttonstate[x] && !buttonstate) {
    a = true;
  }
  else {
    a = false;
  }
  lastbuttonstate[x] = buttonstate;
  return a;

}
int PS3::getAnalogHat(int x) {
  int a = map(buff[x], 0, 254, -128, 127);
  -3 < a && a < 3 ? 0 : a;
  return -3 < a && a < 3 ? 0 : a;
}
ISR(SPI_STC_vect)
{
  c = SPDR;
  if (index < sizeof(buff))
  {
    if (c == 255)
    {
      index = 0;
    }
    else
    {
      buff[index++] = c;
    }
  }
  else
  {
    index = 0;
  }
}
