#include <iostream>
using std::cout;
using std::endl;

class student{
public:
	int getGrade();
	std::string getName();
	void setGrade(int a);	
	void setName(std::string q);	
	student();

private:
	std::string name;
	int grade;
};

student::student()
{
	name = "b";
	grade = 0;
}

std::string student::getName()
{
	return name;
}

int student::getGrade()
{
	return grade;
}

void student::setGrade(int a)
{
	grade = a;
}

void student::setName(std::string s)
{
	name = s;
}


void graduate(student& b)
{
	b.setGrade(b.getGrade() + 1);
}


int main ()
{
	student x;
	cout << x.getName() << " is in grade " << x.getGrade() << endl;	
	graduate(x);	
	cout << x.getName() << " is in grade " << x.getGrade() << endl;
}
