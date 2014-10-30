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

		std::cout << "applying land/water map to landscape" << std::endl;
		
		BmpFile::BmpArray const& bmp_array = bmp.GetArray();
		
		if (! (bmp_array.GetSize() == m_landscape.GetSize()))
		{
			throw std::runtime_error("size mismatch between land/water bitmap and landscape");
		}

		//  write land/water flags into landscape cells
		for (unsigned int i = 0; i < cfg.GetNx(); ++i)
		{
			for (unsigned int j = 0; j < cfg.GetNy(); ++j)
			{
				m_landscape(i, j).m_land = static_cast<bool>(bmp_array(i, j));
			}
		}
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

}   //  namespace PsCourseworkI
