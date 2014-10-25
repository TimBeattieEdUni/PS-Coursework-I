//////////////////////////////////////////////////////////////////////////////
/// @file     test/UnitTest.cpp
///
/// @brief    Unit test for STIBIS protocol classes.
///


//////////////////////////////////////////////////////////////////////////////
//  Unit test framework header (must be before class test headers).
#include <UnitTest++.h>


//////////////////////////////////////////////////////////////////////////////
//  Test header for this directory.
#include "UnitTest.hpp"


//////////////////////////////////////////////////////////////////////////////
/// @brief    Program entry point.
///
/// @details  Runs unit tests for all classes in STIB.
///
/// @param    argc Standard argument count.
/// @param    argv Standard argument list.
///
int main(int argc, char* argv[])
{
	(void) argc;
	(void) argv;
	
    return UnitTest::RunAllTests();
}
