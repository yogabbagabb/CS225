int main()
{
int * x = new int (3);
int p = *x;

/*
This creates a memory leak, because the memory allocated onto the heap
from the call to line 3 isn't returned back to the system	
 */
}
