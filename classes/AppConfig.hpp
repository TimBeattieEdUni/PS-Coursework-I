//////////////////////////////////////////////////////////////////////////////
/// @file     AppConfig.hpp
///
/// @brief    Interface declaration for class AppConfig.
///


#ifndef GROUP_PRACTICAL_APPCONFIG_HPP
#define GROUP_PRACTICAL_APPCONFIG_HPP


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <string>


namespace GroupPractical
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
			/// Constructor from config file name.
			AppConfig(std::string const& cfg_filename);
		
			~AppConfig();      ///< Destructor.
			
			int     GetNx();   ///< Getter.
			int     GetNy();   ///< Getter.
			int     GetT();    ///< Getter.
			double  Getdt();   ///< Getter.
			double  Getr();    ///< Getter.
			double  Geta();    ///< Getter.
			double  Getb();    ///< Getter.
			double  Getm();    ///< Getter.
			double  Getk();    ///< Getter.
			double  Getl();    ///< Getter.

		private:
			AppConfig();                                  ///< Default Constructor.
			AppConfig(AppConfig const& rhs);              ///< Copy constructor.
			AppConfig& operator=(AppConfig const& rhs);   ///< Assignment operator.

			int     m_Nx;   ///< Landscape size on X-axis.
			int     m_Ny;   ///< Landscape size on y-axis.
			int     m_T;    ///< Time steps between outputs.
			double  m_r;    ///< Birth rate of hares.
			double  m_a;    ///< Predation rate at which pumas eat hares.
			double  m_b;    ///< Birth rate of pumas per one hare eaten.
			double  m_m;    ///< Puma mortality rate.
			double  m_k;    ///< Diffusion rate for hares.
			double  m_l;    ///< Diffusion rate for pumas.
			double  m_dt;   ///< Time step in seconds.
	};

}   //  namespace GroupPractical


#endif  //  #ndef GROUP_PRACTICAL_APPCONFIG_HPP
