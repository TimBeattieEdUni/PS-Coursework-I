//////////////////////////////////////////////////////////////////////////////
/// @file     DemoClass.cpp
///
/// @brief    Implementation of class DemoClass.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "DemoClass.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details
	///
	/// @param
	///
	/// @pre
	/// @post
	///
	/// @exception
	///
	DemoClass::DemoClass()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Cleans up any resources.
	///
	/// @pre
	/// @post
	///
	DemoClass::~DemoClass()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details
	///
	/// @param      Object to copy.
	///
	/// @pre
	/// @post
	///
	/// @exception
	///
	DemoClass::DemoClass(DemoClass const& rhs)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		(void) rhs;
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details
	///
	/// @param      Object on the right-hand side of the assignment statement.
	/// @return
	///
	/// @pre
	/// @post
	///
	/// @exception
	///
	DemoClass& DemoClass::operator=(DemoClass const& rhs)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		(void) rhs;
		return *this;
	}
	
}   //  namespace PsCourseworkI

