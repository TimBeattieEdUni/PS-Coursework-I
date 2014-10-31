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
			typedef Array2D<unsigned int> BmpArray;          ///< Saves typing.
		
			BmpFile(std::string bmp_filename);               ///< Constructor from filename.

			BmpArray const& GetArray() const { return m_array; }   ///< Getter.
			
		private:
			BmpFile(BmpFile const& rhs);                     ///< Copy constructor.
			BmpFile& operator=(BmpFile const& rhs);          ///< Assignment operator.
		
			BmpArray m_array;                                ///< Bitmap in memory.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_BMPFILE_HPP
