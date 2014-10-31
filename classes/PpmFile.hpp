//////////////////////////////////////////////////////////////////////////////
/// @file     PpmFile.hpp
///
/// @brief    Interface declaration for class PpmFile.
///


#ifndef PSCOURSEWORKI_PPMFILE_HPP
#define PSCOURSEWORKI_PPMFILE_HPP


//////////////////////////////////////////////////////////////////////////////
//  Local headers.
#include "Array2D.hpp"
#include "AppConfig.hpp" 


//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <string>
#include <fstream>


namespace PsCourseworkI
{
	//////////////////////////////////////////////////////////////////////////////
	/// @brief        RGB Pixel.
	///
	/// @details      Represents a red-green-blue pixel with maximum component 
	///               value of 255.
	///
	struct Pixel
	{
		/// Constructor from component values.
		Pixel(unsigned char red, unsigned char green, unsigned char blue) 
			: m_red(red)
			, m_green(green)
			, m_blue(blue)
		{
			
		}
		
		unsigned int m_red;     ///< Red component;
		unsigned int m_green;   ///< Green component;
		unsigned int m_blue;    ///< Blue component;
		
	};
	

	//////////////////////////////////////////////////////////////////////////////
	/// @brief      PPM image file writer.
	///
	/// @details    Enables writing images to file in PPM P3 format.
	///
	class PpmFile
	{
		public:
			/// Constructor from filename and image size.
			PpmFile(std::string const& filename, Size const& dimensions, unsigned int const max_rgb_val);
		
			void WritePixel(Pixel const& pixel);      ///< Writes pixel to file.
			void Finalise();                          ///< Closes file.
					
		private:
			PpmFile(PpmFile const& rhs);              ///< Copy constructor.
			PpmFile& operator=(PpmFile const& rhs);   ///< Assignment operator.
		
			unsigned int const m_max_rgb_val;         ///< Maximum value for any pixel RGB component.
			unsigned int m_pixels_written;            ///< Running total of pixels written to file.
			Size m_size;                              ///< Image size in pixels.
			std::ofstream m_out_file;                 ///< The file itself.
	};

}   //  namespace PsCourseworkI


#endif  //  #ndef PSCOURSEWORKI_PPMFILE_HPP
