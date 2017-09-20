#include"Classes.h"

HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){

	srand(time(NULL));
	adjustWindow();

	Floor myFl;
	Bird myBird(3,12,2);//start x,start y,jump height
	ObstacleGen myObst(5, 3,10,1);//start at, distance between obst, hole size,obst width
	Physics myPh(&myBird,&myObst);//physics..
	Score myScore(&myObst,&myBird);
	Print myPrint(&myBird,&myObst,&myFl,&myScore);
	
	cout << "Press any key to start"<<endl<<" Jump with space";
	_getch();//stops program
	
	while (true){


		myPh.birdMove();
		myScore.calcualte();
		myObst.fill();//generate obst
		myPh.ObstacleMove();
		ClearScreen(hndl);
		myPrint.print();
		if (myPh.collision()){
			break;
		}
		Sleep(100);
	}
	_getch();//stops program
	return 0;
}