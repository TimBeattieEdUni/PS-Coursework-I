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
	/// @details    Sets up the 2D array of landscape cells.
	///
	/// @param      cfg  Application configuration.
	///
	/// @post       Landscape array has been initialised.
	///
	Landscape::Landscape(AppConfig const& cfg, BmpFile const& bmp)
		: m_landscape(Size(cfg.GetNx(), cfg.GetNy()))
	{
		(void) cfg;

		std::cout << "landscape size:      " << m_landscape.GetSize().m_x << " x " << m_landscape.GetSize().m_y << std::endl;
		
		ApplyLandWaterMap(bmp);
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Describe object destruction here.
	///
	/// @param      Describe parameters here, one line each.
	///
	/// @pre        List what must be true before this function is called.
	/// @post       List what is guaranteed to be true after this function returns.
	///
	/// @exception  None; this is a destructor.
	///
	Landscape::~Landscape()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
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

}   //  namespace PsCourseworkI
