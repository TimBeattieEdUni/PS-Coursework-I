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
#include <sys/time.h>


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

	//fields for timing
	timeval t_start,t_end;
	//set starting time
	gettimeofday(&t_start,NULL); // on windows OS use: GetSystemTime



	try
	{
		//  parse command line
		AppArgs args(argc, argv);

		//  load configuration from file
		AppConfig cfg(args.GetCfgFilename());

		//  load land/water map from file
		BmpFile land_water_mask(args.GetMapFilename());

		//  initialise the landscape
		Landscape landscape(cfg);
		landscape.ApplyLandWaterMask(land_water_mask.GetArray());
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

        // timing:
        gettimeofday(&t_end,NULL);

        unsigned int seconds_diff=(t_end.tv_sec - t_start.tv_sec);
        unsigned int microseconds_diff=(t_end.tv_usec - t_start.tv_usec);

        //transforming the seconds and microseconds output in usaual format (h,min,sec,msec,usec)
        unsigned int hours=(seconds_diff/3600);
        unsigned int minutes=(seconds_diff/60);
        unsigned int seconds=seconds_diff-hours*3600-minutes*60;

        unsigned int milliseconds=(microseconds_diff/1000);
        unsigned int microseconds=microseconds_diff-1000*milliseconds;

        //timing output
        std::cout << "Elapsed time= "<<hours<<" h "<<minutes<<" min "<<seconds<<" sec "<<milliseconds<<" msec "<<microseconds<<" usec "<<std::endl;




    }
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
