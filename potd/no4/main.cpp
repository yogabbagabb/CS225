#include <string>
#include <iostream>
#include "pet.h"

using namespace std;

bool check(string testing,
           int expected,
           int got) {
  cout << "Checking " << testing << ": ";
  if (expected == got) {
    cout << "PASS!" << endl;
    return true;
  } else {
    cout << "OH NO!  Expected '" << expected <<
      "' but got '" << got << "' instead." << endl;
    return false;
  }
}

bool check(string testing,
           string expected,
           string got) {
    cout << "Checking " << testing << ": ";
    if (expected == got) {
       cout << "PASS!" << endl;
       return true;
    } else {
       cout << "OH NO!  Expected '" << expected <<
            "' but got '" << got << "' instead." << endl;
       return false;
    }
}

int main(){
    Pet Rover; 
    Pet Trinity("Trinity",2002,"cat","Kelly");
    Pet Ravi("Ravi",1995,"tarantula","Mattox");

    check("Rover's name","Rover",Rover.getName());
    check("Rover's type","dog",Rover.getType());
    check("Rover's birth year",2016,Rover.getBY());
    check("Rover's owner","Cinda",Rover.getOwnerName());

    check("Trinity's name","Trinity",Trinity.getName());
    check("Trinity's type","cat",Trinity.getType());
    check("Trinity's birth year",2002,Trinity.getBY());
    check("Trinity's owner","Kelly",Trinity.getOwnerName());

    check("Ravi's name","Ravi",Ravi.getName());
    check("Ravi's type","tarantula",Ravi.getType());
    check("Ravi's birth year",1995,Ravi.getBY());
    check("Ravi's owner","Mattox",Ravi.getOwnerName());

    return 0;
}

