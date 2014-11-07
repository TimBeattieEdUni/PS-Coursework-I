//////////////////////////////////////////////////////////////////////////////
/// @file     PopulationAverager-Test.hpp
///
/// @brief    Unit test for class PopulationAverager.
///
/// @todo     Test case of all-water landscape.
///


#ifndef PSCOURSEWORKI_POPULATIONAVERAGER_TEST_HPP
#define PSCOURSEWORKI_POPULATIONAVERAGER_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "PopulationAverager.hpp"
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

	//  this mustn't be changed; tests assume a 2x2 landscape with all land except south-east corner water
	unsigned const int size = 2;
	Landscape::LsArray ls_geography(Size(size, size));

	//  prep landscape with known populations
	ls_geography(0, 0).m_land = true;
	ls_geography(0, 0).m_hares = 1.0;
	ls_geography(0, 0).m_pumas = 5.0;

	ls_geography(0, 1).m_land = true;
	ls_geography(0, 1).m_hares = 2.0;
	ls_geography(0, 1).m_pumas = 6.0;

	ls_geography(1, 0).m_land = true;
	ls_geography(1, 0).m_hares = 3.0;
	ls_geography(1, 0).m_pumas = 7.0;

	ls_geography(1, 1).m_land = true;
	ls_geography(1, 1).m_hares = 4.0;
	ls_geography(1, 1).m_pumas = 8.0;

	//  let population averager calculate its values
	PopulationAverager pa(ls_geography);

	double pop_hare_external = pa.GetAvgHares();
	double pop_puma_external = pa.GetAvgPumas();

	//  calculate our own values
	double pop_puma_local = 0.0;
	double pop_hare_local = 0.0;
	pop_hare_local = (1.0 + 2.0 + 3.0 + 4.0) / 4.0;
	pop_puma_local = (5.0 + 6.0 + 7.0 + 8.0) / 4.0;

	//  check within reasonable floating point accuracy
	double epsilon = 0.0000001;
	CHECK(fabs(pop_puma_local - pop_puma_external) < epsilon);
	CHECK(fabs(pop_hare_local - pop_hare_external) < epsilon);

	//  prep landscape with known populations
	ls_geography(0, 0).m_land = false;
	ls_geography(0, 1).m_land = false;
	ls_geography(1, 0).m_land = false;
	ls_geography(1, 1).m_land = false;

	//  let population averager calculate its values
	PopulationAverager paZeroLand(ls_geography);

	pop_hare_external = paZeroLand.GetAvgHares();
	pop_puma_external = paZeroLand.GetAvgPumas();

	//  calculate our own values
	pop_puma_local = 0.0;
	pop_hare_local = 0.0;

	//  Test population averager handles all water/zero population
	CHECK(fabs(pop_puma_local - pop_puma_external) < epsilon);
	CHECK(fabs(pop_hare_local - pop_hare_external) < epsilon);


}


#endif  //  #ndef PSCOURSEWORKI_POPULATIONAVERAGER_TEST_HPP
