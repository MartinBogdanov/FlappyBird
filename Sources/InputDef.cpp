#include"Classes.h"

bool Input::spaceDown(){
	if (_kbhit())
	{
		char ch = _getch();
		switch (ch)
		{
		case 32:
			return true;
		}
	}
	return false;
}