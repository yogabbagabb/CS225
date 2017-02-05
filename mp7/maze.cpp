/*
makeMaze:

seed a matrix of width * height and consisting of -s and +s to signal whether the
right wall or bottom wall is to be considered for removing

randomize this matrix;

then iterate through it

take each output and consider whether executing it would create a cycle. If it will create a cycle
then do not add it

how to add: add a entry to the adjacency list of vertexes. add which entry? the index of the array

how do we determine if a cycle is created

create width * height disjoint sets. if the removal of a wall links two components already part of a disjoint set
then this must mean that the removal would create a cycle -- so don't do it.

also do not break a wall if it lies on the boundary.
*/
#include "maze.h"
#include <time.h>
#include <iostream>
#include <algorithm>
using namespace std;

  void SquareMaze::makeMaze(int width, int height)
  {
    this->height = height;
    this->width = width;
    int length = 2 * width * height;

    cells.clear();
    for (int i = 0; i < length/2; i++)
    {
      cells.push_back(Vertex(i, true, true));
    }

    int * arr = new int [2 * width * height];
    for (int i =0; i < length/2; i++)
    {
      arr[i] = (i+1);
    }
    for (int i = 0; i < length/2; i++)
    {
      arr[i + length/2] = -(i+1);
    }

    DisjointSets s;
    s.addelements(length/2);

    // randomized
    srand(time(NULL));
    random_shuffle(&arr[0], &arr[length]);


    for (int i = 0; i < length; i++)
    {
      if (NotOnPerimeter(arr[i]))
      {
        if (noncyclical(s, arr[i]))
        {
          if (arr[i] < 0)
            cells[abs(arr[i])-1].hasLowerWall = false;
          else
            cells[abs(arr[i])-1].hasRightWall = false;

        }
      }
    }

    delete []arr;

  }

  bool SquareMaze::noncyclical(DisjointSets & s, int index) const
  {
    if (index < 0)
    {
      index = abs(index) - 1;
      if (s.find(index) == s.find(index + width))
        return false;
      else
        s.setunion(index, index + width);
    }
    else
    {
      index = abs(index) - 1;
      if (s.find(index) == s.find(index + 1))
        return false;
      else
        s.setunion(index, index + 1);
    }

    return true;
  }

  bool SquareMaze::NotOnPerimeter(int trueindex) const
  {
    int index = abs(trueindex) - 1;
    int number = width * height;
    if (((index + 1) % width == 0 && trueindex > 0) || (index + width >= number && trueindex < 0))
      return false;
    else
      return true;
  }
/*
_____
canTravel:
get the current coordinate in terms of x and y
perform the necessary case by case additions
dir = 0 represents a rightward step (+1 to the x coordinate)
dir = 1 represents a downward step (+1 to the y coordinate)
dir = 2 represents a leftward step (-1 to the x coordinate)
dir = 3 represents an upward step (-1 to the y coordinate)

therefore must store the original one
and must store the new one

determine if x and y are accessible (either by border or in vectorized form by the adjacency list)

*/

  int SquareMaze::idx(int x, int y) const
  {
    return x + (y)*width;
  }

  bool SquareMaze::canTravel(int x, int y, int dir)	const
  {
      int index = idx(x,y);
    if (index >= width * height || x >= width || y >= height)
      return false;

    if (dir == 0)
    {
      return (index + 1) % width != 0 && !cells[index].hasRightWall;
    }

    else if (dir == 1)
    {
      return index + width < width * height && !cells[index].hasLowerWall;
    }

    else if (dir == 2)
    {
      return (index % width != 0) && !cells[index-1].hasRightWall;
    }

    else
    {
      return (index/width != 0) && !cells[index- width].hasLowerWall;
    }
  }
/*
____
setWall:

get the index based on (x,y)
dir = 0, 1, 2, 3
get the index based on the direction moved from (x,y)
bool exists = true, false

if exists is true
delete the connection between two adjacent vertexes, assuming there is a connection
if there is no connection, leave it be

if exists is fasle

if there is a connection, break it,
or else if there is no connection, fail to break it

void SquareMaze::setWall	(	int 	x,
int 	y,
int 	dir,
bool 	exists
)
*/

