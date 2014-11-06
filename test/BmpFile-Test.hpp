//////////////////////////////////////////////////////////////////////////////
/// @file     BmpFile-Test.hpp
///
/// @brief    Unit test for class BmpFile.
///


#ifndef REPO_CLASSES_BMPFILE_TEST_HPP
#define REPO_CLASSES_BMPFILE_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "BmpFile.hpp"

//////////////////////////////////////////////////////////////////////////////
/// @brief  First test for class BmpFile.
///
/// @test   BmpFile can be constructed from valid arguments.
///
TEST(BmpFile)
{
	using PsCourseworkI::BmpFile;

	BmpFile bmp("inputs/BmpFile-Test.dat");

   for ( int j=0; j<2; j++)
   {
      for (int i=0; i<3; i++)
      {
         std::cout << "bmp.GetArray(" <<i << "," << j << ") = " << bmp.GetArray()(i,j) << std::endl; 
      }
   }
   // the numbers below are from: "inputs/BmpFile-Test.dat"
   // they must not be altered!
    CHECK(bmp.GetArray()(0,0) == 1);
	CHECK(bmp.GetArray()(1,0) == 23);
	CHECK(bmp.GetArray()(2,0) == 5);

	CHECK(bmp.GetArray()(0,1) == 0);
	CHECK(bmp.GetArray()(1,1) == 4);
	CHECK(bmp.GetArray()(2,1) == 6);
}


#endif  //  #ndef REPO_CLASSES_BMPFILE_TEST_HPP
