#include <sstream>
#include <algorithm>
#include "board.h"

int main() {
	cout << "Welcome to the Nonogram Game!" <<endl;
	cout << "Fill or unfill the board with your coordinate to match the hidden pattern." << endl;
        cout << "Input numbers 0-3 for row and 0-3 for column to indicate position on board." << endl;
	int pattern[100] = { 0,1,1,0,
						1,0,0,1,
						1,1,1,1,
						1,0,0,1 };

	//whole board; Z represents the pattern needed from the pattern array
	char entire[300] = { ' ', ' ', ' ', ' ', ' ', ' ', '1', ' ', '1', ' ', ' ', ' ',
						 ' ', ' ', ' ', ' ', '3', ' ', '1', ' ', '1', ' ', '3', ' ',
						 ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-',
						 ' ', ' ', '2', '|', 'Z', '|', 'Z', '|', 'Z', '|', 'Z', '|',
						 ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-',
						 '1', ' ', '1', '|', 'Z', '|', 'Z', '|', 'Z', '|', 'Z', '|',
						 ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-',
						 ' ', ' ', '4', '|', 'Z', '|', 'Z', '|', 'Z', '|', 'Z', '|',
						 ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-',
						 '1', ' ', '1', '|', 'Z', '|', 'Z', '|', 'Z', '|', 'Z', '|',
						 ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-' };

	//int response = 0;

	Board userBoard;
	Board board(pattern, 4);
	userBoard.printEntire(entire);
	cout << endl;
	string userInput;
	int k = 0; //counting variable
	string token; //token variable when separating string
	string arr2[2]; 

		while (1) {
			cout << "What would you like to fill? ie. 1,2 or Quit or Compare" << endl;
			getline(cin, userInput);
                        if (userInput == "Compare" || userInput == "compare"){
                            if (userBoard.missCount(board) == 1){
                                cout << "Missing: 1 spot" << endl;
                            }
                            else if (userBoard.missCount(board) == 0){
                                    cout << "Missing: 0 spots" << endl;
                                }
                                else{
                                    cout << "Missing: " << userBoard.missCount(board) << " spots" << endl;
                                }
                        }
                        else{
                                if (userInput == "Quit" || userInput == "quit")
                                    break;
                            //replaces the "-" character to become a " "
                            replace(userInput.begin(), userInput.end(), ',', ' ');


                                            istringstream ss(userInput);


                                            while (getline(ss, token, ' ')) {

                                                    arr2[k] = token;
                                                    k++;
                                            }



                                    k = 0;
                                    userBoard.fillSpot(stoi(arr2[0]), stoi(arr2[1]));
                                    userBoard.printEntire(entire);

                    }
                }

		if (userBoard.compare(board))
			cout << "Congratulations! It is correct!" << endl;
		else {
			cout << "Missing: " << userBoard.missCount(board) << endl;
		}
        //shows user the board game pattern
	cout << "Entire Board Game Pattern" << endl;
	board.printEntire(entire);
	system("pause");
	return 0;
    
}