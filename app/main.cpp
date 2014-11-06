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


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <sys/time.h>


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

	//fields for timing
	timeval t_start,t_end;
	//set starting time
	gettimeofday(&t_start,NULL); // on windows OS use: GetSystemTime

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

		//  fill top half of map with pumas and bottom with hares
//		Landscape::PopulationMap pumas(Size(cfg.m_Nx, cfg.m_Ny));
//		Landscape::PopulationMap hares(Size(cfg.m_Nx, cfg.m_Ny));
//		for (unsigned int x = 0; x < cfg.m_Nx; ++x)
//		{
//			for (unsigned int y = 0; y < cfg.m_Ny; ++y)
//			{
//				if (y < cfg.m_Ny / 2)
//				{
//					pumas(x, y) = 0.5;
//					hares(x, y) = 0.0;
//				}
//				else
//				{
//					pumas(x, y) = 0.0;
//					hares(x, y) = 0.5;					
//				}
//			}
//		}
//		landscape.ApplyPopulation(pumas, Landscape::ePumas);
//		landscape.ApplyPopulation(hares, Landscape::eHares);
		
		//  initialise PPM file writer
		LandscapePpmWriter ls_writer(landscape);

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

        // timing:
        gettimeofday(&t_end,NULL);

        unsigned int seconds_diff=(t_end.tv_sec - t_start.tv_sec);
        unsigned int microseconds_diff=(t_end.tv_usec - t_start.tv_usec);

        //  transforming the seconds and microseconds output in usaual format (h,min,sec,msec,usec)
        unsigned int hours=(seconds_diff/3600);
        unsigned int minutes = seconds_diff / 60;
        unsigned int seconds = seconds_diff - (hours * 3600) - (minutes * 60);
        unsigned int milliseconds = microseconds_diff / 1000;

        //  timing output
        std::cout << "Elapsed time: " << minutes << "m " << seconds << "." << milliseconds << "s" << std::endl;
    }
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
