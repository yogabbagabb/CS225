#include "image.h"
		
#include "scene.h"

#include<iostream>
using std::cout;
using std::endl;

	Scene::Scene()
	{
		max = 0;
		images = NULL;
	}
	Scene::Scene(int val)
	{
		max = val;
		images = new Image * [val];
		for (int i = 0; i < max; i++)
		{
			images[i] = NULL;
		
		}
	}
	Scene::~Scene()
	{
		destroyImages();
	}
    
	void Scene::destroyImages()
	{
		

		for (int i = 0; i < max; i++)
		{

			if (images[i] != NULL)
			{
				delete images[i];
				images[i] = NULL;
			}
		}



		delete []images;


	}

	Scene::Scene(const Scene& source)
	{
		max = source.max;
		images = new Image *[max];

		for (int i = 0; i  < max; i++)
		{
			if (source.images[i])
				images[i] = new Image(*(source.images[i]));
			else
				images[i] = NULL;		
		}

	}
	
    const Scene& Scene::operator=(const Scene& source)
	{
		// where are the members of a dynomically allocated thingy stored?
		// what do != and == do by default?

		if (this != &source)
		{
		
			max = source.max;

		//try using clear(); instead of destroyImages?
			destroyImages();
			images = new Image *[max];
		
			for (int i = 0; i  < max; i++)
			{
	 
				if (source.images[i])
					images[i] = new Image(*(source.images[i]));
				else
					images[i] = NULL;		
			}
		}
	
		return *this;
	}
    void Scene::changemaxlayers(int newmax)
	{
		if (newmax < max)
		{
			for (int i = newmax; i <= max - 1; i++)
			{
				if (images[i] != NULL)
					{	this -> grumble();
						return;					
					}
			}			
		}

		if (newmax == max)
			return;
		
		Image ** temp = images;
		images = new Image *[newmax];
		int min = (newmax < max)? newmax : max;

		for (int i = 0; i < min; i++)
		{
			images[i] = temp[i];
		}

		for (int i = min; i < newmax; i++)
		{
			images[i] = NULL;
		}
	
		max = newmax;
		delete temp;
				
	}
    void Scene::addpicture (const char *FileName, int index, int x, int y)
	{
		if (index > (this->max) - 1 || index < 0)
		{	
			this->grumble();
			return;
		}
		
		// note Can we assume FileName is valid?
		

		Image * toAdd = new Image (x,y,index);
		std::string file(FileName);
		toAdd -> readFromFile(file);
		delete images[index];
		images[index] = toAdd;
		
		
	}
    void Scene::changelayer(int index, int	newIndex)
	{

		if (this -> testFail(index))
			return;

		if (this -> testFail(newIndex))
			return;

		if (newIndex == index)
			return;

		delete images[newIndex];
		images[newIndex] = images[index];
		images[newIndex] -> index = newIndex;
		images[index] = NULL; 
			
		
	}

    void Scene::translate(int index, int xcoord, int ycoord)
	{
		if (this -> testFail(index))
			return; 	

		if (images[index] == NULL)
		{
			this -> grumble();
			return;
		}

		images[index] -> x = xcoord;

		images[index] -> y = ycoord;

	
	}
    void Scene::deletepicture(int index)
	{
		if (this -> testFail(index))
			return; 	

		if (images[index] == NULL)
		{
			this -> grumble();
			return;
		}

		delete images[index];
		images[index] = NULL;
	}
    
	Image* Scene::getpicture(int index) const
	{	
		if (index > max-1 || index < 0)
		{
			this -> grumble();
			return NULL;
		}
		
		if (images[index] == NULL)
		{
			this -> grumble();
			return NULL;
		}

		return images[index];
		
	}


    Image Scene::drawscene() const
	{
		int * dimensions = getDimensions();
		Image scene (0,0,-1, dimensions[0], dimensions[1]);
		delete dimensions;
		dimensions = NULL;
		
		for (int i = 0; i < max; i++)
		{					
			if (images[i])
				pasteOn(scene, *images[i]);
		}			
		

		return scene;
		
		
	}

	/*Takes an image and draws it onto the canvas
		Assumption: source can fit onto this canvas
	*/	
	void Scene::pasteOn(Image& canvas, Image& source) const
	{
		int startX = source.x;
		int startY = source.y;
		int stopX = startX + source.width();
		int stopY = startY + source.height();
		
		
		for (int i = startX; i < stopX; i++)
		{
			for (int j = startY; j < stopY; j++)
			{
				*canvas(i,j) = *source(i - startX, j - startY);
			}
		}

	}

	/*
		Returns an int*, containing the minimum dimensions needed for the colllage.
		the int* contains two entries: height and width
	*/
	int* Scene::getDimensions () const
	{
			int maxX = 0;
			int maxY = 0;
			
			for (int i = 0; i < max; i++)
			{
				if (images[i] != NULL)
				{
					int contenderX = images[i]->x + images[i] -> width();
					int contenderY = images[i]->y + images[i] -> height();

					maxX = (maxX > contenderX)? maxX : contenderX;
					maxY = (maxY > contenderY)? maxY : contenderY;
				}
			}

			int d_size = 2;
			int * dimensions = new int [d_size];
			dimensions[0] = maxX; dimensions[1] = maxY;
			return dimensions;	
	}

	bool Scene::testFail(int index) const
	{
		if (index > (this->max) - 1 || index < 0)
		{	
			this->grumble();
			return true;
		}

		return false;
	}

	void Scene::grumble() const
	{
		cout << "index out of bounds" << endl;
	}

	void Scene::mark(int n) const
	{
		cout << "mark: " << n << endl;
	}


