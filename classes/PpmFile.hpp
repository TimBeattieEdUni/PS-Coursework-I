//////////////////////////////////////////////////////////////////////////////
/// @file     PpmFile.hpp
///
/// @brief    Interface declaration for class PpmFile.
///


#ifndef PSCOURSEWORKI_MPPFILE_HPP
#define PSCOURSEWORKI_MPPFILE_HPP


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "Array2D.hpp"
#include "AppConfig.hpp" 


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
	class PpmFile
	{
		public:
//			typedef Array2D<char> PpmArray;                  ///< Saves typing.
					
		      	PpmFile(AppConfig const& cfg, unsigned int time_step/*, std::string ppm_filename*/ /*,WHAT_IS_TO_BE_PRINTED*/);///< Constructor from filename.

//			PpmArray const& GetArray() const { return m_array; }   ///< Getter.
			
		private:
//			PpmFile(PpmFile const& rhs);                     ///< Copy constructor.
//			PpmFile& operator=(PpmFile const& rhs);          ///< Assignment operator.
		
//			BmpArray m_array;                                ///< MPP in memory.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_MPPFILE_HPP
