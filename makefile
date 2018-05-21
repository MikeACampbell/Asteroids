###################################################################
# MAKEFILE
#   Asteroids
# Authors:
#	Jacob Bowser and Michael Campbell
# Extra Credit:
#	Colored asteroids and score tracking. The score in the top
# 	left is the players current score and the top right is the
#	current top score. Which is read and saved to a .txt. 
#	Game Over screen thats tells players if they got a new
#	high score
#####################################################################

asteroids:  main.o uiDraw.o uiInteract.o point.o vector.o asteroids.o ship.o	rock.o bullet.o
	g++ -o asteroids main.o uiDraw.o uiInteract.o asteroids.o point.o vector.o rock.o bullet.o  ship.o -lglut -lGLU
	tar -cf asteroids.tar *.cpp *.h highScore.txt makefile

###############################################################
# Individual files
###############################################################

rock.o: rock.cpp asteroids.h
	g++ -c rock.cpp

ship.o: ship.cpp asteroids.h
	g++ -c ship.cpp

bullet.o: bullet.cpp asteroids.h
	g++ -c bullet.cpp


vector.o: vector.h vector.cpp
	g++ -c vector.cpp

asteroids.o: asteroids.cpp asteroids.h
	g++ -c asteroids.cpp

uiDraw.o: uiDraw.h uiDraw.cpp point.h 
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

main.o : main.cpp point.h uiDraw.h uiInteract.h
	g++ -c main.cpp



###############################################################
# General rules
###############################################################
clean :
	rm *.o *gch ship uiTest  *~ 

all :  a.out

###############################################################
# Ref: http://www.gnu.org/software/make/manual/make.html
###############################################################
