//////////////////////////////////////////////////////////////////////////////
/// @file     Population.hpp
///
/// @brief    Interface declaration for class DemoClass.
///


#ifndef PSCOURSEWORKI_Population_HPP
#define PSCOURSEWORKI_Population_HPP


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

			Array2D<double> Puma_Array; ///< Array of Puma population
			Array2D<double> Hare_Array(); ///< Array of Hare population
			void populate_Pumas_in_packs(unsigned int option); ///< Generates a Puma population
			void populate_puma_evenly();///< Generates a Puma population
			void populate_Hares(); ///< Generates a Hare Population
			//void change_random_seed(unsigned int seednumber); Polish: add option to change seed number

		private:
			double random05();
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_DEMOCLASS_HPP