void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
  if (dir == 0)
  {
    cells[idx(x,y)].hasRightWall = exists;
  }
  else
  {
    cells[idx(x,y)].hasLowerWall = exists;
  }
}

/*

____
solve (fromDir, int x, int y):
return a vector of ints

if:
  you've hit a dead end at the position of the last row -- meaning that you've actually crossed the last row
  or if all paths proceeding from your last location have been assessed:
    meaning that you determined which of them is most lengthy -- and you return that one

go somewhere that is neither in the fromDir and in a direction you can proceed to

*/
// vector<int> SquareMaze::solveMaze()
// {
//   vector<int> solutions(0);
//   solutions = search(3, 0, 0, solutions);
//   exitX = solutions.back();
//   solutions.resize(solutions.size()-1);
//   return solutions;
// }



int SquareMaze::getX(int index)
{
  return index % width;
}
int SquareMaze::getY(int index)
{
  return index/width;
}


void SquareMaze::backtrack(int x, int y, vector<vector<int>> & solutions)
{
  vector<int> solution;
  int finalX = x;
  int toDir;
  while (x != 0 || y != 0)
  {
    int backDir = cells[idx(x,y)].fromDir;

    if (backDir == 0)
    {
      solution.insert(solution.begin(), 2);
      x += 1;
    }

    if (backDir == 1)
    {
      solution.insert(solution.begin(), 3);
      y += 1;
    }

    if (backDir == 2)
    {
      solution.insert(solution.begin(), 0);
      x -= 1;
    }

    if (backDir == 3)
    {
      solution.insert(solution.begin(), 1);
      y -= 1;
    }

  }

  solution.push_back(-(finalX+1));
  solutions.push_back(solution);
//
}


vector<int> SquareMaze::solveMaze()
{
  stack<int> vertexes;
  vector<vector<int>> solutions;
  int index = 0;
  cells[0].fromDir = 3;
  int x = 0; int y = 0;
  vertexes.push(0);
  while (!vertexes.empty())
  {
    index = vertexes.top(); vertexes.pop();
     x = getX(index);
     y = getY(index);

     if (y == height - 1)
     {
      backtrack(x,y, solutions);
    }

    if (canTravel(x,y,0) && 0 != cells[idx(x,y)].fromDir)
    {
      cells[idx(x+1,y)].fromDir = 2;
      vertexes.push(idx(x+1, y));
    }

    if (canTravel(x,y,1) && 1 != cells[idx(x,y)].fromDir)
    {
      cells[idx(x,y+1)].fromDir = 3;
      vertexes.push(idx(x, y+1));
    }

    if (canTravel(x,y,2) && 2 != cells[idx(x,y)].fromDir)
    {
    cells[idx(x-1,y)].fromDir = 0;
    vertexes.push(idx(x-1, y));
    }

    if (canTravel(x,y,3) && 3 != cells[idx(x,y)].fromDir)
    {
    cells[idx(x,y-1)].fromDir = 1;
    vertexes.push(idx(x, y-1));
    }

  }

  int bestIndex = getLongestPath(solutions);
  exitX = solutions[bestIndex].back();
  solutions[bestIndex].pop_back();
  return solutions[bestIndex];


}



int SquareMaze::getLongestPath(vector<vector<int>> & contenders)
{

  int maxSize = (int)contenders[0].size();
  int xCoord = abs(contenders[0].back());
  int bestContender = 0;

  for (int i = 1; i < (int)(contenders.size()); i++)
  {
    if ((int)contenders[i].size() > maxSize)
    {
      maxSize = (int)contenders[i].size();
      xCoord = abs(contenders[i].back());
      bestContender = i;
    }
    else if ((int)contenders[i].size() == maxSize)
    {
      if (xCoord > abs(contenders[i].back()))
      {
        xCoord = abs(contenders[i].back());
        bestContender = i;
      }
    }
  }

  return bestContender;

  /*
    use what is above save the first if
  */

}

