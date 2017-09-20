#include"Classes.h"

Obstacle::Obstacle(int x, int holeSize){
	this->x = x;
	this->width = width;
	this->holeSize = holeSize;
	offset = floorY/2-1;
	symbol = static_cast<char>(219);
	holeStart = rand() % (floorY - offset) + offset/3  + 1;
	while (floorY - holeStart < holeSize){//makes sure that hole isnt smaller
		holeStart = rand() % (floorY - offset) + offset / 3 + 1;
	}
	for (int i = 0; i < floorY; i++)
	{
		if (i < holeStart || i >= holeStart + holeSize){
			shape.push_back(GameObject(x, i, symbol));	
		}
		else{
			shape.push_back(GameObject(x, i, ' '));
			
		}
	}
}
void Obstacle::UpdateX(int x){
	this->x = x;
	for (int i = 0; i < shape.size(); i++)
	{
		shape[i].Coordinates.X = x;
	}
}
