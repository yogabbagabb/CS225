#include<iostream>
using namespace std;

void practiceStat()
{
}


void practice()
{
	int * a = new int [2];
	for (int i = 0 ; i < 2; i++)
	{
		cout << a[i] << endl;
	}
	
	int * x = new int();
	cout << *x << endl;

	delete x;
	delete a;
}


void practiceFour()
{
	int * x = new int();
	*x = 6;
	cout << &x << endl;
	delete x;
	x = NULL;
	cout << &x << endl;
}

void practiceThree()
{
	// Practice stack declaration of arrays
	/*
		int * [] returns an array of pointers
		int (*) [] returns a pointer to an array
		int (*name) [] is the declaration of a pointer to array
		int * name [] is the declaration of an array of pointers
		
		EDIT: I suspect these do same thing, ie: declare a certin array
,	the only difference being that two of these name the creations and 2 d
don't
	*/

	
	
}

void practiceTwo()
{
	int ** arr = new int *[3];
	arr[0] = new int[3];
	arr[0][2] = 2;
	cout << (*(arr+ 0))[2] << endl;
}

void practiceTypeOne()
{
/* I am going to declare a pointer to a dynamic array */

int ** someP;
int * arr = new int [3];
someP = &arr;

cout << "Exampl" << (*someP)[0] << (**someP) << endl;

/* To delete */

delete []arr;

}

int main()
{


	practice();
}
