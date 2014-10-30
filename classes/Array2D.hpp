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


namespace PsCourseworkI
{
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
			struct Size
			{
				unsigned int m_x;
				unsigned int m_y;
			};
			
			Array2D(Size size);                        ///< Constructor.
			~Array2D();                                ///< Destructor.

			Size GetSize() const { return m_size; }    ///< Getter.
		
			/// Element access.
			T& operator() (unsigned int x, unsigned int y);

		private:
			Array2D();                                 ///< Default constructor.
			Array2D(Array2D const& rhs);               ///< Copy constructor.
			Array2D& operator=(Array2D const& rhs);    ///< Assignment operator.

			Size const m_size ;                        ///< Array X and Y extents.
			std::vector<T> m_array;                    ///< The array itself.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_ARRAY2D_HPP
