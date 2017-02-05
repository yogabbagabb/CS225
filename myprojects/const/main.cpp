
#include <iostream>
using namespace std;


int main ()
{
	//  This above is a compile time error -- the compiler recognizes
	// that x is a read only variable

	int * myVar = new int [3];
	myVar[0] = 2;
	cout << *myVar << endl;
	
	
}
