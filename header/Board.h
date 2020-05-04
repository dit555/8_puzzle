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

	void printBox();
	void printLine();

	~Board();
private:
string **brd;
int size;
};


#endif
