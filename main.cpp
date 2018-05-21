/*****************************************************************
 * Source File:
 *      Main
 * Author:
 *      Jacob Bowser and Michael Campbell
 * Summary:
 *      Contains the main and callBack function of the program   
 ***************************************************************/

#include "asteroids.h"


/*********************************************************
* CALLBACK
*  The main interaction loop of the engine, using OpenGL.
*  Will also catch any input events
***********************************************************/
void callBack(const Interface *pUI, void *p)
{
   //Void class pointer
   Asteroids * pAsteroids = (Asteroids *)p;

   //advances objects and catches any keyboard events
   pAsteroids->advance(pUI); 

   //checks to see if any collisions have occured
   pAsteroids->interact();
}

/****************************************************************
* MAIN
*  Initalizes the drawing windows, intalizes the game and run it.
*****************************************************************/
int main(int argc, char **argv)
{
   //Starts the drawing.
   Interface ui(argc, argv, "Asteroids!");
 
   //initilizes our game class
   Asteroids asteroids;
   
   //Inilizes the ifStream
   std::ifstream fin;

   //Opens the .txt file that stores the current high score
   fin.open ("highScore.txt");

   //Copies the high score from the file
   fin >> asteroids.highScore;

   //Closes the file
   fin.close();

   //Starts the callback function and starts the game
   ui.run(callBack, &asteroids);

   return 0;
};
  
