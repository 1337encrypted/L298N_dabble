#include "L298N_BLE.h"
#include<Dabble.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

FourWD car;                                   //Create an object of class car
uint8_t key;                                  //Key for the switch case
  
void setup()
{  
  Serial.begin(250000); 
  Dabble.begin(9600,0,1);
}

void loop()
{   
  Dabble.processInput(); 
/*
  if (GamePad.isUpPressed() && GamePad.isSquarePressed())
  {
    car.leftBackPivot();
    Serial.println("Left Back Pivot");
  }
  else if (GamePad.isDownPressed() && GamePad.isCirclePressed())
  {
    car.rightBackPivot();
    Serial.println("Right Back Pivot");
  }
  */
  if (GamePad.isUpPressed())
  {
    car.front();
    Serial.println("Foreward");
  }
  else if (GamePad.isDownPressed())
  {
    car.back();
    Serial.println("Backward");
  }
  else if (GamePad.isLeftPressed())
  {
    car.leftturn();
    Serial.println("Left");
  }
  else if (GamePad.isRightPressed())
  {
    car.rightturn();
    Serial.println("Right");
  }
  else if(GamePad.isCirclePressed())
  {
    car.rightShift();
    Serial.println("Right Shift");
  }
  else if(GamePad.isSquarePressed())
  {
    car.leftShift();
    Serial.println("Left Shift");
  }

  else if (GamePad.isTrianglePressed())
  {
    car.leftDiagonalFront();
    Serial.println("Left Diagonal Front");
  }
  else if (GamePad.isCrossPressed())
  {
    car.leftDiagonalBack();
    Serial.println("Left Diagonal Back");
  }
  else if (GamePad.isSelectPressed())
  {
    car.rightDiagonalFront();
    Serial.println("Right Diagonal Front");
  }
  else if (GamePad.isStartPressed())
  {
    car.rightDiagonalBack();
    Serial.println("Right Diagonal Back");
  }
  else
  {
    car.Stp();
    Serial.println("Stop");  
  }
  /*
  Serial.print('\t');
  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
  */
}
