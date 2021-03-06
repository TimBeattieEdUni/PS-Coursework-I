//////////////////////////////////////////////////////////////////////////////
/// @file       main.cpp
///
/// @brief      Provides main() for Programming Skills Group Coursework.
///


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "AppArgs.hpp"
#include "AppConfig.hpp"
#include "Landscape.hpp"
#include "LandscapePpmWriter.hpp"
#include "BmpFile.hpp"
#include "PopulationAverager.hpp"
#include "PpmFile.hpp"
#include "Timing.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <sstream>
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

	//start the timer
	Timing timer;
	timer.ResetTiming();

	try
	{
		//  parse command line
		AppArgs args(argc, argv);

		//  load configuration from file
		AppConfigReader const cfg_reader(args.GetCfgFilename());
		AppConfig const& cfg = cfg_reader.GetConfig();

		//  load land/water map from file
		BmpFile land_water_mask(args.GetLwMaskFilename());

		//  initialise the landscape
		Landscape landscape(cfg);
		landscape.ApplyLandWaterMask(land_water_mask.GetArray());

		landscape.ApplyRandomPumas(2.0);
		landscape.ApplyRandomHares(4.0);

		//  run the simulation
        for (unsigned int i=0; i<cfg.m_TT; ++i)
        {
			//  regular outputs: populations as PPM and averages
			if (0 == i % cfg.m_T)
			{
				//  create output filename
				std::stringstream filename_ss;
				filename_ss << "output" << i << ".ppm";

				//  write current state of the landscape to PPM file
				LandscapePpmWriter ls_writer(landscape.GetArray());
				ls_writer.Write(filename_ss.str());

				PopulationAverager pa(landscape.GetArray());
				std::cout << "average populations: hares: " << pa.GetAvgHares() << "  pumas: " << pa.GetAvgPumas() << std::endl;
			}

			//  do update and report time
			landscape.Update();
			double sim_time = i * cfg.m_dt;
			std::cout << "landscape updated to time " << sim_time << " months" << std::endl;
        }

		std::cout << "simulation complete" << std::endl;

        //define timing output variables
        unsigned int minutes, seconds, milliseconds;

        //getting timing
        timer.ReportTiming(minutes, seconds, milliseconds);

        //  timing output
        std::cout << "Elapsed time: " << minutes << "m " << seconds << "." << milliseconds << "s" << std::endl;
    }
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
