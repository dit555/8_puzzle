#include <iostream>
#include <string>
#include <math.h>

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

Board::Board(string n){
	//parse inputs
	int numInputs = 0;
	for (int i = 0; i < n.size(); i++){
		if(n[i] == ' ')
			numInputs++;
	}
	size = (int)sqrt((double)numInputs);

	//assigne inputs to and array
	string* inputs = new string[size];
	int index = 0;
	int l1 = 0;
	int l2 = 0;
	for (int i = 0; i < n.length(); i++){
		if (n[i] == ' '){
			l2 = i;
			inputs[index] = n.substr(l1,l2);
			l1 = i + 1;
			index++;
		}
	}
	//put the inputs into a board
	int i, j;
	index = 0;
        brd = new string*[size];
        for (i = 0; i < size; i++){
                //cout << "row: " << i << endl;
                string* col = new string[size];
                for (j = 0; j < size;j++){
                        //cout << "column: " << j << endl;
                        col[j] = inputs[index];
                        index++;
			if (inputs[index] == "*"){
				emptyX = i;
				emptyY = j;
			}
                }
                brd[i] = col;
        }


	delete[] inputs;
}

void Board::swap(int x1, int y1, int x2, int y2){
	string temp = brd[y1][x1];
	brd[y1][x1] = brd[y2][x2];
	brd[y2][x2] = temp;
}

void Board::up(){
	//check if there is space to move up
	if ( emptyY != 0){
		swap(emptyX, emptyY, emptyX, emptyY - 1);		
		emptyY--;
	}
	else
		cout << "cannot slide up" << endl;
}

void Board::down(){
	//check if there is space to move down
        if ( emptyY != size){
                swap(emptyX, emptyY, emptyX, emptyY + 1);
		emptyY++;
        }
        else
                cout << "cannot slide down" << endl;
}

void Board::left(){
	//check if there is space to move up
        if ( emptyX != 0){
                swap(emptyX, emptyY, emptyX - 1, emptyY);
		emptyX--;
        }
        else
                cout << "cannot slide left" << endl;
}

void Board::right(){
	//check if there is space to move right
        if ( emptyX != size){
                swap(emptyX, emptyY, emptyX + 1, emptyY);
        	emptyY++;
	}
        else
                cout << "cannot slide right" << endl;
}

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

