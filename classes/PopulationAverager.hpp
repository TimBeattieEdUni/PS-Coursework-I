//////////////////////////////////////////////////////////////////////////////
/// @file     PopulationAverager.hpp
///
/// @brief    Interface declaration for class PopulationAverager.
///


#ifndef PSCOURSEWORKI_POPULATIONAVERAGER_HPP
#define PSCOURSEWORKI_POPULATIONAVERAGER_HPP


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "Landscape.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Calculates the avarage population value of hares and pumas.
	///
	/// @details    Returns a Population avarage value of Cells.
	///
	class PopulationAverager
	{
		public:
			PopulationAverager(Landscape::LsArray const& population);       ///< Constructor.

			double GetAvgHares() { return m_avg_hares; }   ///< Getter.
			double GetAvgPumas() { return m_avg_pumas; }   ///< Getter.

		private:
			PopulationAverager(PopulationAverager const& rhs);              ///< Copy constructor.
			PopulationAverager& operator=(PopulationAverager const& rhs);   ///< Assignment operator.

			double m_avg_hares;   ///< Average hare population.
			double m_avg_pumas;   ///< Average puma population.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_POPULATIONAVERAGER_HPP
