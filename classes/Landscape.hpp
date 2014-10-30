//////////////////////////////////////////////////////////////////////////////
/// @file     Landscape.hpp
///
/// @brief    Interface declaration for class Landscape.
///


#ifndef PSCOURSEWORKI_LANDSCAPE_HPP
#define PSCOURSEWORKI_LANDSCAPE_HPP


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "AppConfig.hpp"


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief
	///
	/// @details
	///
	/// @invariant
	///
	class Landscape
	{
		public:
			Landscape(AppConfig const& cfg);   ///< Constructor.
			~Landscape();                      ///< Destructor.

			void DoStep();                     ///< Updates the landscape by one step.
		
		private:
			Landscape();                                  ///< Default Constructor.
			Landscape(Landscape const& rhs);              ///< Copy constructor.
			Landscape& operator=(Landscape const& rhs);   ///< Assignment operator.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_LANDSCAPE_HPP
