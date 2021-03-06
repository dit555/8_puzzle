#ifndef _TREE_
#define _TREE_

#include "Node.h"
#include "Board.h"

class Tree {
public:
	Tree(Node* n);
	Node* newNode(Board* b, int de);
	void explore(Node* b);

	int minUCF(Node* n); //returns the min node to expolre in uniform cost search
	int minMTH(Node* n); //returns the min node to explore in Misplaced TIle Huristic
	int minEDH(Node* n); //returns the min node to explore in Euclidian Distance Huristic

	Node* findNode(Node* n, int p);
	bool isGoal(Node* n);

	void solveUCF();
	void solveMTH();
	void solveEDH();

private:
	Node* root;
	int size;
};

#endif