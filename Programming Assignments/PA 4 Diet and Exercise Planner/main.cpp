/*

*/

#include "PA4.h"


int main(void)
{
	FitnessAppWrapper go;
	bool exit = false;
	go.runApp();
mainMenu:
	exit = go.menuInputs();

	if (exit == false) // Program does not exit and terminate
	{
		system("pause");
		system("cls");
		go.displayMenu();
		goto mainMenu;
	}



	return 0;
}