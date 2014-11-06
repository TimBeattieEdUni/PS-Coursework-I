//////////////////////////////////////////////////////////////////////////////
/// @file     LandscapePpmWriter.hpp
///
/// @brief    Interface declaration for class LandscapePpmWriter.
///


#ifndef GROUP_PRACTICAL_REPO_LANDSCAPEPPMWRITER_HPP
#define GROUP_PRACTICAL_REPO_LANDSCAPEPPMWRITER_HPP


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "Landscape.hpp"
#include "PpmFile.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <string>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Landscape to PPM file converter.
	///
	/// @details    Writes a Landscape's array of Cells to a PPM image file.
	///
	class LandscapePpmWriter
	{
		public:
			LandscapePpmWriter(Landscape::LsArray const& array);    ///< Constructor.
			
			void Write(std::string const& filename);                ///< Writes Cells to PPM file.

		private:
			LandscapePpmWriter(LandscapePpmWriter const& rhs);              ///< Copy constructor.
			LandscapePpmWriter& operator=(LandscapePpmWriter const& rhs);   ///< Assignment operator.
		
			Landscape::LsArray const& m_array;   ///< The landscape to be written.
	};
	
}   //  namespace PsCourseworkI


#endif  //  #ndef GROUP_PRACTICAL_REPO_LANDSCAPEPPMWRITER_HPP
