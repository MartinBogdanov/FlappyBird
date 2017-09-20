#pragma once
#include"BuildingBlock.h"



class Bird{
private:
	int x, y,jumpHeight;
public:
	vector<GameObject> shape;
	Bird(int x, int y,int jumpHeight);
	COORD lowerWingXY(){ return shape[0].Coordinates; }
	COORD upperWingXY(){ return shape[2].Coordinates; }	
	int getJump(){ return jumpHeight; }
	int getX(){ return x; }
};

class Floor{
private:
	char symbol;
	vector<GameObject> shape;
public:
	
	Floor();
	vector<GameObject> getShape(){ return shape;}
};


class Obstacle{
private:
	char symbol;
	int offset;
	int holeSize;
	int holeStart;
	int width;
	int x;
public:
	vector<GameObject> shape;
	int getHoleSize(){ return holeSize; }
	int getHoleStart(){ return holeStart; }
	int getX(){ return x; }
	Obstacle(int x, int holeSize);
	void UpdateX(int x);

};

class ObstacleGen{//a vector with obstacles
private:	
	int distance;//between obstacles
	int holeSize;//hole size forevery obstacle
	int x;//the x coord for every new obstacle
	int width;
public:
	vector<Obstacle> allObst;
	ObstacleGen(int start, int dist, int holeSize,int width);
	int getHoleSize(){ return holeSize; }
	int getWidth(){ return width; }
	void fill();
};

class Input{ 
public:
	bool spaceDown();
};

class Physics{
private:

	Bird * myBird;
	Input myInput;
	ObstacleGen * myObst;

public:
	Physics(Bird*myBird, ObstacleGen * myObst);

	void birdMove();
	
	void ObstacleMove();

	bool collision();

};


class Score{
private:
	int score;
	ObstacleGen * myObst;
	Bird * myBird;
public:

	Score(ObstacleGen * myObst, Bird * myBird);
	int getScore(){ return score; }
	void calcualte();
};

class Print{
private:
	
	Bird * myBird;
	ObstacleGen * myObst;
	Floor * myFl;
	Score * myScore;
public:
	Print(Bird * myBird, ObstacleGen * myObst, Floor * myFl, Score * myScore);
	void print();
};

