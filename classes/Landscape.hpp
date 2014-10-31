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
			typedef Array2D<Cell> LsArray;                ///< Type for the landscape array.

			Landscape(AppConfig const& cfg, BmpFile const& bmp);   ///< Constructor.

			void DoStep();                                ///< Updates the landscape by one step.
		
			void ApplyLandWaterMap(BmpFile const& bmp);   ///< Applies land/water bitmap.
			void ApplyRandomPumas();                      ///< Applies random puma population density.
			void ApplyRandomHares();                      ///< Applies random hare population density.
		
			LsArray const& GetArray() const { return m_array; }   ///< Getter.

		private:
			Landscape();                                  ///< Default Constructor.
			Landscape(Landscape const& rhs);              ///< Copy constructor.
			Landscape& operator=(Landscape const& rhs);   ///< Assignment operator.
				
			void InitHalo();                              ///< Initialises the halo.
		
			Size m_landscape_size;                        ///< Landscape size without halo.
			LsArray m_array;                              ///< Landscape array including halo.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_LANDSCAPE_HPP
