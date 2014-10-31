//////////////////////////////////////////////////////////////////////////////
/// @file       main.cpp
///
/// @brief      Provides main() for Programming Skills Group Practical.
///


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "AppArgs.hpp"
#include "AppConfig.hpp"
#include "Landscape.hpp"
#include "BmpFile.hpp"
#include "PpmFile.hpp"

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
		AppConfig cfg(args.GetCfgFilename());
		
		//  load land/water map from file
		BmpFile map_bmp(args.GetMapFilename());
		
		//  initialise the landscape
		Landscape landscape(cfg, map_bmp);

		landscape.ApplyRandomPumas();
		landscape.ApplyRandomHares();

		//  run the simulation
        for (unsigned int i=0; i<cfg.GetTT(); ++i)
        {
			landscape.DoStep();
			
			if (0 == i % cfg.GetT())
			{
				//  write regular output here.
				
				// write landscape to Plain ASCii PPM File (add functionality to append index)  				
				PpmFile wrt_ppm(cfg, i /*WHAT_IS_TO_BE_PRINTED*/);
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

