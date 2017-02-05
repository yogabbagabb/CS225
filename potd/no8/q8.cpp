#include <iostream>
using namespace std;

int main()
{
	char * x = new char [5];
	for (int i =0; i < 5; i++)
	{	
		x[i] = (char)(i);
	}	
	char ** y = &x;
	cout << "The value of y is " << y << endl;

	int sum = 0;
	for (int i =0; i < 5; i++)
	{
		sum += x[i];
	}
	 
	cout << "The sum of the characters is " << sum << endl;

}
