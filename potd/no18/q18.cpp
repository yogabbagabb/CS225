#include <iostream>
using namespace std;
// Write a templated class BankAccount
// It should have a private member balance
// It should have public functions
// getBalance
// add (accepts an amount, adds it to balance, returns nothing)
// remove (accepts an amount, subtracts it from balance, returns nothing)
// a constructor that takes in the initial balance as a parameter
// Write a main function with two bank accounts
// The first bank account should be able to store dollars and change
// The second bank account is at a bank that refuses to accept change,
//so the amounts involved in transactions will only be integers
// Each account should start with a $2000 balance
// Add .50tothefirstbankaccountandremove.50tothefirstbankaccountandremove50 from the second

template<class T>
class BankAccount
{
private:
  T balance;

public:
  T getBalance()
  {
    return balance;
  }

  BankAccount(T initial)
  {
    balance = initial;
  }

  void add(T amount)
  {
    balance += amount;
  }

  void remove(T amount)
  {
    balance -= amount;
  }
};

int main()
{
  BankAccount <double> a(2000);
  a.add(0.50);
  BankAccount <int> b(2000);
  b.add(50);
  cout << a.getBalance() << endl;
  cout << b.getBalance() << endl;
}
