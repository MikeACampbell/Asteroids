/*****************************************************************
* Source File:
*      Ship 
* Author:
*      Jacob Bowser and Michael Campbell
* Summary:
*      This code contains th functions for the Ship. It will move the ship,
*      thrust and rotate, and it will fire the bullets.
***************************************************************/
#include "asteroids.h"
using namespace std;

/************************************
* Ship : Advance
*   Moves the ship across the screen    
*************************************/
void Ship :: advance(const Interface * pUI, Asteroids * asteroids)
{
   point.setWrap(true); //Sets wrap to true
   if(pUI->isLeft())    //Rotates the ship left when the
                        //left arrow key is pressed
      orientation += 10;
   if(pUI->isRight())   //Rotates the ship right when the
                        //right arrow key is pressed
      orientation -= 10;

   if(pUI->isUp())     //Moves the ship in the direction it's
                       //pointed when up key is pressed
   {
      Vector vThrust(v.getPoint());
      vThrust.setVelocity(orientation, 0.2);
      v = (vThrust + v);
   }
   point.addX(v.getDx());
   point.addY(v.getDy());
   
   if(pUI->isSpace())   //Fires a bullet when space is pressed
      asteroids->addItem(new Bullet(v, orientation, point));
}

/*************************
* Ship : Draw
*        Draws the ship
**************************/
void Ship :: draw(Point point) const
{
   drawShip(point, orientation); //Draws the ship
}


