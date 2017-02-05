#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int x = 2016;
	
	cout << "x is stored at address " << &x << " and has value " << x << endl;
	int ** p = new int * ();
//	int * temp = *p;
	*p = &x;
	**p = 2017;
	cout << "x is stored at address " << *p << " and has value " << **p << endl;
	delete p;
}
