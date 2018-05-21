/*****************************************************************
 * Source File:
 *      Asteroids
 * Author:
 *      Jacob Bowser and Michael Campbell
 * Summary:
 *      This code contains the functions for the advancement of the
 *      game.
 ***************************************************************/

#include "asteroids.h"
using namespace std;

// //Initalizes score and scoreExceded
// int Asteroids :: score = 0;
// bool Asteroids :: scoreExceded = false;

/*****************************************************************
 * The default constructor for Asteroids. It makes a ship and five
 * Big asteroids.
 ***************************************************************/
Asteroids :: Asteroids()
{
   score = 0;
   scoreExceded = false;
   for(int shipNum = 0; shipNum < 1; shipNum++)
      elements.push_back(new Ship);
   for(int rockNum = 0; rockNum < 5; rockNum++)
      elements.push_back(new BigRock); 
}

/*****************************************************************
 * The advance function will progress the game and deal with dead
 * objects.
 ***************************************************************/
void Asteroids :: advance(const Interface * ui)
{
   list <Inertia*> :: iterator it;

   for(it = elements.begin(); it != elements.end(); ++it)
   {
      (*it)->advance(ui, this);
      (*it)->draw((*it)->point);
      if((*it)->getPoint().isDead())
      {
         //if the type of the dead element is a ship trigger game over
         if ((*it)->getType() == 1)
         {
            saveScore();
            elements.clear();
             
            break; 
         }
         score += ((*it)->getPoints());
         it = elements.erase(it);
      }
   }

   //Draws the scores
   drawScores();

   //Displays the Game Over screen
   if (elements.size() == 0)
   {
      Point gameOver(point.getX() - 36 , point.getY());
      Point congrats(point.getX() - 60, point.getY() - 20);

      drawText(gameOver, "Game Over");

      //If high score has been exceeded display congrats message
      if (scoreExceded == true)
         drawText(congrats, "New High Score!");
      
   }
}

/***********************************************************
* Asteroids : saveScore
*      Checks to see if score has been exceeded and if so
*      overwrites score file.
************************************************************/
void Asteroids :: saveScore()
{
   if (scoreExceded == true)
   {
      std::ofstream output;
      output.open ("highScore.txt");
      output << highScore;
      output.close();
   }

}

/***************************************************************
* Asteroids : DrawScores
*      Draws both the high score and the current player score
*      Also adjusts and new high score when exceded.
*****************************************************************/
void Asteroids :: drawScores()
{
   int scoreOffset = 70;
   int highScoreOffset = 5;
  

   //A loop that draws a score counter
   for(int iDigit = 1000000; iDigit; iDigit /= 10)
   {
      //Displays a counter for the current player score
      Point playerScore(point.getXMax() - scoreOffset , point.getYMax() - 5);
      drawNumber(playerScore, (score/iDigit%10));
      scoreOffset -= 10;
      if(scoreOffset == 0)
         scoreOffset = 70;
      assert(scoreOffset > 0);

      //Displays the current high score
      Point topScore(point.getXMin() + highScoreOffset , point.getYMax() - 5);
      drawNumber(topScore, (highScore/iDigit%10));
      highScoreOffset += 10;
      if(highScoreOffset == 75)
         highScoreOffset = 0;
      assert(highScoreOffset < 75);
   }

   //Flips a bool if the the player score exceedes the high score
   if(highScore < score)
   {
      highScore = score;
      scoreExceded = true;
   }

}

/*****************************************************************
 * The interact function will use the hit function to detect if
 * any objects have hit each other.
 ***************************************************************/
void Asteroids :: interact()
{
   list <Inertia*> :: iterator it;
   list <Inertia*> :: reverse_iterator that;
   for(it = elements.begin(); it != elements.end(); ++it)  
      for(that = elements.rbegin(); that != elements.rend(); ++that)
         hit(*it, *that);
}

/*****************************************************************
 * This function adds items to the list when called .
 ***************************************************************/
void Asteroids :: addItem(Inertia * object) 
{
   elements.push_back(object);
}

/*****************************************************************
 * The hit function will detect if any objects have struck each
 * other.
 ***************************************************************/
void Asteroids :: hit(Inertia * object1, Inertia * object2) const
{
   float difference = 9999999;       // set difference to a very high number
   float slice = 1 / max(max(abs(object1->v.getDx()),
                             abs(object2->v.getDx())),
                         max(object1->v.getDy(),
                             object2->v.getDy()));
   // Check the differences between the two objects and find the smallest
   // distance.
   for (float percent = 0.0; percent <= 1.0; percent += slice)
   {
      float x = ((object1->point.getX() +
                  (object1->v.getDx() * percent)) -
                 (object2->point.getX() +
                  (object2->v.getDx() * percent)));
      
      float y = ((object1->point.getY() +
                  (object1->v.getDy() * percent)) -
                 (object2->point.getY() +
                  (object2->v.getDy() * percent)));
      
      float distanceSquared = (x * x) + (y * y);
      difference = std::min(distanceSquared, difference);   
   }
   // get the square root (pythagoreum theorem)
   float diff = sqrt(difference);
   if(object1->getType() == object2->getType())
      ;
   else if(object1->getSize() + object2->getSize() > diff && diff != 0)
   {
      object1->point.kill();
      object2->point.kill();
   }
}
   


