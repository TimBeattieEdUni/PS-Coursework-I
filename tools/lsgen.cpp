//////////////////////////////////////////////////////////////////////////////
/// @file       lsgen.cpp
///
/// @brief      Provides main() for the landscape generator tool.
///
/// @details    The landscape generator creates an all-land landscape file 
///             with the x and y dimensions given on the command line.
///



//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <fstream>
#include <sstream>


//////////////////////////////////////////////////////////////////////////////
/// @brief      Program entry point.
///
/// @details    
///
/// @param      argc Standard argument count.
/// @param      argv Standard argument list.
///
int main(int argc, char* argv[])
{
	if (3 != argc)
	{
		std::cout << "usage: lsgen <width> <height>" << std::endl;
		return -1;
	}

	std::stringstream converter;
	unsigned int width   = 0;
	unsigned int height  = 0;
	
	converter << argv[1] << " " << argv[2];
	converter >> width;
	converter >> height;

	std::stringstream filename_ss; 
	filename_ss << "all-land-" << width << "x" << height << ".dat";
	
	std::ofstream out_file(filename_ss.str().c_str());
	out_file << width << " " << height << "\n";
	
	for (unsigned int i = 0; i < height; ++i)
	{
		for (unsigned int j = 0; j < width; ++j)
		{
			out_file << "1 ";
		}
		
		out_file << "\n";
	}

	std::cout << "created " << width << " x " << height << " landscape in file \"" << filename_ss.str() << "\""<< std::endl;
}

