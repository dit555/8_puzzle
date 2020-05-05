#include <iostream>

#include "../header/Board.h"
#include "../header/Node.h"
#include <string>

using std::string;
using std::cout;
using std::endl;

int main(){
	//const string b[9] = {"1" , "3", "2", "4","5","6","7","*","8"};
	Board a(3);
	Node b(&a);
	if (b.isLeaf())
		cout << "leaf" << endl;	
	//b.getBrd()->printBox();
	b.explore();
	cout << endl << endl;
	b.getBrd()->printBox();
	return 0;
}
