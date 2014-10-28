//////////////////////////////////////////////////////////////////////////////
/// @file     AppArgs.hpp
///
/// @brief    Interface declaration for class AppArgs.
///


#ifndef GROUP_PRACTICAL_APPARGS_HPP
#define GROUP_PRACTICAL_APPARGS_HPP


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <string>


namespace GroupPractical
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief      Command-line arguments.
	///
	/// @details    Makes command-line arguments available by name.
	///
	class AppArgs
	{
		public:
			AppArgs(int argc, char** argv);   ///< Constructor.
			~AppArgs();                                         ///< Destructor.
		
			std::string CfgFilename() const;                    ///< Getter.

		private:
			AppArgs();                                          ///< Default constructor.
			AppArgs(AppArgs const& rhs);                        ///< Copy constructor.
			AppArgs& operator=(AppArgs const& rhs);             ///< Assignment operator.

			static const int s_num_args = 2;                    ///< Required arguments including exe name.
			std::string m_cfg_filename;                         ///< Configuration file name.
	};

}   //  namespace GroupPractical


#endif  //  #ndef GROUP_PRACTICAL_APPARGS_HPP
