#include <iostream>
#include <string>
using namespace std;

class Square{
    private:
        string name;
        double * lengthptr;
    public:
        Square();
        Square(const Square & old);
        ~Square();
        void setName(string newName);
        void setLength(double newVal);
        string getName() const;
        double getLength() const;
        Square& operator=(const Square& ref);
        Square& operator+(const Square& ref);
        /*
        We should overload the assignment operator
        because the default assignment operator does a
        member-wise copy, which, for pointers, only copies
        the address of the pointer and not the value of its pointee.
        */


};

Square::Square(){
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

Square& Square::operator=(const Square& ref)
{
    if (this != &ref)
    {
        this -> name = ref.name;
        delete lengthptr;
        lengthptr = new double(*ref.lengthptr);
    }

    return *this;
}

Square& Square::operator+(const Square& ref )
{
    Square * sum = new Square(*this);
    sum->setName(sum->getName() + ref.name);
    *(sum->lengthptr) += *(ref.lengthptr);

    return *sum;
}

void Square::setName(string newName){name = newName;}
void Square::setLength(double newVal){*lengthptr = newVal;}
string Square::getName() const {return name;}
double Square::getLength() const {return *lengthptr;}

Square::Square(const Square & other){
    cout << "I am copying!" << endl;
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square(){
    delete lengthptr;
}


int main(){
    Square a;
    Square b = a;
    // Square c(a);
    //
    // Square d;
    // Square e = c + d;
    // cout << e.getLength();
    // cout << e.getName();
    // Square q = e;
    // cout << q.getLength();
    // cout << q.getName();

    return 0;
}
