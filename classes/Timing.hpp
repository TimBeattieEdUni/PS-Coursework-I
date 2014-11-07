//////////////////////////////////////////////////////////////////////////////
/// @file     Timing.hpp
///
/// @brief    Interface declaration for class Timing.
///


#ifndef PSCOURSEWORKI_TIMING_HPP
#define PSCOURSEWORKI_TIMING_HPP


//////////////////////////////////////////////////////////////////////////////
//  Local headers.



//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <ctime>
#include <sys/time.h>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Stopwatch class for timing.
	///
	/// @details    Start and report elapsed time.
	///
	class Timing
	{
		public:
            Timing();                                        ///< Constructor.

            void ResetTiming();                              ///< Setter
            void ReportTiming(unsigned int &minutes,
                              unsigned int &seconds,
                              unsigned int &milliseconds);  ///< Getter

		private:
            timeval m_start,m_end;                          ///< Time stamps

	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_TIMING_HPP
