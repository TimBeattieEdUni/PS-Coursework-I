//////////////////////////////////////////////////////////////////////////////
/// @file     AppArgs-Test.hpp
///
/// @brief    Unit test for class AppArgs.
///


#ifndef PSCOURSEWORKI_APPARGS_TEST_HPP
#define PSCOURSEWORKI_APPARGS_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "AppArgs.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <stdexcept>


//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests successful construction.
///
/// @test   AppArgs can be constructed from valid arguments.
/// @test   Arguments are stored and retrieved correctly.
///
TEST(AppArgsConstruct)
{
	using PsCourseworkI::AppArgs;
	
	int const argc = 3;
	
	//  add const here to prevent compiler warning about deprecated conversion 
	char const* exename = "exename";
	char const* cfgfile = "cfgfile";
	char const* mapfile = "mapfile";
	
	char const* argv[argc] = { exename, cfgfile, mapfile };
	
	try
	{
		//  remove const here to mimic what main() is given
		AppArgs args(argc, (char**)argv);
		CHECK(args.GetCfgFilename() == cfgfile);
		CHECK(args.GetMapFilename() == mapfile);
	}
	catch (...)
	{
		CHECK(false);
	}
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests construction failure.
///
/// @test   AppArgs throws on invalid number of arguments.
///
TEST(AppArgsThrowOnInvalidArgs)
{
	using PsCourseworkI::AppArgs;
	
	int const argc = 4;
	
	//  add const here to prevent compiler warning about deprecated conversion 
	char const* exename = "exename";
	char const* cfgfile = "cfgfile";
	char const* mapfile = "mapfile";
	char const* wrongun = "wrongun";
	
	char const* argv[argc] = { exename, cfgfile, mapfile, wrongun };
	
	CHECK_THROW(AppArgs args(argc, (char**)argv), std::runtime_error);
}


#endif  //  #ndef PSCOURSEWORKI_APPARGS_TEST_HPP