vector<int> SquareMaze::search(int fromDir, int x, int y, vector<int> developing)
{
  vector<vector<int>> contenders;

  int theSize = developing.size();
  developing.resize(theSize + 1);

  if (0 != fromDir && canTravel(x,y, 0))
  {
    developing[theSize] = 0;
    vector<int> received = search(2, x+1, y, developing);
    if (received.back() != -(width + 1))
      contenders.push_back(received);
  }
  else
  {
    if (y == height-1)
    {
      developing[theSize] = -(x+1);
      contenders.push_back(developing);
    }

  }

  if (1 != fromDir && canTravel(x,y, 1))
  {
    developing[theSize] = 1;
    vector <int> received = search(3, x, y+1, developing);
    if (received.back() != -(width + 1))
      contenders.push_back(received);
  }
  else
  {
    if (y == height-1)
    {
      developing[theSize] = -(x+1);
      contenders.push_back(developing);
    }

  }

  if (2 != fromDir && canTravel(x,y, 2))
  {
    developing[theSize] = 2;
    vector <int> received = search(0, x-1, y, developing);
    if (received.back() != -(width + 1))
      contenders.push_back(received);
  }
  else
  {
    if (y == height-1)
    {
      developing[theSize] = -(x+1);
      contenders.push_back(developing);
    }
  }

  if (3 != fromDir && canTravel(x,y, 3))
  {
    developing[theSize] = 3;
    vector <int> received = search(1, x, y-1, developing);
    if (received.back() != -(width + 1))
      contenders.push_back(received);
  }
  else
  {
    if (y == height-1)
    {
      developing[theSize] = -(x+1);
      contenders.push_back(developing);
    }
  }


  int bestIndex = getLongestPath(contenders);
  if (bestIndex == -1)
  {
     return vector<int>{-(width+1)};
  }
  else
  {
    return contenders[bestIndex];
  }

}
PNG * SquareMaze::drawMaze()const
{
  int repWidth = width * 10 + 1;
  int repHeight = height * 10 + 1;
  PNG * maze = new PNG (repWidth, repHeight);

  RGBAPixel * temp;
  for (int i = 0; i < repWidth; i++)
  {
    if ( i < 1 || i > 9)
    {
      temp = (*maze)(i,0);
      *temp = RGBAPixel(0, 0, 0);
    }
  }

  for (int i = 0; i < repHeight; i++)
  {
      temp = (*maze)(0,i);
      *temp = RGBAPixel(0, 0, 0);

  }


  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      if (cells[idx(i,j)].hasRightWall)
      {
        for (int k = 0; k <= 10; k++)
        {
          temp = (*maze)((i+1)*10, j*10+k);
          *temp = RGBAPixel(0, 0, 0);
        }
      }
      if (cells[idx(i,j)].hasLowerWall)
      {
        for (int k = 0; k <= 10; k++)
        {
          temp = (*maze)(i*10+k, (j+1)*10);
          *temp = RGBAPixel(0, 0, 0);
        }
      }
    }
  }

  return maze;

}

PNG * SquareMaze::drawMazeWithSolution()
{
  PNG * maze = drawMaze();
  vector<int> solution = solveMaze();

  auto it = solution.begin();
  int x = 5; int y = 5;
  RGBAPixel * temp;

  while (it != solution.end())
  {
    if (*it == 0)
    {
      for (int k = 0; k <= 10; k++)
      {
        temp = (*maze)(x, y);
        x++;
        *temp = RGBAPixel(255, 0, 0);
      }
      x--;
    }
    else if (*it == 1)
    {
      for (int k = 0; k <= 10; k++)
      {
        temp = (*maze)(x, y++);
        *temp = RGBAPixel(255, 0, 0);
      }
      y--;
    }

    else if (*it == 2)
    {
      for (int k = 0; k <= 10; k++)
      {
        temp = (*maze)(x--, y);
        *temp = RGBAPixel(255, 0, 0);
      }
      x++;
    }
    else
    {
      for (int k = 0; k <= 10; k++)
      {
        temp = (*maze)(x, y--);
        *temp = RGBAPixel(255, 0, 0);
      }
      y++;
    }

    it++;
  }
    int xPos = abs(exitX) - 1;
    // might need changing
    for (int k = 1; k < 10; k++)
    {
      temp = (*maze)(xPos * 10 + k, height * 10);
      *temp = RGBAPixel(255, 255, 255);
    }

    return maze;


  }
