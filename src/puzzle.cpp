#include <iostream>

#include "../header/Board.h"

int main(){
	Board a(3);
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
