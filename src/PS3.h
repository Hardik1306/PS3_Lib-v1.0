#define PS3_h
#ifdef PS3_h

#include "Arduino.h"


#define TRIANGLE 0
#define CIRCLE 1
#define CROSS 2
#define SQUARE 3
#define UP 4
#define RIGHT 5
#define DOWN 6
#define LEFT 7
#define L1 8
#define R1 9
#define L2 10
#define R2 11
#define L3 12
#define R3 13
#define SELECT 14
#define START 15
#define PS 16
#define LX LeftHatX
#define LY LeftHatY
#define RX RightHatX
#define RY RightHatY
#define LeftHatX 17
#define LeftHatY 18
#define RightHatX 19
#define RightHatY 20


class PS3 {
  public:
    byte x;
    byte lastbuttonstate[16];
    bool flag = 0;
    PS3(void) {}
    void begin();
    void printAnalogHat();
    bool getButtonPress(int x);
    bool getButtonClick(int x);
    bool getButtonRelease(int x);
    int getAnalogHat(int x);
    void printButton();
};
#endif


