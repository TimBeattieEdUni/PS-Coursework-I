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
	/// @brief      Landscape for population simulation.
	///
	/// @details    Implements a population simulation of pumas and hares on a 
	///             rectangular grid of cells which can be either land or water.
	///
	class Landscape
	{
		public:
			typedef Array2D<Cell> LsArray;                ///< Type for the landscape array.

			/// Constructor from configuration and land/water bitmask.
			Landscape(AppConfig const& cfg);

			LsArray const& GetArray() const;              ///< Getter.
			void Update();                                ///< Updates the landscape by one time step.
		
			///< Applies land/water bitmask.
			void ApplyLandWaterMask(BmpFile::BmpArray const& bmp);
		
			void ApplyRandomPumas();                      ///< Applies random puma population density.
			void ApplyRandomHares();                      ///< Applies random hare population density.
		
		private:
			Landscape(Landscape const& rhs);              ///< Copy constructor.
			Landscape& operator=(Landscape const& rhs);   ///< Assignment operator.
				
			void InitHalos();                             ///< Initialises array halos.
				
			bool m_bswap_arrays;                          ///< Indicates which array is current/new.
			Size m_landscape_size;                        ///< Landscape size without halo.
			AppConfig const& m_cfg;                       ///< Application configuration.
			LsArray m_array_old;                          ///< Old landscape array (including halo).
			LsArray m_array_new;                          ///< New landscape array (including halo).
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_LANDSCAPE_HPP
