//////////////////////////////////////////////////////////////////////////////
/// @file     PopulationAverager-Test.hpp
///
/// @brief    Unit test for class PopulationAverager.
///


#ifndef PSCOURSEWORKI_PopulationAverager_TEST_HPP
#define PSCOURSEWORKI_PopulationAverager_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "PopulationAverager.hpp"
#include "AppConfig.hpp"
#include "Landscape.hpp"

//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>



//////////////////////////////////////////////////////////////////////////////
/// @brief  First test for class PopulationAverager.
///
/// @test   PopulationAverager can be constructed from valid arguments.
///
TEST(PopulationAverager)
{
	using namespace PsCourseworkI;

	//  these mustn't be changed; tests assume a 2x2 landscape with all land except south-east corner water
	unsigned const int size = 2;
	Landscape::LsArray ls_geography;
	ls_geography.Resize(Size(size,size));
	ls_geography(0,0).m_land=true;
	ls_geography(0,0).m_hares=1.0;
	ls_geography(0,0).m_pumas=5.0;

	ls_geography(0,1).m_land=true;
	ls_geography(0,1).m_hares=2.0;
	ls_geography(0,1).m_pumas=6.0;

	ls_geography(1,0).m_land=true;
	ls_geography(1,0).m_hares=3.0;
	ls_geography(1,0).m_pumas=7.0;

	ls_geography(1,1).m_land=true;
	ls_geography(1,1).m_hares=4.0;
	ls_geography(1,1).m_pumas=8.0;


	PopulationAverager pa(ls_geography);
	double pop_hare_external = 0.0, pop_hare_local = 0.0;
	double pop_puma_external = 0.0, pop_puma_local = 0.0;
	pa.Write(pop_puma_external,pop_hare_external);
	std::cout << "Puma avarage original: "<< pop_puma_external << std::endl; 
	std::cout << "Hare avarage original: "<< pop_hare_external << std::endl;

	pop_hare_local = (1.0+2.0+3.0+4.0)/4.0;
	pop_puma_local = (5.0+6.0+7.0+8.0)/4.0;
	std::cout << "Puma avarage test: "<< pop_puma_local << std::endl; 
	std::cout << "Hare avarage tes: "<< pop_hare_local << std::endl;
	CHECK(pop_puma_local == pop_puma_external);
	CHECK(pop_hare_local == pop_hare_external);
}


#endif  //  #ndef PSCOURSEWORKI_PopulationAverager_TEST_HPP
