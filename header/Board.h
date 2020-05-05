#ifndef BOARD
#define BOARD

#include <string>

using std::string;

class Board{
public:
	Board(const int n);
	Board(const string* n, const int s);
	
	void swap(int x1, int y1, int x2, int y2);
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
int emptyX;
int emptyY;
};


#endif
