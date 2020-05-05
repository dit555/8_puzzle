#ifndef _TREE_
#define _TREE_

#include "Node.h"
#include "Board.h"

class Tree{
public:
	Tree(Node* n);
	Node* newNode(Board* b);
	void explore(Node* b);
	Node* min();

private:
Node* root;
};

#endif
