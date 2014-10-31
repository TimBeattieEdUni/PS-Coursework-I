//////////////////////////////////////////////////////////////////////////////
/// @file     Population.hpp
///
/// @brief    Interface declaration for class DemoClass.
///


#ifndef PSCOURSEWORKI_Population_HPP
#define PSCOURSEWORKI_Population_HPP

//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "Array2D.hpp"




namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Generate the Puma and Hare ditribution on a Array2D
	///
	/// @details    Populates an Array2D of values with Pumas and one with values for Hares
	///
	///
	class Population
	{
		public:

			Population(Size size, bool timestamp_seed);    ///< Constructor.
			~Population();   ///< Destructor.

			typedef Array2D<double> Population_array;                ///< Type for the Hares and Puma arrays
			Population_array Puma_array;  ///< The Puma population itself.
			Population_array Hare_array;  ///< The Hare population itself.


			//Array2D<double> Puma_Array; ///< Array of Puma population
			//Array2D<double> Hare_Array(); ///< Array of Hare population
			void populate_Pumas_in_packs(unsigned int number_of_packs, unsigned int size_of_packs); ///< Generates a Puma population
			void populate_puma_evenly();///< Generates a Puma population
			void populate_Hares(); ///< Generates a Hare Population
			//void change_random_seed(unsigned int seednumber); Polish: add option to change seed number

		private:
			double random0x(unsigned int x);
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_DEMOCLASS_HPP
