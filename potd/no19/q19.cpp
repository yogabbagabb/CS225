#include <iostream>
#include <string>
using namespace std;

//
// Write a templated function more with takes in two variables of the same type
// and returns whichever variable is greater than (>) the other
// Write a main method that uses the more function on two instances
//of the food class that has been provided for you to print out which food you have more of
// (HINT: you might have to add something to the food class in order for
// more to be able to be called propperly.)
// For example, if we had 8 apples and 6 oranges than your program should output:


class Food{
    private:
        string name;
        int quantity;
    public:
        Food();
        void setName(string newName);
        void setQuantity(int newQuantity);
        string getName();
        int getQuantity() const;
        bool operator>(Food other) const;
};

Food::Food(){name = "food"; quantity = 0;}
void Food::setName(string newName){name = newName;}
void Food::setQuantity(int newQuantity){quantity = newQuantity;}
string Food::getName(){return name;}
int Food::getQuantity() const {return quantity;}

bool Food::operator>(Food other) const{return this->quantity > other.quantity;}

void increaseQuantity(Food * food){
    (*food).setQuantity((*food).getQuantity() + 1);
}


// Your `more` code here
template<class T> T more(T first, T second)
{
  if (first > second)
    return first;
  else
    return second;
}

int main(){
    Food apples, oranges, greater;
    apples.setName("apples");
    apples.setQuantity(7);
    oranges.setName("oranges");
    oranges.setQuantity(5);
    greater = more<Food>(apples, oranges);
    cout << "We have more " << greater.getName() << endl;
    return 0;
}
