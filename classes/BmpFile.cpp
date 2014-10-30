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
	BmpFile::BmpFile(std::string filename)
		: m_array()
	{
		//  open input stream 
		std::ifstream file_reader(filename.c_str());
		
  		//  check that input file is valid
		if ( !file_reader.is_open() )
		{
			throw std::runtime_error("failed to open bitmap file");
		}
		
  		//  first two integers are bitmap x and y sizes
		unsigned int size_x = 0;
		unsigned int size_y = 0;
		file_reader >> size_x >> size_y;
		
		//  validate dimensions
		if (0 == size_x || 0 == size_y)
		{
			throw std::runtime_error("bitmap had zero for x or y size");
		}
		
		//  prep the array
		Size bmp_size(size_x, size_y);
		m_array.Resize(bmp_size);
		
		//  read each subsequent field into the corresponding element of the array.
		for (unsigned int i=0; i<size_x; i++)
		{
			for (unsigned int j=0; j<size_y; j++)
			{
				file_reader >> m_array(i, j);
			}
		}		
	}

}   //  namespace PsCourseworkI
