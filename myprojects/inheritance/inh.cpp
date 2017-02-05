#include<iostream>
using namespace std;

class House
{
private:
  double rent;
  int age;

protected:
  int lifetime;

public:

  int sliceEx;

  virtual double getRent()
  {
    return rent;
  }

  // virtual double doNothing() = 0;

  virtual ~House() = 0;
  House()
  {
    lifetime = 1;
    rent = 5.4;
    sliceEx = 1;
  }

  double getLifetime()
  {
    return lifetime;
  }




};

House::~House()
{

}

class Apartment: public House
{

private:
  double rent;
  double lifetime;
public:


  Apartment()
  {
    rent = 3.4;
    lifetime = 4;
    House::lifetime = 3;
  }

  double getRent()
  {
    return rent;
  }

  virtual double getLifetime()
  {
    return lifetime;
  }

  ~Apartment()
  {

  }

};

int main()
{

  Apartment a;
  House * h = &a;
  // House h;
  // Apartment a;
  // cout << a.getLifetime() << endl;
  // cout << h.getRent() << endl;
  //
  // // Remark: if a must use getRent() but does not itself define the method then
  // // it will use the getRent() of h, which returns the member variable of H!
  //
  // //Remark: cout << h.Apartment::getRent() << endl; is a compiler error
  // // Because Apartment::geRent() is not a member of class house
  //
  //
  // //Remark: Use House::field or House::method if you want to access the member
  // // variables of the base class
  //
  // House * h2 = &a;
  //
  // // This, below, is invalid, because it tries to access a protected member
  // // A protected member is accessible, within the class, to the class and,
  // // within subclasses, to the subclasses.
  //
  // h = a;
  // // as a result of this line, all the member variables of a that are native to
  // // House get assigned to h
  // //Proof: we should see 3
  //
  // cout <<  h.getLifetime() << endl;
  //
  //
  // // cout << h.getLifetime() << endl;This is not valid since there is no getLifeTime
  // // in House
  //
  // cout << h.getRent() << endl; // This returns house's rent (5.4) and not
  // // 3.4, which is the rent of apartment (the rent variable of a is different
  // // from that of h -- there are two floating around!
  //
  // cout << a.House::getRent() << endl;
  // //This is legal and prints the rent of house
  //
  // // a = h throws a compiler error because there is no viable overload for =
  // // cout << h2->getLifetime() << endl;
  // // The above is impossible unless House also has that method getLifeTime();
  //
  // // Remark: the effects of splicing on object (as opposed to pointer) --
  // // virtual is ignored. Consider the pointer version:
  //
  // House * hP = &a;
  // cout << hP->getRent() << endl;
  // // this above prints hte rent of the apartment
  //
  // // Remark: the effects of declaring virtual but making no implementation
  // // This is possible, firstly, if the method type is void
  // // Secondly it obliges nothing. A method could well do nothing on purpose.
  //
  //
  // // Remark: the effects of varying the type of object inherited
  // // Prediction, if I make apartment inherit a protected house, then the above
  // // a.House::getRent() no longer is possible
  //
  // // the syntax of a pure virtual function
  // // no function braces {}; just () = 0
  // //Remark: until a class implements a pure virtual method, regardless if it
  // // inherits from some other class, it is also abstract!
  //
  // // http://stackoverflow.com/questions/16666317/why-can-a-base-pointer-point-to-derived-object-only-under-public-inheritance
  // // you can have polymorphism where inheritance is non-public but addresses not
  // // sendable directly outside class. see above
}
