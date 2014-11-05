//////////////////////////////////////////////////////////////////////////////
/// @file     PopulationAverager.cpp
///
/// @brief    Implementation of class PopulationAverager.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "PopulationAverager.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
//#include <iostream>
//#include <fstream>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Stores a reference to the given population.
	///
	/// @param      The population to be calculated/returned.
	///
	PopulationAverager::PopulationAverager(Landscape::LsArray const& population)
		: m_avg_hares(0.0)
		, m_avg_pumas(0.0)
	{
		Size ls_size = population.GetSize();
		double totalHares = 0.0;
		double totalPumas = 0.0;
		
		unsigned int cell_counter = 0;
		
		//  sum all hare and puma values
		for (unsigned int j = 0; j < ls_size.m_y; ++j)
		{
			for (unsigned int i = 0; i < ls_size.m_x; ++i)
			{				
				// ignore water
				if (population(i, j).m_land)
				{
					totalHares += population(i, j).m_hares;
					totalPumas += population(i, j).m_pumas;
					cell_counter++;
				}				
			}
		}

		//  ignore rounding errors; values tend to stay within one order of magnitude
		if (cell_counter > 0)
		{
			m_avg_pumas = totalPumas / (double)cell_counter;
			m_avg_hares = totalHares / (double)cell_counter;
		}
		else
		{
			//  handle special case of all-water landscape with values of zero
			m_avg_pumas = 0.0;
			m_avg_hares = 0.0;
		}
	}

}   //  namespace PsCourseworkI
