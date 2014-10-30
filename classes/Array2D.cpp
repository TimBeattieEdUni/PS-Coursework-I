//////////////////////////////////////////////////////////////////////////////
/// @file     Array2D.cpp
///
/// @brief    Implementation of class Array2D.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "Array2D.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <stdexcept>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Sets up the array.
	///
	/// @param      size  X and Y sizes of the array.
	///
	/// @post       Array has been allocated.
	///
	/// @exception  std::logic_error Invalid array size(s).
	///
	template <typename T>
	Array2D<T>::Array2D(Size size)
		: m_size(size)
		, m_array(size.m_x * size.m_y)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		if ((0 == size.m_x) || (0 == size.m_y))
		{
			throw std::logic_error("array size cannot be zero");
		}
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Clean-up is automatic so far.
	///
	template <typename T>
	Array2D<T>::~Array2D()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Provides access to array elements via x and y indices.
	///               Performs bounds checking.
	///
	/// @param        x  X-index of array element.
	/// @param        y  Y-index of array element.
	/// @return       Reference to the requested array element.
	///
	/// @exception    std::logic_error Invalid array index.
	///
	template <typename T>
	T& Array2D<T>::operator() (unsigned int x, unsigned int y)
	{
		if (x >= m_size.m_x)
		{
			throw std::logic_error("Array2D: x dimension out of bounds");
		}

		if (y >= m_size.m_y)
		{
			throw std::logic_error("Array2D: y dimension out of bounds");
		}
		
		return m_array[(x * m_size.m_x) + y];
	}

	
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Declared private to prevent use.
	///
	/// @param      rhs  Object to copy.
	///
	template <typename T>
	Array2D<T>::Array2D(Array2D const& rhs)
		: m_size()
		, m_array()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		(void) rhs;
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Declared private to prevent use.
	///
	/// @param      rhs  Object on the right-hand side of the assignment statement.
	/// @return     Object which has been assigned.
	///
	template <typename T>
	Array2D<T>& Array2D<T>::operator=(Array2D<T> const& rhs)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		(void) rhs;
		return *this;
	}

}   //  namespace PsCourseworkI


//  Instantiate the types we know we'll need
template class PsCourseworkI::Array2D<double>;
