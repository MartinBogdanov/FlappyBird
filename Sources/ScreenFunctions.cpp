#include "BuildingBlock.h"


void ClearScreen(HANDLE consoleHandle)//Not mine but its better than system cls.
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount=(floorY)*floorWidth;
	COORD homeCoords = { 0, 0 };

	if (consoleHandle == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(consoleHandle, &csbi))
		return;

//	cellCount = csbi.dwSize.X *csbi.dwSize.Y; //All cells in the buffer

	/* Fill the  buffer with spaces */
	if (!FillConsoleOutputCharacter(
		consoleHandle,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count))
		return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		consoleHandle,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count))
		return;

	/* Move the cursor home */
	SetConsoleCursorPosition(consoleHandle, homeCoords);
}


void hideCursor()//kurzora e grozen
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void noButtons(){

	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();//  Get a handle to the desktop window
	GetWindowRect(hDesktop, &desktop); // Get the size of screen to the variable desktop

	LONG style;
	HWND ConsoleWindow;
	ConsoleWindow = GetConsoleWindow();
	style = GetWindowLong(ConsoleWindow, GWL_STYLE);
	style &= ~(WS_MINIMIZEBOX);
	SetWindowLongPtr(ConsoleWindow, GWL_STYLE, style);

	SetWindowPos(ConsoleWindow, NULL, desktop.right / 2 - 128, desktop.bottom / 2 - 260, 0, 0, SWP_FRAMECHANGED |
		SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);

}

void adjustWindow(){
	//hide cursor
	hideCursor();
	//no minimize and changes the window's postion
	noButtons();
	//set up the window
	SetConsoleTitle(L"Flappy Bird");
	SMALL_RECT rect = { 0, 0, floorWidth-1, floorY+1 };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);

	//remove scroll
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), new_size);
}
