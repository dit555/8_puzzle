#include <iostream>
#include <fstream>

#include "../header/Board.h"
#include "../header/Node.h"
#include "../header/Tree.h"
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ofstream;

int main() {
	char a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
	cout << "Welcome to 862126186 8 puzzle solver." << endl;
	cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;
	cin >> a1;


	if (a1 == '1'){
		Board a(3);
		cout << "your board (not yet scrambled) is: " << endl;
		a.printBox();

		cout << "Enter your choice of algorithm: " << endl;
		cout << "1. Uniform Cost Search\n";
		cout << "2. Misplaced Tile heuristic\n";
		cout << "3. A* with Euclidian Distance heuristic\n";

		cin >> a2;

		//put into trace
		if (a2 == '1'){
                        a.scramble(3);
                        Node b(&a);
                        Tree c(&b);

		ofstream myfile;
		myfile.open("trace.txt", std::ios::trunc);
		myfile << "Welcome to 862126186 8 puzzle solver." << endl;
        	myfile << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;
       		myfile << a1 << endl << endl;

                myfile << "your board (not yet scrambled) is: " << endl;
		myfile.close();
		a.printBox();
		myfile.open("trace.txt", std::ios::app);
                myfile << "Enter your choice of algorithm: " << endl;
                myfile << "1. Uniform Cost Search\n";
                myfile << "2. Misplaced Tile heuristic\n";
                myfile << "3. A* with Euclidian Distance heuristic\n";
		myfile << a2 << endl;
		myfile << "*NOTE: only 3 tiles have been moved in the scramble\n" 
			<<"for conviencence as scrambles that are higher\n" 
			<< "have a potential to take a very long time in UCS* \n" << endl;
		myfile.close();
		c.solveUCF();
		}

		else if (a2 == '2'){
                        a.scramble(10);
                        Node b(&a);
                        Tree c(&b);
                        c.solveMTH();
                }

                else if (a2 == '3'){
                        a.scramble(10);
                        Node b(&a);
                        Tree c(&b);
                        c.solveEDH();
                }

	}
	
	//const string d[9] = { "1" , "*", "3", "4","2","6","7","5","8" };
	//Board a( 3);
	//a.up();
	//a.left();
	//a.down();
	
	//a.scramble(20);
	//a.printBox();
	//cout << endl << endl;
	//Node b(&a);
	//cout <<b.calcEdh() << endl;
	//cout << b.getDepth() << endl;
	//cout << endl << b.calcMth() << endl;
	//Tree c(&b);
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
