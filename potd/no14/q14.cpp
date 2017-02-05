#include<iostream>



class square
{

double * length;
std::string name;

public:

      square()
      {
        name = "mysquare";
        length = new double (2.0);
      }

      square(square& ref)
      {
        this->name = ref.name;
        this->length = new double(*(ref.length));
        std::cout << "I am copying!" << std::endl;
      }

      ~square()
      {
        delete length;
      }

};

int main()
{
  square a;
  square b(a);
  square c = b;
}
