//////////////////////////////////////////////////////////////////////////////
/// @file     Cell.hpp
///
/// @brief    Interface declaration for class Cell.
///


#ifndef PSCOURSEWORKI_CELL_HPP
#define PSCOURSEWORKI_CELL_HPP


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <vector>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Represents one cell in the landscape.
	///
	/// @details    Stores hare and puma population densities and land/water 
	///             status.
	///
	class Cell
	{
		public:
			Cell();    ///< Constructor.

			bool    m_land;     ///< Land/water flag.
			double  m_hare_d;   ///< Population density of hares.
			double  m_puma_d;   ///< Population density of pumas.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_CELL_HPP
