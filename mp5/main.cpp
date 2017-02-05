/**
 * @file main.cpp
 * Contains code to test your Quadtree implementation.
 */

#include <iostream>
#include "png.h"
#include "quadtree.h"

using std::cout;
using std::endl;

void play()
{
  int * a, * b, * c, *d;
  a = b = c = d = NULL;
  cout << a << b << c << d;
}

void mytest()
{
  PNG imgIn, imgOut;
  imgIn.readFromFile("in.png");
  cout << "This is the width/length of in: "  << imgIn.width() << "," << imgIn.height() << endl;

  cout << "Testing copy constructor" << endl;
  Quadtree myTree(imgIn, 128);
  Quadtree copyTree(myTree);
  imgOut = copyTree.decompress();
  // This should have no difference with outHalf
  imgOut.writeToFile("compareWithinOne.png");

  cout << "Testing assignment" << endl;
  Quadtree x;
  x = copyTree;
  imgOut = x.decompress();
  // This should have no difference with outHalf
  imgOut.writeToFile("compareWithinTwo.png");

  cout << "Testing build" << endl;
  imgIn.readFromFile("A.png");
  Quadtree y(imgIn, 128);
  imgIn.readFromFile("in.png");
  y.buildTree(imgIn, 128);
  imgOut = x.decompress();
  // This hould have no difference with outHalf
  imgOut.writeToFile("compareWithinThree.png");

  cout << "Testing delete" << endl;
  Quadtree * p = new Quadtree(imgIn, 64);
  delete p;
  cout << "Have to run this test with valgrind" << endl;

  cout << "Testing getPixel" << endl;
  Quadtree l(imgIn, 128);
  RGBAPixel samOne = l.getPixel(56,73);
  RGBAPixel samTwo = *(imgIn(56,73));

  bool same = true;
  for (int i = 0 ;i < 128; i++)
  {
    for (int j = 0;  j < 128; j++)
    {
      samOne = l.getPixel(i,j);
      samTwo = *(imgIn(i,j));
      same = (samOne == samTwo);
      if (!same)
        break;
    }
    if (!same)
      break;
  }
  cout << "Pixels (all) retrieved are the same" << (same) << endl;


}

void testTwo()
{
  PNG imgIn, imgOut;
  imgIn.readFromFile("in.png");
  Quadtree tinyTree(imgIn, 4);
  cout << "Printing tinyTree:\n";
  tinyTree.printTree();
}

void theirs()
{
  PNG imgIn, imgOut;
  imgIn.readFromFile("in.png");

  // test constructor, decompress
  Quadtree halfTree(imgIn, 128);
  imgOut = halfTree.decompress();
  imgOut.writeToFile("outHalf.png");

  // now for the real tests
  Quadtree fullTree;
  fullTree.buildTree(imgIn, 256);

  // you may want to experiment with different commands in this section

  // test pruneSize and idealPrune (slow in valgrind, so you may want to
  // comment these out when doing most of your testing for memory leaks)
  cout << "fullTree.pruneSize(0) = "      << fullTree.pruneSize(0) << endl;
  cout << "fullTree.pruneSize(100) = "    << fullTree.pruneSize(100) << endl;
  cout << "fullTree.pruneSize(1000) = "   << fullTree.pruneSize(1000) << endl;
  cout << "fullTree.pruneSize(100000) = " << fullTree.pruneSize(100000) << endl;

  cout << "fullTree.idealPrune(1000) = "  << fullTree.idealPrune(1000) << endl;
  cout << "fullTree.idealPrune(10000) = " << fullTree.idealPrune(10000) << endl;

  // Test some creation/deletion functions
  Quadtree fullTree2;
  fullTree2 = fullTree;
  imgOut = fullTree2.decompress();
  imgOut.writeToFile("outCopy.png");

  // test clockwiseRotate
  fullTree.clockwiseRotate();
  imgOut = fullTree.decompress();
  imgOut.writeToFile("outRotated.png");

  // test prune
  fullTree = fullTree2;
  fullTree.prune(1000);
  imgOut = fullTree.decompress();
  imgOut.writeToFile("outPruned.png");

  // test several functions in succession
  Quadtree fullTree3(fullTree2);
  fullTree3.clockwiseRotate();
  fullTree3.prune(10000);
  fullTree3.clockwiseRotate();
  fullTree3.clockwiseRotate();
  fullTree3.clockwiseRotate();
  imgOut = fullTree3.decompress();
  imgOut.writeToFile("outEtc.png");

  // ensure that printTree still works
  Quadtree tinyTree(imgIn, 32);
  cout << "Printing tinyTree:\n";
  tinyTree.prune(100);
  tinyTree.printTree();

}

int main()
{
    // mytest();
    // play();
    // testTwo();
    theirs();
    return 0;
}
