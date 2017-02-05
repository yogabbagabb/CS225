/**
 * @file testsquaremaze.cpp
 * Performs basic tests of SquareMaze.
 * @date April 2007
 * @author Jonathan Ray
 */

#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "png.h"


void testRandom()
{
  int width = 10;
  int height = 10;
  int length = width*height;

  int * arr = new int [2 * width * height];
  for (int i =0; i < length/2; i++)
  {
    arr[i] = (i+1);
  }
  for (int i = 0; i < length/2; i++)
  {
    arr[i + length/2] = -(i+1);
  }

  // randomized
  srand(time(NULL));
  random_shuffle(&arr[0], &arr[length]);
  for (int i =0  ; i < length; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void testimper()
{
  SquareMaze m;
  m.makeMaze(2, 2);
  std::cout << "MakeMaze complete" << std::endl;

  PNG* unsolved = m.drawMaze();
  unsolved->writeToFile("unsolved3.png");
  delete unsolved;
  std::cout << "drawMaze complete" << std::endl;

  std::vector<int> sol = m.solveMaze();
  std::cout << "solveMaze complete" << std::endl;

  PNG* solved = m.drawMazeWithSolution();
  solved->writeToFile("solved3.png");
  delete solved;
  std::cout << "drawMazeWithSolution complete" << std::endl;

}

void standard()
{
  SquareMaze m;
  m.makeMaze(50, 50);
  std::cout << "MakeMaze complete" << std::endl;

  PNG* unsolved = m.drawMaze();
  unsolved->writeToFile("unsolved.png");
  delete unsolved;
  std::cout << "drawMaze complete" << std::endl;

  std::vector<int> sol = m.solveMaze();
  std::cout << "solveMaze complete" << std::endl;

  PNG* solved = m.drawMazeWithSolution();
  solved->writeToFile("solved.png");
  delete solved;
  std::cout << "drawMazeWithSolution complete" << std::endl;

  for (int i = 400; i < 2000; i += 200)
  {
    m.makeMaze(i, i);
    std::cout << "MakeMaze complete" << std::endl;

    unsolved = m.drawMaze();
    unsolved->writeToFile("unsolved2.png");
    delete unsolved;
    std::cout << "drawMaze complete" << std::endl;

     sol = m.solveMaze();
    std::cout << "solveMaze complete" << std::endl;

    solved = m.drawMazeWithSolution();
    solved->writeToFile("solved2.png");
    delete solved;
    std::cout << "drawMazeWithSolution complete" << std::endl;
  }


}
int main()
{
  testimper();
}
