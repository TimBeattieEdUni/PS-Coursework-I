//////////////////////////////////////////////////////////////////////////////
/// @file     LandscapePpmWriter.cpp
///
/// @brief    Implementation of class LandscapePpmWriter.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "LandscapePpmWriter.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <fstream>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Stores a reference to the given landscape.
	///
	/// @param      The landscape to be written.
	///
	LandscapePpmWriter::LandscapePpmWriter(Landscape& landscape)
		: m_landscape(landscape)
	{

	}

	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Writes the landscape of cells to a PPM file with the given
	///               filename, leaving out the halo.
	///
	/// @param        filename  PPM filename.
	///
	/// @post         All cells in the landscape have been written to the PPM file.
	///
	/// @exception    std::runtime_error The file could not be opened or written to.
	///
	void LandscapePpmWriter::Write(std::string const& filename)
	{
		std::cout << "writing landscape to \"" << filename << "\"" << std::endl; 

		unsigned int const rgb_max = 255;
		
		Landscape::LsArray const& ls_array = m_landscape.GetArray();
		Size ls_size = ls_array.GetSize();
		
		Size size_nohalo(ls_size.m_x - 2, ls_size.m_y - 2);
		
		PpmFile ppm_file(filename, size_nohalo, rgb_max);		
		for (unsigned int i = 1; i < ls_size.m_x - 1; ++i)
		{
			for (unsigned int j = 1; j < ls_size.m_y - 1; ++j)
			{
				Cell const& cell = ls_array(i, j);
				unsigned char blue_val = cell.m_land ? 0 : 255;
				ppm_file.WritePixel(Pixel(cell.m_pumas, cell.m_hares, blue_val));
			}
		}

		ppm_file.Finalise();
	}

}   //  namespace PsCourseworkI
