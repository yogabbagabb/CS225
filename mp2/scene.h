#ifndef scene_H
#define scene_H

class Scene
{
public:
	Scene();
	~Scene();
	Scene(int x);
	Scene(const Scene &souce);
    const Scene & operator=(const Scene &source);
    void changemaxlayers(int newmax);
	void addpicture (const char *FileName, int index, int x, int y);
	void changelayer(int index, int newindex);
	void translate(int index, int xcoord, int ycoord);
	void deletepicture(int index);
	Image* getpicture(int index) const;
	Image drawscene() const;
	void destroyImages();


private:
	int max;
	Image ** images;
	void grumble() const;
	bool testFail(int index) const;
	void mark(int n) const;
	int* getDimensions () const;
	void pasteOn(Image& canvas, Image& source) const;
};

#endif
