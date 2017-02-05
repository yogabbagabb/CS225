#include "rgbapixel.h"
#include "png.h"
using namespace std;

#include <iostream>
using std::cout;



/*
Take an image and shift (x,y) to (width - x, height  - y)
*/
PNG * rotateImage(PNG * image)
{
	
	int width = image -> width();
	int height = image -> height();
	PNG * output = new PNG(width, height);
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			RGBAPixel * a = (*image)(x,y); 
			// *(output->(width - x, height - y)) = a;
			*(*output)((width -1 ) - x, (height - 1) - y) = *a;
			
		}
	}

	return output;
}

int main()
{
	PNG * input = new PNG;
	input -> readFromFile("in.png");
	PNG * output = rotateImage(input);
	delete input;
	output -> writeToFile("out.png"); 
	delete output;
}

