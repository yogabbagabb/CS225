#include<stddef.h>

int main()
{

int * x = NULL;

/* if (1+1 == 2)
{
	int a = 3;
	x = &a;

// This doesn't work
} */

*x = 2;
}

/*
X initially points to no memory location (ie null). We then try to access 
the value stored at this memory location; this produces the segFault.
*/
