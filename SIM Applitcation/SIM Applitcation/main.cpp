#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

#include "SIM_Microprocessor.h"

using namespace std;

void DisplayMessage();

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 400, true);

	DisplayMessage();

	//Skeleton Code...
	//Functionality will be encapsulated in SIM class.



	return 0;
}

void DisplayMessage()
{
	cout << endl;
	cout << "~~~~~~~~~~ Welcome to Simple Integer Machine ~~~~~~~~~~" << endl;
	Sleep(500);
	cout << "How it works:" << endl;
	cout << "1)This program reads a simple text file with a certain header." << endl;
	cout << "2)Loads it into the Instruction Memory bank of the SIM." << endl;
	cout << "3)Performs its calculations and stores into the Data Memory bank." << endl;
	cout << "4)The User can access the Instruction Memory/Data Memory after execution." << endl;
	cout << "5)The User can re-use the program if he/she wishes to." << endl;
	Sleep(800);
	cout << "Enough talk. Press any key to continue!" << endl;
	_getch();
	system("CLS");
}