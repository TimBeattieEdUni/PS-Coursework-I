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
			Cell();             ///< Default constructor.
		
			Cell(bool land, double hares, double pumas);   ///< Constructor from values.

			bool    m_land;     ///< Land/water flag.
			double  m_hares;    ///< Population density of hares.
			double  m_pumas;    ///< Population density of pumas.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_CELL_HPP
