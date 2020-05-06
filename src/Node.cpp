#include <iostream>
#include <stdlib.h>

#include "../header/Node.h"
#include "../header/Board.h"

using std::cout;
using std::endl;

Node::Node(Board* board) {
	b = board;
	u = nullptr;
	d = nullptr;
	l = nullptr;
	r = nullptr;

	depth = 0;
}

Node::Node(Board* board, int de) {
	b = board;
	u = nullptr;
	d = nullptr;
	l = nullptr;
	r = nullptr;

	depth = de;
}

void Node::setUP(Node* N) {
	u = N;
}

void Node::setDOWN(Node* N) {
	d = N;
}

void Node::setLEFT(Node* N) {
	l = N;
}

void Node::setRIGHT(Node* N) {
	r = N;
}


Node* Node::UP() {
	return u;
}

Node* Node::DOWN() {
	return d;
}

Node* Node::LEFT() {
	return l;
}

Node* Node::RIGHT() {
	return r;
}

void Node::incDepth() {
	depth++;
}

void Node::setDepth(int n) {
	depth = n;
}

int Node::getDepth() {
	return depth;
}

int Node::calcMth(){
	int val = 9;
	int s = this->getBrd()->getSize();
	Board a(s);
	for (int i = 0; i < s; i++){
		for(int j = 0; j < s; j++){
			if (a.getVal(i, j) == this->getBrd()->getVal(i, j))
				val--;	
		}
	}	
	return val;
}

int Node::calcEdh(){
	int val = 0;
	int s = this->getBrd()->getSize();
        Board a(s);
        for (int i = 0; i < s; i++){
                for(int j = 0; j < s; j++){
			// if tile misplaced find how far away it is
                        if (a.getVal(i, j) != this->getBrd()->getVal(i, j)){
                        	for (int l = 0; l < s; l++){
					for(int m = 0; m < s; m++){
						//cout << i << j << l << m;
						if(a.getVal(i, j) == this->getBrd()->getVal(l, m)){
							val += abs(i - l);
							//cout << i << "-" << j << endl;
							val += abs(j - m);
							//cout << l << "-" << m << endl;

						}
					}
				}	
			}
                }
        }
        return val;
}

Board* Node::getBrd() {
	return b;
}
bool Node::isLeaf() {
	if (u == nullptr && d == nullptr &&  l == nullptr && r == nullptr)
		return true;
	else
		return false;
}

Node::~Node() {
	delete u;
	delete d;
	delete l;
	delete r;
}
