#include <iostream>

#include "../header/Board.h"
#include <string>

using std::string;

int main(){
	//const string b[9] = {"1" , "3", "2", "4","5","6","7","*","8"};
	Board a(3);
	a.scramble(20);
	a.printBox();	
	
	return 0;
}
