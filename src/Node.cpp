#include <iostream>

#include "../header/Node.h"
#include "../header/Board.h"

Node::Node(Board* board){
	b = board;
	u = nullptr;
	d = nullptr;
	l = nullptr;
	r = nullptr;
}

void Node::explore(){
	
	if(b->getEmptyY() != 0){
		Board* temp = new Board(b);
		Node* temp2 = new Node(temp);
		u = temp2;
		u->getBrd()->up();
		u->getBrd()->printBox();
	}	
	
	if(b->getEmptyY() != b->getSize()){
		Board* temp3 = new Board(b);
		Node* temp4 = new Node(temp3);
                d = temp4;
                d->getBrd()->down();
                d->getBrd()->printBox();
        }

	if(b->getEmptyX() != 0){
		Board* temp5 = new Board(b);
                Node* temp6 = new Node(temp5);
                l = temp6;
                l->getBrd()->left();
                l->getBrd()->printBox();
        }

	if(b->getEmptyY() != b->getSize()){
		Board* temp7 = new Board(b);
                Node* temp8 = new Node(temp7);
                r = temp8;
                r->getBrd()->right();
                r->getBrd()->printBox();
        }
}

Node* Node::UP(){
	return u;
}

Node* Node::DOWN(){
        return d;
}

Node* Node::LEFT(){
        return l;
}

Node* Node::RIGHT(){
        return r;
}

Node* Node::CUR(){
	return this;
}

Board* Node::getBrd(){
	return b;
}
bool Node::isLeaf(){
	if (u == nullptr, d == nullptr, l == nullptr, r == nullptr)
		return true;
	else
		return false;
}

Node::~Node(){
	delete u;
	delete d;
	delete l;
	delete r;
}
