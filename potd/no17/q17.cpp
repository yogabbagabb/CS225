// Write a class Pet that is derived from the Animal class
// In addition to the animal_type and food_type variables, Pet should have a private variable name and private variable owner_name
// Write functions that get and set the type of food, name, and owner name of the pet class
// Write a function print that prints "My name is __ __." where the blank is the value of the name variable
// Write a default constructor for pet that initializes animal_type to cat, food_type to fish, name to "Fluffy", and owner_name to "Cinda" and a constructor that takes in the type of animal, type of food, name, and owner name as parameters
// Create a main function
// Produce the following output by calling only the print functions you have writen:
// I am a cat.
// My name is Garfield.

#include<iostream>
using namespace std;

class Animal
{
  private:
    std::string type;
  protected:
    std::string food_type;
  public:

    Animal()
    {
      type = "cat";
      food_type = "fish";
    }

    Animal(std::string dog, std::string cat)
    {
      type = dog;
      food_type = cat;

    }
    void setType(std::string type)
    {
        this->type = type;
    }

    void setFood(std::string type)
    {
        this->food_type = type;
    }

    std::string getType()
    {
      return type;
    }

    std::string getFood()
    {
      return food_type;
    }

    void print()
    {
      std::cout << "I am a " << type << std::endl;
    }

};


class Pet: public Animal
{
private:
  std::string name;
  std::string owner_name;

public:

  Pet(): Animal()
  {
    name = "Fluffy";
    owner_name = "Cinda";
  }

  void setName(std::string name)
  {
    this->name = name;
  }

  void setOwnerName(std::string name)
  {
    this->owner_name = name;
  }

  std::string getName()
  {
    return name;
  }

  std::string getOwnerName()
  {
    return owner_name;
  }

  void print()
  {
    cout << "My name is " << name << endl;
  }
};

int main()
{
    Pet * a = new Pet ();
    a->setName("Garfield");
    a->Animal::print();
    a->print(); 
}
