#include"Classes.h"

Score::Score(ObstacleGen * myObst, Bird * myBird) :score(0), myObst(myObst), myBird(myBird){}

void Score::calcualte(){
	for (int i = 0; i < myObst->allObst.size(); i++)
	{
		if (myObst->allObst[i].getX() == myBird->getX() - 1 && myObst->allObst[i + 1].getX() >  myBird->getX() + 1){
			score++;
		}
	}
}