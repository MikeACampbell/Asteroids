/*********************************************
* Header File:
*       Vector class implementation
* Author:
*       Jacob Bowser and Michael Campbell
* Summary:
*       Implements the vector class
**********************************************/
#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <math.h>
#include "uiDraw.h"
#include "point.h"
#include <cassert>
#include <stdio.h>

class Vector : public Point
{
  public:
  Vector() : dx(0.0), dy(0.0) {}
  Vector(Point point) : dx(0.0), dy(0.0) {}
   Point getPoint() const { return point; }
   float getDx()    const { return dx; }
   float getDy()    const { return dy; }
   float getMag()   const { return (sqrt(dx*dx + dy*dy)); }
   float setDx(float speed);
   float setDy(float speed);
   Vector operator + (const Vector & v);
   Vector operator +=(const Vector & v);
   void setVelocity(float orientation, float speed);
      
  private:
   Point point;
   float dx;
   float dy;
   float orientation;
   float velocity;
};

#endif //VECTOR_H
