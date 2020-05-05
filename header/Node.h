#ifndef _NODE_
#define _NODE_

#include "Board.h"

class Node {
public:
	Node (Board* board);
	
	Node* UP();
	Node* DOWN();
	Node* LEFT();
	Node* RIGHT();

	Node* CUR(); //return pointer to current node

	Board* getBrd();
	
	void explore();
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
