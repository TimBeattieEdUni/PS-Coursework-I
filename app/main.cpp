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
#include "LandscapePpmWriter.hpp"
#include "BmpFile.hpp"
#include "PpmFile.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <sstream>
#include <ctime>


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

	// start clock for total time
	clock_t ttotal;
	ttotal=std::clock();


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

		//  initialise PPM file writer
		LandscapePpmWriter ls_writer(landscape);


		//  run the simulation
        for (unsigned int i=0; i<cfg.GetTT(); ++i)
        {
			//  write current state to PPM file regularly
			if (0 == i % cfg.GetT())
			{
				//  create output filename
				std::stringstream filename_ss;
				filename_ss << "output/output" << i << ".ppm";

				//  write current state of the landscape to PPM file
				ls_writer.Write(filename_ss.str());
			}

			landscape.Update();
        }


		std::cout << "simulation complete" << std::endl;

		//timings:
		ttotal=std::clock()-ttotal;
  		std::cout << "Total CPU time spend=" <<static_cast<double>(ttotal)/CLOCKS_PER_SEC<<std::endl;



    }
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
