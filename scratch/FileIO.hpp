//////////////////////////////////////////////////////////////////////////////
/// @file     FileIO.hpp
///
/// @brief    Interface declaration for class FileIO.
///


//#ifndef GROUP_PRACTICAL_DEMOCLASS_HPP
//#define GROUP_PRACTICAL_DEMOCLASS_HPP

#include "params.hpp"

#include <iostream>

namespace GroupPractical
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

		private:
	};

}   //  namespace GroupPractical


//#endif  //  #ndef GROUP_PRACTICAL_DEMOCLASS_HPP

