//////////////////////////////////////////////////////////////////////////////
/// @file     PopulationAverager.hpp
///
/// @brief    Interface declaration for class PopulationAverager.
///


#ifndef PSCOURSEWORKI_PopulationAverager_HPP
#define PSCOURSEWORKI_PopulationAverager_HPP


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
			PopulationAverager(Landscape::LsArray& population);    ///< Constructor.
			
			void Write(double& totalPuma, double& totalHare);     ///< Returns Cell's population.

		private:
			PopulationAverager(PopulationAverager const& rhs);              ///< Copy constructor.
			PopulationAverager& operator=(PopulationAverager const& rhs);   ///< Assignment operator.
					
			Landscape::LsArray& m_population;   ///< The population to be stored.

	};
	
}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_PopulationAverager_HPP
