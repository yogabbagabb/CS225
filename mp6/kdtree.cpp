/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    if (first[curDim] < second[curDim])
      return true;
    else if (first[curDim] > second[curDim])
      return false;
    else if (first < second)
      return true;
    else
      return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    int r1 = 0; int r2 = 0;
    for (int i = 0 ; i < Dim; i++)
    {
      r1 += (target[i]-currentBest[i]) * (target[i]-currentBest[i]);
    }

    for (int i = 0 ; i < Dim; i++)
    {
      r2 += (target[i]-potential[i]) * (target[i]-potential[i]);
    }

    if (r2 < r1)
      return true;
    else if (r1 < r2)
      return false;
    else if (potential < currentBest)
      return true;
    else
      return false;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    points = newPoints;
    if (points.size() > 0)
      order(0, points.size() - 1, points, 0);
}

template <int Dim>
int KDTree<Dim>::max(int a, int b) const
{
  if (a > b)
    return a;
  else if (a < b)
    return b;
  else return a;
}

template <int Dim>
void KDTree<Dim>::order(int left, int right, vector<Point<Dim>> & points, int count)
{
  if (left != right)
  {
    int half = (left + right)/2;
    quickselect(left, right, half, points, count);
    order(left, max(left,half - 1), points, count + 1);
    order(half + 1, right, points, count + 1);
  }
}

template <int Dim>
void KDTree<Dim>::quickselect(int left, int right, int half, std::vector<Point<Dim>> & points, int count)
{
  int mid = partition(left, right, (left + right)/2, points, count);

  if (half < mid)
    quickselect(left, mid - 1, half, points, count);
  else if (half > mid)
    quickselect(mid + 1, right, half, points, count);
}

template <int Dim>
int KDTree<Dim>::partition(int left, int right, int pivot, std::vector<Point<Dim>> & points, int count)
{
  swap(points[pivot], points[right]);

  int farLeft = left;

  for (int i = left; i < right; i++)
  {
    if (smallerDimVal(points[i], points[right], count % Dim))
    {
        swap(points[farLeft], points[i]);
        farLeft++;
    }
  }

  swap(points[right], points[farLeft]);

  return farLeft;
}

template <int Dim>
void KDTree<Dim>::swap(Point<Dim> & a, Point<Dim> & b)
{
  Point<Dim> temp;
  temp = a;
  a = b;
  b = temp;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    if (points.size() > 0)
      return descend(0, points.size() - 1, 0, query);
    else
      {
        Point<Dim> defaul;
        return defaul;
      }
}

template <int Dim>
int KDTree<Dim>::absDSquared(int a, int b) const
{
  return (a-b) *(a-b);
}

template<int Dim>
int KDTree<Dim>::radiusSquared(const Point<Dim> &a, const Point<Dim> &b) const
{
  int total = 0;

  for (int i = 0; i < Dim; i++)
  {
    total += (a[i]-b[i])*(a[i]-b[i]);
  }

  return total;
}

template<int Dim>
Point<Dim> KDTree<Dim>::descend (int left, int right, int count, const Point<Dim> & query) const
{

  if (left == right)
    return points[left];

  int mid = (left + right)/2;
  bool wentLeft = false;

  // using & to bind to something const disqualifies the const?
  Point<Dim> best;

  if (smallerDimVal(points[mid], query, count % Dim))
  {
    best = descend(mid + 1 , right, count + 1, query);
  }
  else
  {
    best = descend(left, max(left,mid - 1), count + 1, query);
    wentLeft = true;
  }

  // 1st check while backtracking

  if (shouldReplace(query, best, points[mid]))
    best = points[mid];


  // 2nd check while backtracking

  int bestRadius = radiusSquared(query, best);
  Point <Dim> anotherPotential;

  if (absDSquared(points[mid][count % Dim], query[count % Dim]) <= bestRadius)
  {
    if (wentLeft)
    {
      anotherPotential = descend(mid + 1, right, count + 1, query);
    }
    else
    {
      anotherPotential = descend(left, max(left,mid - 1), count +1 , query);
    }

    if (shouldReplace(query, best, anotherPotential))
      best = anotherPotential;
  }

  return best;
}
