#ifndef _PET_H
#define _PET_H

#include <string>
using namespace std;

class Pet {
 public:
  // Declare your constructors here!
	Pet();
	Pet(string name, int BY, string type, string ownerName);

  // Other member functions
  void setName(std::string newName);
  void setBY(int newBY);
  void setType(std::string newType);
  void setOwnerName(std::string newName);
  std::string getName();
  int getBY();
  std::string getType();
  std::string getOwnerName();

 private:
  std::string name;
  int birth_year;
  std::string type;
  std::string owner_name;
};

#endif
