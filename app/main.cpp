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
	using namespace GroupPractical;
	
	try 
	{
		AppArgs args(argc, argv);

		AppConfig cfg(args.CfgFilename());
		
		Landscape landscape(cfg);
		
		DemoClass the_demo;
		(void) the_demo;
	}
	catch (std::exception const& e) 
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}

