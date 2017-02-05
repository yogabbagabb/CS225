#include<iostream>
using namespace std;

  class Dog
  {

  private:

    int name;
    int lastName;
    int * pointer;
    int middleName;
      public:
          // question : does lastName get initialized as well if we use our own default constructor?
          // No. it gets default initialized if not declared in the initalization list
          // Not being a class type -- the value is indeterminate


          Dog() // is there an implicit initialization list? Yes there is.
          {
              //name = 3;
          }

          int getName()
          {
            return name;
          }

          int getLastName()
          {
            return lastName;
          }

          void getAllNames()
          {
            cout << name << " " << lastName <<  " " << middleName << " " << pointer;
          }

          const Dog*& manPointer(const Dog * point) const
          {
            // This is a bad practice with the new assignment. What if the new assignment weren't made (!2!)
            //donothing
            cout << "Printing inside the function what the address is of the pointer?" << endl;
            cout << point << endl;
            // shouldn't this, below, be illegal?
            //
            // It would be if we had const after *
            point = new Dog();
            return point;
            // This is not legal because const is outside on the far right
            // name = 4;
            // Notice the triple of uses const:
            /*
            Outside to indicate the return type is consy, inside to indicate
            the parameter type is not mutable. outside on the right
            to indicate that no private member will be touched.

            Note that in a declaration such as
            int * const x;
            const specifies that in

            const int * x;
            The pointer is variable but the value fixed

            int const * x;
            Same as above

            int * const x;
            The pointer is not variable but the value is fixed
            */

          }

          void experiment()
          {
            int x; // This is undefined inside teh scope of a function
            // http://stackoverflow.com/questions/23263798/why-c-primitive-types-are-not-initialized-like-the-rest-of-types
            cout << x << endl;

            int * a = new int[4];
            // This gives garbage values.
            for (int i = 0 ; i  < 4; i++)
            {
              cout << a[i] << " ";
            }
            cout << endl;
            delete a;

             a = new int[4] ();
             // This invokes something close to a constructor although primitives don't have a constructor
            for (int i = 0 ; i  < 4; i++)
            {
              cout << a[i] << " ";
            }
            cout << endl;
            delete a;

          }
  };

  void stir(int & x, int * y) {
  x = 7;
  y = new int(10);
  }


  int main()
  {
    /*
      While polymorphism doesn't work on objects, can you still extract information from
      Dog a = Poodle b; (!1!)
      To test -- if base does not have a method that derived does
      can virtual on the derived one allow a base handle to access it?
      That is, can you access data of b from a?
    */
    Dog bob;
    cout << "Printing Dog's last name" << endl;
    cout << bob.getName() << endl;
    Dog * q = &bob;
    cout << "Printing the adrdress of bob" << endl;
    cout << q << endl;
    const Dog * a = bob.manPointer(q);
    cout << "printing the address of a copy of bob's pointer returned by reference" << endl;
    cout << a << endl;
    delete a;
    cout << "printing all names of dog" << endl;
    int x;
    x = 6;
    bob.getAllNames();
    bob.experiment();
    
    cout << "past delete x(int)" << endl;
    // bob = NULL; Error objects cannot be set to null

    // This generates seg-fault below
    // int w; int * v = NULL;
    // stir(w, v);
    // cout << w << ", " << *v << endl;
    // delete v; return 0;
  }
