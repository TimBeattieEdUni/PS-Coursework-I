//////////////////////////////////////////////////////////////////////////////
/// @file     Cell.hpp
///
/// @brief    Interface declaration for class Cell.
///


#ifndef PSCOURSEWORKI_CELL_HPP
#define PSCOURSEWORKI_CELL_HPP


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Represents one cell in the landscape.
	///
	/// @details    Stores hare and puma population densities and land/water 
	///             status.  Knows about its north/south/east/west neighbours.
	///
	class Cell
	{
		public:
			Cell();    ///< Constructor.
			~Cell();   ///< Destructor.

		private:
			Cell(Cell const& rhs);              ///< Copy constructor.
			Cell& operator=(Cell const& rhs);   ///< Assignment operator.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_CELL_HPP
