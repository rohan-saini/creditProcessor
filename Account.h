//
//  Account.h
//  Braintree Coding Challenge
//

#ifndef Account_h
#define Account_h
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    string name; // account owner's name
    bool accountNumValid; // stores whether account number is valid
    int balance; // stores balance
    int limit; //stores limit of account
    
public:
    // constructors for Account object
    Account();
    Account(string name_in, string accountNum_in, int limit_in);
    
    // getters
    string getName();
    int getBalance();
    bool getAccountNumValid();
    
    // charge and credit functions
    void charge(int amount);
    void credit(int amount);
};

#endif /* Account_h */

