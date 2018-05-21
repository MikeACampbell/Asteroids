/*******************************************************************
 * This program will make the objects progress across the screen,
 * it will implement speed and direction of the objects, depending on
 * the inputs from the other functions.
 * Author:
 *      Jacob Bowser and Michael Campbell
 ********************************************************************/

#include "vector.h"


#define deg2rad(value) ((M_PI / 180) * (value))

float Vector :: setDx(float speed)
{
   dx = speed;                     // set the change in x
   return dx;
}

float Vector :: setDy(float speed)
{
   dy = speed;                    // set the change in y
   return dy;   
}

Vector Vector :: operator + (const Vector & v)
{
   Vector vReturn;
   vReturn.dx = this->dx + v.dx;
   vReturn.dy = this->dy + v.dy;
   return vReturn;
}

void Vector :: setVelocity(float orientation, float speed)
{
   setDx(-cos(deg2rad(orientation)) * speed); 
   setDy(-sin(deg2rad(orientation)) * speed);
}


      
