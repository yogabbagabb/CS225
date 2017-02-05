/**********************************************************
 * testscene.cpp -- part of CS225 MP2
 *
 * This file performs some basic tests of the Scene class.
 * It is not intended to catch every possible error.You may
 * modifty this or write your own testscene.cpp to perform
 * additional tests.
 *
 *   Author: Jonathan Ray
 *   Date: 02 Feb 2007
 */

#include "image.h"
#include "scene.h"

#include <iostream>
using std::cout;
using std::endl;

void mark(int n)
{
cout << "Mark " << n << endl;
}

int main()
{

	Scene* s;

	//TOC
	/*
		1) Out of bounds in addPicture, both negative and overflow values tested
		2) getPicture gets and addP sends
		3) Tests changeLayer
		4) Test translate	
		5) Tests changemaxlayers
		6) Tests drawScene
	*/


	//1) This tests out of bounds in addpicture	
	
	s = new Scene(2);
	s->addpicture("in_01.png", -1, 0,0);
	delete s;
	s = NULL;
	
	// 2) This tests that getPicture successfully retrieves a picture sent by addP

	s = new Scene(2);
	s->addpicture("in_01.png", 0, 0,0);
	mark(1);
	s->addpicture("in_02.png",1,0,0);	
	mark(2);	
	Image * sample = s->getpicture(0);
	mark(3);	
	sample ->writeToFile("in1test.png");
	sample = s->getpicture(1);
	mark(4);	
	cout << sample << endl;
	sample ->writeToFile("in2test.png");
	mark(5);
		
	delete s;
		

	// 3) This tests whether change makes any allocation (it shouldn't) and whether
	// it succeeds in moving an index;
	s = new Scene(3);
	s->addpicture("in_01.png", 0, 0,0);
	s->addpicture("in_02.png",1,0,0);
	s->changelayer(0,1);
	 sample = s->getpicture(1);	
	sample ->writeToFile("a.png");
	cout << s->getpicture(0) << endl;
	delete s; 

	//4) Tests whether translate changes to the correct range
	/*s = new Scene(3);
	s->addpicture("in_01.png", 0, 0,0);
	s->translate(0, 3, 4);	
	cout << (s->getpicture(0))->y << endl;
	mark(3);	
	delete s;*/


	//5) Tests changemaxlayers
	
	s = new Scene(3);
	s->addpicture("in_01.png", 0, 0,0);
	s->addpicture("in_02.png",1,0,0);
	s->addpicture("in_03.png",2,0,0);
	mark(2);
	s->changemaxlayers(2);
	mark(1);
		
 sample = s->getpicture(0);	
	sample ->writeToFile("a.png");	
	sample = s->getpicture(1);	
	sample ->writeToFile("b.png");	
	sample = s->getpicture(2);	
	cout << sample << endl;
	delete s; 
	
	cout <<  "Test for newmax < max" << endl;
	s = new Scene(3);
	s->addpicture("in_01.png", 0, 0,0);
	s->addpicture("in_02.png",1,0,0);
	s->addpicture("in_03.png",2,0,0);
	s->changemaxlayers(2);

	sample = s->getpicture(0);	
	sample ->writeToFile("a.png");	
	sample = s->getpicture(1);	
	sample ->writeToFile("b.png");	
	sample = s->getpicture(2);	
	cout << sample << endl;
	delete s;

	cout << "Test for newmax > max " << endl;
	s = new Scene(3);
	s->addpicture("in_01.png", 0, 0,0);
	s->addpicture("in_02.png",1,0,0);
	s->addpicture("in_03.png",2,0,0);
	s->changemaxlayers(10);

	sample = s->getpicture(0);	
	sample ->writeToFile("a.png");	
	sample = s->getpicture(1);	
	sample ->writeToFile("b.png");	
	sample = s->getpicture(2);	
	cout << sample << endl;
	delete s;
	
	//Test for newmax = max;

	cout <<  "Test for newmax = max" << endl;
	s = new Scene(2);
	s->addpicture("in_01.png", 0, 0,0);
	s->addpicture("in_02.png",1,0,0);
	sample = s->getpicture(0);
        cout << sample << endl;
        sample = s->getpicture(1);
        cout << sample << endl;
	s->changemaxlayers(2);

	sample = s->getpicture(0);	
	cout << sample << endl;
	sample = s->getpicture(1);	
	cout << sample << endl;
	delete s;
	
	
	// 6) Tests the dimensions helper method in drawScene(). Note that the print statement
		// is printed internally in drawscene as oppposed to here -- sorry
		/*s = new Scene(3);
		s->addpicture("in_01.png", 0, 100, 100);
    	s->addpicture("in_02.png", 1, 0, 100);
    	s->addpicture("in_03.png", 2, 50, 50);
		Image fin = s->drawscene();
		fin.writeToFile("c.png");
		*/	
	/*
		My tests are above, theirs below
	*/
	
   

	// I do some stuff starting here
	/*cout << "I start" << endl;
	Image mag = *(set-> getpicture(0));
	mag.writeToFile("a.png");
	cout << set->getpicture(1) << endl;

	mag = *(set-> getpicture(2));
	cout << set->getpicture(4) << endl;
	mag.writeToFile("b.png");
	mag = *(set-> getpicture(3));
	mag.writeToFile("c.png");
	cout << "I end" << endl;*/
	// I stop doing some stuff starting here 
	
   	/*Scene* set = new Scene(5);
    set->addpicture("in_01.png", 0, 0, 0);
    set->addpicture("in_02.png", 1, 60, 60);
    set->addpicture("in_03.png", 2, 150, 0);
    Image result = set->drawscene();
    result.writeToFile("scene.png");

    set->changelayer(1, 3);
    result = set->drawscene();
    result.writeToFile("scene2.png");

    set->translate(0, 50, 50);
    result = set->drawscene();
    result.writeToFile("scene3.png");

    set->getpicture(0)->adjustbrightness(-70, -70, -70);
    result = set->drawscene();
    result.writeToFile("scene4.png");

    set->deletepicture(3);
    result = set->drawscene();
    result.writeToFile("scene5.png");

    Scene* sc = new Scene(*set);
    sc->getpicture(0)->flipleft();
    result = set->drawscene();
    result.writeToFile("scene6.png"); // scene 5 and scene 6 should be the same
    result = sc->drawscene();
    result.writeToFile("scene7.png");

    delete set;
    set = new Scene(5);
    *set = *sc;
    result = set->drawscene();
    result.writeToFile("scene8.png"); // scene7 and scene8 should be the same.
    delete set;
    delete sc;
	*/

	
	// tests assignment operator below
	/*
	Scene * s = new Scene (2);

	s->addpicture("in_01.png",0,0,0);
	Scene p (3);
	Scene q (4);
	cout << s->getpicture(0) << endl;
	s->getpicture(1);
	q = p = *s;

	Image * m = q.getpicture(0);
	m->writeToFile("a.png");
	delete s;
	*/


    return 0;
	
}
