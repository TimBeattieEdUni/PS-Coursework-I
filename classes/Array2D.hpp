//////////////////////////////////////////////////////////////////////////////
/// @file     Array2D.hpp
///
/// @brief    Interface declaration for class Array2D.
///


#ifndef PSCOURSEWORKI_ARRAY2D_HPP
#define PSCOURSEWORKI_ARRAY2D_HPP


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <vector>
#include <stdexcept>
#include <iostream>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Two-dimensional size.
	///
	/// @details    Provides a single object for 2D array dimensions.
	///
	struct Size
	{
		Size(unsigned int x, unsigned int y) : m_x(x), m_y(y) {}
		Size& operator=(Size const& rhs) { m_x = rhs.m_x; m_y = rhs.m_y; return *this; }
		unsigned int m_x;
		unsigned int m_y;
	};

	
	//////////////////////////////////////////////////////////////////////////////
	/// @brief        Equivalence operator for Size objects.
	///
	/// @param        lhs  Object on the left-hand side of the comparison.
	/// @param        rhs  Object on the right-hand side of the comparison.
	/// @return       true if the Sizes are equal, false if not.
	///	
	inline bool operator==(Size const& lhs, Size const& rhs)
	{
		return ((lhs.m_x == rhs.m_x) && (lhs.m_y == rhs.m_y));
	}

	
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      2D array.
	///
	/// @details    Provides a two-dimensional contiguously- and dynamically-
	///             allocated array.
	///
	template <typename T>
	class Array2D
	{
		public:
			Array2D();                                 ///< Default Constructor.
			Array2D(Size size);                        ///< Constructor from size.

			Size GetSize() const { return m_size; }    ///< Getter.
			void Resize(Size const& new_size);         ///< Resizes the array.
		
			/// Element access.
			T&        operator() (unsigned int x, unsigned int y);
			/// Const element access.
			T const&  operator() (unsigned int x, unsigned int y)  const; 

		private:
			Array2D(Array2D const& rhs);               ///< Copy constructor.
			Array2D& operator=(Array2D const& rhs);    ///< Assignment operator.

			Size m_size;                               ///< Array X and Y extents.
			std::vector<T> m_array;                    ///< The array itself.
	};

	
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
		if ((0 == size.m_x) || (0 == size.m_y))
		{
			throw std::logic_error("array size cannot be zero");
		}
	}
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Initialises the array with zero size.
	///
	template <typename T>
	Array2D<T>::Array2D()
		: m_size(Size(0,0))
		, m_array()
	{
		
	}
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Clears the array and reinitialises it with the given size.
	///
	/// @param        size  New size for the array.
	///
	/// @post         The array has been resized.
	///
	template <typename T>
	void Array2D<T>::Resize(Size const& new_size)
	{
		m_array.clear();
		m_array.resize(new_size.m_x * new_size.m_y);
		m_size = new_size;
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
		
		return m_array[(y * m_size.m_x) + x];
	}
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Const version of operator() above.
	///
	/// @param        x  X-index of array element.
	/// @param        y  Y-index of array element.
	/// @return       Reference to the requested array element.
	///
	/// @exception    std::logic_error Invalid array index.
	///
	template <typename T>
	T const& Array2D<T>::operator() (unsigned int x, unsigned int y) const
	{
		if (x >= m_size.m_x)
		{
			throw std::logic_error("Array2D: x dimension out of bounds");
		}
		
		if (y >= m_size.m_y)
		{
			throw std::logic_error("Array2D: y dimension out of bounds");
		}
		
		return m_array[(y * m_size.m_x) + x];
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


#endif  //  #ndef PSCOURSEWORKI_ARRAY2D_HPP
