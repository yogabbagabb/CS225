#include "list.h"
#include "blockpng.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;


void line()
{
  cout << "_____" << endl;
}

void after()
{
  cout << "After" << endl;
}

void before(string arg)
{
  cout << "Before " << arg << endl;
}

void testMemoryDestruction()
{
//
  List<int> intList;
  intList.insertFront(4);
  intList.insertFront(3);
  intList.insertFront(4);
  intList.print(std::cout);

  List<int> * secList = new List<int> ();
  secList ->insertFront(4);
  secList ->insertFront(22);
  delete secList;

}

void testMySplit()
{
    List<int> intList;
    for (int i = 0 ; i < 4; i++)
    {
      intList.insertFront(i);
    }

    cout << "Testing on size 2 of 4" << endl;

    cout << "Before" << endl;
    intList.print(cout);
    List<int> output = intList.split(2);
    cout << "After, the resulting list:" << endl;
    output.print(cout);
    cout << "And the original one" << endl;
    intList.print(cout);

    List<int> secIntList;
    for (int i = 0 ; i < 14; i++)
    {
      secIntList.insertFront(i);
    }

    cout << "Testing on size 5 of 14" << endl;

    cout << "Before" << endl;
    secIntList.print(cout);
    List<int> secOutput = secIntList.split(5);
    cout << "After, the resulting list:" << endl;
    secOutput.print(cout);
    cout << "And the original one" << endl;
    secIntList.print(cout);

    List<int> thirdIntList;
    for (int i = 0 ; i < 4; i++)
    {
      thirdIntList.insertFront(i);
    }

    cout << "Testing on size 0 of 4" << endl;

    cout << "Before" << endl;
    thirdIntList.print(cout);
    List<int> thirdOutput = thirdIntList.split(0);
    cout << "After, the resulting list:" << endl;
    thirdOutput.print(cout);
    cout << "And the original one" << endl;
    thirdIntList.print(cout);


    List<int> fourthIntList;

    cout << "Testing on size 0 of 0" << endl;

    cout << "Before" << endl;
    fourthIntList.print(cout);
    List<int> fourthOutput = fourthIntList.split(1);
    cout << "After, the resulting list:" << endl;
    fourthOutput.print(cout);
    cout << "And the original one" << endl;
    fourthIntList.print(cout);

}
void testMyWaterfall()
{
  List<int> intList;
  intList.print(std::cout);
  std::cout << "After waterfall" << std::endl;
  intList.waterfall();
  std::cout << "size:" << intList.size();
  intList.print(std::cout);

  intList.insertFront(1);
  intList.print(std::cout);
  std::cout << "After waterfall" << std::endl;
  intList.waterfall();
  intList.print(std::cout);

  intList.insertBack(2);
  intList.print(std::cout);
  std::cout << "After waterfall" << std::endl;
  intList.waterfall();
  intList.print(std::cout);

  intList.insertBack(3);
  intList.insertBack(4);
  intList.insertBack(5);
  intList.insertBack(6);
  intList.insertBack(7);
  intList.insertBack(8);
  intList.print(std::cout);
  std::cout << "After waterfall" << std::endl;
  intList.waterfall();
  std::cout << "size:" << intList.size();
  intList.print(std::cout);

}

void testMyMerge()
{



  List<int> intList;
  for (int i = 0; i < 9; i++)
  {
    intList.insertBack(i);
  }

  List<int> secList;
  for (int i = 3; i < 9; i++)
  {
    secList.insertBack(i);
  }

  intList.mergeWith(secList);
  intList.print(cout);
  cout << "testing if parameter list is blank" << endl;
  secList.print(cout);

  List<int> list;
  List<int> mlist;
  for (int i = 0; i < 3; i++)
  {
    list.insertBack(i);
  }

  for (int i = 0; i < 3; i++)
  {
    mlist.insertBack(i);
  }

  list.mergeWith(mlist);
  list.print(cout);
  cout << "testing if parameter list is blank" << endl;
  mlist.print(cout);





  List<int> blank;
  List<int> full;
  full.insertBack(1);

  blank.mergeWith(full);
  blank.print(cout);


  List<int> sblank;
  List<int> sfull;
  sfull.insertBack(1);

  sfull.mergeWith(sblank);
  sfull.print(cout);


  List<int> mer;
  mer.insertBack(1);
  List<int> merm;
  merm.insertBack(0);
  mer.mergeWith(merm);
  mer.print(cout);

}

