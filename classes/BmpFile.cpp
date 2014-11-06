//////////////////////////////////////////////////////////////////////////////
/// @file     BmpFile.cpp
///
/// @brief    Implementation of class BmpFile.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "BmpFile.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <stdexcept>
#include <fstream>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Provides access to bitmap files as specified in the coursework
	///             handout.
	///
	/// @param      filename  Name of file to open.
	///
	/// @post       Bitmap file has been loaded into a 2D array in memory.
	///
	/// @exception  std::runtime_error  File could not be opened.
	///
	BmpFile::BmpFile(std::string bmp_filename)
		: m_array()
	{
		std::cout << "loading bitmask file \"" << bmp_filename << "\"" << std::endl;

		//  open input stream 
		std::ifstream file_reader(bmp_filename.c_str());
		
  		//  check that input file is valid
		if (! file_reader.is_open())
		{
			throw std::runtime_error("failed to open bitmap file");
		}
		
  		//  first two integers are bitmap x and y sizes
		unsigned int height = 0;
		unsigned int width = 0;
		file_reader >> height >> width;
		
		std::cout << "bitmask size: " << height << " x " << width << std::endl;
		//  validate dimensions
		if (0 == height || 0 == width)
		{
			throw std::runtime_error("found zero x or y size in bitmap file");
		}
		
		//  prep the array
		Size bmp_size(height, width);
		m_array.Resize(bmp_size);
		
		//  read each subsequent field into the corresponding element of the array.
		for (unsigned int j=0; j<width; j++)
		{
			for (unsigned int i=0; i<height; i++)
			{
				file_reader >> m_array(i, j);
			}
		}		
	}

}   //  namespace PsCourseworkI
