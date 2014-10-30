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

	void FileIO::GetDimensions(std::string inputfile, int* xdimension, int* ydimension)
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
	/// @details Converts land/water array to array that makes sense with final 
	///	     PPM output.                             
	///		Before: land = 1; water = 0
	///		After: 	land = 255; water = 0
	/// @param 	
	///
	/// @pre
	/// @post
	///
	/// @exception
	///

	void FileIO::ConvertBitmap(double bitmap[XMAX][YMAX], int* xdimension, int* ydimension)
	{

		//We will use blue values to represent the land. 
		for (int i=0; i<*xdimension; i++)
		{
			for (int j=0; j<*ydimension; j++)
			{
			//Set the 'water' to be maximum strength blue colour
				if ( bitmap[i][j] == 0 ) 
				{
					bitmap[i][j] = 255; 
				}
			//Set the 'island' to be black
				else if ( bitmap[i][j] == 1 ) 
				{
					bitmap[i][j] = 0; 
				}
			}
		}

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

	void FileIO::ReadBitmap(std::string inputfile, double p_bmp_array[XMAX][YMAX], int* xdimension, int* ydimension)
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
	
	//////////////////////////////////////////////////////////////////////////////
	/// @details Writes image of dimension xdimension x ydimension in PPM format
	///          to file specified in argument 1.              
	/// @param 	
	///
	/// @pre
	/// @post
	///
	/// @exception
	///
	void FileIO::WritePPM(std::string outputfile, double p_bmp_array[XMAX][YMAX], int* xdimension, int* ydimension)
	{
		//Open output stream 
		std :: ofstream file_writer(outputfile.c_str());
		
		//Check that inputfile is valid
		if ( !file_writer.is_open() )
		{
			std::cout << "I/O Error: Could not open file " << outputfile << std::endl;
			return;
		}

		//Write out PPM 'magic number'
		file_writer << "P3" << std::endl;	

		//Write the dimensions of the image (width then height)
		file_writer << *ydimension << " " << *xdimension << std::endl;

		//Write the dimensions of the image (width then height)
		file_writer << "255" << std::endl;  
		
		//Write the array out as raster image, line by line. 
		for (int i=0; i<*xdimension; i++)
		{
			for (int j=0; j<*ydimension; j++)
			{
				file_writer << "0 0 " << p_bmp_array[i][j] << "\t";
			}
			
			file_writer << std::endl;
		}

	}
}   //  namespace PsCourseworkI