void testMyMergeSort()
{
  List<int> intList;
  for (int i  = 0; i < 10; i++)
  {
    intList.insertFront(i);
  }

  intList.sort();
  intList.print(cout);

  List<int> secList;
  for (int i = 0; i < 34; i++)
  {
    secList.insertFront(rand() % 10  + 1);
    intList.insertFront(rand() % 10  + 1);
  }

  before("sort -- added to list");
  intList.print(cout);
  line();
  after();
  intList.sort();
  intList.print(cout);

  before("secList sorted");
  secList.print(cout);
  secList.sort();
  line();
  after();
  secList.print(cout);

  secList.reverseNth(4);
  cout << "after reverseNth:" << endl;
  secList.print(cout);
  cout << "after another sort:" << endl;
  secList.sort();
  secList.print(cout);

  cout << "after reverseNth:" << endl;
  secList.reverseNth(6);
  secList.print(cout);
  line();
  after();
  secList.sort();
  secList.print(cout);

  cout  << "Before (for blank list)" << endl;
  List<int>finalList;
  finalList.print(cout);
  after();
  line();
  finalList.sort();
  finalList.print(cout);

  before("already sorted");
  secList.print(cout);
  line();
  after();
  secList.sort();
  secList.print(cout);

  List<int> another;
  for (int i =0 ;i  < 10; i++)
  {
    another.insertFront(2);
  }
  before("dupes");
  another.print(cout);
  line();
  after();
  another.sort();
  another.print(cout);




}

void testMyReverseNth()
{
  List<int> intList;
  intList.insertFront(2);
  intList.insertFront(3);
  intList.insertFront(4);
  intList.insertFront(3);
  intList.insertFront(7);
  intList.print(std::cout);
  std::cout << "After reverse" << std::endl;
  intList.reverseNth(2);
  intList.print(std::cout);
  std::cout << "size:" << intList.size();
  std::cout << "\n";

  intList.print(std::cout);
  intList.reverseNth(1);
  std::cout << "After reverse" << std::endl;
  intList.print(std::cout);
  std::cout << "\n";


  intList.print(std::cout);
  intList.reverseNth(0);
  std::cout << "After reverse" << std::endl;
  intList.print(std::cout);
  std::cout << "\n";

  intList.print(std::cout);
  intList.reverseNth(6);
  std::cout << "After reverse" << std::endl;
  std::cout << "size:" << intList.size();
  intList.print(std::cout);

  cout << "With n = 5" << endl;
  intList.print(std::cout);
  intList.reverseNth(5);
  std::cout << "After reverse" << std::endl;
  std::cout << "size:" << intList.size();
  intList.print(std::cout);

  cout << "With n = 3" << endl;
  intList.print(std::cout);
  intList.reverseNth(3);
  std::cout << "After reverse" << std::endl;
  std::cout << "size:" << intList.size();
  intList.print(std::cout);

  cout << "With n = 4" << endl;
  intList.print(std::cout);
  intList.reverseNth(4);
  std::cout << "After reverse" << std::endl;
  std::cout << "size:" << intList.size();
  intList.print(std::cout);
}

void testMyReverse()
{

  List<int> intList;
  intList.insertFront(2);
  intList.insertFront(3);
  intList.insertFront(4);
  intList.insertFront(3);
  std::cout << "size:" << intList.size();
  intList.print(std::cout);

  std::cout << "After reverse" << std::endl;
  std::cout << "size:" << intList.size();

  intList.reverse();
  intList.print(std::cout);
  std::cout << "\n";

  List<int> mList;
  mList.insertFront(2);
  mList.insertFront(4);
  mList.print(std::cout);
  //
  std::cout << "After reverse" << std::endl;
  std::cout << "size:" << mList.size();

  mList.reverse();
  mList.print(std::cout);

  List<int> thirdList;
  thirdList.print(std::cout);

  std::cout << "After reverse" << std::endl;
  std::cout << "size:" << thirdList.size();

  thirdList.reverse();
  thirdList.print(std::cout);
}

List<RGBAPixel> imageToList(PNG const& img, bool reverse = false)
{
    List<RGBAPixel> list;
    for (size_t i = 0; i < img.width(); i++) {
        for (size_t j = 0; j < img.height(); j++) {
            if (reverse)
                list.insertFront(*img(i, j));
            else
                list.insertBack(*img(i, j));
        }
    }
    return list;
}

BlockPNG listToImage(List<RGBAPixel> const& list, int width, int height)
{
    BlockPNG ret;
    ret.resize(width, height);
    vector<RGBAPixel> v(list.begin(), list.end());
    int x = 0;
    int y = 0;
    for (size_t i = 0; i < v.size(); i++) {
        *ret(x, y) = v[i];
        y++;
        if (y == height) {
            y = 0;
            x++;
        }
    }
    return ret;
}

