//////////////////////////////////////////////////////////////////////////////
/// @file     Landscape.cpp
///
/// @brief    Implementation of class Landscape.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "Landscape.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <algorithm>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Sets up the 2D array of landscape cells using sizes obtained
	///             from the app's configuration.  Adds halo cells surrounding the
	///             landscape.
	///
	/// @param      cfg  Application configuration.
	///
	/// @post       Landscape array has been initialised.
	///
	Landscape::Landscape(AppConfig const& cfg, BmpFile const& bmp)
		: m_landscape(Size(cfg.GetNx() + 2, cfg.GetNy() + 2))
	{
		std::cout << "landscape size:      " << m_landscape.GetSize().m_x << " x " << m_landscape.GetSize().m_y << std::endl;
		
		ApplyLandWaterMap(bmp);
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Advances the simulation by one time step.
	///
	void Landscape::DoStep()
	{
		std::cout << "time step" << std::endl;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Reads the given land/water bitmap and applies it to the
	///               array of cells.
	///
	/// @param        bmp  Land/water bitmap.
	///
	/// @post         The given land/water bitmap has been applied to the landscape.
	///
	void Landscape::ApplyLandWaterMap(BmpFile const& bmp)
	{
		BmpFile::BmpArray const& bmp_array = bmp.GetArray();
		
		std::cout << "land/water map size: " << bmp_array.GetSize().m_x << " x " << bmp_array.GetSize().m_y << std::endl;
		
		//  handle non-matching bmp and landscape sizes gracefully
		unsigned int size_x = std::min(bmp_array.GetSize().m_x, m_landscape.GetSize().m_x);
		unsigned int size_y = std::min(bmp_array.GetSize().m_y, m_landscape.GetSize().m_y);
		
		//  write land/water flags into landscape cells
		for (unsigned int i = 0; i < size_x; ++i)
		{
			for (unsigned int j = 0; j < size_y; ++j)
			{
				m_landscape(i, j).m_land = static_cast<bool>(bmp_array(i, j));
			}
		}		
	}

	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Sets the population density of pumas in each landscape cell
	///               to a random value between 0 and 1.
	///
	void Landscape::ApplyRandomPumas()
	{
		for (unsigned int i = 1; i < m_landscape.GetSize().m_x - 1; ++i)
		{
			for (unsigned int j = 1; j < m_landscape.GetSize().m_y - 1; ++j)
			{
				if (m_landscape(i, j).m_land)
				{
					m_landscape(i, j).m_puma_d = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) ;
					std::cout << m_landscape(i, j).m_puma_d << std::endl;
				}
			}
		}				
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details      Sets the population density of hares in each landscape cell
	///               to a random value between 0 and 1.
	///
	void Landscape::ApplyRandomHares()
	{
		for (unsigned int i = 1; i < m_landscape.GetSize().m_x - 1; ++i)
		{
			for (unsigned int j = 1; j < m_landscape.GetSize().m_y - 1; ++j)
			{
				if (m_landscape(i, j).m_land)
				{
					m_landscape(i, j).m_hare_d = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) ;
					std::cout << m_landscape(i, j).m_hare_d << std::endl;
				}
			}
		}				
	}

}   //  namespace PsCourseworkI
