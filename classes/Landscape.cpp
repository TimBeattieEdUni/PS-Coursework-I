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
		: m_landscape_size(cfg.GetNx(), cfg.GetNy())
		, m_array(Size(cfg.GetNx() + 2, cfg.GetNy() + 2))
	{
		std::cout << "landscape size: " << m_landscape_size.m_x << " x " << m_landscape_size.m_y << std::endl;
		
		InitHalo();
		ApplyLandWaterMap(bmp);
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Advances the simulation by one time step.
	///
	void Landscape::DoStep()
	{
		std::cout << "updating landscape" << std::endl;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Reads the given land/water bitmap and applies it to the
	///               array of cells, taking account of the halo.
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
		unsigned int size_x = std::min(bmp_array.GetSize().m_x, m_landscape_size.m_x);
		unsigned int size_y = std::min(bmp_array.GetSize().m_y, m_landscape_size.m_y);

		std::cout << "bitmap-landscape matching area: " << size_x << " x " << size_y << std::endl;

		//  write land/water flags into landscape cells inside the halo
		for (unsigned int i = 0; i < size_x; ++i)
		{
			for (unsigned int j = 0; j < size_y; ++j)
			{
				m_array(i + 1, j + 1).m_land = static_cast<bool>(bmp_array(i, j));
			}
		}		
	}

	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Sets the population density of pumas in each landscape cell
	///               to a random value between 0 and 1.
	///
	void Landscape::ApplyRandomPumas()
	{
		for (unsigned int i = 0; i < m_landscape_size.m_x; ++i)
		{
			for (unsigned int j = 0; j < m_landscape_size.m_y; ++j)
			{
				if (m_array(i + 1, j + 1).m_land)
				{
					m_array(i + 1, j + 1).m_pumas = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) ;
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
		for (unsigned int i = 0; i < m_landscape_size.m_x; ++i)
		{
			for (unsigned int j = 0; j < m_landscape_size.m_y; ++j)
			{
				if (m_array(i + 1, j + 1).m_land)
				{
					m_array(i + 1, j + 1).m_hares = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) ;
				}
			}
		}				
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details      Creates a halo of water cells surrounding the landscape.
	///
	void Landscape::InitHalo()
	{
		Cell const water(false, 0.0, 0.0);
		
		unsigned int size_x = m_array.GetSize().m_x;
		unsigned int size_y = m_array.GetSize().m_y;
		
		for (unsigned int i = 0; i < size_x; ++i)
		{
			m_array(i, 0)           = water;
			m_array(i, size_x - 1)  = water;
		}
		
		for (unsigned int j = 0; j < size_y; ++j)
		{
			m_array(0, j)           = water;
			m_array(size_y - 1, j)  = water;
		}
	}
	
}   //  namespace PsCourseworkI
