//////////////////////////////////////////////////////////////////////////////
/// @file     Population.cpp
///
/// @brief    Implementation of class Pupulation.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "Population.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <cstdlib>
#include <ctime>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details Initialise the two Array2D arrays for the Puma and Hare population
	///
	/// @param size...A Size structure which holds the grid lenghts N_x and N_y
	/// @param timestamp_seed... A bool variable: if true the current timestamp is used as seed number for std::rand(). If false the standard seed number is used
	/// @pre
	/// @post Initialised an Array2D Puma_Array and Hare_Array to represent the population of Pumas and Hares repectively
	///
	/// @exception
	///
	Population::Population(Array2D<double>::Size grid_size, bool timestamp_seed)
	{
	    if(timestamp_seed)
	    {
	        std::srand(std::time(0)); //use current time as seed for random generator)
	    }

	    Array2D<double> Puma_Array(grid_size);
	    Array2D<double> Hare_Array(grid_size);

		std::cout << __PRETTY_FUNCTION__ << std::endl;


	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Cleans up any resources.
	///
	/// @pre A object of class Population must exist
	/// @post The object of class Population is deleted
	///
	Population::~Population()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

    //////////////////////////////////////////////////////////////////////////////
	/// @details Populates the Hare_array with a pseudo-random distribution between 0 and 5
	///
	/// @param None
	///
	/// @pre
	/// @post Hare_Array is populated with double values between 0 and 5
	///
	/// @exception No exception
	///

    void Population::populate_Hares()
    {
        Array2D<double>::Size grid_size = Hare_Array.GetSize();

        for (unsigned int i=0; i<grid_size.m_x; i++)
        {
            for (unsigned int j=0; j<grid_size.m_y; j++)
            {
                Hare_Array(i,j)=random0x(5);
            }
        }
    }


    //////////////////////////////////////////////////////////////////////////////
	/// @details Populates the Puma_array with a pseudo-random distribution between 0 and 5
	///
	/// @param None
	///
	/// @pre
	/// @post Puma_Array is populated with double values between 0 and 5
	///
	/// @exception No exception
	///

    void Population::populate_Pumas_evenly()
    {
        Array2D<double>::Size grid_size = Puma_Array.GetSize();

        for (unsigned int i=0; i<grid_size.m_x; i++)
        {
            for (unsigned int j=0; j<grid_size.m_y; j++)
            {
                Puma_Array(i,j)=random0x(5);
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    ///@todo implement to take care not to place pumas on water. implement handling with caes where the pack reaches the boundary
	/// @details Populates the Puma_array with pack of Pumas on random choosen places. Ignores if the random location is water or not and if packs are overlapping.
	///
	/// @param number_of_packs...number of packs ditributed
	/// @param size_of_packs...size of packs. a square of pack_size^2 gridpoints with the random position beeing the left upper gridcell is populated with puma density 5
	///
	/// @pre
	/// @post Puma_Array is populated with spezified configuration
	///
	/// @exception No exception
	///

    void Population::populate_Pumas_in_packs(unsigned int number_of_packs, unsigned int size_of_packs)
    {
        unsigned int packlocation_x, packlocation_y;

        Array2D<double>::Size grid_size = Puma_Array.GetSize();

        for(unsigned int i=0; i<number_of_packs; i++)
        {
            pack_location_x=std::floor(rand0x(grid_size.m_x));//generate pack location
            pack_location_y=std::floor(rand0x(grid_size.m_y));

            for(unsigned int i=pack_location_x; i<grid_size.m_x; i++) // populating puma beginning on top left corner of the pack
            {
                for (unsigned int j=packlocation_y; j<grid_size.m_y; j++)
                {
                    Puma_Array(i,j)=5;
                }
            }
        }
    }




    //////////////////////////////////////////////////////////////////////////////
	/// @details returnes a pseudo-random number of type double between 0 and x
	///
	/// @param None
	///
	/// @pre
	/// @post
	///
	/// @exception No exception
	///

    double Population::random0x(unsigned int x)
    {
        return std::rand()*x/(RAND_MAX+0.00001); //scaling the random variable between 0 and RAND_MAX to a value between zero and 5
                                                 // added 0.00001 in the denominator to make it a floating point operation.
    }


}
