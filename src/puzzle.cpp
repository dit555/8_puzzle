#include <iostream>

#include "../header/Board.h"
#include <string>

int main(){
	Board a("1 2 3 4 5 6 7 8 * ");
	a.up();
	a.left();
	a.printBox();
	a.down();
	a.printBox();
	a.right();
	a.printBox();	
	a.printLine();
	return 0;
}
