#include "string.h"
#include <iostream>



class food
{
	private:
		int quantity;
		std::string name;

	public:
		food();
		std::string getName();
		int getQuantity();
		void setName(std::string na);
		void setQuantity(int q);

};






food::food()
{
	name = "carrot";
	// What is the lifetime of these variables bound to objects?
	// It seems that strings can also be assigned using string s = "something"
	// and yet strings are objects -- which, I thought, don't obey this syntax. Can they obey it?
	quantity = 3;
}


std::string food::getName()
{
	return name;
}

int food::getQuantity()
{
	return quantity;
}

void food::setName(std::string n)
{
	name = n;
}
void food::setQuantity(int q)
{
	quantity = q;
}


void increaseQuantity(food * foo)
{
	int quant = foo -> getQuantity();
	foo -> setQuantity(quant + 1);
}
int main()
{

	food foo;
	std::cout << foo.getQuantity() << std::endl;
	increaseQuantity(&foo);
	std::cout << foo.getQuantity() << std::endl;	

}
