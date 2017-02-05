/*
You will be writing a program that utilizes the const keyword in different ways.
If you need a review of const (particularly const pointers) you might want to check out this tutorial
In a new file do the following:
Write a class Circle that has one member: double radius, and accessor and mutator methods for this member variable.
Write a function print that takes in a Circle object as a parameter and prints out I am a circle. My radius is followed by the value of radius
Make sure that the actual Circle object that you pass in as a parameter is used by the funciton (not a copy of the Circle, that is pass by ____)
Signify to the compiler that the print function will not alter the Circle parameter. Now alter the method so it calls setRadius. Write in a comment what happens when you try to compile/run (with an empty main method). Comment out the setRadius line.
Write a main method that
Creates a Circle object and set it's radius to some value
Next create two pointers to the Circle you created
The first pointer must be constant in the sense that you cannot change the Circle object the pointer points to
The second must be constant in the sense that you cannot what the pointer points to (i.e., you cannot do the following: int * x = p; x = q; where p and q are integers)
Print out the following using the first pointer: The radius is followed by the radius value.
*/
#include <iostream>
using namespace std;

class Circle
{
public:
  int radius;
  int * y;
  int getRadius()
  {
    return radius;
  }
  void setRadius(int ra)
  {
    radius = ra;
  }

  // Lesson
  void print() const
  {
    cout << "radius is" << radius;
    setRadius(3);
  }
};



int main()
{

  Circle x;
  x.print();
  return 0;
}