void checkSoln(string test, PNG out, string soln_file)
{
    PNG soln;
    soln.readFromFile(soln_file.c_str());

    if (!(soln == out))
        cerr << "[" << test << "]: Image does not match " << soln_file << endl;
    else
        cerr << "Match!" << endl;
}

void testInserts()
{
    cout << "Hi! I'm your friendly `" __FILE__ "`. You should edit me to enable the insertion tests." << endl;
    cout << endl;
    cout << "Guess what? You can also add your own!" << endl;
    cout << endl;
    cout << "Most of the tests for this MP use images, and those can be hard to debug." << endl;
    cout << "You should add some tests that use integer lists!" << endl;
    cout << endl;
    cout << "Start by uncommenting lines " << (__LINE__ + 3) << " through " << (__LINE__ + 26) << "." << endl;

    /* uncomment the below */

    cout << "[main]: " << __func__ << "()" << endl;
    List<int> list;

    // test insertFront
    for (size_t i = 1; i <= 10; i++)
        list.insertFront(i);

    cout << "[testInserts]: " << list << endl;
    cout << "[testInserts]: size: " << list.size() << endl;
    if (list.size() != 10)
        cout << "[testInserts]: Incorrect size" << endl;


    List<int> list2;

    // test insertBack
    for (size_t i = 1; i <= 10; i++)
        list2.insertBack(i);

    cout << "[testInserts]: " << list2 << endl;
    cout << "[testInserts]: size: " << list2.size() << endl;
    if (list2.size() != 10)
        cout << "[testInserts]: Incorrect size" << endl;

}

void testReverse()
{
    cout << "[main]: " << __func__ << "()" << endl;
    PNG in("in_02.png");

    List<RGBAPixel> list = imageToList(in);
    list.reverse();

    PNG out = listToImage(list, in.width(), in.height());
    out.writeToFile("reverse.png");

    checkSoln(__func__, out, "soln_reverse.png");
}

void testReverseNth()
{
    cout << "[main]: " << __func__ << "()" << endl;
    PNG in("in_03.png");

    List<RGBAPixel> list = imageToList(in);
    list.reverseNth(in.height() * 20);

    PNG out = listToImage(list, in.width(), in.height());
    out.writeToFile("reverseNth_01.png");

    checkSoln(__func__, out, "soln_reverseNth_01.png");

    in.readFromFile("in_04.png");
    list = imageToList(in);
    list.reverseNth(in.height() * 61);
    out = listToImage(list, in.width(), in.height());
    out.writeToFile("reverseNth_02.png");

    checkSoln(__func__, out, "soln_reverseNth_02.png");
}

void testWaterfall()
{
    cout << "[main]: " << __func__ << "()" << endl;
    PNG in("in_05.png");

    List<RGBAPixel> list = imageToList(in);
    list.waterfall();

    PNG out = listToImage(list, in.width(), in.height());
    out.writeToFile("waterfall_01.png");

    checkSoln(__func__, out, "soln_waterfall_01.png");

    in.readFromFile("in_06.png");
    list = imageToList(in);
    list.waterfall();
    out = listToImage(list, in.width(), in.height());
    out.writeToFile("waterfall_02.png");

    checkSoln(__func__, out, "soln_waterfall_02.png");
}

void testSplit()
{
    cout << "[main]: " << __func__ << "()" << endl;

    PNG in("in_07.png");
    List<RGBAPixel> list1;
    for (size_t i = 0; i < in.width(); i++)
        for (size_t j = 0; j < in.height(); j++)
            list1.insertBack(*in(i, j));
    List<RGBAPixel> list2 = list1.split(400 * 240);
    List<RGBAPixel> list3 = list2.split(400 * 240);

    vector<RGBAPixel> im1vect(list1.begin(), list1.end());
    vector<RGBAPixel> im2vect(list2.begin(), list2.end());
    vector<RGBAPixel> im3vect(list3.begin(), list3.end());

    PNG out1(400, 240);
    int x = 0;
    for (size_t i = 0; i < im1vect.size(); i++) {
        int y = i % 240;
        *out1(x, y) = im1vect[i];
        if (y == 239)
            x++;
    }
    out1.writeToFile("split_01.png");
    checkSoln(__func__, out1, "soln_split_01.png");

    PNG out2(400, 240);
    x = 0;
    for (size_t i = 0; i < im2vect.size(); i++) {
        int y = i % 240;
        *out2(x, y) = im2vect[i];
        if (y == 239)
            x++;
    }
    out2.writeToFile("split_02.png");
    checkSoln(__func__, out2, "soln_split_02.png");

    PNG out3(400, 240);
    x = 0;
    for (size_t i = 0; i < im3vect.size(); i++) {
        int y = i % 240;
        *out3(x, y) = im3vect[i];
        if (y == 239)
            x++;
    }
    out3.writeToFile("split_03.png");
    checkSoln(__func__, out3, "soln_split_03.png");
}

