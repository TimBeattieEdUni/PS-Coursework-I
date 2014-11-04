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


//  error tolerance for comparison
double const epsilon = 0.00001;


//////////////////////////////////////////////////////////////////////////////
/// @brief  Checks halo cells are still water with zero population.
///
void CheckHalo(PsCourseworkI::Landscape& ls)
{
	using namespace PsCourseworkI;
	
	Landscape::LsArray const& ls_array = ls.GetArray();
	unsigned int ls_array_width  = ls_array.GetSize().m_x;
	unsigned int ls_array_height = ls_array.GetSize().m_y;
	
	//  top and bottom edges
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
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests landscape initialisation.
///
void TestLandscapeInit(PsCourseworkI::Landscape& ls, PsCourseworkI::AppConfig const& cfg)
{
	using namespace PsCourseworkI;
	
	Landscape::LsArray const& ls_array = ls.GetArray();
	Size array_size = ls_array.GetSize();
	
	unsigned int array_width   = array_size.m_x;
	unsigned int array_height  = array_size.m_y;
	
	CHECK(array_width  == cfg.m_Nx + 2);
	CHECK(array_height == cfg.m_Ny + 2);
	
	//  check all cells are zero after initialisation (including halo)
	for (unsigned int y = 0; y < array_height; ++y)
	{
		for (unsigned int x = 0; x < array_width; ++x)
		{
			Cell const& cell = ls_array(x, y);
			CHECK(cell.m_land   == false);
			CHECK(cell.m_pumas  == 0.0);
			CHECK(cell.m_hares  == 0.0);
		}	
	}	
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests applying land/water bitmask to a Landscape.
///
void TestApplyLandWaterBitmask(PsCourseworkI::Landscape& ls, PsCourseworkI::AppConfig const& cfg)
{
	using namespace PsCourseworkI;

	//  prep bitmask - all land except south-east corner
	BmpFile::BmpArray lw_mask(Size(cfg.m_Nx, cfg.m_Ny));
	
	lw_mask(0, 0) = 1;
	lw_mask(1, 0) = 1;
	lw_mask(0, 1) = 1;
	lw_mask(1, 1) = 0;
	
	ls.ApplyLandWaterMask(lw_mask);
	
	CHECK(ls.GetArray()(1, 1).m_land == true);
	CHECK(ls.GetArray()(2, 1).m_land == true);
	CHECK(ls.GetArray()(1, 2).m_land == true);
	CHECK(ls.GetArray()(2, 2).m_land == false);
	
	CheckHalo(ls);
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests applying puma population to a Landscape.
///
void TestApplyPumas(PsCourseworkI::Landscape& ls, PsCourseworkI::AppConfig const& cfg)
{
	using namespace PsCourseworkI;
	
	Landscape::LsArray const& array = ls.GetArray();

	//  take a copy of the landscape array for comparison later
	Landscape::LsArray copy(Size(cfg.m_Nx + 2, cfg.m_Ny + 2));
	for (unsigned int y = 0; y < cfg.m_Ny + 2; ++y)
	{
		for (unsigned int x = 0; x < cfg.m_Nx + 2; ++x)
		{
			copy(x, y) = array(x,y);
		}
	}

	//  apply a known population
	Landscape::PopulationMap puma_map(Size(cfg.m_Nx, cfg.m_Ny));
	
	puma_map(0, 0) = 1.0;
	puma_map(1, 0) = 2.0;
	puma_map(0, 1) = 3.0;
	puma_map(1, 1) = 4.0;
	
	ls.ApplyPopulation(puma_map, Landscape::ePumas);
	
	//  verify land/water and hares are unchanged 
	for (unsigned int y = 0; y < cfg.m_Ny + 2; ++y)
	{
		for (unsigned int x = 0; x < cfg.m_Nx + 2; ++x)
		{
			CHECK(array(x, y).m_land == copy(x, y).m_land);
			CHECK(fabs(array(x, y).m_hares - copy(x, y).m_hares) < epsilon);
		}
	}
	
	//  inside the halo, verify pumas are as assigned (or 0 for water cells)
	for (unsigned int y = 0; y < cfg.m_Ny; ++y)
	{
		for (unsigned int x = 0; x < cfg.m_Nx; ++x)
		{
			Cell const& cell_ls = array(x + 1, y + 1);
			
			if (cell_ls.m_land)
			{
				CHECK(fabs(cell_ls.m_pumas - puma_map(x, y)) < epsilon);
			}
			else
			{
				CHECK(cell_ls.m_pumas == 0.0);
			}
		}
	}
	
	CheckHalo(ls);
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests applying hare population to a Landscape.
///
/// @todo   It would be good to factor out the common logic between this 
///         function and the puma version of the same thing, but a good way to 
///         do this wasn't apparent.
///
void TestApplyHares(PsCourseworkI::Landscape& ls, PsCourseworkI::AppConfig const& cfg)
{
	using namespace PsCourseworkI;
	
	Landscape::LsArray const& array = ls.GetArray();
	
	//  take a copy of the landscape array for comparison later
	Landscape::LsArray copy(Size(cfg.m_Nx + 2, cfg.m_Ny + 2));
	for (unsigned int y = 0; y < cfg.m_Ny + 2; ++y)
	{
		for (unsigned int x = 0; x < cfg.m_Nx + 2; ++x)
		{
			copy(x, y) = array(x,y);
		}
	}
	
	//  apply a known population
	Landscape::PopulationMap hare_map(Size(cfg.m_Nx, cfg.m_Ny));
	
	hare_map(0, 0) = 5.0;
	hare_map(1, 0) = 6.0;
	hare_map(0, 1) = 7.0;
	hare_map(1, 1) = 8.0;
	
	ls.ApplyPopulation(hare_map, Landscape::eHares);
	
	//  verify land/water and pumas are unchanged 
	for (unsigned int y = 0; y < cfg.m_Ny + 2; ++y)
	{
		for (unsigned int x = 0; x < cfg.m_Nx + 2; ++x)
		{
			CHECK(array(x, y).m_land == copy(x, y).m_land);
			CHECK(fabs(array(x, y).m_pumas - copy(x, y).m_pumas) < epsilon);
		}
	}
	
	//  inside the halo, verify hares are as assigned (or 0 for water cells)
	for (unsigned int y = 0; y < cfg.m_Ny; ++y)
	{
		for (unsigned int x = 0; x < cfg.m_Nx; ++x)
		{
			Cell const& cell_ls   = array(x + 1, y + 1);
			
			if(cell_ls.m_land)
			{
				CHECK(fabs(cell_ls.m_hares - hare_map(x, y)) < epsilon);
			}
			else
			{
				CHECK(cell_ls.m_hares == 0.0);
			}
		}
	}
	
	CheckHalo(ls);
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  Tests updating the landscape
///
void TestUpdate(PsCourseworkI::Landscape& ls, PsCourseworkI::AppConfig const& cfg)
{
	using namespace PsCourseworkI;
	
	Landscape::LsArray const& array = ls.GetArray();
	unsigned int array_width  = array.GetSize().m_x;
	unsigned int array_height = array.GetSize().m_y;

	//  take a copy of the landscape array for comparison later
	Landscape::LsArray copy(Size(array_width, array_height));
	for (unsigned int y = 0; y < array_height; ++y)
	{
		for (unsigned int x = 0; x < array_width; ++x)
		{
			copy(x, y) = array(x,y);
		}
	}

	ls.Update();
	
	//  this is necessary because class Landscape switches arrays after each update
	Landscape::LsArray const& updated_array = ls.GetArray();
	
	//  check non-halo cell values using array indices
	for (unsigned int y = 1; y < array_height - 1; ++y)
	{
		for (unsigned int x = 1; x < array_width - 1; ++x)
		{
			//  verify land/water status hasn't changed
			CHECK(updated_array(x, y).m_land == copy(x, y).m_land);
			
			//  check puma and hare densities
			if (updated_array(x, y).m_land)
			{
				//  independent implementation of the equations; if implementations agree,
				//  we can have confidence in the result
				
				//  read old values from the arrays we applied
				double h_old_i_j  = copy(x    , y    ).m_hares;
				double h_old_im_j = copy(x - 1, y    ).m_hares;
				double h_old_ip_j = copy(x + 1, y    ).m_hares;
				double h_old_i_jm = copy(x    , y - 1).m_hares;
				double h_old_i_jp = copy(x    , y + 1).m_hares;
				
				double p_old_i_j  = copy(x    , y    ).m_pumas;
				double p_old_im_j = copy(x - 1, y    ).m_pumas;
				double p_old_ip_j = copy(x + 1, y    ).m_pumas;
				double p_old_i_jm = copy(x    , y - 1).m_pumas;
				double p_old_i_jp = copy(x    , y + 1).m_pumas;
				
				unsigned int nb = 0;
				if (copy(x - 1, y    ).m_land) { ++nb; }
				if (copy(x + 1, y    ).m_land) { ++nb; }
				if (copy(x    , y - 1).m_land) { ++nb; }
				if (copy(x    , y + 1).m_land) { ++nb; }

				double expected_pumas = p_old_i_j + cfg.m_dt * (cfg.m_b * h_old_i_j * p_old_i_j - cfg.m_m * p_old_i_j + cfg.m_l * (p_old_im_j + p_old_ip_j + p_old_i_jm + p_old_i_jp - nb * p_old_i_j));
				CHECK(fabs(expected_pumas - updated_array(x, y).m_pumas) < epsilon);
				
				double expected_hares = h_old_i_j + cfg.m_dt * (cfg.m_r * h_old_i_j - cfg.m_a * h_old_i_j * p_old_i_j + cfg.m_k * (h_old_im_j + h_old_ip_j + h_old_i_jm + h_old_i_jp - nb * h_old_i_j));
				CHECK(fabs(expected_hares - updated_array(x, y).m_hares) < epsilon);
			}
			else
			{
				//  water cells should remain at zero
				CHECK(updated_array(x, y).m_pumas  == 0.0);
				CHECK(updated_array(x, y).m_hares  == 0.0);
			}
		}
	}
	
	CheckHalo(ls);
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  Test class Landscape.
///
/// @test   Landscape is initialised correctly.
/// @test   Land/water mask is applied correctly.
/// @test   Hare population is applied correctly.
/// @test   Puma population is applied correctly.
/// @test   Landscape::Update() assigns correct new values to all cells.
///
TEST(LandscapeUpdate)
{
	using namespace PsCourseworkI;

	//  these mustn't be changed; tests assume a 2x2 landscape with all land except south-east corner water
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

	//  create landscape and run tests
	Landscape ls(cfg);
	
	TestLandscapeInit(ls, cfg);
	TestApplyLandWaterBitmask(ls, cfg);
	TestApplyPumas(ls, cfg);
	TestApplyHares(ls, cfg);
	TestUpdate(ls, cfg);
}


#endif  //  #ndef PSCOURSEWORKI_LANDSCAPE_TEST_HPP
