//////////////////////////////////////////////////////////////////////////////
/// @file     FileIO.cpp
///
/// @brief    Implementation of class FileIO.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "FileIO.hpp"
#include "params.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <fstream>
#include <string>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details
	///
	/// @param
	///
	/// @pre
	/// @post
	///
	/// @exception
	///
	FileIO::FileIO()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	//////////////////////////////////////////////////////////////////////////////
	/// @details    Cleans up any resources.
	///
	/// @pre
	/// @post
	///
	FileIO::~FileIO()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details Stores dimensions of bitmap file passed to argument 1 in       
	///		arguments 2 and 3.                             
	/// @param 	
	///
	/// @pre
	/// @post
	///
	/// @exception
	/// 

	void GetDimensions(std::string inputfile, int* xdimension, int* ydimension)
	{
		//Open input stream 
		std :: ifstream file_reader(inputfile.c_str());
		
		//Check that inputfile is valid
		if ( !file_reader.is_open() )
		{
			std::cout << "I/O Error: Could not open file " << inputfile << std::endl;
			return;
		}

		//Read first to fields into variables passed for dimensions
		file_reader >> *xdimension >> *ydimension;

		return;
	}

	//////////////////////////////////////////////////////////////////////////////
	/// @details Reads array passed to argument 1 to array passed to argument 2,
	///		stores image dimensons in arguments 3 and 4.
	/// @param 	
	///
	/// @pre
	/// @post
	///
	/// @exception
	///

	void ReadBitmap(std::string inputfile, double p_bmp_array[XMAX][YMAX], int* xdimension, int* ydimension)
	{
		//Open input stream 
		std :: ifstream file_reader(inputfile.c_str());
		
		//Check that inputfile is valid
		if ( !file_reader.is_open() )
		{
			std::cout << "I/O Error: Could not open file " << inputfile << std::endl;
			return;
		}

		//Read first to fields into variables passed for dimensions
		file_reader >> *xdimension >> *ydimension;

		//Read all subsequent fields into the corresponding element of the passed array.              .
		for (int i=0; i<*xdimension; i++)
		{
			for (int j=0; j<*ydimension; j++)
			{
				file_reader >> p_bmp_array[i][j];
			}
		}

	}
	
}   //  namespace PsCourseworkI

