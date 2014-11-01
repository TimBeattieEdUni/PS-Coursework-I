//////////////////////////////////////////////////////////////////////////////
/// @file     PpmFile.cpp
///
/// @brief    Implementation of class PpmFile.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "PpmFile.hpp"
#include "AppConfig.hpp"



//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Prepares a file for PPM output, including writing the magic
	///             number to the start of the file.  
	///
	/// @param      filename  Name of file for writing.
	///
	/// @exception  std::runtime_error  File could not be opened for writing.
	///
	/// @todo       Class PpmFile is hard-coded to RGB pixel values of 255,255,255.
	///
	PpmFile::PpmFile(std::string const& filename, Size const& size, unsigned int const max_rgb_val)
		: m_max_rgb_val(max_rgb_val)
		, m_pixels_written(0)
		, m_size(size)
		, m_out_file(filename.c_str())
	{
		std::cout << "preparing PPM file: \"" << filename << "\"" << std::endl; 

  		//  check that output file is valid
		if ( !m_out_file.is_open() )
		{
			throw std::runtime_error("failed to open ppm file for writing");
		}

		//  write header: magic number, image size, and max pixel component value
		m_out_file << "P3" << "\n";
		m_out_file << size.m_y << " " << size.m_x << "\n";
		m_out_file << m_max_rgb_val << "\n";
	}

	
	void PpmFile::WritePixel(Pixel const& pixel)
	{
		m_out_file << pixel.m_red << " " << pixel.m_green << " " << pixel.m_blue << "\t";
		
		++m_pixels_written;

		//  new line after every 4 pixels to stay within PPM P3 format's limit of 70 chars per line
		if (0 == (m_pixels_written % 4))
		{
			m_out_file << "\n";
		}
	}
	

	void PpmFile::Finalise()
	{
		m_out_file << "\n";
		m_out_file.close();
		
		std::cout << "PPM file closed; " << m_pixels_written << " pixels written" << std::endl;
		
		if (m_pixels_written != (m_size.m_x * m_size.m_y))
		{
			throw std::logic_error("wrong number of pixels written; PPM file will be corrupt");
		}
	}

}   //  namespace PsCourseworkI
