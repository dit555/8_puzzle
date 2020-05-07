#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>

#include "../header/Board.h"

using std::cout;
using std::endl;

using std::string;
using std::to_string;

Board::Board(const int n){
	int i, j;
	int value = 1; //first number to be put in the board
	brd = new string*[n];
	for (i = 0; i < n;i++){
		//cout << "row: " << i << endl;
		string* col = new string[n];
		for (j = 0; j < n;j++){
			//cout << "column: " << j << endl;
			col[j] = to_string(value);
			value++;
		}
		brd[i] = col;
	}
	emptyX = n - 1;
       	emptyY = n - 1;	
	brd[emptyX][emptyY] = "*";
	
	size = n;
}

Board::Board(string *n, const int s){
	int i, j;
        int value = 0; //first number to be put in the board
	brd = new string*[s];
        for (i = 0; i < s;i++){
                //cout << "row: " << i << endl;
                string* col = new string[s];
                for (j = 0; j < s;j++){
                        //cout << "column: " << j << endl;
                        col[j] = n[value];
                        value++;
			if (col[j] == "*"){
				emptyX = j;
				emptyY = i;
			}
			
                }
                brd[i] = col;
        }
        size = s;
}

Board::Board(Board* b){
	int i, j;
        int value = 0; //first number to be put in the board
        brd = new string*[b->getSize()];
        for (i = 0; i < b->getSize() ;i++){
                //cout << "row: " << i << endl;
                string* col = new string[b->getSize()];
                for (j = 0; j < b->getSize() ;j++){
                        //cout << "column: " << j << endl;
                        col[j] = b->getVal(i,j);

                }
                brd[i] = col;
        }
	
	size = b->getSize();
	emptyX = b->getEmptyX();
	emptyY = b->getEmptyY();
	if (brd == nullptr)
		cout << "fuck" << endl;
}

string** Board::getBoard() const{
	return brd;
}

string Board::getVal(int x, int y) const{
	return brd[x][y];
}

int Board::getSize() const{
	return size;
}

int Board::getEmptyX() const{
	return emptyX;
}

int Board::getEmptyY() const{
	return emptyY;
}

void Board::swap(int x1, int y1, int x2, int y2){
	string temp = brd[y1][x1];
	brd[y1][x1] = brd[y2][x2];
	brd[y2][x2] = temp;
}

bool Board::up(){
	//check if there is space to move up
	if ( emptyY != 0){
		swap(emptyX, emptyY, emptyX, emptyY - 1);		
		emptyY--;
		return true;
	}
	else
		return false;
		//cout << "cannot slide up" << endl;
}

bool Board::down(){
	//check if there is space to move down
        if ( emptyY != size - 1){
                swap(emptyX, emptyY, emptyX, emptyY + 1);
		emptyY++;
		return true;
        }
        else
		return false;
                //cout << "cannot slide down" << endl;
}

bool Board::left(){
	//check if there is space to move up
        if ( emptyX != 0){
                swap(emptyX, emptyY, emptyX - 1, emptyY);
		emptyX--;
        	return true;
	}
        else
		return false;
                //cout << "cannot slide left" << endl;
}

bool Board::right(){
	//check if there is space to move right
        if ( emptyX != size - 1){
                swap(emptyX, emptyY, emptyX + 1, emptyY);
        	emptyX++;
		return true;
	}
        else
		return false;
                //cout << "cannot slide right" << endl;
}

void Board::scramble(int n){
	int choice = 0;
	int p = n;
	srand(time(NULL));
	while(p > 0 ){
		choice = rand() % 4;

		//cout << choice << endl;

		if (choice == 0 && emptyY != 0){
			this->up();
		}
		else if (choice == 1 && emptyY != size - 1){
			this->down();
		}
		else if (choice == 2 && emptyX != 0){
			this->left();
		}
		else if (choice == 3 && emptyX != size - 1){
			this->right();
		}
		else
			p++;
		//this->printBox();
		//cout << endl;
		p--;
	}
}

void Board::printBox(){
	int i, j;
	int n = size;
	std::ofstream myfile;
	myfile.open ("trace.txt", std::ios::app); //appends to file
	for (i = 0; i < n;i++){
                for (j = 0; j < n;j++){
                        myfile << brd[i][j] << " ";
                }
		myfile << endl;
        }
	myfile.close();
}

void Board::printLine(){
	for (int i = 0; i < size; i++){
		for(int j = 0; j < size;j++){
			cout << brd[i][j] << " ";
		}
	}
	cout << endl;
}

Board::~Board(){
	for (int i = 0; i < size; i++)
		delete[] brd[i];

	delete[] brd;
}

