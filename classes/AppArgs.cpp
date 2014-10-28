//////////////////////////////////////////////////////////////////////////////
/// @file     AppArgs.cpp
///
/// @brief    Implementation of class AppArgs.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "AppArgs.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>
#include <stdexcept>


namespace GroupPractical
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Copies command line arguments into member variables.
	///
	/// @param      argc Number of arguments.
	/// @param      argv Argument list as array of char pointers.
	///
	/// @post       Command line arguments are in member variables.
	///
	/// @exception  std::logic_error Wrong number of arguments.
	///
	AppArgs::AppArgs(int argc, char** argv)
		: m_cfg_filename()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		if (s_num_args != argc)
		{
			throw std::runtime_error("usage: popsim <config-file>");
		}

		m_cfg_filename = std::string(argv[1]);
	}
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Declared private to prevent use.
	///
	AppArgs::AppArgs()
		: m_cfg_filename()
	{

	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Describe object destruction here.
	///
	/// @param      Describe parameters here, one line each.
	///
	/// @pre        List what must be true before this function is called.
	/// @post       List what is guaranteed to be true after this function returns.
	///
	/// @exception  None; this is a destructor.
	///
	AppArgs::~AppArgs()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Describe copy construction here.
	///
	/// @param      Object to copy.
	///
	/// @pre        List what must be true before this function is called.
	/// @post       List what is guaranteed to be true after this function returns.
	///
	/// @exception  List exceptions this function may throw here.
	///
	AppArgs::AppArgs(AppArgs const& rhs)
		: m_cfg_filename()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		(void) rhs;
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Describe object assignment here.
	///
	/// @param      Object on the right-hand side of the assignment statement.
	/// @return     Object which has been assigned.
	///
	/// @pre        List what must be true before this function is called.
	/// @post       List what is guaranteed to be true after this function returns.
	///
	/// @exception  List exceptions this function may throw here.
	///
	AppArgs& AppArgs::operator=(AppArgs const& rhs)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		(void) rhs;
		return *this;
	}

	
	//////////////////////////////////////////////////////////////////////////////
	/// @return     Config file name.
	///
	/// @pre        Config file name read from command line.
	///
	std::string AppArgs::CfgFilename() const
	{
		return m_cfg_filename;
	}
										 
}   //  namespace GroupPractical
