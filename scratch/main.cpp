//////////////////////////////////////////////////////////////////////////////
/// @file       main.cpp
///
/// @brief      Provides main() for Programming Skills Group Practical.
///


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "FileIO.hpp"
#include "params.hpp"

//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>


//////////////////////////////////////////////////////////////////////////////
/// @brief      Program entry point.
///
/// @details    Runs the simulation of puma and hare populations.
///
/// @param      argc Standard argument count.
/// @param      argv Standard argument list.
///
int main(int argc, char* argv[])
{
	(void) argc;
	(void) argv;
	
	double landscape [XMAX][YMAX];
	
	int nx = 0;
	int ny = 0;
	
	GroupPractical::FileIO read;
	(void) read;
	
	read.GetDimensions("small.dat", &nx, &ny);
	read.ReadBitmap("small.dat", landscape, &nx, &ny);
	
	std::cout << "nx = " << nx << std::endl;
	std::cout << "ny = " << ny << std::endl;
	
	return 0;
}

