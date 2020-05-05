#include <iostream>

#include "../header/Node.h"
#include "../header/Board.h"
#include "../header/Tree.h"

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

Node* Tree::minUCF(){

}

Node* Tree::minMTH(){

}

Node* Tree::minEDH(){

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

}

void Tree::solveMTH(){

}

void Tree::solveEDH(){

}
