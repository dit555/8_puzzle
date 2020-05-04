#include <iostream>
#include <string>

#include "../header/Board.h"

using std::cout;
using std::endl;

using std::string;
using std::to_string;

Board::Board(int n){
	int i, j;
	int value = 0;
	brd = new string[n][n];
	for (i = 0; i < n;i++){
		for (j = 0; j < n;j++){
			brd[i][j] = to_string(value);
			value++;
		}
	}
	brd[n-1][n-1] = "*";
	size = n;
}

Board::Board(string n);
Board::void up();
Board::void down();
Board::void left();
Board::void right();

Board::void printBox(){
	int i, j;
	for (i = 0; i < n;i++){
                for (j = 0; j < n;j++){
                        cout << brd[i][j] << " ";
                }
		cout << endl;
        }
}

Board::void printLine();

Board::~Board(){
	delete[] brd;
}

