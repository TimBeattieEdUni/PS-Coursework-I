//////////////////////////////////////////////////////////////////////////////
/// @file     BmpFile.hpp
///
/// @brief    Interface declaration for class BmpFile.
///


#ifndef PSCOURSEWORKI_BMPFILE_HPP
#define PSCOURSEWORKI_BMPFILE_HPP


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "Array2D.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <string>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief
	///
	/// @details
	///
	/// @invariant
	///
	class BmpFile
	{
		public:
			BmpFile(std::string bmp_filename);         ///< Constructor from filename.

		private:
			BmpFile(BmpFile const& rhs);              ///< Copy constructor.
			BmpFile& operator=(BmpFile const& rhs);   ///< Assignment operator.
		
			Array2D<char> m_array;                    ///< Bitmap in memory.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_BMPFILE_HPP
