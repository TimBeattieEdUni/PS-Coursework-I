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
	/// @details    Writes our passed array out to a Plain PPM file as specified        
	///		in the courseword handout.
	///
	/// @param      cfg           Configuration File.   
	///             ppm_filename  Name of file to open.
	///
	/// @post       Passed Array has been written to Plain PPM file.       
	///
	/// @exception  std::runtime_error  File could not be opened.
	///
	PpmFile::PpmFile(AppConfig const& cfg, unsigned int time_step/*, std::string ppm_filename*/ /*,WHAT_IS_TO_BE_PRINTED */ )
//		: m_array()
//	void FileIO::WritePPM(std::string outputfile, double p_bmp_array[XMAX][YMAX], int* xdimension, int* ydimension)
	{
		//  define the name of the output file
		std::stringstream ss(std::stringstream::in | std::stringstream::out);
		ss << "output/output";
		ss << time_step;
		std::string ppm_filename = ss.str();	
		
		std::cout << "writing landscape to file \"" << ppm_filename << "\"" << std::endl; 

		//  open output stream 
		std::ofstream file_writer(ppm_filename.c_str());
		
  		//  check that output file is valid
		if ( !file_writer.is_open() )
		{
			throw std::runtime_error("failed to open ppm file for writing");
		}

		(void) cfg;

		//  write PPM configuration data
		file_writer << "P3" << std::endl;				//  magic number	
		file_writer << cfg.GetNy() << " " << cfg.GetNx() << std::endl;	//  image dimensions (width height)
		file_writer << "255" << std::endl; 				//  pixel value range 
	
		//  write the array out as raster image.
		for (unsigned int i=0; i<cfg.GetNx(); i++)
		{
			for (unsigned int j=0; j<cfg.GetNy(); j++)
			{
				file_writer << "0 0 0" << /* WHAT_IS_TO_BE_PRINTED << */ "\t";
			}
			
			file_writer << std::endl;
		}

	}
/*
		if (0 == size_x || 0 == size_y)
		{
			throw std::runtime_error("bitmap had zero for x or y size");
		}
		
*/
}   //  namespace PsCourseworkI
