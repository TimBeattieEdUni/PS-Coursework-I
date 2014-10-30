//////////////////////////////////////////////////////////////////////////////
/// @file     FileIO.hpp
///
/// @brief    Interface declaration for class FileIO.
///


//#ifndef PSCOURSEWORKI_DEMOCLASS_HPP
//#define PSCOURSEWORKI_DEMOCLASS_HPP

#include "params.hpp"

#include <iostream>

namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Demonstration class.
	///
	/// @details    Provides an example of how a basic class can be declared and 
	///             Doxygen-documented.
	///
	class FileIO
	{
		public:
  			FileIO();    ///< Constructor.
  			~FileIO();   ///< Destructor.
			void ReadBitmap(std::string inputfile, double p_bmp_array[XMAX][YMAX], int* xdimension, int* ydimension);
			void GetDimensions(std::string inputfile, int* xdimension, int* ydimension);  
			void WritePPM(std::string outputfile, double p_bmp_array[XMAX][YMAX], int* xdimension, int* ydimension);
			void ConvertBitmap(double bitmap[XMAX][YMAX], int* xdimension, int* ydimension);
		private:
	};

}   //  namespace PsCourseworkI


//#endif  //  #ndef PSCOURSEWORKI_DEMOCLASS_HPP

