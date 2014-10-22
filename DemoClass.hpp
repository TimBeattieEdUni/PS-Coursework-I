//////////////////////////////////////////////////////////////////////////////
/// @file     DemoClass.hpp
///
/// @brief    Interface declaration for class DemoClass.
///


#ifndef GROUP_PRACTICAL_DEMOCLASS_HPP
#define GROUP_PRACTICAL_DEMOCLASS_HPP


namespace GroupPractical
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

}   //  namespace GroupPractical


#endif  //  #ndef GROUP_PRACTICAL_DEMOCLASS_HPP

