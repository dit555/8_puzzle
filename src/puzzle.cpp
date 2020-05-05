#include <iostream>

#include "../header/Board.h"
#include "../header/Node.h"
#include "../header/Tree.h"
#include <string>

using std::string;
using std::cout;
using std::endl;

int main(){
	const string d[9] = {"1" , "2", "3", "4","*","5","6","7","8"};
	Board a(3);
	a.up();
	a.left();
	//a.scramble(3);
	//a.printBox();
	//cout << endl << endl;
	Node b(&a);
	Tree c(&b);

	c.solveUCF();
	
	

	//cout << c.minUCF(&b) << endl;
	//if (b.isLeaf())
		//cout << "leaf" << endl;	
	//b.getBrd()->printBox();
	//c.explore(&b);
	//cout << endl << endl;
	//if (c.isGoal(&b))
        //        cout << "GOAL!" << endl;
	return 0;
}
