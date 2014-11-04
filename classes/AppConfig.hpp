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
	/// @brief      Application configuration.
	///
	/// @details    Stores all application configuration options.
	///
	/// @invariant  All config is unchanged.
	///
	struct AppConfig
	{
		void Print();   ///< Writes config to stdout.

		///  Variable names as per the Group Coursework handout.
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
	
	
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Application configuration reader.
	///
	/// @details    Loads popsim's configuration from file and makes items 
	///             available by name.
	///
	class AppConfigReader
	{
		public:
			AppConfigReader(std::string const& cfg_filename);         ///< Constructor from config file name.
			AppConfigReader();                                        ///< Destructor.
		
			AppConfig const& GetConfig() const { return m_cfg; }      ///< Getter.
			
		private:
			AppConfigReader(AppConfigReader const& rhs);              ///< Copy constructor.
			AppConfigReader& operator=(AppConfigReader const& rhs);   ///< Assignment operator.
		
			void          RemoveComment(std::string & line);          ///< Strips comments from line.
			unsigned int  StringToInt    (std::string const& str);    ///< Converts string to integer.
			double        StringToDouble (std::string const& str);    ///< Converts string to double.

			AppConfig m_cfg;                                          ///< The configuration itself.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_APPCONFIG_HPP
