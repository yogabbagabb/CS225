#include<iostream>

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



int main()
{
return 0;
}
