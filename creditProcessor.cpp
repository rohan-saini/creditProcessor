//
//  creditProcessor.cpp
//  Braintree Coding Challenge
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "Account.h"

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
            
            // find the correct client and then charge/credit their account
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
void summary(map<string, Account> &client_map)
{
    map<string, Account>::iterator it;
    for(it = client_map.begin(); it != client_map.end(); it++)
    {
        string name = it->second.getName();
        int balance = it->second.getBalance();
        if(!it->second.getAccountNumValid())
        {
            cout << name << ": error" << endl;
        }
        else
        {
            cout << name << ": $" << balance << endl;
        }
    }
}

// main
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    
    // hash map that stores all the clients and their account information
    map<string, Account> client_map;
    
    // checking whether input is from file or from STDIN
    if(argc > 1)
    {
        string file = argv[1];
        ifstream inputStream(file);
        completeProcesses(inputStream, client_map);
    }
    else
    {
        istream &inputStream = cin;
        completeProcesses(inputStream, client_map);
    }
    
    summary(client_map);
    return 0;
}
