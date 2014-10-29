//////////////////////////////////////////////////////////////////////////////
/// @file       main.cpp
///
/// @brief      Provides main() for Programming Skills Group Practical.
///


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "DemoClass.hpp"
#include "AppArgs.hpp"
#include "AppConfig.hpp"
#include "Landscape.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>


//////////////////////////////////////////	////////////////////////////////////
/// @brief      Program entry point.
///
/// @details    Runs the simulation of puma and hare populations.
///
/// @param      argc Standard argument count.
/// @param      argv Standard argument list.
///
int main(int argc, char* argv[])
{
	using namespace PsCourseworkI;
	
	try 
	{
		//  parse command line
		AppArgs args(argc, argv);

		//  load configuration from file
		AppConfig cfg(args.CfgFilename());
		
		//  initialise the landscape
		Landscape landscape(cfg);  //  include pgm arrays for land/water and initial population densities

        for (int i=0; i<cfg.GetTT(); ++i)
        {
			landscape.DoStep();
			
			if (0 == i % cfg.GetT())
			{
				//  write regular output here.
			}
        }
		
		//  do final output here.
    }
	catch (std::exception const& e) 
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}

