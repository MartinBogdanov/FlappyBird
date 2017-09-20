#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <string>


const int floorY = 20;
const int floorWidth = 30;

using namespace std;

class GameObject//Code form a previous game - Tetris.
{

public:
	COORD Coordinates;
	char Symbol;

	friend bool operator== (const GameObject &a, const GameObject &b)
	{
		bool same = false;
		same = a.Coordinates.X == b.Coordinates.X && a.Coordinates.Y == b.Coordinates.Y && a.Symbol == b.Symbol;
		return same;
	}

	
	GameObject::GameObject(int x, int y, char symbol) :
		Symbol(symbol)
	{
		COORD coordinates = { x, y };
		this->Coordinates = coordinates;
	}

	GameObject::GameObject(const GameObject& gameObject) :
		Coordinates(gameObject.Coordinates), Symbol(gameObject.Symbol)
	{	}

	void GameObject::Draw(HANDLE consoleOutputHandle) const
	{
		SetConsoleCursorPosition(consoleOutputHandle, this->Coordinates);
		std::cout << this->Symbol;
	}
};


void hideCursor();
void noButtons();
void adjustWindow();
void ClearScreen(HANDLE consoleHandle);
