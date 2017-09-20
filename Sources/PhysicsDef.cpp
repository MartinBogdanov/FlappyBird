#include"Classes.h"

Physics::Physics(Bird*myBird, ObstacleGen * myObst){
	
	this->myBird = myBird;
	this->myObst = myObst;
}

void Physics::birdMove(){
	bool space = myInput.spaceDown();
	if (space == false) {
		for (int i = 0; i < myBird->shape.size(); i++)
		{
			myBird->shape[i].Coordinates.Y++;
		}

	}
	else if (space == true){
		for (int i = 0; i < myBird->shape.size(); i++)
		{
			myBird->shape[i].Coordinates.Y -= myBird->getJump();
		}
	}
	else{
		for (int i = 0; i < myBird->shape.size(); i++)
		{
			myBird->shape[i].Coordinates.Y++;
		}
	}

}

void Physics::ObstacleMove(){

	for (int i = 0; i < myObst->allObst.size(); i++)
	{
		int x = myObst->allObst[i].getX();

		myObst->allObst[i].UpdateX(--x);

	}

}

bool Physics::collision(){

	if (myBird->lowerWingXY().Y >= floorY || myBird->upperWingXY().Y<0){
		return true;
	}
	for (int j = 0; j < myObst->allObst.size(); j++)
	{
		if (myObst->allObst[j].getX() <= myBird->getX()+1  && myObst->allObst[j].getX()>=myBird->getX() - 1){
			for (int i = 0; i < myBird->shape.size(); i++)
			{
				if (myBird->shape[i].Coordinates.Y < myObst->allObst.front().getHoleStart()){
					return true;
				}
				if (myBird->shape[i].Coordinates.Y >= myObst->allObst.front().getHoleStart() + myObst->getHoleSize()){
					return true;
				}
			}
		}
	}
	return false;
}