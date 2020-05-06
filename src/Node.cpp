#include <iostream>

#include "Node.h"
#include "Board.h"

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
