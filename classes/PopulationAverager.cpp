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
	PopulationAverager::PopulationAverager(Landscape::LsArray& population)
		: m_population(population)
	{
		
	}

	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Calculates and returns the average population.
	///
	/// @param        double puma/hare by ref, thus can be stored 
	///
	/// @post         
	///
	/// @exception    
	///
	/// 
	///
	void PopulationAverager::Write(double& totalPuma, double&totalHare)
	{
		std::cout << std::endl; 

		
		//Landscape::LsArray const& ls_array = m_population.GetArray();
		//Landscape::LsArray const& ls_array

		
		Size ls_size = m_population.GetSize();
		totalHare = 0.0;
		totalPuma = 0.0;
		
		unsigned int cell_counter = 0;
			
		for (unsigned int j = 0; j < ls_size.m_y; ++j)
		{
			for (unsigned int i = 0; i < ls_size.m_x; ++i)
			{

				if(m_population(i,j).m_land)
				{// the avarage population does not take into account the unpopulatable regions, i.e. water
					totalHare += m_population(i,j).m_hares;
					totalPuma += m_population(i,j).m_pumas;
					cell_counter++;
				}
				
			}
		}
		if(cell_counter > 0)
		{
			totalPuma = totalPuma/(double)cell_counter;
			totalHare = totalHare/(double)cell_counter;
		
			//std::cout << "The avarage number of pumas per cell is: "<< totalPuma << std::endl; 
			//std::cout << "The avarage number of hares per cell is: "<< totalHare << std::endl;
		} 
		else
		{
			std::cout << "There is no land to calulate on. " << std::endl;
		}
	}

}   //  namespace PsCourseworkI
