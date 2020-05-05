#include <iostream>

#include "../header/Node.h"
#include "../header/Board.h"
#include "../header/Tree.h"

Tree::Tree(Node* n){
	root = n;
}

Node* Tree::newNode(Board* b){
	Node *temp = new Node(b);
	return temp;
}

void Tree::explore(Node* b){

        if(b->getBrd()->getEmptyY() != 0){

                b->setUP(newNode(b->getBrd()));
                b->UP()->getBrd()->up();
                b->UP()->getBrd()->printBox();
        }

        std::cout << std::endl;
        std::cout << std::endl;

        if(b->getBrd()->getEmptyY() != b->getBrd()->getSize()){
                b->setDOWN(newNode(b->getBrd()));
                b->DOWN()->getBrd()->down();
                b->DOWN()->getBrd()->printBox();
        }
	
	std::cout << std::endl;
        std::cout << std::endl;


        if(b->getBrd()->getEmptyX() != 0){
         
                b->setLEFT(newNode(b->getBrd()));
                b->LEFT()->getBrd()->left();
                b->LEFT()->getBrd()->printBox();
	}
	
	std::cout << std::endl;
        std::cout << std::endl;


        if(b->getBrd()->getEmptyY() != b->getBrd()->getSize()){
                
                b->setRIGHT(newNode(b->getBrd()));
                b->RIGHT()->getBrd()->right();
                b->RIGHT()->getBrd()->printBox();
        }

	std::cout << std::endl;
        std::cout << std::endl;
	b->getBrd()->printBox();
       	std::cout << std::endl;
}

Node* Tree::min(){}
