#include <iostream>
#include <algorithm>

#include "../header/Node.h"
#include "../header/Board.h"
#include "../header/Tree.h"

using std::cout;
using std::endl;

Tree::Tree(Node* n){
	root = n;
	root->setDepth(0);
}

Node* Tree::newNode(Board* b){
	Board* a = new Board(b);
	Node* temp = new Node(a);
	return temp;
}

void Tree::explore(Node* b){

        if(b->getBrd()->getEmptyY() != 0){

                b->setUP(newNode(b->getBrd()));
                b->UP()->getBrd()->up();
		b->UP()->incDepth();
                //b->UP()->getBrd()->printBox();
        }

        //std::cout << std::endl;
        //std::cout << std::endl;

        if(b->getBrd()->getEmptyY() != b->getBrd()->getSize()){
                b->setDOWN(newNode(b->getBrd()));
                b->DOWN()->getBrd()->down();
		b->DOWN()->incDepth();
                //b->DOWN()->getBrd()->printBox();
        }
	
	//std::cout << std::endl;
        //std::cout << std::endl;


        if(b->getBrd()->getEmptyX() != 0){
         
                b->setLEFT(newNode(b->getBrd()));
                b->LEFT()->getBrd()->left();
		b->LEFT()->incDepth();
                //b->LEFT()->getBrd()->printBox();
	}
	
	//std::cout << std::endl;
        //std::cout << std::endl;


        if(b->getBrd()->getEmptyY() != b->getBrd()->getSize()){
                
                b->setRIGHT(newNode(b->getBrd()));
                b->RIGHT()->getBrd()->right();
		b->RIGHT()->incDepth();
                //b->RIGHT()->getBrd()->printBox();
     	}
}

int Tree::minUCF(Node* n){
	//temporary mins
	int tempu;
	int tempd;
	int templ;
	int tempr;

	int temp1;
	int temp2;	
	
	//recursively iterate through all nodes	
	if(n->UP() != nullptr){
		tempu =  minUCF(n->UP());
	}
	else
		tempu = 100000; //garbage value that can never be min

	if(n->DOWN() != nullptr)
                tempd = minUCF(n->DOWN());
	else
		tempd = 100000;

	if(n->LEFT() != nullptr)
                templ =  minUCF(n->LEFT());
	else
		templ = 100000;

	if(n->RIGHT() != nullptr)
                tempr =  minUCF(n->RIGHT());
	else
		tempr = 100000;
	//only looking for values of leaf nodes
	if (n->isLeaf())
		return n->getDepth();

	temp1 = std::min(tempu, tempd);
	temp2 = std::min(templ, tempr);

	temp1 = std::min(temp1, temp2); //is the most min value of the child nodes
	return temp1;



	
}
int Tree::minMTH(Node* n){

}

int Tree::minEDH(Node* n){

}

Node* findNode(Node* n, int p){
	if(n->UP() != nullptr){
                return  findNode(n->UP(), p);
        }

        if(n->DOWN() != nullptr)
                return findNode(n->DOWN(), p);

        if(n->LEFT() != nullptr)
                return findNode(n->LEFT(), p);

        if(n->RIGHT() != nullptr)
                return findNode(n->RIGHT(), p);
	
	if (n->getDepth() == p)
		return n;

	return nullptr;
}

bool Tree::isGoal(Node* n){
	bool equal = false;
	int s = n->getBrd()->getSize();
	Board a(s);
	for (int i = 0; i < s;i++){
		for (int j = 0; j< s; j++){
			if (n->getBrd()->getVal(i,j) == a.getVal(i,j))
				equal = true;
			else
				equal = false;

		}
	}
	return equal;
}

void Tree::solveUCF(){
	Node* temp = root;
	if (this->isGoal(temp)){
		temp->getBrd()->printBox();
		cout << "GOAL!" << endl;
	}
	else{
		cout << "exploring root node" << endl;
		temp->getBrd()->printBox();
		cout << endl;
		this->explore(temp);

		while(1){
			int cost = this->minUCF(root);
			temp = this->findNode(root, cost);
			if(this->isGoal(temp)){
				temp->getBrd()->printBox();
				cout << "GOAL!" << endl;
				break;
			}
			else
				cout << "exploring node of cost: " << cost << endl;
		       		temp->getBrd()->printBox();	
				this->explore(temp);
				cout << endl;
				
		}
	}
}

void Tree::solveMTH(){

}

void Tree::solveEDH(){

}
