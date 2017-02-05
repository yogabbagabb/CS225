#include<iostream>
using namespace std;

int main()
{

// see piazaa post 2163 for reference to lecture

/* int * ss;
*ss  = 3; */
// This can produce a segmentation fault in compilers; it depends. 
// The call to int * ss; sometimes retrieves memory from outside 
// the allocated memory of the program -- so it retrieves "new" memory" and 
// whence faults


/* int * s = NULL;
cout << *s << endl; */
// This produces a segmentation fault

cout << "start" << endl;
int x = 3;
int **l = new int * () ;
*l = &x;
cout << &(**l) << endl;
cout << &x << endl;
cout << "end" << endl;

int * p, *q;
p = new int;
q = p;
*q = 8;
cout << q << endl;
delete p;
cout << "watch" << *p << endl;
cout << q << endl;
cout << p << endl;
*p = 12;
q = NULL;

cout << "start" << endl;
cout << p << endl;
cout << q << endl;
cout << *p << endl;

}
