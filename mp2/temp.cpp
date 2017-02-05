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


