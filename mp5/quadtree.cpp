/**
 * @file quadtree.cpp
 * Quadtree class implementation.
 * @date Spring 2008
 */

 #include "quadtree.h"


Quadtree::Quadtree()
{
  root = NULL;
}

Quadtree::Quadtree(const Quadtree &ref)
{
  root = NULL;
  copy(root, ref.root);
}

void Quadtree::copy(QuadtreeNode *& first,  QuadtreeNode * const & second)
{
  if (second != NULL)
  {

    first = new QuadtreeNode();
    first->element = second->element;
    first->length = second->length;


    copy(first->nwChild, second->nwChild);
    copy(first->neChild, second->neChild);
    copy(first->seChild, second->seChild);
    copy(first->swChild, second->swChild);
  }
}

Quadtree& Quadtree::operator=(const Quadtree &ref)
{
  if (this != &ref)
  {
    clear(root);
    root = NULL;
    copy(root, ref.root);
  }
  return *this;
}

Quadtree::Quadtree(PNG const & source, int resolution)
{
  // This root = NULL must be here!
  root = NULL;
  buildTree(source, resolution);
}

Quadtree::~Quadtree()
{
  clear(root);
}
void Quadtree::clear(QuadtreeNode *& subroot)
{
  if (subroot != NULL)
  {
    clear(subroot->nwChild);
    clear(subroot->neChild);
    clear(subroot->swChild);
    clear(subroot->seChild);

    delete subroot;
    subroot = NULL;

  }
}


void Quadtree::buildTree(PNG const & source, int resolution)
{
  clear(root);
  build(source, root, 0,0, resolution);
}

void Quadtree::compAverage(QuadtreeNode *& root)
{
  QuadtreeNode * a = (root->nwChild);
  QuadtreeNode * b = (root->neChild);
  QuadtreeNode * c = (root->seChild);
  QuadtreeNode * d = (root->swChild);

  root->avgRed = (int)(a->avgRed + b->avgRed + c->avgRed + d->avgRed)/4;
  root->avgBlue = (int)(a->avgBlue + b->avgBlue + c->avgBlue + d->avgBlue)/4;
  root->avgGreen = (int)(a->avgGreen + b->avgGreen + c->avgGreen + d->avgGreen)/4;
}

void Quadtree::build(PNG const & source, QuadtreeNode *& root, int x, int y, int resolution)
{
  root = new QuadtreeNode();
  if(resolution == 1)
  {
    root->element = *(source(x,y));
    root->length = resolution;

    root->avgRed = root->element.red;
    root->avgBlue = root->element.blue;
    root->avgGreen = root->element.green;
  }
  else
  {
    int half = resolution/2;
    build(source, root->nwChild, x,y, half);
    build(source, root->neChild, x+half, y, half);
    build(source, root->seChild, x+half, y+half, half);
    build(source, root->swChild, x, y+half, half);

    root->element = *(source(x,y));
    root->length = resolution;

    compAverage(root);
  }


}

PNG Quadtree::decompress() const
{
  if (!root)
    return PNG();
  else
    {
      PNG pic(root->length, root->length);
      decompress(pic, root, 0, 0);
      return pic;
    }
}

bool Quadtree::isChild(QuadtreeNode * const& root) const
{
  /*
  *I am making a HUGE ASSUMPTION HERE THAT ONE"S NULLNESS IS INDICATIVE OF ALL OTHERS
  */
  return (root->nwChild == NULL);
}
void Quadtree::decompress(PNG & pic, QuadtreeNode* const & root, int x, int y) const
{
  if (isChild(root))
  {
    int length = root->length;
    RGBAPixel * spot;
    for (int i = 0; i < length; i++)
    {
      for (int j = 0; j < length; j++)
      {
        spot = pic(x+j,y+i);
        *spot = root->element;
      }
    }
  }
  else
  {
    // RGBAPixel * spot = pic(x,y);
    // *spot = root->element;
    int half = root->length/2;

    decompress(pic, root->nwChild, x, y);
    decompress(pic, root->neChild, x+half, y);
    decompress(pic, root->seChild, x+half, y+half);
    decompress(pic, root->swChild, x, y+half);
  }
}
RGBAPixel Quadtree::getPixel(int x, int y) const
{
  return jumpTo(x, y, 0,0, root);
}

RGBAPixel Quadtree::jumpTo(int pixX, int pixY, int x, int y, QuadtreeNode * root) const
{
  if (isChild(root))
    return root->element;
  else
  {
    int length = root->length;
    bool left = (pixX < (x + length/2));
    bool top = (pixY < (y + length/2));

    if (top && left)
      return jumpTo(pixX, pixY, x, y, root->nwChild);
    else if (top && !left)
      return jumpTo(pixX, pixY, x+length/2, y, root->neChild);
    else if (!top && !left)
      return jumpTo(pixX, pixY, x+length/2, y+length/2, root->seChild);
    else
      return jumpTo(pixX, pixY, x, y+length/2, root->swChild);

  }
}

