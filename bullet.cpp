/**************************************************
* Bullet.cpp
*   This program will deal with the bullets in the program
*   it will set the bullets to their starting position,
*   it will set the speed of the bullets and using the angle
*   of the rifle, it will determine the direction of the bullets.
*   It will also determine if the bullet is dead or alive.  
* Author:
*       Michael Campbell and Jacob Bowser
***************************************************/

#include "asteroids.h"
using namespace std;

/************************
* Non-Default Constructor
**************************/
Bullet :: Bullet(Vector speed, float orientation, Point p) : Inertia()
{
   framesToLive = 0; //Initilizes the frame to lives
   this->point = p;
   
   v.setVelocity(orientation, 6.0); //Initilizes the speed of the bullet
   v = (speed + v); //Adds the speed of the ship to the bullet

   point.addX(v.getDx()); 
   point.addY(v.getDy());
   point.addX(v.getDx());
   point.addY(v.getDy());
}

/**********************************************
* Bullet : Advance 
*       Advances the bullet across the screen
***********************************************/
void Bullet :: advance(const Interface * pUI, Asteroids * asteroid)
{   
   point.setWrap(true); //Initializes wrap don't go off the screen
   point.addX(v.getDx());
   point.addY(v.getDy());
   
   framesToLive++; //Adds to the framesToLive variable 
   if(framesToLive > 50) 
      point.kill(); //Deletes the bullet once it's been alive for 40 frames
}

/***********************
* Bullet : Draw       
*       Draws the bullet 
**************************/
void Bullet::draw(Point point) const
{
   drawDot(point); 
}

