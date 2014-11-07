//////////////////////////////////////////////////////////////////////////////
/// @file     Timing.cpp
///
/// @brief    Implementation of class Timing.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "Timing.hpp"


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Stores the elapsed time.
	///
	///
	Timing::Timing()
	: m_start(), m_end()
	{

	}


    //////////////////////////////////////////////////////////////////////////////
	/// @details    Sets starting timestamp to current time.
	///
	///
	void Timing::ResetTiming()
	{
	    //set starting time
        gettimeofday(&m_start,NULL); // on windows OS use: GetSystemTime

	}


    //////////////////////////////////////////////////////////////////////////////
	/// @details    Reports the time difference since last reset.
	///
	///
	void Timing::ReportTiming(
                            unsigned int &minutes,
                            unsigned int &seconds,
                            unsigned int &milliseconds
                            )
	{
        // timing:
        gettimeofday(&m_end,NULL);

        unsigned int seconds_diff=(m_end.tv_sec - m_start.tv_sec);
        unsigned int microseconds_diff=(m_end.tv_usec - m_start.tv_usec);

        //  transforming the seconds and microseconds output in usaual format (h,min,sec,msec,usec)

        //uncommend if you want hours
        //hours=(seconds_diff/3600);
        //seconds = seconds_diff - (hours * 3600) - (minutes * 60);

        minutes = seconds_diff / 60;
        seconds = seconds_diff - (minutes * 60);
        milliseconds = microseconds_diff / 1000;
	}

}   //  namespace PsCourseworkI
