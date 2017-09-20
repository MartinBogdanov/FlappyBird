#include"Classes.h"

Floor::Floor(){
	symbol =static_cast<char>(177);
	for (int i = 0; i < floorWidth; i++){
		shape.push_back(GameObject(i, floorY, symbol));
	}
}