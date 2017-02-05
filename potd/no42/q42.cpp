#include <iostream>
using namespace std;


void getInput(int playerid, int *arr, int SIZE){
    // get user choice
    char token = (playerid == 1) ? 'X' : 'O';
    int row, col;
    cout << "Player " << playerid << ", it's your turn." << endl;
    do{
        cout << "Where would you like to place an " << token << "? Row (1, 2...): ";
        cin >> row;
        cout << "Col (1, 2...): ";
        cin >> col;
        if(col < 1 || col > SIZE)
            cout << "Column must be between 1 and " << SIZE << endl;
        if(row < 1 || row > SIZE)
            cout << "Row must be between 1 and " << SIZE << endl;
        if(arr[(row - 1) * SIZE + (col - 1)] != 0)
            cout << "That square is already occupied" << endl;
    } while( row < 1 || row > SIZE || col < 1 || col > SIZE || arr[(row - 1) * SIZE + (col - 1)] != 0);

    // store in data structure
    arr[(row - 1) * SIZE + (col - 1)] = playerid;
}

void printBoard(int *arr, int SIZE){

  for (int i = 0 ; i < SIZE*SIZE; i++)
  {
    if (i%3 == 0)
    {
      cout << "\n";
      cout << "_______________" << endl;
      cout << "| ";
    }
    if (arr[SIZE* i/3 + i%3] == 2)
    {
      cout << "X |";
    }
    else if (arr[SIZE *i/3 + i%3] == 1)
    {
      cout << "O |";
    }
    else
    {
      cout << " |";
    }

  }

  cout << "| ";
  cout << "________________" << endl;

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
        printBoard(arr, size);
        cout << "PLAYER " << player << " it's your move.";
        getInput(player, arr, size);
        // if(winner = check(arr, size)){
        //     printBoard(arr, size);
        //     cout << "PLAYER " << winner << " WINS!" << endl;
        //     delete [] arr;
        //     return 0;
        // }
        player = (player == 1) ? 2 : 1;
        turn++;
    }
    printBoard(arr, size);
    cout << "Cat's game." << endl;
    delete [] arr;
    return 0;
}