void Quadtree::clockwiseRotate()
{
  clockwiseRotate(root);
}

void Quadtree::clockwiseRotate(QuadtreeNode *& root)
{
    if (!root)
      return;

    clockwiseRotate(root->nwChild);
    clockwiseRotate(root->neChild);
    clockwiseRotate(root->seChild);
    clockwiseRotate(root->swChild);

    QuadtreeNode * save = root->swChild;

    root->swChild = root->seChild;
    root->seChild = root->neChild;
    root->neChild = root->nwChild;
    root->nwChild = save;

}


int Quadtree::distance(QuadtreeNode * const& node, std::tuple<int,int,int> avg) const
{
  return pow((node->element.red - std::get<0>(avg)),2) + pow((node->element.blue - std::get<1>(avg)),2) + pow((node->element.green - std::get<2>(avg)),2);
}
bool Quadtree::isPruneable(QuadtreeNode * const& root, std::tuple<int,int,int> avg, int tolerance) const
{
  if (isChild(root))
  {
    return (distance(root, avg) <= tolerance);
  }
  else
    return isPruneable(root->nwChild, avg, tolerance) && isPruneable(root->neChild, avg, tolerance)
        && isPruneable(root->seChild, avg, tolerance) && isPruneable(root->swChild, avg, tolerance);
}

void Quadtree::prune(int tolerance)
{
  if (!root)
    return;

  prune (root, tolerance);
}

void Quadtree::deleteChildren(QuadtreeNode *& root)
{
  if (root->nwChild)
  {
    delete root->nwChild;
    delete root->neChild;
    delete root->seChild;
    delete root->swChild;

    // root->nwChild = root->neChild = root->seChild = root->swChild = NULL;

    root->nwChild = NULL;
    root->neChild = NULL;
     root->seChild = NULL;
     root->swChild = NULL;
  }
}

void Quadtree::prune(QuadtreeNode *& root, int tolerance)
{
    if (root)
    {
      // NOTe: We use RBG here instead of RGB!
      std::tuple<int,int,int> avg = std::make_tuple(root->avgRed, root->avgBlue, root->avgGreen);
      if (isPruneable(root, avg, tolerance))
      {
        clear(root->nwChild);
        clear(root->neChild);
        clear(root->seChild);
        clear(root->swChild);

        root->element.red =  std::get<0>(avg);
        root->element.blue =  std::get<1>(avg);
        root->element.green =  std::get<2>(avg);
      }
      else
      {
        prune(root->nwChild, tolerance);
        prune(root->neChild, tolerance);
        prune(root->seChild, tolerance);
        prune(root->swChild, tolerance);
      }
    }
}

int Quadtree::pruneSize(int tolerance) const
{
  std::tuple<int,int,int> avg = std::make_tuple(root->avgRed, root->avgBlue, root->avgGreen);
  return pruneSize(tolerance, root, avg);
}

int Quadtree::pruneSize(int tolerance, QuadtreeNode * const& root, std::tuple<int,int,int> & avg) const
{

  if (isChild(root))
    return 1;

  if (isPruneable(root, avg, tolerance))
    return 1;

  else
  {
    QuadtreeNode * a = root->nwChild;
    QuadtreeNode * b  = root->neChild;
    QuadtreeNode * c = root->seChild;
    QuadtreeNode * d = root->swChild;

    std::tuple<int,int,int> nwTup = std::make_tuple(a->avgRed, a->avgBlue, a->avgGreen);
    std::tuple<int,int,int> neTup = std::make_tuple(b->avgRed, b->avgBlue, b->avgGreen);
    std::tuple<int,int,int> seTup = std::make_tuple(c->avgRed, c->avgBlue, c->avgGreen);
    std::tuple<int,int,int> swTup = std::make_tuple(d->avgRed, d->avgBlue, d->avgGreen);

    return pruneSize(tolerance, root->nwChild, nwTup) + pruneSize(tolerance, root->neChild, neTup)
  + pruneSize(tolerance, root->seChild, seTup) + pruneSize(tolerance, root->swChild, swTup);
  }
}

int Quadtree::idealPrune(int numLeaves)const
{
  int max = pow(256,2)*3;
  if (pruneSize(1) <= numLeaves)
    return 1;

  int min = 0;
  int maxTwo = 0;
  for (int i = 1; i <2*max; i*=2)
  {
    if (pruneSize(i) > numLeaves && pruneSize(i*2) <= numLeaves)
    {
      min = i;
      maxTwo = 2*i;
      break;
    }
  }


  return binarySearch(min, maxTwo, numLeaves);
}

int Quadtree::binarySearch(int min, int max, int numLeaves) const
{

  if (min == max)
    return min;
  else{

    int middle = (min + max)/2;
    if (pruneSize(middle) > numLeaves)
      return binarySearch(middle+1, max, numLeaves);
    else
      return binarySearch(min, middle, numLeaves);
    // caution we can get stuck here
  }
}
