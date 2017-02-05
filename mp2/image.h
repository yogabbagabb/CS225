

#ifndef image_H
#define image_H

#include "png.h"

class Image : public PNG
{
	public:

		Image();
		Image(int x, int y, int index);
		Image(const Image& other);
		Image(int a, int b, int c, size_t width, size_t height);	
		void flipleft();
		void adjustbrightness(int r, int g, int b);
		void invertcolors();
		int x;
		int y;
		int index;
		~Image();
		Image& operator=(const Image& other);
	
	private:
		

};

#endif
