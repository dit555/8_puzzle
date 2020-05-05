#ifndef _NODE_
#define _NODE_

#include "Board.h"

class Node {
public:
	Node (Board* board);
	void explore();

private:
Board* b; //pointer to the board
Board* u; //pointer the the nex board when tile moved up
Board* d; //pointer to the next board when tile moved down
Board* l; //pointer to the next board when tile moved left
Board* r; //pointer to the next board when tile moved right

int depth; //depth of node in tree
};



#endif
