#include <iostream>
#include <string>

#include "../header/Board.h"

using std::cout;
using std::endl;

using std::string;
using std::to_string;

Board::Board(const int n){
	int i, j;
	int value = 0;
	brd = new string*[n];
	for (i = 0; i < n;i++){
		cout << "row: " << i << endl;
		for (j = 0; j < n;j++){
			cout << "column: " << j << endl;
			brd[i][j] = to_string(value);
			value++;
		}
	}
	brd[n-1][n-1] = "*";
	size = n;
}

Board::Board(string n){};
void Board::up(){};
void Board::down(){};
void Board::left(){};
void Board::right(){};

void Board::printBox(){
	int i, j;
	int n = size;
	for (i = 0; i < n;i++){
                for (j = 0; j < n;j++){
                        cout << brd[i][j] << " ";
                }
		cout << endl;
        }
}

void Board::printLine(){};

Board::~Board(){
	delete[] brd;
}

