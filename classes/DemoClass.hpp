//////////////////////////////////////////////////////////////////////////////
/// @file     DemoClass.hpp
///
/// @brief    Interface declaration for class DemoClass.
///


#ifndef PSCOURSEWORKI_DEMOCLASS_HPP
#define PSCOURSEWORKI_DEMOCLASS_HPP


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Demonstration class.
	///
	/// @details    Provides an example of how a basic class can be declared and 
	///             Doxygen-documented.
	///
	class DemoClass
	{
		public:
			DemoClass();    ///< Constructor.
			~DemoClass();   ///< Destructor.

		private:
			DemoClass(DemoClass const& rhs);              ///< Copy constructor.
			DemoClass& operator=(DemoClass const& rhs);   ///< Assignment operator.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_DEMOCLASS_HPP

