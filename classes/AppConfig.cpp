//////////////////////////////////////////////////////////////////////////////
/// @file     AppConfig.cpp
///
/// @brief    Implementation of class AppConfig.
///


//////////////////////////////////////////////////////////////////////////////
//  This class's header.
#include "AppConfig.hpp"


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <iostream>


namespace GroupPractical
{
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Constructor from configuration file name.
	///
	/// @param      cfg_filename  Configuration file name.
	///
	/// @post       Configuration has been loaded.
	///
	/// @exception  List exceptions this function may throw here.
	///
	AppConfig::AppConfig(std::string const& cfg_filename)
		: m_Nx(0)
		, m_Ny(0)
		, m_T(0)
		, m_r(0.0)
		, m_a(0.0)
		, m_b(0.0)
		, m_m(0.0)
		, m_k(0.0)
		, m_l(0.0)
		, m_dt(0.0)

	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		(void) cfg_filename;
		
		//  check file exists
		
		//  read lines in
		
		//  parse lines and store options
	}

	
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Declared private to prevent use.
	///
	AppConfig::AppConfig()
		: m_Nx(0)
		, m_Ny(0)
		, m_T(0)
		, m_r(0.0)
		, m_a(0.0)
		, m_b(0.0)
		, m_m(0.0)
		, m_k(0.0)
		, m_l(0.0)
		, m_dt(0.0)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Describe object destruction here.
	///
	/// @exception  None; this is a destructor.
	///
	AppConfig::~AppConfig()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Describe copy construction here.
	///
	/// @param      rhs  Object to copy.
	///
	/// @pre        List what must be true before this function is called.
	/// @post       List what is guaranteed to be true after this function returns.
	///
	/// @exception  List exceptions this function may throw here.
	///
	AppConfig::AppConfig(AppConfig const& rhs)
		: m_Nx(0)
		, m_Ny(0)
		, m_T(0)
		, m_r(0.0)
		, m_a(0.0)
		, m_b(0.0)
		, m_m(0.0)
		, m_k(0.0)
		, m_l(0.0)
		, m_dt(0.0)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		(void) rhs;
	}


	//////////////////////////////////////////////////////////////////////////////
	/// @details    Describe object assignment here.
	///
	/// @param      rhs Object on the right-hand side of the assignment statement.
	/// @return     Object which has been assigned.
	///
	/// @pre        List what must be true before this function is called.
	/// @post       List what is guaranteed to be true after this function returns.
	///
	/// @exception  List exceptions this function may throw here.
	///
	AppConfig& AppConfig::operator=(AppConfig const& rhs)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		(void) rhs;
		return *this;
	}
	
}   //  namespace GroupPractical
