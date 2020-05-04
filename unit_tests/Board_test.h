#ifdef _BOARD_TEST_H_
#define _BOARD_TEST_H_

#include "gtest/gtest.h"
#include "../src/Board.cpp"

#include <string>

using std::string;

TEST(BoardDefineTest, BoardTest){
	Board a(3);
	testing::internal::CaptureStdout();
	a.printLine();
	string output = testing::internal::GetCapturedSdout();

	EXPECT_EQ(output, "1 2 3 4 5 6 7 8 * ");

}

#endif
