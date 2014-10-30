//////////////////////////////////////////////////////////////////////////////
/// @file     DemoClass-Test.hpp
///
/// @brief    Unit test for class DemoClass.
///
/// @note     This program is the confidential and proprietary product of
///           Hanover Displays Limited. Any unauthorised use, reproduction or
///           transfer of this program is strictly prohibited.
///           Copyright 2013 Hanover Displays Limited.
///           (Subject to limited distribution and restricted disclosure only.)
///           All rights reserved.
///


#ifndef PSCOURSEWORKI_DEMOCLASS_TEST_HPP
#define PSCOURSEWORKI_DEMOCLASS_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "DemoClass.hpp"


TEST(DemoClass)
{
	using PsCourseworkI::DemoClass;

	DemoClass d;
	(void) d;

	CHECK(true);
}


#endif  //  #ndef PSCOURSEWORKI_DEMOCLASS_TEST_HPP
