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


namespace PsCourseworkI
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
		, m_map_filename()
	{
		if (s_num_args != argc)
		{
			throw std::runtime_error("usage: popsim <config-file> <map-file>");
		}

		std::cout << "reading command line arguments" << std::endl;
		m_cfg_filename = std::string(argv[1]);
		m_map_filename = std::string(argv[2]);
	}
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @return     Config file name.
	///
	/// @pre        Config file name read from command line.
	///
	std::string AppArgs::GetCfgFilename() const
	{
		return m_cfg_filename;
	}
										 

	//////////////////////////////////////////////////////////////////////////////
	/// @return     Map file name.
	///
	/// @pre        Land/water mask file name.
	///
	std::string AppArgs::GetLwMaskFilename() const
	{
		return m_map_filename;
	}

}   //  namespace PsCourseworkI
