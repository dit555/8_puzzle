#include <iostream>

#include "Board.h"
#include "Node.h"
#include "Tree.h"
#include <string>

using std::string;
using std::cout;
using std::endl;

int main() {
	const string d[9] = { "1" , "2", "3", "4","*","5","6","7","8" };
	Board a(3);
	a.up();
	a.left();
	//a.scramble(3);
	//a.printBox();
	//cout << endl << endl;
	Node b(&a);
	//cout << b.getDepth() << endl;

	Tree c(&b);

	/*c.explore(&b);
	c.explore(b.UP());
	c.explore(b.DOWN());
	c.explore(b.LEFT());
	c.explore(b.RIGHT());*/

	//cout << endl <<  c.minUCF(&b) << endl;
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
