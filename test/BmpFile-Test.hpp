//////////////////////////////////////////////////////////////////////////////
/// @file     BmpFile-Test.hpp
///
/// @brief    Unit test for class BmpFile.
///
/// @todo     Test failure modes for class BmpFile.
///


#ifndef PSCOURSEWORKI_BMPFILE_TEST_HPP
#define PSCOURSEWORKI_BMPFILE_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "BmpFile.hpp"


//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests loading bitmask from file.
///
/// @test   BmpFile correctly reads in a .dat file containing a non-square
///         land/water mask.
///
TEST(BmpFile)
{
	using PsCourseworkI::BmpFile;

	BmpFile bmp("inputs/BmpFile-Test.dat");

	//  these must match the file "inputs/BmpFile-Test.dat"
	CHECK(bmp.GetArray()(0, 0) == 1);
	CHECK(bmp.GetArray()(1, 0) == 23);
	CHECK(bmp.GetArray()(2, 0) == 5);

	CHECK(bmp.GetArray()(0, 1) == 0);
	CHECK(bmp.GetArray()(1, 1) == 4);
	CHECK(bmp.GetArray()(2, 1) == 6);
}


#endif  //  #ndef PSCOURSEWORKI_BMPFILE_TEST_HPP
