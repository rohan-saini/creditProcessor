//
//  CreditProcessorTests.cpp
//  Braintree Coding Challenge
//

#include <stdio.h>
#include "Account.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

// reads file input information and completes add, charge, or credit processes
void completeProcesses(istream &inputStream, map<string, Account> &client_map)
{
    string action, name, accountNum;
    char dollar;
    int limit, amount;
    
    // reading in file from input source
    while(inputStream >> action)
    {
        if(action == "Add")
        {
            inputStream >> name >> accountNum >> dollar >> limit;
            
            // creating new Account object and pushing to vector of all clients
            Account acc(name, accountNum, limit);
            client_map.insert(make_pair(name, acc));
        }
        else
        {
            inputStream >> name >> dollar >> amount;
            map<string, Account>::iterator it;
            
            // searching for correct client and then charging/crediting their account
            if(action == "Charge")
            {
                it = client_map.find(name);
                it->second.charge(amount);
            }
            else
            {
                it = client_map.find(name);
                it->second.credit(amount);
            }
        }
    }
}

// prints summary of balance information for all clients
void summary(map<string, Account> &client_map, stringstream &s)
{
    map<string, Account>::iterator it;
    for(it = client_map.begin(); it != client_map.end(); it++)
    {
        string name = it->second.getName();
        int balance = it->second.getBalance();
        if(!it->second.getAccountNumValid())
        {
            s << name << ": error" << endl;
        }
        else
        {
            s << name << ": $" << balance << endl;
        }
    }
}

// unit testing functions
void test_add(); // tests add function (Account constructor)
void test_credit(); // tests credit function
void test_charge(); // tests charge function
void test_account_valid(); // tests luhn 10 check
void test_limit(); // tests adding charges above the limit
void test_charge_invalid(); // tests charges with invalid account number

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    
    // unit testing all functions of Account
    test_add();
    test_credit();
    test_charge();
    test_account_valid();
    test_limit();
    test_charge_invalid();
    
    // retrieving the input file and the solution file
    string filename = argv[1];
    string filename_correct = argv[2];
    ifstream inputStream(filename);
    ifstream inputCorrect(filename_correct);
    
    map<string, Account> client_map;
    completeProcesses(inputStream, client_map);
    
    // writing the output to a stringstream object to later compare to solution
    stringstream s;
    summary(client_map, s);
    
    // comparing output line by line with solution and halting the program if a line doesn't match
    string line, line_correct;
    while(getline(inputCorrect, line_correct))
    {
        getline(s, line);
        assert(line == line_correct);
    }
    
    cout << "Output passes test." << endl;
    
    return 0;
}

// implementation of unit testing functions
void test_add()
{
    Account acc("Bob", "4024007191722635", 1000);
    string name = acc.getName();
    bool valid = acc.getAccountNumValid();
    int balance = acc.getBalance();
    
    assert(name == "Bob");
    assert(valid == true);
    assert(balance == 0);
    
    cout << "test_add() PASSED" << endl;
}

void test_credit()
{
    Account acc("Bob", "4024007191722635", 1000);
    acc.credit(350);
    int balance = acc.getBalance();

    assert(balance == -350);
    
    cout << "test_credit() PASSED" << endl;
}

void test_charge()
{
    Account acc("Bob", "4024007191722635", 1000);
    acc.charge(500);
    int balance = acc.getBalance();
    
    assert(balance == 500);
    
    cout << "test_charge() PASSED" << endl;
}

void test_account_valid()
{
    Account acc("Bob", "1234567891011", 1000);
    bool valid = acc.getAccountNumValid();
    assert(!valid);
    
    Account acc2("Charles", "5454545454545454", 1000);
    bool valid2 = acc2.getAccountNumValid();
    assert(valid2);
    
    cout << "test_account_valid() PASSED" << endl;
}

void test_limit()
{
    Account acc("Bob", "4024007191722635", 1000);
    acc.charge(500);
    acc.charge(700);
    acc.charge(200);
    int balance = acc.getBalance();
    
    assert(balance == 700);
    
    cout << "test_limit() PASSED" << endl;
}

void test_charge_invalid()
{
    Account acc("Bob", "1234567891011", 1000);
    acc.charge(500);
    acc.charge(700);
    acc.charge(200);
    int balance = acc.getBalance();
    
    assert(balance == 0);
    
    cout << "test_limit() PASSED" << endl;
}
