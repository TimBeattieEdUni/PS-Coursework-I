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
#include <iomanip>


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
	using namespace PsCourseworkI;

	// get the starting time
	time_t t_start=time(NULL);



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
				filename_ss << "output" << i << ".ppm";

				//  write current state of the landscape to PPM file
				ls_writer.Write(filename_ss.str());
			}

			//  do update and report time
			landscape.Update();
			double sim_time = i * cfg.Getdt();
			std::cout << "landscape updated to time " << sim_time << " months" << std::endl;
        }

		std::cout << "simulation complete" << std::endl;

        // get the ending time
        time_t t_end=time(NULL);
        double t_simulation=difftime(t_end, t_start); // getting elapsed time till start

        //splitting the time in hours minutes and seconds:
        unsigned int hours=static_cast<unsigned int>(t_simulation/3600);
        unsigned int minutes=static_cast<unsigned int>(t_simulation/60);
        double seconds=t_simulation-hours*3600-minutes*60;

  		std::cout << "Elapsed time= "<<hours<<" h "<<minutes<<" min "<<seconds<<" s "<<std::endl;
    }
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
