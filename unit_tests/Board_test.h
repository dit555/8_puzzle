#ifdef _BOARD_TEST_H_
#define _BOARD_TEST_H_

#include "gtest/gtest.h"
#include "../header/Board.h"

#include <string>

using std::string;

TEST(BoardDefineTest, BoardTest){
	Board a(3);
	testing::internal::CaptureStdout();
	a.printBox();
	string output = testing::internal::GetCapturedSdout();

	EXPECT_EQ(output, "1 2 3 \n4 5 6 \n7 8 *");

}

#endif
