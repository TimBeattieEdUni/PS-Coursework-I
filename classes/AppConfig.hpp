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
	/// @todo Add input file names.
	///
	class AppConfig
	{
		public:
			/// Constructor from config file name.
			AppConfig(std::string const& cfg_filename);
		
			~AppConfig();      ///< Destructor.
			
			int     GetNx() { return m_Nx; }   ///< Getter.
			int     GetNy() { return m_Ny; }   ///< Getter.
			int     GetT()  { return m_T;  }   ///< Getter.
			int     GetTT() { return m_TT; }   ///< Getter.
			double  Getr()  { return m_r;  }   ///< Getter.
			double  Geta()  { return m_a;  }   ///< Getter.
			double  Getb()  { return m_b;  }   ///< Getter.
			double  Getm()  { return m_m;  }   ///< Getter.
			double  Getk()  { return m_k;  }   ///< Getter.
			double  Getl()  { return m_l;  }   ///< Getter.
			double  Getdt() { return m_dt; }   ///< Getter.

		private:
			AppConfig();                                  ///< Default Constructor.
			AppConfig(AppConfig const& rhs);              ///< Copy constructor.
			AppConfig& operator=(AppConfig const& rhs);   ///< Assignment operator.

			int     m_Nx;   ///< Landscape size on X-axis.
			int     m_Ny;   ///< Landscape size on y-axis.
			int     m_T;    ///< Time steps between outputs.
			int     m_TT;   ///< Total number of time steps in simulation.
			double  m_r;    ///< Birth rate of hares.
			double  m_a;    ///< Predation rate at which pumas eat hares.
			double  m_b;    ///< Birth rate of pumas per one hare eaten.
			double  m_m;    ///< Puma mortality rate.
			double  m_k;    ///< Diffusion rate for hares.
			double  m_l;    ///< Diffusion rate for pumas.
			double  m_dt;   ///< Time step in seconds.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_APPCONFIG_HPP
