#include <iostream>
using namespace std;


class BMP
{
private:
  int age;

public:
  int getAge()
  {
    return age;
  }
};

class picRoster
{
private:
BMP ** courses;
int * enrollments;
int numCourses;
// some helper functions
public:

picRoster()
{
  numCourses = 10;
  enrollments = new int [numCourses];
  for (int i = 0; i < numCourses; i++)
    enrollments[i] = i+3;

  courses = new BMP *[numCourses];
  for (int i = 0; i < numCourses; i++)
  {
    courses[i] = new BMP[enrollments[i]];

    for (int j = 0; j < enrollments[i]; j++)
    {
      BMP c;
      courses[i][j] = c;
    }

  }
}

~picRoster()
{
  clear();
  cout << "Deleted" << endl;
}

void clear()
{


  for (int i = 0; i < numCourses; i++)
  {

    delete []courses[i];
    // note that this syntax must appear here!

  }

  delete []courses;
  delete []enrollments;
}

picRoster& operator=(const picRoster& ref)
{

  if (this != &ref)
  {
        clear();
        this->numCourses = ref.numCourses;

        enrollments = new int [numCourses];

        for (int i = 0; i < numCourses; i++)
          enrollments[i] = ref.enrollments[i];

        courses = new BMP *[numCourses];

        for (int i = 0; i < numCourses; i++)
        {
          courses[i] = new BMP[enrollments[i]];

          for (int j = 0; j < enrollments[i]; j++)
          {
            courses[i][j] = ref.courses[i][j];
          }
        }
  }

  return *this;

}

picRoster(const picRoster& ref)
{
  enrollments = new int [ref.numCourses];
  numCourses = ref.numCourses;
  for (int i = 0; i < numCourses; i++)
    enrollments[i] = ref.enrollments[i];

  courses = new BMP *[numCourses];

  for (int i = 0; i < numCourses; i++)
  {
    courses[i] = new BMP[enrollments[i]];

    for (int j = 0; j < enrollments[i]; j++)
    {
      courses[i][j] = ref.courses[i][j];
    }
  }


}
// constructors and destructor
// operator= declaration
// lots of public member functions
};


int main()
{
  picRoster a;
  picRoster b(a);

}
