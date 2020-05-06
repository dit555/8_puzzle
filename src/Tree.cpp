#include <iostream>
#include <algorithm>

#include "../header/Node.h"
#include "../header/Board.h"
#include "../header/Tree.h"

using std::cout;
using std::endl;

Tree::Tree(Node* n) {
	root = n;
	root->setDepth(0);
	size = n->getBrd()->getSize();
}

Node* Tree::newNode(Board* b, int de) {
	Board* a = new Board(b);
	Node* temp = new Node(a, de);
	return temp;
}

void Tree::explore(Node* b) {

	//b->getBrd()->printBox();

	if (b->getBrd()->getEmptyY() > 0) {
		/*cout << "tyring up..." << endl;*/
		b->setUP(newNode(b->getBrd(), b->getDepth() + 1));
		b->UP()->getBrd()->up();
		//b->UP()->incDepth();
		/*b->UP()->getBrd()->printBox();*/
			//cout << endl << b->UP()->getDepth();
	}

	/*std::cout << std::endl;
	std::cout << std::endl;*/

	if (b->getBrd()->getEmptyY() < b->getBrd()->getSize() - 1) {
		/*cout << "tyring down..." << endl;*/
		b->setDOWN(newNode(b->getBrd(), b->getDepth() + 1));
		b->DOWN()->getBrd()->down();
		//b->DOWN()->incDepth();
		/*b->DOWN()->getBrd()->printBox();*/
		//cout << endl << b->DOWN()->getDepth();

	}

	/*std::cout << std::endl;
		std::cout << std::endl;*/


	if (b->getBrd()->getEmptyX() > 0) {
		/*cout << "tyring left..." << endl;*/
		b->setLEFT(newNode(b->getBrd(), b->getDepth() + 1));
		b->LEFT()->getBrd()->left();
		//b->LEFT()->incDepth();
				/*b->LEFT()->getBrd()->printBox();*/
		//cout << endl << b->LEFT()->getDepth();

	}

	/*std::cout << std::endl;
		std::cout << std::endl;*/


	if (b->getBrd()->getEmptyY() < b->getBrd()->getSize() - 1) {
		/*cout << "tyring right..." << endl;*/
		b->setRIGHT(newNode(b->getBrd(), b->getDepth() + 1));
		b->RIGHT()->getBrd()->right();
		//b->RIGHT()->incDepth();
				/*b->RIGHT()->getBrd()->printBox();*/
		//cout << endl << b->RIGHT()->getDepth();

	}

	cout << "exploring SUCCESS" << endl << endl;
}

int Tree::minUCF(Node* n) {
	//temporary mins
	int tempu;
	int tempd;
	int templ;
	int tempr;

	int temp1;
	int temp2;

	//recursively iterate through all nodes	
	if (n->UP() != nullptr) {
		tempu = minUCF(n->UP());
	}
	else
		tempu = 1000000; //garbage value that can never be min

	if (n->DOWN() != nullptr)
		tempd = minUCF(n->DOWN());
	else
		tempd = 10000000;

	if (n->LEFT() != nullptr)
		templ = minUCF(n->LEFT());
	else
		templ = 10000000;

	if (n->RIGHT() != nullptr)
		tempr = minUCF(n->RIGHT());
	else
		tempr = 10000000;
	//only looking for values of leaf nodes
	if (n->isLeaf())
		return n->getDepth();

	temp1 = std::min(tempu, tempd);
	temp2 = std::min(templ, tempr);

	temp1 = std::min(temp1, temp2); //is the most min value of the child nodes
	return temp1;




}
int Tree::minMTH(Node* n) {
	return 0;
}

int Tree::minEDH(Node* n) {
	return 0;
}

Node* Tree::findNode(Node* n, int p) {
	Node* temp;
	if (n->UP() != nullptr) {
		temp = findNode(n->UP(), p);
		if (temp == nullptr);
		else return temp;
	}

	if (n->DOWN() != nullptr) {
		temp = findNode(n->DOWN(), p);
		if (temp == nullptr);
		else return temp;
	}

	if (n->LEFT() != nullptr){
		temp = findNode(n->LEFT(), p);
		if (temp == nullptr);
		else return temp;
	}

	if (n->RIGHT() != nullptr){
		temp = findNode(n->RIGHT(), p);
		if (temp == nullptr);
		else return temp;
	}

	if (n->getDepth() == p && n->isLeaf())
		return n;

	return nullptr;
}

bool Tree::isGoal(Node* n) {
	bool equal = false;
	Board a(size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			
			if (n->getBrd()->getVal(i, j) == a.getVal(i, j))
				equal = true;
			else {
				equal = false;
				break;
			}

		}
	}
	return equal;
}

void Tree::solveUCF() {
	int tries = 0;
	Node* temp = root;
	if (this->isGoal(temp)) {
		temp->getBrd()->printBox();
		tries++;
		cout << "GOAL!" << endl;
	}
	else {
		cout << "exploring root node" << endl;
		temp->getBrd()->printBox();
		cout << "cost: 0" << endl << endl;
		this->explore(temp);

		while (1) {
			int cost = this->minUCF(root);
			cout << "cost: " << cost << endl;
			temp = this->findNode(root, cost);
			
			if (this->isGoal(temp)) {
				temp->getBrd()->printBox();
				cout << "GOAL!" << endl;
				cout << "this solution took " << tries << "tries." << endl;
				break;
			}
			else {
				tries++;
				cout << "exploring node: " << endl;
				temp->getBrd()->printBox();
				cout << "of cost: " << cost << endl << endl;
				this->explore(temp);
				cout << endl;
			}
		}
	}
}

void Tree::solveMTH() {

}

void Tree::solveEDH() {

}
