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
	/// @details      Writes all configuration options to stdout.
	///
	/// @todo Ideally, this would be a stream operator.
	///
	void AppConfig::Print()
	{
		std::cout << "configuration:" << std::endl;
		
		std::cout << "  Nx = " << m_Nx << std::endl;
		std::cout << "  Ny = " << m_Ny << std::endl;
		std::cout << "   T = " << m_T  << std::endl;
		std::cout << "  TT = " << m_TT << std::endl;
		std::cout << "   r = " << m_r  << std::endl;
		std::cout << "   a = " << m_a  << std::endl;
		std::cout << "   b = " << m_b  << std::endl;
		std::cout << "   m = " << m_m  << std::endl;
		std::cout << "   k = " << m_k  << std::endl;
		std::cout << "   l = " << m_l  << std::endl;
		std::cout << "  dt = " << m_dt << std::endl;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @details    Constructor from configuration file name.
	///
	/// @param      cfg_filename  Configuration file name.
	///
	/// @post       Configuration has been loaded.
	///
	/// @exception  std::runtime_error  Configuration file could not be opened.
	///
	AppConfigReader::AppConfigReader(std::string const& cfg_filename)
		: m_cfg()
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
			
			//  read key (if any)
			std::string key;
			splitter >> key;
			if (0 == key.size())
			{
				continue;
			}

			//  read value (if any)
			std::string value;
			splitter >> value;

			if (0 == value.size())
			{
				std::cout << cfg_filename << ":" << line_num << ": warning: ignoring line with key but no value" << std::endl;
				std::cout << cfg_filename << ":" << line_num << ": " << line << std::endl;
				continue;				
			}
	
			//  identify which key we've just read
			if (key == "Nx")
			{
				m_cfg.m_Nx = StringToInt(value);
			}
			else if (key == "Ny")
			{
				m_cfg.m_Ny = StringToInt(value);
			}
			else if (key == "T")
			{
				m_cfg.m_T = StringToInt(value); 
			}
			else if (key == "TT")
			{
				m_cfg.m_TT = StringToInt(value);
			}
			else if (key == "r")
			{
				m_cfg.m_r = StringToDouble(value);
			}
			else if (key == "a")
			{
				m_cfg.m_a = StringToDouble(value);
			}
			else if (key == "b")
			{
				m_cfg.m_b = StringToDouble(value);
			}
			else if (key == "m")
			{
				m_cfg.m_m = StringToDouble(value);
			}
			else if (key == "k")
			{
				m_cfg.m_k = StringToDouble(value);
			}
			else if (key == "l")
			{
				m_cfg.m_l = StringToDouble(value);
			}
			else if (key == "dt")
			{
				m_cfg.m_dt = StringToDouble(value);
			}
			else
			{
				std::cout << cfg_filename << ":" << line_num << ": warning: unrecognised key name" << std::endl;
				std::cout << cfg_filename << ":" << line_num << ": " << line << std::endl;				
			}
		}
		
		m_cfg.Print();
	}
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @details      Converts the given string to an unsigned integer.
	///
	/// @param        str  The given string
	/// @return       Integer value read from the given string.
	///
	unsigned int AppConfigReader::StringToInt(std::string const& str)
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
	double AppConfigReader::StringToDouble(std::string const& str)
	{
		double value;
		std::stringstream converter(str);
		
		converter >> value;
		return value;		
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
	void AppConfigReader::RemoveComment(std::string& line)
	{
		line = line.substr(0, line.find('#'));
	}
	

}   //  namespace PsCourseworkI
