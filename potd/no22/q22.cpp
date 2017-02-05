#include<iostream>
#include<map>
using namespace std;

/*


Write a program that takes in an input string from stdin and prints out the character that appears most frequently in the string (regardless of case, e.g. in "Haha", "h" and "a" both appear twice)
You can assume the string will only contain upper and lowercase letters and spaces
(HINT: ask Google about the map data structure in the STL.)
If there is a tie in the frequency of two letters, print out the one that is alphabetically first
Sample output with input string "Hello world":

The most frequent character is l
*/


int main()
{

cout << "Give me your line please" << endl;
string container;
cin >> container;

map<char, int> freq;

for (size_t i = 0 ; i < container.length(); i++)
{
  if (freq.count(container[i])  == 0)
  {
      freq[container[i]];
  }
  else
  {
      int& exists = freq[container[i]];
      exists += 1;
  }



}



std::map<char,int>::iterator it=freq.begin();
char maxFreq = it->first;
int times = it ->second;
++it;

for (it; it!=freq.end(); ++it)
{
  if (it -> second >= times)
  {
    if (it ->second == times)
    {
      maxFreq = (tolower(it->first) < tolower(maxFreq))? it->first: maxFreq;
    }
    else
    {
      maxFreq = it->first;
      times = it->second;
    }
  }
}

cout << "The most frequent letter is: " << maxFreq << endl;


}
