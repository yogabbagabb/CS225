
#include "image.h"


#include <iostream>
using std::cout;
using std::endl;

Image::Image()
{
	x = 0;
	y = 0;
	index = 0;
}


Image::Image(int a, int b, int c)
{
	x = a;
	y = b;
	index = c;
}

Image::Image(int a, int b, int c, size_t width, size_t height): PNG(width, height)
{
	x = a;
	y = b;
	index = c;	
}
Image::Image(const Image& other): PNG(other)
{
	x = other.x;
	y = other.y;
	index = other.index;	
}

Image::~Image()
{
	/*
		Automatically taken care of...
	*/
}

Image& Image::operator=(const Image& other)
{
	if (this != &other)
	{	
		this -> x = other.x ;
		this -> y = other.y;
		this -> index = other.index;

		this -> PNG::operator=(other);
	}

	return (*this);
}

void Image::flipleft()
{
	int xLength = width();
	
	int yLength = height();
	
	int midPoint = xLength/2;
	RGBAPixel temp;

	for (int i = 0; i < yLength; i++)
	{
		for (int j= 0; j < midPoint; j++)
		{
			temp = *((*this)(xLength -1 - j, i));
			
			 *((*this)(xLength - 1- j, i)) = 
			 *((*this)( j, i));
			 *((*this)( j, i)) = temp;
			
		}
	}

	
	


}

void Image::adjustbrightness(int r, int g, int b)		
{
	
	int xLength = this-> width();
	int yLength = this -> height();
	

	RGBAPixel * current;
	int ceil = 255;
	int floor = 0;
	
	for (int i = 0; i < yLength; i++)
	{
		for (int j= 0; j < xLength; j++)
		{
			current = (*this)(j,i);
			int sumR = current -> red + r;
		
			if (sumR > 255)
			{
				current -> red = ceil;
			}

			else if (sumR < 0)
			{		
				current -> red = floor;
			}
			else
			{
				current -> red = sumR;
			}
			
			/*
				BLUE TIME
			*/

			int sumB = current -> blue + b;
			

		
			if (sumB > 255)
			{
				current -> blue = ceil;
			}

			else if (sumB < 0)
			{		
				current -> blue = floor;
			}
			else
			{
				current -> blue = sumB;
			}

			/*
				GREEN TIME
			*/

			int sumG = current -> green+ g;

			if (sumG > 255)
			{
				current -> green = ceil;
			}

			else if (sumG < 0)
			{		
				current -> green = floor;
			}
			else
			{
				current -> green = sumG;
			}
		}
	}

	
	
}


void Image::invertcolors()
{

	int xLength = this->width();
	int yLength = this -> height();
	

	RGBAPixel * current;
	int diff = 255;

	for (int i = 0; i < yLength; i++)
	{
		for (int j= 0; j < xLength; j++)
		{
			current = (*this)(j,i);
			(*current).red = -(*current).red + diff;
			(*current).green = -(*current).green + diff;
			(*current).blue = -(*current).blue + diff;
			

		}
	}
	


}
