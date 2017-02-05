#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
ofstream myfile;
 myfile.open ("test.txt");
 myfile << "Writing this to a file.\n";
 myfile << "Writing something else.\n";
 myfile.close();
 string line;
 ifstream otherFile("test.txt");
 while( getline(otherFile, line))
 {
   cout << line << "\n";
 }
  return 0;
}
