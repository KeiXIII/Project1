#include <iostream>
#include <fstream>
#include <string>
#include "Monogram.h"
#include "minesweeper.h"

using namespace std;

int main() {

	int choice;

	cout << "Welcome to PUZZLES!" << endl;
	cout << "Please Choose a Game From our Menu!" << endl;
	cout << "MENU\n----\n1.Monogram\n2.Minesweeper" << endl;

	cin >> choice;

	if (choice == 1)
	{
		Monogram *game1 = new Monogram();
		game1->startGame();
	}
	else if (choice == 2)
	{
            MineSweeperGame *game2 = new MineSweeperGame();
            game2->startUp();
	}
	else
	{
		cout << "THANK YOU FOR PLAYING!\n";
	}
        
	//system("pause");
	return 0;
}