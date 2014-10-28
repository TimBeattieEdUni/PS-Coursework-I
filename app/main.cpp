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
		std::cout << "parsing command line arguments" << std::endl;
		AppArgs args(argc, argv);

		std::cout << "loading confiuration from \"" << args.CfgFilename() << "\"" << std::endl;
		AppConfig cfg(args.CfgFilename());
		
		DemoClass the_demo;
		(void) the_demo;
	}
	catch (std::exception const& e) 
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}

