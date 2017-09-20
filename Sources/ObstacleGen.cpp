#include"Classes.h"

ObstacleGen::ObstacleGen(int start, int dist, int holeSize, int width) :x(start), distance(dist), holeSize(holeSize), width(width){
	Obstacle myObst(x, holeSize);
	for (int i = 0; i < width; i++)
	{
		myObst.UpdateX(x + i);
		allObst.push_back(myObst);
		
	}
	x += width;
}
void ObstacleGen::fill(){
	while (allObst.back().getX()< floorWidth - distance){//fill 
		x += distance;
		if (x > floorWidth){//makes sure that that obstacles dont go off floor
			x = floorWidth-width;
		}
		Obstacle myObst(x, holeSize);
		for (int i = 0; i < width; i++)
		{
			myObst.UpdateX(x + i);
			allObst.push_back(myObst);
			
		}
		x += width;

	}
	
	if (allObst.front().getX() <= 0){//delete the first 
		allObst.erase(allObst.begin());
	}
}