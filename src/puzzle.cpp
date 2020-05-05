#include <iostream>

#include "../header/Board.h"
#include <string>

using std::string;

int main(){
	const string b[9] = {"1" , "3", "2", "4","5","6","7","*","8"};
	Board a(b, 3);
	a.printBox();	
	a.printLine();
	return 0;
}
