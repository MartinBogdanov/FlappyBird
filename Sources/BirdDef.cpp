#include"Classes.h"

Bird::Bird(int x,int y,int jumpHeight):x(x),y(y){
	this->jumpHeight = jumpHeight;
	shape.push_back(GameObject(x, y + 1, static_cast<char>(221)));//wing
	shape.push_back(GameObject(x, y, ':'));//body
	shape.push_back(GameObject(x, y - 1, static_cast<char>(221)));//wing
	shape.push_back(GameObject(x - 1, y, static_cast<char>(219)));// static_cast<char>(219)//tail
	shape.push_back(GameObject(x+1, y, 16));//head
}