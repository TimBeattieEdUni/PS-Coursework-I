//////////////////////////////////////////////////////////////////////////////
/// @file     Landscape.hpp
///
/// @brief    Interface declaration for class Landscape.
///


#ifndef GROUP_PRACTICAL_LANDSCAPE_HPP
#define GROUP_PRACTICAL_LANDSCAPE_HPP


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "AppConfig.hpp"


namespace GroupPractical
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
			Landscape(AppConfig const& cfg);    ///< Constructor.
			~Landscape();                       ///< Destructor.

		private:
			Landscape();                                  ///< Default Constructor.
			Landscape(Landscape const& rhs);              ///< Copy constructor.
			Landscape& operator=(Landscape const& rhs);   ///< Assignment operator.
	};

}   //  namespace GroupPractical


#endif  //  #ndef GROUP_PRACTICAL_LANDSCAPE_HPP
