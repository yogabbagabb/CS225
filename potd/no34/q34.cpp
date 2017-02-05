#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int myhash(string str){     // many different hash fucntions acceptable, this is just an example

  return (str.length() % 4);
}

int main(){
    cout << "State your question: ";
    string in;
    getline(cin, in);
    // put error checking code here...

    if (in.substr(in.length()-1) != "?" || in.length() > 100)
    {
      cout << "error" << endl;
      return 1;
    }

    int val = myhash(in);

    cout << in << " hashed to value " << val << endl;
    if(val == 0)
        cout << "The outlook is bleak." << endl;
    else if(val == 1)
        cout << "The answer is most likely yes." << endl;
    else if(val == 2)
        cout << "Is today Tuesday? If yes, then yes! Otherwise, probably not." << endl;
    else if(val == 3)
        cout << "Most definitely!" << endl;
    else
        cout << "The future in unclear at the moment. Try again later." << endl;
    return 0;
}
