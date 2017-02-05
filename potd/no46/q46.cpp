#include <iostream>
#include <string>
using namespace std;

class Food{
    protected:
        string name;
    public:
        Food(){name = "Food";}
        virtual void printColor(){cout << "Foods come in a variety of colors." << endl;}
};

class Fruit : public Food{
    public:
        Fruit(){name = "Fruit";}
        void printColor(){cout << "Fruits come in a variety of colors." << endl;}
};

class SpecificFruit : public Fruit{
    private:
        string color;
    public:
        SpecificFruit(string newName, string newColor){
            name = newName;
            color = newColor;
        }
        void printColor(){cout << "A " << name << " is " << color << "." << endl;}
};

void printColors(Food * arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i]->printColor();
    }
}

/Ever wonder what that #define and #ifndef stuff is at the beginning of classes? Read this tutorial If you need a review on macros in general, this might help.
Write a program that defines one macro that substitutes some text of your choosing with the string "purple" and another macro IAMDEFINED that does not get substituted with anything
Write a main function that prints out "purple is a great color" only if IAMDEFINED is defined using your macros
In a comment explain what a header guard is and why they are useful

int main()
{
  Food x;
  Fruit y;
  SpecificFruit z("banana", "yellow");
  SpecificFruit l("stawberry", "red");
  Food * arr[4];
  arr[0] = &x; arr[1] = &y; arr[2] = &z; arr[3] = &l;
  printColors(arr,4);
}
