//////////////////////////////////////////////////////////////////////////////
/// @file     Landscape.cpp
///
/// @brief    Implementation of class Landscape.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "Landscape.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <algorithm>
#include <vector>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Sets up the 2D arrays of landscape cells using sizes obtained
	///             from the app's configuration.  Adds halo cells surrounding the
	///             landscape.
	///
	/// @param      cfg  Application configuration.
	///
	/// @post       Landscape array has been initialised.
	///
	Landscape::Landscape(AppConfig const& cfg)
		: m_bswap_arrays(false)
		, m_landscape_size(cfg.GetNx(), cfg.GetNy())
		, m_cfg(cfg)
		, m_array_old(Size(cfg.GetNx() + 2, cfg.GetNy() + 2))
		, m_array_new(Size(cfg.GetNx() + 2, cfg.GetNy() + 2))
	{
		std::cout << "landscape size: " << m_landscape_size.m_x << " x " << m_landscape_size.m_y << std::endl;

		InitHalos();
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details      Provides access to the current state of the landscape.
	///
	/// @return       The array which has most recently been updated.
	///
	Landscape::LsArray const& Landscape::GetArray() const
	{
		if (m_bswap_arrays)
		{
			return m_array_new;
		}
		else
		{
			return m_array_old;
		}
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Advances the simulation by one time step.  Alternates which
	///             array is "old" and which is "new".  Data in "old"
	///             is used to calculate values which are written to "new".
	///
	/// @todo       Performance improvement: store pointers to neighbours in each cell at start-up.
	///
	void Landscape::Update()
	{
		m_bswap_arrays = !m_bswap_arrays;

		LsArray& array_new = m_bswap_arrays ? m_array_new : m_array_old;
		LsArray& array_old = m_bswap_arrays ? m_array_old : m_array_new;

		//  iterate over landscape rows and columns, converting landscape indices to array indices
		//  as the landscape is offset by (1,1) in the array

//  (1 of 2) Iteration order of x and y were swapped for performance
//		for (unsigned int ls_i = 0; ls_i < m_landscape_size.m_x; ++ls_i)
//		{
//			unsigned int array_i = ls_i + 1;

		for (unsigned int ls_j = 0; ls_j < m_landscape_size.m_y; ++ls_j)
		{
			unsigned int array_j = ls_j + 1;

//  (2 of 2) Iteration order of x and y were swapped for performance
//			for (unsigned int ls_j = 0; ls_j < m_landscape_size.m_y; ++ls_j)
//			{
//				unsigned int array_j = ls_j + 1;

			for (unsigned int ls_i = 0; ls_i < m_landscape_size.m_x; ++ls_i)
			{
				unsigned int array_i = ls_i + 1;

				//  at this point, we're never in a halo cell, so we don't need to check array bounds
				//  when looking for neighbours, and neighbouring halo cells will have zero populations

				//  the cell we're about to update in the "new" array
				Cell& cell_new = array_new(array_i, array_j);

				//  no update necessary for water cells
				if (! cell_new.m_land)
				{
					continue;
				}

				//  the same cell and its neighbours in the "old" array
				Cell const& cell_old  = array_old(array_i, array_j);
				Cell const& nbr_n     = array_old(array_i + 1, array_j);
				Cell const& nbr_s     = array_old(array_i - 1, array_j);
				Cell const& nbr_e     = array_old(array_i, array_j + 1);
				Cell const& nbr_w     = array_old(array_i, array_j - 1);

				//  number of neighbouring land cells
				unsigned int land_nbrs = nbr_n.m_land ? 1 : 0
				                       + nbr_s.m_land ? 1 : 0
				                       + nbr_e.m_land ? 1 : 0
				                       + nbr_w.m_land ? 1 : 0;

				cell_new.m_hares = cell_old.m_hares + m_cfg.Getdt() * ( m_cfg.Getr() * cell_old.m_hares
				                                                  - m_cfg.Geta() * cell_old.m_hares * cell_old.m_pumas
				                                                  + m_cfg.Getk()   * ( nbr_n.m_hares
																			    + nbr_s.m_hares
																			    + nbr_e.m_hares
																			    + nbr_w.m_hares
																			    - land_nbrs * cell_old.m_hares));

				cell_new.m_pumas = cell_old.m_pumas + m_cfg.Getdt() * ( m_cfg.Getb() * cell_old.m_hares * cell_old.m_pumas
															    - m_cfg.Getm() * cell_old.m_pumas
															    + m_cfg.Getl() * ( nbr_n.m_pumas
																			  + nbr_s.m_pumas
																			  + nbr_e.m_pumas
																			  + nbr_w.m_pumas
																			  - land_nbrs * cell_old.m_pumas));
			}
		}
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details      Reads the given land/water bitmap and applies it to the two
	///               landscapes.
	///
	/// @param        bmp  Land/water bit mask.
	///
	/// @post         The given land/water bit mask has been applied to the landscape.
	///
	void Landscape::ApplyLandWaterMask(BmpFile::BmpArray const& mask_array)
	{
		unsigned int size_x = m_landscape_size.m_x;
		unsigned int size_y = m_landscape_size.m_y;

		//  check sizes of bitmask and landscape match
		Size bmp_size = mask_array.GetSize();
		if (! (bmp_size == m_landscape_size))
		{
			std::cout << "\nwarning: land/water bitmask size differs from landscape size" << std::endl;

			//  use size of intersection of bit mask and landscape
			size_x = std::min(mask_array.GetSize().m_x, m_landscape_size.m_x);
			size_y = std::min(mask_array.GetSize().m_y, m_landscape_size.m_y);

			std::cout << "applying bitmask to overlapping rectangle: " << size_x << " x " << size_y << "\n" << std::endl;
		}

		//  write land/water flags into landscape cells inside the halo
		for (unsigned int j = 0; j < size_y; ++j)
		{
			for (unsigned int i = 0; i < size_x; ++i)
			{
				//  adjust i and j for landscape's 1x1 offset into the array
				m_array_old(i + 1, j + 1).m_land = static_cast<bool>(mask_array(i, j));
				m_array_new(i + 1, j + 1).m_land = static_cast<bool>(mask_array(i, j));
			}
		}
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details      Sets the population density of pumas in each landscape cell
	///               to a random value between 0 and 1.
	///
	void Landscape::ApplyRandomPumas()
	{
		for (unsigned int i = 0; i < m_landscape_size.m_x; ++i)
		{
			for (unsigned int j = 0; j < m_landscape_size.m_y; ++j)
			{
				if (m_array_old(i + 1, j + 1).m_land)
				{
					m_array_old(i + 1, j + 1).m_pumas = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
					m_array_new(i + 1, j + 1).m_pumas = m_array_old(i + 1, j + 1).m_pumas;
				}
			}
		}
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details      Sets the population density of pumas to consist of a number of packs (puma density 2) of given size in random land places.
	///               When the same grid point is randomed twice it is over ridden so it is not guaranteed that one gets exactly  the spezified number of Packs (especially relevant for very small landscapes and or landscapes with very few land points)
	///
	///@param N_Packs   number of packs
	///
	///
	void Landscape::ApplyPackPumas(unsigned int N_Packs)
	{
	    unsigned int Pack_Location, Pack_i, Pack_j;

	    //searching for land
	    std::vector<unsigned int> Land_sites;

        for (unsigned int i = 0; i < m_landscape_size.m_x; ++i)
		{
			for (unsigned int j = 0; j < m_landscape_size.m_y; ++j)
			{
				if (m_array_old(i + 1, j + 1).m_land)
				{
                    Land_sites.push_back(j*m_landscape_size.m_x+i);
				}
			}
		}

        for (unsigned int i = 0; i < N_Packs; ++i)
        {
            Pack_Location=static_cast<unsigned int>(static_cast<double>(rand()) / static_cast<double>(RAND_MAX)*Land_sites.size());
            Pack_i = Pack_Location % m_landscape_size.m_x;
            Pack_j = Pack_Location / m_landscape_size.m_x;

            m_array_old(Pack_i + 1, Pack_j + 1).m_pumas = 2.0;
            m_array_new(Pack_i + 1, Pack_j + 1).m_pumas = m_array_old(Pack_i + 1, Pack_j + 1).m_pumas;

        }

	}




	//////////////////////////////////////////////////////////////////////////////
	/// @details      Sets the population density of hares in each landscape cell
	///               to a random value between 0 and 1.
	///
	void Landscape::ApplyRandomHares()
	{
		for (unsigned int i = 0; i < m_landscape_size.m_x; ++i)
		{
			for (unsigned int j = 0; j < m_landscape_size.m_y; ++j)
			{
				if (m_array_old(i + 1, j + 1).m_land)
				{
					m_array_old(i + 1, j + 1).m_hares = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
					m_array_new(i + 1, j + 1).m_hares = m_array_old(i + 1, j + 1).m_hares;
				}
			}
		}
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details      Creates a halo of water cells surrounding each landscape.
	///
	void Landscape::InitHalos()
	{
		Cell const water(false, 0.0, 0.0);

		unsigned int size_x = m_array_old.GetSize().m_x;
		unsigned int size_y = m_array_old.GetSize().m_y;

		for (unsigned int i = 0; i < size_x; ++i)
		{
			m_array_old(i, 0)           = water;
			m_array_old(i, size_y - 1)  = water;

			m_array_new(i, 0)           = water;
			m_array_new(i, size_y - 1)  = water;
		}

		for (unsigned int j = 0; j < size_y; ++j)
		{
			m_array_old(0, j)           = water;
			m_array_old(size_x - 1, j)  = water;

			m_array_new(0, j)           = water;
			m_array_new(size_x - 1, j)  = water;
		}
	}

}   //  namespace PsCourseworkI
