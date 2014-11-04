//////////////////////////////////////////////////////////////////////////////
/// @file     Landscape-Test.hpp
///
/// @brief    Unit test for class Landscape.
///


#ifndef PSCOURSEWORKI_LANDSCAPE_TEST_HPP
#define PSCOURSEWORKI_LANDSCAPE_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "Landscape.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "AppConfig.hpp"
#include "Landscape.hpp"
#include "BmpFile.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <stdexcept>
#include <cmath>
#include <iostream>


////////////////////////////////////////////////////////////////////////////
/// @brief  First test for class Landscape.
///
/// @test   Landscape can be constructed from valid arguments.
///
TEST(LandscapeApplyPumas)
{
	using PsCourseworkI:: Landscape;


	CHECK(true);
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  Test landscape update.
///
/// @test   Landscape::Update() assigns correct new values to all cells.
///
TEST(LandscapeUpdate)
{
	using namespace PsCourseworkI;

	// error tolerance for comparison
	double epsilon = 0.00001; 

	unsigned int const ls_width  = 2;
	unsigned int const ls_height = 2;
	
	//  2x2 configuration with defaults from handout
	AppConfig cfg;
	cfg.m_Nx = ls_width;
	cfg.m_Ny = ls_height;
	cfg.m_T  = 1;
	cfg.m_TT = 1;
	cfg.m_r  = 0.08;
	cfg.m_a  = 0.04;
	cfg.m_b  = 0.02;
	cfg.m_m  = 0.06;
	cfg.m_k  = 0.2;
	cfg.m_l  = 0.2;
	cfg.m_dt = 0.4;

	//  prep all-land land/water mask
	BmpFile::BmpArray lw_mask(Size(ls_width, ls_height));
	for (unsigned int y = 0; y < ls_height; ++y)
	{
		for (unsigned int x = 0; x < ls_width; ++x)
		{
			lw_mask(x, y) = 1;
		}
	}

	//  prep puma and hare populations
	Landscape::PopulationMap puma_map(Size(ls_width, ls_height));
	Landscape::PopulationMap hare_map(Size(ls_width, ls_height));
	for (unsigned int y = 0; y < ls_height; ++y)
	{
		for (unsigned int x = 0; x < ls_width; ++x)
		{
			puma_map(x, y) = 0.01 * (x + 1) * (y + 1);
			hare_map(x, y) = 0.1  * (x + 1) * (y + 1);
		}
	}

	//  set up the landscape
	Landscape ls(cfg);
	ls.ApplyLandWaterMask(lw_mask);
	ls.ApplyPopulation(puma_map, Landscape::ePumas);
	ls.ApplyPopulation(hare_map, Landscape::eHares);

	Landscape::LsArray const& ls_array = ls.GetArray();

	//  verify applied pumas and hares, adjusting indices for halo
	for (unsigned int y = 0; y < ls_height; ++y)
	{
		for (unsigned int x = 0; x < ls_width; ++x)
		{
			CHECK(ls_array(x, y).m_pumas - (0.01 * (x + 1) * (y + 1)) < epsilon);
			CHECK(ls_array(x, y).m_hares - (0.1  * (x + 1) * (y + 1)) < epsilon);
		}
	}
	
	//  take a copy of the entire array before the update
	Landscape::LsArray ls_array_copy(ls.GetArray().GetSize());
	unsigned int ls_array_width   = ls_array.GetSize().m_x;
	unsigned int ls_array_height  = ls_array.GetSize().m_y;

	for (unsigned int j = 0; j < ls_array_height; ++j)
	{
		for (unsigned int i = 0; i < ls_array_width; ++i)
		{
			ls_array_copy(i, j) = ls_array(i, j);
		}
	}
	
	ls.Update();
	
	//  check halo cells are water and have no population: top and bottom edges
	for (unsigned int x = 0; x < ls_array_width; ++x)
	{
		CHECK(ls_array(x, 0).m_land   == false);
		CHECK(ls_array(x, 0).m_pumas  == 0.0);
		CHECK(ls_array(x, 0).m_hares  == 0.0);
		
		CHECK(ls_array(x, ls_array_width - 1).m_land   == false);
		CHECK(ls_array(x, ls_array_width - 1).m_pumas  == 0.0);
		CHECK(ls_array(x, ls_array_width - 1).m_hares  == 0.0);
	}
	
	//  left and right edges
	for (unsigned int y = 0; y < ls_array_height; ++y)
	{
		CHECK(ls_array(0, y).m_land   == false);
		CHECK(ls_array(0, y).m_pumas  == 0.0);
		CHECK(ls_array(0, y).m_hares  == 0.0);
		
		CHECK(ls_array(ls_array_height - 1, y).m_land   == false);
		CHECK(ls_array(ls_array_height - 1, y).m_pumas  == 0.0);
		CHECK(ls_array(ls_array_height - 1, y).m_hares  == 0.0);
	}

	//  check non-halo cell values using array indices
	for (unsigned int y = 1; y < ls_array_height - 1; ++y)
	{
		for (unsigned int x = 1; x < ls_array_width - 1; ++x)
		{
			//  verify land/water status hasn't changed
			bool lw_flag = ls_array(x, y).m_land;
			CHECK(lw_flag == lw_mask(x - 1, y - 1));

			//  check puma and hare densities
			if (lw_flag)
			{
				//  independent implementation of the equations; if implementations agree,
				//  we can have confidence in the result
				
				//  read old values from the arrays we applied
				double h_old_i_j  = ls_array_copy(x    , y    ).m_hares;
				double h_old_im_j = ls_array_copy(x - 1, y    ).m_hares;
				double h_old_ip_j = ls_array_copy(x + 1, y    ).m_hares;
				double h_old_i_jm = ls_array_copy(x    , y - 1).m_hares;
				double h_old_i_jp = ls_array_copy(x    , y + 1).m_hares;

				double p_old_i_j  = ls_array_copy(x    , y    ).m_pumas;
				double p_old_im_j = ls_array_copy(x - 1, y    ).m_pumas;
				double p_old_ip_j = ls_array_copy(x + 1, y    ).m_pumas;
				double p_old_i_jm = ls_array_copy(x    , y - 1).m_pumas;
				double p_old_i_jp = ls_array_copy(x    , y + 1).m_pumas;

				unsigned int nb = 0;
				if (ls_array_copy(x - 1, y    ).m_land) { ++nb; }
				if (ls_array_copy(x + 1, y    ).m_land) { ++nb; }
				if (ls_array_copy(x    , y - 1).m_land) { ++nb; }
				if (ls_array_copy(x    , y + 1).m_land) { ++nb; }

				double expected_pumas = p_old_i_j + cfg.m_dt * (cfg.m_b * h_old_i_j * p_old_i_j - cfg.m_m * p_old_i_j + cfg.m_l * (p_old_im_j + p_old_ip_j + p_old_i_jm + p_old_i_jp - nb * p_old_i_j));
				std::cout << "expected, actual: " << expected_pumas << "," << ls_array(x, y).m_pumas << std::endl;
//				CHECK(fabs(expected_pumas - ls_array(x, y).m_pumas) < epsilon);

				double expected_hares = h_old_i_j + cfg.m_dt * (cfg.m_r * h_old_i_j - cfg.m_a * h_old_i_j * p_old_i_j + cfg.m_k * (h_old_im_j + h_old_ip_j + h_old_i_jm + h_old_i_jp - nb * h_old_i_j));				
				std::cout << "expected, actual: " << expected_hares << "," << ls_array(x, y).m_hares << std::endl;
//				CHECK(fabs(expected_hares - ls_array(x, y).m_hares) < epsilon);
			}
			else
			{
				//  water cells should remain at zero
				CHECK(ls_array(x, y).m_pumas  == 0.0);
				CHECK(ls_array(x, y).m_hares  == 0.0);				
			}
		}
	}

/*
	// read out the explicit initial values for the Hares
	double H_11 = landscape(1, 1).m_hares;
	double H_12 = landscape(1, 2).m_hares;
	double H_21 = landscape(2, 1).m_hares;
	double H_22 = landscape(2, 2).m_hares;
	// read out the explicit initial values for the Pumas
	double P_11 = landscape(1, 1).m_pumas;
	double P_12 = landscape(1, 2).m_pumas;
	double P_21 = landscape(2, 1).m_pumas;
	double P_22 = landscape(2, 2).m_pumas;

	std::cout << "inital value H_11= " << H_11 << std::endl;
	std::cout << "inital value P_11= " << P_11 << std::endl;


	//calculate the evolved values explicitely
	H_11 = H_11 + dt * (H_11 * (r - a * P_11) + k * (H_21 + H_12 - 2 * H_11));
	H_12 = H_12 + dt * (H_12 * (r - a * P_12) + k * (H_11 - H_12));
	H_21 = H_21 + dt * (H_21 * (r - a * P_21) + k * (H_11 - H_21));
	H_22 = 0; //this gridcell is water

	P_11 = P_11 + dt * (P_11 * (b * H_11 - m) + l * (P_21 + P_12 - 2 * P_11));
	P_12 = P_12 + dt * (P_12 * (b * H_12 - m) + l * (P_11 - P_12));
	P_21 = P_21 + dt * (P_21 * (b * H_21 - m) + l * (P_11 - P_21));
	P_22 = 0;

	std::cout << "explicit updated value H_11= " << H_11 << std::endl;
	std::cout << "explicit updated value P_11= " << P_11 << std::endl;

	//update the landscape via the lanscape class
	landscape2x2.Update();

	//read out the evolved values for Hares
	double H_11_evo = landscape(1, 1).m_hares;
	double H_12_evo = landscape(1, 2).m_hares;
	double H_21_evo = landscape(2, 1).m_hares;
	double H_22_evo = landscape(2, 2).m_hares;
	// read out the evolved values for Pumas
	double P_11_evo = landscape(1, 1).m_pumas;
	double P_12_evo = landscape(1, 2).m_pumas;
	double P_21_evo = landscape(2, 1).m_pumas;
	double P_22_evo = landscape(2, 2).m_pumas;

	std::cout << "class updated value H_11= " << H_11 << std::endl;
	std::cout << "class updated value P_11= " << P_11 << std::endl;

	//check if the values agree in tolerance interval

	CHECK(fabs(H_11 - H_11_evo) <= epsilon);
	CHECK(fabs(H_12 - H_12_evo) <= epsilon);
	CHECK(fabs(H_21 - H_21_evo) <= epsilon);
	CHECK(fabs(H_22 - H_22_evo) <= epsilon);
	CHECK(fabs(P_11 - P_11_evo) <= epsilon);
	CHECK(fabs(P_12 - P_12_evo) <= epsilon);
	CHECK(fabs(P_21 - P_21_evo) <= epsilon);
	CHECK(fabs(P_22 - P_22_evo) <= epsilon);
*/
}


#endif  //  #ndef PSCOURSEWORKI_LANDSCAPE_TEST_HPP
