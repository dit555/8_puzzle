#ifndef BOARD
#define BOARD

#include <string>

using std::string;

class Board{
public:
	Board(int n);
	Board(string n);

	void up();
	void down();
	void left();
	void right();


private:
string **brd;
}	


#endif
