/*****************************************************************
 * Source File:
 *      Ship:
 * Author:
 *      Jacob Bowser and Michael Campbell
 * Summary:
 *      This code contains the functions for the Rocks. It will draw and
 *      move and rotate. It will deal with the production of the new
 *      smaller asteroids when a bigger one has been destroyed..
 ***************************************************************/
#include "asteroids.h"
using namespace std;


/*****************************************************************
 * The big asteroid constructor, it sets the speed to a random
 * number between 0 and three and in a random direction, it sets
 * it to appear on the right side of the screen in a random spot.
 ***************************************************************/
BigRock :: BigRock() : Rock()
{
   point.setX(point.getXMax());
   v.setDx(random(-3.0, 3.0));
   point.setY(random(-256, 256));
   v.setDy(random(-3.0, 3.0));
}

/*****************************************************************
 * The medium rock constructor. It setsthe speed of the medium rock
 * to the speed of the Big rock from which it spawned plus between
 * 0 to 1.5 and in a random direction.
 ***************************************************************/
MediumRock :: MediumRock(Vector vec, Point p) : Rock()
{
   this->point = p;
   point.resurrect();
   Vector vKick;
   vKick.setDx(random(-1.5, 1.5));
   vKick.setDy(random(-1.5, 1.5));
   v = (vKick + vec);
}

/*****************************************************************
 * The medium rock constructor. It setsthe speed of the medium rock
 * to the speed of the Big rock from which it spawned plus between
 * 0 to 3 and in a random direction.
 ***************************************************************/
SmallRock :: SmallRock(Vector vec, Point p) : Rock()
{
   this->point = p;
   point.resurrect();
   Vector vKick;
   vKick.setDx(random(-3.0, 3.0));
   vKick.setDy(random(-3.0, 3.0));
   v = (vKick + vec);
}

/*****************************************************************
 * this function advances the big Rock and if it dies spawns two
 * medium rocks and a small rock.
 ***************************************************************/
void BigRock :: advance(const Interface * pUI, Asteroids * asteroids)
{
   point.setWrap(true);
   point.addX(v.getDx());         // advance the rock
   point.addY(v.getDy());
   orientation += 2;              // rotate the rock
   
   if(point.isDead())
   {
      asteroids->addItem(new MediumRock(this->v, this->point));
      asteroids->addItem(new MediumRock(this->v, this->point));
      asteroids->addItem(new SmallRock(this->v, this->point));
   }     
}

/*****************************************************************
 * this function advances the medium Rock and if it dies spawns two
 * small rocks.
 ***************************************************************/
void MediumRock :: advance(const Interface * pUI, Asteroids * asteroids)
{
   point.setWrap(true);
   point.addX(v.getDx());         // advance the rock
   point.addY(v.getDy());
   orientation += 5;              // rotate the rock
   
   if(point.isDead())
   {
      asteroids->addItem(new SmallRock(this->v, this->point));
      asteroids->addItem(new SmallRock(this->v, this->point));
   }
   
}

/*****************************************************************
 * this function advances the big Rock and if it dies it has a one
 * in three chance of introducing a new big rock.
 ***************************************************************/
void SmallRock :: advance(const Interface * pUI, Asteroids * asteroids)
{
   point.setWrap(true);
   point.addX(v.getDx());    // advance the rock
   point.addY(v.getDy());
   orientation += 10;        // rotate the rock
   
   if(point.isDead())        // if it dies
   {
      int spawn = random(0, 3);    // 1 in 3 chance of spawn
      if(spawn == 0)
         asteroids->addItem(new BigRock); // add a new big rock
   }
}

/*****************************************************************
 * Draws the big Rock.
 ***************************************************************/
void BigRock :: draw(Point point) const
{
   drawPolygon(point, 20, 5, orientation);      
}

/*****************************************************************
 * Draws the Medium Rock.
 ***************************************************************/
void MediumRock :: draw(Point point) const
{ 
   drawPolygon(point, 10, 4, orientation);
} 

/*****************************************************************
 * Draws the small Rock.
 ***************************************************************/
void SmallRock :: draw(Point point) const
{
   drawPolygon(point, 5, 3, orientation);
}


