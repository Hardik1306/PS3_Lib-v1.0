#include<SPI.h>
#include <Ps3Controller.h>
#define macAddress "11:11:11:11:11:11"
byte a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255};


void setup()
{ Serial.begin(115200);
  Ps3.begin(macAddress);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  pinMode(SS, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
}

void loop() {

  if (Ps3.isConnected()) {
    a[0] = Ps3.data.button.triangle;
    a[1] = Ps3.data.button.circle;
    a[2] = Ps3.data.button.cross;
    a[3] = Ps3.data.button.square;
    a[4] = Ps3.data.button.up;
    a[5] = Ps3.data.button.right;
    a[6] = Ps3.data.button.down;
    a[7] = Ps3.data.button.left;
    a[8] = Ps3.data.button.l1;
    a[9] = Ps3.data.button.r1;
    a[10] = Ps3.data.button.l2;
    a[11] = Ps3.data.button.r2;
    a[12] = Ps3.data.button.l3;
    a[13] = Ps3.data.button.r3;
    a[14] = Ps3.data.button.select;
    a[15] = Ps3.data.button.start;
    a[16] = Ps3.data.button.ps;
    a[17] =  map(Ps3.data.analog.stick.lx , -128, 127, 0, 254);
    a[18] =  map(Ps3.data.analog.stick.ly , -128, 127, 0, 254);
    a[19] =  map(Ps3.data.analog.stick.rx , -128, 127, 0, 254);
    a[20] =  map(Ps3.data.analog.stick.ry , -128, 127, 0, 254);
    digitalWrite(SS, 0);
    for (int i = 0; i < sizeof(a); i++)
    {
      SPI.transfer(a[i]);
    }
    digitalWrite(SS, 1);
    delay(10);
  }
    if (!Ps3.isConnected()) {
      memset(a, NULL, 16);
      a[17] = 127;
      a[18] = 127;
      a[19] = 127;
      a[20] = 127;
      digitalWrite(SS, 0);
      for (int i = 0; i < sizeof(a); i++)
      {
        SPI.transfer(a[i]);
      }
      digitalWrite(SS, 1);
      delay(10);
    }
}
