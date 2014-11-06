//////////////////////////////////////////////////////////////////////////////
/// @file     LandscapePpmWriter-Test.hpp
///
/// @brief    Unit test for class LandscapePpmWriter.
///


#ifndef PSCOURSEWORKI_LANDSCAPEPPMWRITER_TEST_HPP
#define PSCOURSEWORKI_LANDSCAPEPPMWRITER_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "LandscapePpmWriter.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <string>
#include <fstream>


//////////////////////////////////////////////////////////////////////////////
/// @brief  First test for class LandscapePpmWriter.
///
/// @test   LandscapePpmWriter can be constructed from valid arguments.
/// @test   LandscapePpmWriter writes correct values to file.
///
TEST(LandscapePpmWriter)
{
	using namespace PsCourseworkI;

	std::string const filename("inputs/LandscapePpmWriter-Test.ppm");
	
	//  prep a landscape with known populations and halo
	Landscape::LsArray landscape(Size(4, 5));

	//  halo
	landscape(0, 0) = Cell(false, 0.0, 0.0);
	landscape(0, 1) = Cell(false, 0.0, 0.0);
	landscape(0, 2) = Cell(false, 0.0, 0.0);
	landscape(0, 3) = Cell(false, 0.0, 0.0);
	landscape(0, 4) = Cell(false, 0.0, 0.0);
	landscape(3, 0) = Cell(false, 0.0, 0.0);
	landscape(3, 1) = Cell(false, 0.0, 0.0);
	landscape(3, 2) = Cell(false, 0.0, 0.0);
	landscape(3, 3) = Cell(false, 0.0, 0.0);
	landscape(3, 4) = Cell(false, 0.0, 0.0);
	landscape(1, 0) = Cell(false, 0.0, 0.0);
	landscape(2, 0) = Cell(false, 0.0, 0.0);
	landscape(3, 0) = Cell(false, 0.0, 0.0);
	landscape(1, 4) = Cell(false, 0.0, 0.0);
	landscape(2, 4) = Cell(false, 0.0, 0.0);
	landscape(3, 4) = Cell(false, 0.0, 0.0);
	
	//  actual landscape
	landscape(1, 1) = Cell(true, 0.8, 0.9);
	landscape(1, 2) = Cell(true, 0.0, 1.1);
	landscape(1, 3) = Cell(true, 1.1, 0.0);
	landscape(2, 1) = Cell(false, 0.0, 0.0);
	landscape(2, 2) = Cell(true, 1.2, 1.2);
	landscape(2, 3) = Cell(false, 0.0, 0.0);
	
	//  write it to file
	LandscapePpmWriter writer(landscape);
	writer.Write(filename);
	
	//  expectd file contents:
	//	P3
	//	2 3
	//	255
	//	229 204 0   0 0 255   255 0 0   255 255 0   
	//	0 255 0   0 0 255
	
	std::ifstream ppm_file(filename.c_str());

	//  check header
	std::string line;
	std::getline(ppm_file, line);
	CHECK(line == "P3");
	std::getline(ppm_file, line);
	CHECK(line == "2 3");	
	std::getline(ppm_file, line);
	CHECK(line == "255");
	
	//  check RGB values
	unsigned int value = 0xffff;
	ppm_file >> value;
	CHECK(229 == value);
	ppm_file >> value;
	CHECK(204 == value);
	ppm_file >> value;
	CHECK(0 == value);

	ppm_file >> value;
	CHECK(0 == value);
	ppm_file >> value;
	CHECK(0 == value);
	ppm_file >> value;
	CHECK(255 == value);

	ppm_file >> value;
	CHECK(255 == value);
	ppm_file >> value;
	CHECK(0 == value);
	ppm_file >> value;
	CHECK(0 == value);
	
	ppm_file >> value;
	CHECK(255 == value);
	ppm_file >> value;
	CHECK(255 == value);
	ppm_file >> value;
	CHECK(0 == value);
	
	ppm_file >> value;
	CHECK(0 == value);
	ppm_file >> value;
	CHECK(255 == value);
	ppm_file >> value;
	CHECK(0 == value);
	
	ppm_file >> value;
	CHECK(0 == value);
	ppm_file >> value;
	CHECK(0 == value);
	ppm_file >> value;
	CHECK(255 == value);
	
	if (remove(filename.c_str()))
	{
		std::cout << "warning: failed to remove LandscapePpmWriter test output file \"" << filename << "\" after test" ;
		std::cout << "File should be removed manually" << std::endl;
	}
}


#endif  //  #ndef PSCOURSEWORKI_LANDSCAPEPPMWRITER_TEST_HPP
