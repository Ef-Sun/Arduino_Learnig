#include "MaxMatrix.h"
#include "font.h"

int button = 2;
int k = 0;
int DIN =5;   // DIN pin of MAX7219 module
int CLK = 7;   // CLK pin of MAX7219 module
int CS = 6;    // CS pin of MAX7219 module
int maxInUse = 1;
MaxMatrix m(DIN, CS, CLK, maxInUse); 

void setup() {
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(0, changeAttitude, RISING);
  m.init(); // MAX7219 initialization
  m.setIntensity(1); // initial led matrix intensity, 0-15
}

void changeAttitude()
{
  k = (k+1)%6;
}

void loop() {
  // Seting the LEDs On or Off at x,y or row,column position

   
  if(k >= 0 && k <= 1)
  {
  m.writeSprite(0, 0, smile01);
  delay(1000);
  }

  if(k >= 2 && k <= 3)
  {
  m.writeSprite(0, 0, smile02);
  }
  
  if(k >= 4 && k <=5)
  {
  m.writeSprite(0, 0, smile03);
  }
  /*
  for (int i=0; i<8; i++)
  {
    m.shiftLeft(false,false);
    delay(300);
  }*/
  delay(100);
  m.clear();
 
}
