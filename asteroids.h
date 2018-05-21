/**********************************************************************
* Header File:
*       Asteroids
* Author:
*       Jacob Bowser and Michael Campbell
* Summary:
*       The initilization of the all the classes used in the program
*********************************************************************/
#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <list>
#include <cassert>
#include "point.h"
#include "vector.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include <fstream>

class Asteroids; //Class prototype for Asteroids

/*******************************************
* The Inertia class
*       Initilization of the Inertia class
********************************************/
class Inertia
{
  public:
   Inertia() {}; //Defualt constructor
   virtual void draw(Point point) const = 0;
   virtual void advance(const Interface * pUI, Asteroids * asteroids) {}
   virtual int getSize() const = 0; 
   virtual int getType() const = 0;
   Point getPoint() {return point;}
   Point point;
   Vector v;
   virtual int getPoints() const = 0;
  protected:
   bool dead;
  
   
  
};

/*******************************************
* The Ship class
*       Initilization of the Ship class
********************************************/
class Ship : public Inertia
{
  public:
  Ship() : Inertia() {};
   virtual void draw(Point point) const;
   virtual void advance(const Interface * pUI, Asteroids * asteroids);
   virtual int getSize() const { return 6; }
   virtual int getType() const { return 1; }
   virtual int getPoints() const { return 0; }
  private:
   float orientation;

};

/*******************************************
* The Bullet class
*       Initilization of the Bullet class
********************************************/
class Bullet : public Inertia
{
  public:
   Bullet(Vector speed, float orientation, Point p);
   virtual void draw(Point point) const;
   virtual void advance(const Interface * pUI,  Asteroids * asteroid);
   virtual int getSize() const { return 1; }
   virtual int getType() const { return 2; }
   virtual int getPoints() const { return 0; }
  
  private:
   int framesToLive;

};


/*******************************************
* The Rock class
*       Initilization of the Rock class.
********************************************/
class Rock : public Inertia
{
  public:
  Rock() : Inertia() { orientation = 0; }
   virtual int getType() const { return 3; }
   virtual void draw(Point point) const = 0;
  protected:
   int orientation;
};


/*******************************************
* The BigRock class
*       Initilization of the BigRock class.
********************************************/
class BigRock : public Rock
{
  public:
   BigRock();
   virtual void advance(const Interface * pUI, Asteroids * asteroids);
   virtual void draw(Point point) const;
   virtual int getSize() const { return 20; }
   virtual int getPoints() const { return 50; }
   
};


/*******************************************
* The MediumRock class
*       Initilization of the MediumRock class.
********************************************/
class MediumRock : public Rock
{
  public:
   MediumRock(Vector v, Point point);
   virtual void advance(const Interface * pUI, Asteroids * asteroids);
   virtual void draw(Point point) const;
   virtual int getSize() const { return 10; }
    virtual int getPoints() const { return 100;}
};


/*******************************************
* The SmallRock class
*       Initilization of the SmallRock class.
********************************************/
class SmallRock : public Rock
{
  public:
   SmallRock(Vector v, Point point);
   virtual void advance(const Interface * pUI, Asteroids * asteroids);
   virtual void draw(Point point) const;
   virtual int getSize() const { return 5; }
   virtual int getPoints() const { return 200; }
};


/*******************************************
* The Asteroids class
*       Initilization of the Asteroids class.
********************************************/
class Asteroids
{
  public:
   Asteroids();
   void advance(const Interface * ui);
   void interact();
   void addItem(Inertia * object);
   void draw();
   void hit(Inertia * object1, Inertia * object2) const;
   void drawScores();
   void saveScore();
    int highScore;
  
   
  private:
   std::list <Inertia *> elements;
   Point point;
   int score;
   bool scoreExceded;
   
};


#endif //ASTEROIDS_H
   
