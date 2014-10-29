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
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>


namespace PsCourseworkI
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
		, m_TT(0)
		, m_r(0.0)
		, m_a(0.0)
		, m_b(0.0)
		, m_m(0.0)
		, m_k(0.0)
		, m_l(0.0)
		, m_dt(0.0)

	{
		std::cout << "loading configuration from file \"" << cfg_filename << "\"" << std::endl;
		
		//  open file
		std::ifstream cfg_file(cfg_filename.c_str());
		if (! cfg_file.good())
		{
			throw std::runtime_error("failed to open config file");
		}
		
		//  process lines
		std::string line;
		unsigned int line_num = 0;
		while (std::getline(cfg_file, line))
		{
			++line_num;
			
			RemoveComment(line);
			
			std::istringstream splitter(line);
			
			//  read key
			std::string key;
			splitter >> key;
			
			//  ignore lines which are whitespace-only
			if (0 == key.size())
			{
				continue;
			}

			//  read value
			std::string value;
			splitter >> value;

			//  "key but no value" means bad line
			if (0 == value.size())
			{
				std::cout << cfg_filename << ":" << line_num << ": warning: ignoring line with key but no value" << std::endl;
				std::cout << cfg_filename << ":" << line_num << ": " << line << std::endl;
				continue;				
			}
	
			//  identify which key we've just read
			if (key == "Nx")
			{
				m_Nx = StringToInt(value);
			}
			else if (key == "Ny")
			{
				m_Ny = StringToInt(value);
			}
			else if (key == "T")
			{
				m_T = StringToInt(value); 
			}
			else if (key == "TT")
			{
				m_TT = StringToInt(value);
			}
			else if (key == "r")
			{
				m_r = StringToDouble(value);
			}
			else if (key == "a")
			{
				m_a = StringToDouble(value);
			}
			else if (key == "b")
			{
				m_b = StringToDouble(value);
			}
			else if (key == "m")
			{
				m_m = StringToDouble(value);
			}
			else if (key == "k")
			{
				m_k = StringToDouble(value);
			}
			else if (key == "l")
			{
				m_l = StringToDouble(value);
			}
			else if (key == "dt")
			{
				m_dt = StringToDouble(value);
			}
			else
			{
				std::cout << cfg_filename << ":" << line_num << ": warning: unrecognised key name" << std::endl;
				std::cout << cfg_filename << ":" << line_num << ": " << line << std::endl;				
			}
		}
	}

	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Converts the given string to an unsigned integer.
	///
	/// @param        str  The given string
	/// @return       Integer value read from the given string.
	///
	unsigned int AppConfig::StringToInt(std::string const& str)
	{
		unsigned int value;
		std::stringstream converter(str);
		
		converter >> value;
		return value;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Converts the given string to a double.
	///
	/// @param        str  The given string
	/// @return       Double value read from the given string.
	///
	double AppConfig::StringToDouble(std::string const& str)
	{
		double value;
		std::stringstream converter(str);
		
		converter >> value;
		return value;		
	}
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Declared private to prevent use.
	///
	AppConfig::AppConfig()
		: m_Nx(0)
		, m_Ny(0)
		, m_T(0)
		, m_TT(0)
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

	}

	//////////////////////////////////////////////////////////////////////////////
	/// @details      Strips comment (anything beginning with '#' from the given 
	///               string.
	///
	/// @param        line  Line from configuration file.
	///
	/// @post         Any comment in the given line has been removed.
	///
	/// @exception    
	///
	void AppConfig::RemoveComment(std::string& line)
	{
		line = line.substr(0, line.find('#'));
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
		, m_TT(0)
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
	
}   //  namespace PsCourseworkI
