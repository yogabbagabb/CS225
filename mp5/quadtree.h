/**
 * @file quadtree.h
 * Quadtree class definition.
 * @date Spring 2008
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"
#include<tuple>
#include<math.h>

/**
 * A tree structure that is used to compress PNG images.
 */
class Quadtree
{

  private:
    /**
     * A simple class representing a single node of a Quadtree.
     * You may want to add to this class; in particular, it could
     * probably use a constructor or two...
     */
    class QuadtreeNode
    {
      public:
        QuadtreeNode()
        {
          nwChild = NULL;
          neChild = NULL;
          swChild = NULL;
          seChild = NULL;
        }
        QuadtreeNode* nwChild; /**< pointer to northwest child */
        QuadtreeNode* neChild; /**< pointer to northeast child */
        QuadtreeNode* swChild; /**< pointer to southwest child */
        QuadtreeNode* seChild; /**< pointer to southeast child */
        int avgRed, avgGreen, avgBlue;
        int length;

        RGBAPixel element; /**< the pixel stored as this node's "data" */
    };

    /*
    * Private helper function to ~Quadtree(). Recursively deletes all nodes
    * in the structure.
    */
    void clear(QuadtreeNode *& root);
    void copy(QuadtreeNode *& first, QuadtreeNode *const &  second);
    void build(PNG const & source, QuadtreeNode *& p, int x, int y, int resolution);
    RGBAPixel jumpTo(int a, int b, int x, int y, QuadtreeNode * root) const;
    bool isChild(QuadtreeNode *const & root) const;
    void decompress(PNG & pic, QuadtreeNode* const & root, int x, int y) const;
    void clockwiseRotate(QuadtreeNode *& root);
    void compAverage(QuadtreeNode *& root);
    bool isPruneable(QuadtreeNode * const& root, std::tuple<int,int,int> avg, int tolerance) const;
    // why do I need this const?
    int distance(QuadtreeNode * const& node, std::tuple<int,int,int> avg) const;
    void prune(QuadtreeNode *& root, int tolerance);
    void deleteChildren(QuadtreeNode *& root);
    int pruneSize(int tolerance, QuadtreeNode * const& root, std::tuple<int,int,int> & avg) const;
    int binarySearch(int min, int max, int numLeaves) const;





    QuadtreeNode* root; /**< pointer to root of quadtree */


  public:

  Quadtree(PNG const & source, int resolution);
  Quadtree();
  ~Quadtree();
  Quadtree(const Quadtree &ref);
  Quadtree& operator=(const Quadtree &ref);
  void buildTree(PNG const & source, int resolution);
  PNG decompress() const;
  RGBAPixel getPixel(int x, int y) const;
  void clockwiseRotate();
  void prune(int tolerance);
  int idealPrune(int numLeaves)const;
  int pruneSize(int tolerance) const;

/**** Functions for testing/grading                      ****/
/**** Do not remove this line or copy its contents here! ****/
#include "quadtree_given.h"
};

#endif
