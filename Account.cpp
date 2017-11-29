//
//  Account.cpp
//  Braintree Coding Challenge
//

#include <stdio.h>
#include <iostream>
#include "Account.h"

using namespace std;

// default constructor for Account object
Account::Account() : name(""), balance(0), accountNumValid(false), limit(0) {}

// constructor for Account object that validates account number (Luhn 10)
Account::Account(string name_in, string accountNum_in, int limit_in):
name(name_in), balance(0), limit(limit_in)
{
    int length = int(accountNum_in.length()) - 1;
    bool toDouble = false; // bool to skip every other number
    int sum = 0;
    
    // iterating over account num backwars
    while(length >= 0)
    {
        char val = accountNum_in[length];
        int value = val - '0';
        
        // adding digits together if necessary
        if(toDouble)
        {
            value *= 2;
            
            if (value > 9)
            {
                value -= 9;
            }
        }
        
        // calculating total sum of new account num
        toDouble = !toDouble;
        sum += value;
        length--;
    }
    
    // checking if sum is divisible by 10
    if(sum % 10 != 0)
    {
        this->accountNumValid = false;
    }
    else
    {
        this->accountNumValid = true;
    }
}

string Account::getName()
{
    return name;
}

int Account::getBalance()
{
    return balance;
}

bool Account::getAccountNumValid()
{
    return accountNumValid;
}

// charge balance function
void Account::charge(int amount)
{
    int total = balance;
    total += amount;
    if(accountNumValid && total <= limit)
    {
        balance += amount;
    }
}

// credit balance function
void Account::credit(int amount)
{
    if(accountNumValid)
    {
        balance -= amount;
    }
}

