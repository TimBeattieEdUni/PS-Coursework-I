//////////////////////////////////////////////////////////////////////////////
/// @file     Array2D-Test.hpp
///
/// @brief    Unit test for class Array2D.
///


#ifndef PSCOURSEWORKI_ARRAY2D_TEST_HPP
#define PSCOURSEWORKI_ARRAY2D_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "Array2D.hpp"



//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <stdexcept>
#include <cmath>




/// @todo remove this
#include <iostream>




//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests successful construction.
///
/// @test   Array2D can be constructed from valid arguments.
/// @test   Array size is stored correctly.
///
TEST(Array2DConstruction)
{
	using PsCourseworkI::Array2D;

	Array2D<double>::Size size1 = { 10, 12 };
	
	Array2D<double> array(size1);
	Array2D<double>::Size size2 = array.GetSize();
	
	CHECK(size1.m_x == size2.m_x);
	CHECK(size1.m_y == size2.m_y);
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests construction failure.
///
/// @test   Array2D throws on invalid array sizes.
///
TEST(Array2DThrowOnInvalidIndex)
{
	using PsCourseworkI::Array2D;

	Array2D<double>::Size size = { 0, 0 };
	
	CHECK_THROW(Array2D<double> array(size), std::logic_error);
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests element access.
///
/// @test   All array elements can be assigned and retrieved.
/// @test   Array2D throws on out-of-bounds indices.
///
TEST(Array2DElementAccess)
{
	using PsCourseworkI::Array2D;
	
	Array2D<double>::Size given_size = { 2, 2 };
	
	Array2D<double> array(given_size);
	Array2D<double>::Size array_size = array.GetSize();
	
	//  element access tests
	for (unsigned int i=0; i<array_size.m_x; ++i)
	{
		for (unsigned int j=0; j<array_size.m_y; ++j)
		{
			double value = 1.01 * static_cast<double>(i + j);
			double delta = 0.0001 * value;

			array(i, j) = value;
			CHECK(fabs(array(i, j) - value) <= delta);
		}
	}

	//  out-of-bounds tests
	CHECK_THROW(array(given_size.m_x, 0), std::logic_error);
	CHECK_THROW(array(0, given_size.m_y), std::logic_error);
	CHECK_THROW(array(given_size.m_x, given_size.m_y), std::logic_error);
}


#endif  //  #ndef PSCOURSEWORKI_ARRAY2D_TEST_HPP