void testMerge()
{
    cout << "[main]: " << __func__ << "()" << endl;

    PNG im1("in_08.png");
    PNG im2("in_09.png");
    PNG out(600, 400);

    vector<RGBAPixel> v1;
    for (size_t i = 0; i < im1.width(); i++)
        for (size_t j = 0; j < im1.height(); j++)
            v1.push_back(*im1(i, j));
    vector<RGBAPixel> v2;
    for (size_t i = 0; i < im2.width(); i++)
        for (size_t j = 0; j < im2.height(); j++)
            v2.push_back(*im2(i, j));
    List<RGBAPixel> l1(v1.begin(), v1.end());
    List<RGBAPixel> l2(v2.begin(), v2.end());
    l1.mergeWith(l2);
    vector<RGBAPixel> merged(l1.begin(), l1.end());
    int x = 0;
    for (size_t i = 0; i < merged.size(); i++) {
        int y = i % 400;
        *out(x, y) = merged[i];
        if (y == 399)
            x++;
    }
    out.writeToFile("merge.png");

    checkSoln(__func__, out, "soln_merge.png");
}

inline vector<int> buildVector(BlockPNG const& b, int d)
{
    vector<int> v;
    for (size_t i = 1; i <= (b.width() * b.height()) / (d * d); i++)
        v.push_back(i);

    return v;
}

void testSort()
{
    cout << "[main]: " << __func__ << "()" << endl;

    srand(225);

    // read in image to be shuffled
    BlockPNG b;
    b.readFromFile("in_01.png");

    int d = 60;
    vector<int> v = buildVector(b, d);
    random_shuffle(v.begin(), v.end());

    // generate shuffled image (done for you already)
    //PNG b2 = b.genImg(v, d);
    //b2.writeToFile("in_01_shuffled_60.png");

    // make list and sort it
    List<int> img_srt(v.begin(), v.end());
    img_srt.sort();

    // vectorize and rebuild image
    vector<int> v2(img_srt.begin(), img_srt.end());

    PNG b3 = b.genImg(v2, d);
    b3.writeToFile("unshuffled_60.png");

    checkSoln("testSort", b3, "in_01.png");

    d = 1;
    v = buildVector(b, d);
    random_shuffle(v.begin(), v.end());

    //PNG q = b.genImg(v, d);
    //q.writeToFile("in_01_shuffled_1.png");

    List<int> q_srt(v.begin(), v.end());
    q_srt.sort();

    v2 = vector<int>(q_srt.begin(), q_srt.end());

    b3 = b.genImg(v2, d);
    b3.writeToFile("unshuffled_1.png");

    checkSoln("testSort", b3, "in_01.png");
}

void testMP31()
{
    testInserts();
    testReverse();
    testReverseNth();
    testWaterfall();
}

void testMP32()
{
    testSplit();
    testMerge();
    testSort();
}

int main(int argc, char** argv)
{
    /*
    TOC:

      1) Test destructor -- testMemoryDestruction()
      2) Test reverse -- testMyReverse()
      3) Test Nth Reverse -- testMyReverseNth()
      4) Test Waterfall -- testMyWaterfall()


    */







    // testMemoryDestruction();
    // testMyReverse();
    //  testMP31();
    //  testMyReverseNth();
    // testMyWaterfall();
    // testMySplit();
    // testMyMerge();
    testMyMergeSort();
    testMP32();


    // vector<string> args(argv, argv + argc);
    // if (argc == 1 || args[1] == "all") {
    //     testMP31();
    //     testMP32();
    // } else {
    //     if (args[1] == "mp3.1" || args[1] == "mp31")
    //         testMP31();
    //     else if (args[1] == "mp3.2" || args[1] == "mp32")
    //         testMP32();
    //     else if (args[1] == "inserts")
    //         testInserts();
    //     else if (args[1] == "reverse") {
    //         testReverse();
    //         testReverseNth();
    //     } else if (args[1] == "waterfall" || args[1] == "waterFall")
    //         testWaterfall();
    //     else if (args[1] == "split")
    //         testSplit();
    //     else if (args[1] == "merge")
    //         testMerge();
    //     else if (args[1] == "sort" || args[1] == "mergesort"
    //              || args[1] == "mergeSort")
    //         testSort();
    // }

    return 0;
}
