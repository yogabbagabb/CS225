#include <iostream>
#include <string>
using namespace std;


void getInput(int playerid, int *arr, int SIZE){
    cout << "Please enter somthing valid: (x,y) or else I blow up\n";
    string output;
    cin >> output;
    int comma = output.find(",");

    int x = (std::stoi(output.substr(1,comma-1)));
    int y = std::stoi(output.substr(comma + 1));
    if (x > SIZE || y > SIZE)
      cout << "Way too big mate! -- I'm outta" << endl;
      
    if (arr[(x-1) + 2*(y-1)] == 0)
      arr[x + 2*y] = 1;
    else
      cout << "Something's already here mate!" << endl;
}


int main(){
    int size;
    int *arr;
    cout << "WElCOME TO TIC-TAC-TOE 5000\nHow large would you like the nxn board to be? n=";
    cin >> size;
    arr = new int[size*size];
    // initialize board
    for(int i = 0; i < size*size; i++){
        arr[i] = 0;
    }
    cout << "LET'S BEGIN!" << endl;
    int turn = 0;
    int player = 1;
    int winner;
    while(turn < size*size){
    //    You'll do this one tomorrow!
    //    printBoard(arr, size);
        cout << "PLAYER " << player << " it's your move.";
        getInput(player, arr, size);
        // You'll do this in two days!
    //    if(winner = check(arr, size)){
    //        printBoard(arr, size);
    //        cout << "PLAYER " << winner << " WINS!" << endl;
    //        delete [] arr;
    //        return 0;
    //    }
        player = (player == 1) ? 2 : 1;
        turn++;
    }
    // printBoard(arr, size);
    cout << "Cat's game." << endl;
    delete [] arr;
    return 0;
}
