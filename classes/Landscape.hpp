//////////////////////////////////////////////////////////////////////////////
/// @file     Landscape.hpp
///
/// @brief    Interface declaration for class Landscape.
///


#ifndef PSCOURSEWORKI_LANDSCAPE_HPP
#define PSCOURSEWORKI_LANDSCAPE_HPP


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "AppConfig.hpp"
#include "Array2D.hpp"
#include "BmpFile.hpp"
#include "Cell.hpp"


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief
	///
	/// @details
	///
	/// @invariant
	///
	class Landscape
	{
		public:
			Landscape(AppConfig const& cfg, BmpFile const& bmp);   ///< Constructor.

			void DoStep();                                ///< Updates the landscape by one step.
		
			void ApplyLandWaterMap(BmpFile const& bmp);   ///< Applies land/water bitmap.
			void ApplyRandomPumas();                      ///< Applies random puma population density.
			void ApplyRandomHares();                      ///< Applies random hare population density.
		

		private:
			Landscape();                                  ///< Default Constructor.
			Landscape(Landscape const& rhs);              ///< Copy constructor.
			Landscape& operator=(Landscape const& rhs);   ///< Assignment operator.
				
			typedef Array2D<Cell> LsArray;                ///< Type for the landscape array.
			LsArray m_landscape;                          ///< The landscape itself.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_LANDSCAPE_HPP
