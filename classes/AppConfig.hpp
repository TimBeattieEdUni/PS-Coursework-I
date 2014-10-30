//////////////////////////////////////////////////////////////////////////////
/// @file     AppConfig.hpp
///
/// @brief    Interface declaration for class AppConfig.
///


#ifndef PSCOURSEWORKI_APPCONFIG_HPP
#define PSCOURSEWORKI_APPCONFIG_HPP


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <string>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Application configuration
	///
	/// @details    Loads popsim's configuration from file and makes items 
	///             available by name.
	///
	/// @invariant  All config is unchanged.
	///
	class AppConfig
	{
		public:
			AppConfig(std::string const& cfg_filename);   ///< Constructor from config file name.
			~AppConfig();                                 ///< Destructor.
			
			unsigned int GetNx() const { return m_Nx; }   ///< Getter.
			unsigned int GetNy() const { return m_Ny; }   ///< Getter.
			unsigned int GetT()  const { return m_T;  }   ///< Getter.
			unsigned int GetTT() const { return m_TT; }   ///< Getter.
		
			double  Getr()  const { return m_r;  }   ///< Getter.
			double  Geta()  const { return m_a;  }   ///< Getter.
			double  Getb()  const { return m_b;  }   ///< Getter.
			double  Getm()  const { return m_m;  }   ///< Getter.
			double  Getk()  const { return m_k;  }   ///< Getter.
			double  Getl()  const { return m_l;  }   ///< Getter.
			double  Getdt() const { return m_dt; }   ///< Getter.

		private:
			AppConfig();                                  ///< Default Constructor.
			AppConfig(AppConfig const& rhs);              ///< Copy constructor.
			AppConfig& operator=(AppConfig const& rhs);   ///< Assignment operator.
		
			void Print();   ///< Writes config to stdout.

			void RemoveComment(std::string & line);       ///< Strips comments from line.
		
			unsigned int  StringToInt    (std::string const& str);   ///< Converts string to integer.
			double        StringToDouble (std::string const& str);   ///< Converts string to double.

			unsigned int m_Nx;   ///< Landscape size on X-axis.
			unsigned int m_Ny;   ///< Landscape size on y-axis.
			unsigned int m_T;    ///< Time steps between outputs.
			unsigned int m_TT;   ///< Total number of time steps in simulation.
		
			double  m_r;    ///< Birth rate of hares.
			double  m_a;    ///< Predation rate at which pumas eat hares.
			double  m_b;    ///< Birth rate of pumas per one hare eaten.
			double  m_m;    ///< Puma mortality rate.
			double  m_k;    ///< Diffusion rate for hares.
			double  m_l;    ///< Diffusion rate for pumas.
			double  m_dt;   ///< Time step.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_APPCONFIG_HPP
