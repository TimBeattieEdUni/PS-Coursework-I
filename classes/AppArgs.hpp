//////////////////////////////////////////////////////////////////////////////
/// @file     AppArgs.hpp
///
/// @brief    Interface declaration for class AppArgs.
///


#ifndef PSCOURSEWORKI_APPARGS_HPP
#define PSCOURSEWORKI_APPARGS_HPP


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <string>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Command-line arguments.
	///
	/// @details    Makes command-line arguments available by name.
	///
	class AppArgs
	{
		public:
			AppArgs(int argc, char** argv);           ///< Constructor.
		
			std::string GetCfgFilename() const;       ///< Getter.
			std::string GetMapFilename() const;       ///< Getter.

		private:
			AppArgs(AppArgs const& rhs);              ///< Copy constructor.
			AppArgs& operator=(AppArgs const& rhs);   ///< Assignment operator.

			static const int s_num_args = 3;          ///< Required arguments including exe name.
			std::string m_cfg_filename;               ///< Configuration file name.
			std::string m_map_filename;               ///< Land/water map file name.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_APPARGS_HPP
