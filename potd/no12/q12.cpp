#include "iostream"
using namespace std;

#include "cmath"
int main()
{
    std::string s;

    std::cout << "Please enter your string" << endl;
    cin >> s;

    while (s.compare("q") != 0 && s.compare("c") != 0 && s.compare("s") != 0)
    {
      std::cout << "Please enter your string" << endl;
      cin >> s;
    }

    if (s.compare("q") == 0)
      return 0;

    std::cout << "Please enter your value" << endl;
    double val;
    cin >> val;

    if (s.compare("s") == 0)
      cout << std::sin(val);

    if (s.compare("c") == 0)
      cout << std::cos(val);


      return 0;
}
