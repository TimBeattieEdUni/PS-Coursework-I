//////////////////////////////////////////////////////////////////////////////
/// @file     PgmFile-Test.hpp
///
/// @brief    Unit test for class PgmFile.
///


#ifndef GROUP PRACTICAL_REPO_PGMFILE_TEST_HPP
#define GROUP PRACTICAL_REPO_PGMFILE_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "PpmFile.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>


//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests writing a ppm file.
///
/// @test   PgmFile can be constructed from valid arguments.
///
TEST(PgmFileConstruct)
{
	using PsCourseworkI::PpmFile;
	using PsCourseworkI::Size;
	using PsCourseworkI::Pixel;
	
	Size size(3, 2);
	unsigned int const max_rgb = 255;
	std::string file_name("PpmFile-Test-output.ppm");
	
	//  scope to ensure PpmFile object is destroyed before we clean up
	{
		PpmFile pf(file_name, size, max_rgb);

		//  create an array in memory
		std::vector<unsigned int> array;
		for (unsigned int i = 0; i < 6; ++i)
		{
			array.push_back(i);
		}
		
		//  write the array to ppm file
		for (unsigned int i = 0; i < 6; ++i)
		{
			pf.WritePixel(Pixel(i, i, i));
		}

		pf.Finalise();
		
		//  verify file contents
		std::ifstream ppm_file(file_name.c_str());
		std::string line;
		getline(ppm_file, line);
		CHECK(line == "P3");
		getline(ppm_file, line);
		CHECK(line == "3 2");
		getline(ppm_file, line);
		CHECK(line == "255");
		
		for (unsigned int i = 0; i < 6; ++i)
		{
			for (unsigned int j = 0; j < 3; ++j)
			{
				unsigned int rgb_val = -1;
				ppm_file >> rgb_val;
				CHECK(i == rgb_val);
			}
		}
	}
	
	if (remove(file_name.c_str()))
	{
		std::cout << "warning: failed to remove PPM test file \"" << file_name << "\" after test; file should be removed manually" << std::endl;
		CHECK(false);
	}
}


#endif  //  #ndef GROUP PRACTICAL_REPO_PGMFILE_TEST_HPP
