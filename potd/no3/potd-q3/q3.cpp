#include <string>
#include <iostream>
using namespace std;

class Pet{

// All fields were set to private. I don't my client to change my cat's name
// to something inappropriate -- or, more generally, change anything about
// it without my consent. My consent is expressed through the specifications
// (at present none) that I provide in my public getter and setter methods.

private:
	int birth_year;
	string type;
	string name;
        string owner_name;		

public:

 	string get_name()
        {
		return name;
	}

	string get_owner_name()
        {
		return owner_name;
	}

	string get_type()
        {
		return type;
        }

 	int get_birth_year()
        {
		return birth_year;
	}

	void set_name(string name)
        {
		this ->name = name;
	}
	void set_owner_name(string owner_name)
        {
		this -> owner_name = owner_name;
	}

	void set_type(string type)
        {
		this -> type = type;
	}

        void set_birth_year(int birth_year)
        {
		this -> birth_year = birth_year;
	}

	

};

int main()
{
	Pet petty;
	petty.set_name("bon");
	cout << petty.get_name();
	petty.set_name("Joe");
	cout << petty.get_name();
	cout << "\n";
	petty.set_birth_year(1997);
	cout << petty.get_birth_year();
	
}
