/* Your code here! */

#ifndef MAZE_H
#define MAZE_H

#include "rgbapixel.h"
#include "png.h"
#include "dsets.h"
#include <vector>
#include <stack>
#include <queue>

using namespace std;


class SquareMaze
{

public:
    void makeMaze(int width, int height);
    bool canTravel(int x, int y, int dir)	const;
    void setWall(int x, int y, int dir, bool exists);
    vector<int> solveMaze();
    PNG * drawMaze()const;
    PNG * drawMazeWithSolution();




private:
  struct Vertex
  {
    int index;
    bool hasLowerWall;
    bool hasRightWall;
    int fromDir;

    Vertex(int i, bool a, bool b)
    {
      index = i;
      hasLowerWall = a;
      hasRightWall = b;
      fromDir = 0;
    }
  };

  vector <Vertex> cells;
  int width;
  int height;
  int exitX;

  bool NotOnPerimeter(int index) const;
  bool noncyclical(DisjointSets & s, int index) const;
  int idx(int x, int y) const;
  vector<int> search(int fromDir, int x, int y, vector<int> developing);
  int getLongestPath(vector<vector<int>> & contenders);
  int getX(int index);
  int getY(int index);
  void backtrack(int x, int y, vector<vector<int>> & solutions);



};
#endif
