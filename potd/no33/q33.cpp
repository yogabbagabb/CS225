#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int myhash(string str){
    int sum = 0;

    for (int i = 0; i < str.length(); i++)
    {
      sum += str[i];
    }
    
    return sum % 4;
}

int main(){
    string in;
    cout << "Enter the location you would like to know the weather forcast for: ";
    getline(cin, in);
    int hashval = myhash(in);
    cout << in << " hashed to value " << hashval << endl;
    if(hashval == 0)
        cout << "It will snow tomorrow." << endl;
    else if(hashval == 1)
        cout << "It will be sunny all day tomorrow." << endl;
    else if(hashval == 2)
        cout << "There is a 50\% chance of rain tomorrow." << endl;
    else
        cout << "There will be a tornado tomorrow. Plan your day accordingly." << endl;
    return 0;
}
