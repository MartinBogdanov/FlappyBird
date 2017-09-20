#include"Classes.h"

Print::Print(Bird * myBird, ObstacleGen * myObst, Floor * myFl, Score * myScore)
	:myBird(myBird), myObst(myObst), myFl(myFl), myScore(myScore){}

void Print::print(){
	for (int i = 0; i < myObst->allObst.size(); i++)
	{
		for (int j = 0; j < myObst->allObst[i].shape.size(); j++)
		{
			myObst->allObst[i].shape[j].Draw(GetStdHandle(STD_OUTPUT_HANDLE));

		}
	}
	for (int i = 0; i < myBird->shape.size(); i++)
	{
		myBird->shape[i].Draw(GetStdHandle(STD_OUTPUT_HANDLE));

	}
	for (int i = 0; i < myFl->getShape().size(); i++)
	{
		myFl->getShape()[i].Draw(GetStdHandle(STD_OUTPUT_HANDLE));

	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { floorWidth / 2-5, floorY + 1 });
	cout << "Score: " << myScore->getScore();
}