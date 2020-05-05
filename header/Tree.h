#ifndef _TREE_
#define _TREE_

#include "Node.h"
#include "Board.h"

class Tree{
public:
	Tree(Node* n);
	Node* newNode(Board* b);
	void explore(Node* b);

	Node* minUCF(); //returns the next node to expolre in uniform cost search
	Node* minMTH(); //returns the next node to explore in Misplaced TIle Huristic
	Node* minEDH(); //returns the next node to explore in Euclidian Distance Huristic

	bool isGoal(Node* n);

	void solveUCF();
	void solveMTH();
	void solveEDH();

private:
Node* root;
};

#endif
