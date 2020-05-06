#ifndef _NODE_
#define _NODE_

#include "Board.h"

class Node {
public:
	Node(Board* board);
	Node(Board* board, int de);

	Node* UP();
	Node* DOWN();
	Node* LEFT();
	Node* RIGHT();

	void setUP(Node* N);
	void setDOWN(Node* N);
	void setLEFT(Node* N);
	void setRIGHT(Node* N);

	void incDepth();
	void setDepth(int n);
	int getDepth();

	Board* getBrd();

	bool isLeaf();

	~Node();
private:
	Board* b; //pointer to the board
	Node* u; //pointer the the nex board when tile moved up
	Node* d; //pointer to the next board when tile moved down
	Node* l; //pointer to the next board when tile moved left
	Node* r; //pointer to the next board when tile moved right

	int depth; //depth of node in tree
};



#endif