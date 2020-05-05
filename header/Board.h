#ifndef BOARD
#define BOARD

#include <string>

using std::string;

class Board{
public:
	Board(const int n);
	Board(const string* n, const int s);
	Board(const Board* b);

	string** getBoard() const;
	string getVal(int x, int y) const;
	int getSize() const;
	int getEmptyX() const;
	int getEmptyY() const;
	
	void swap(int x1, int y1, int x2, int y2);
	bool up();
	bool down();
	bool left();
	bool right();

	void scramble(int n);

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
