#include <iostream>
#include <tuple>
#include <vector>
using namespace std;


std::tuple<std::vector<int>, bool> isPrime(int x)
{
    bool isPrime = true;
    std::vector<int> candidates;

    for (int i = 2; i < x; i ++)
    {
      if (x%i == 0)
      {
        isPrime = false;
        candidates.push_back(i);
      }
    }

  return (std::make_tuple(candidates, isPrime));


}

int main(){
    int x;
    cout << "Enter a positive integer: " << endl;
    cin >> x;

    std::tuple<std::vector<int>, bool> tup = isPrime(x);

    if (std::get<1>(tup))
    {
      cout << x << " is Prime" << endl;
    }
    else
    {
      vector<int> q = std::get<0>(tup);
      cout << "Some candidates to refute primeness:" << endl;
      for (int i : q)
      {
        cout << i << " ";
      }
    }

}
