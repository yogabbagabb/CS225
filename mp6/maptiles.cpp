/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include <utility>
#include "maptiles.h"

using namespace std;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
    map<Point<3>, TileImage> theMap;
    vector<Point<3>> thePoints;

    for (TileImage t: theTiles)
    {
      RGBAPixel avgColor = t.getAverageColor();
      double arr[3]; arr[0] = avgColor.red; arr[1] = avgColor.green; arr[2] = avgColor.blue;
      Point<3> toPut(arr);
      thePoints.push_back(toPut);
      theMap.insert(std::pair<Point<3>, TileImage>(toPut, t));
    }

    KDTree <3> theTree(thePoints);

    int rows = theSource.getRows();
    int cols = theSource.getColumns();
    MosaicCanvas * canvas = new MosaicCanvas(rows, cols);

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        RGBAPixel avgColor = theSource.getRegionColor(i, j);
        double arr[3]; arr[0] = avgColor.red; arr[1] = avgColor.green; arr[2] = avgColor.blue;
        Point<3> toFind(arr);

        Point<3> neighbor = theTree.findNearestNeighbor(toFind);
        canvas->setTile(i, j, theMap[neighbor]);
      }
    }

    return canvas;

}
