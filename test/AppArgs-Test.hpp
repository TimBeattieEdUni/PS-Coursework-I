//////////////////////////////////////////////////////////////////////////////
/// @file     AppArgs-Test.hpp
///
/// @brief    Unit test for class AppArgs.
///


#ifndef GROUP_PRACTICAL_APPARGS_TEST_HPP
#define GROUP_PRACTICAL_APPARGS_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "AppArgs.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <stdexcept>


//////////////////////////////////////////////////////////////////////////////
/// @brief  First test for class AppArgs.
///
/// @test   AppArgs can be constructed from valid arguments.
/// @test   Arguments are stored and retrieved correctly.
///
TEST(AppArgsConstruct)
{
	using GroupPractical::AppArgs;
	
	int const argc = 2;
	
	//  add const here to prevent compiler warning about deprecated conversion 
	char const* exename = "exename";
	char const* cfgfile = "cfgfile";
	
	char const* argv[argc] = { exename, cfgfile };
	
	try
	{
		//  remove const here to mimic what main() is given
		AppArgs args(argc, (char**)argv);
		CHECK(args.CfgFilename() == cfgfile);
	}
	catch (...)
	{
		CHECK(false);
	}
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  First test for class AppArgs.
///
/// @test   AppArgs can be constructed from valid arguments.
/// @test   Arguments are stored and retrieved correctly.
///
TEST(AppArgsThrowOnInvalidArgs)
{
	using GroupPractical::AppArgs;
	
	int const argc = 3;
	
	//  add const here to prevent compiler warning about deprecated conversion 
	char const* exename = "exename";
	char const* cfgfile = "cfgfile";
	char const* wrongun = "wrongun";
	
	char const* argv[argc] = { exename, cfgfile, wrongun };
	
	CHECK_THROW(AppArgs args(argc, (char**)argv), std::runtime_error);
}


#endif  //  #ndef GROUP_PRACTICAL_APPARGS_TEST_HPP
