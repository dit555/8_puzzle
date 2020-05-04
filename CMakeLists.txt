CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

INCLUDE_DIRECTORIES(${header})
#INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)

ADD_EXECUTABLE(puzzle
	header/Board.h
	src/Board.cpp
	src/puzzle.cpp

)

ADD_EXECUTABLE(test
	unit_tests/unit_test.cpp
	unit_tests/Board_test.h
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
