#include <iostream>

#include "../header/Board.h"
#include "../header/Node.h"
#include "../header/Tree.h"
#include <string>

using std::string;
using std::cout;
using std::endl;

int main() {
	const string d[9] = { "1" , "*", "3", "4","2","6","7","5","8" };
	Board a(3);
	//a.up();
	//a.left();
	//a.down();
	
	a.scramble(20);
	a.printBox();
	//cout << endl << endl;
	Node b(&a);
	cout <<b.calcEdh() << endl;
	//cout << b.getDepth() << endl;
	//cout << endl << b.calcMth() << endl;
	Tree c(&b);
	//c.solveMTH();
	/*c.explore(&b);
	c.explore(b.UP());
	c.explore(b.UP()->UP());
	c.explore(b.UP()->DOWN());
	c.explore(b.UP()->RIGHT());
	c.explore(b.RIGHT());*/

	//cout << endl <<  c.minUCF(&b) << endl;
	//c.solveUCF();



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
