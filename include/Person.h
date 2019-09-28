#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class Person
{
private:
    char* fstName;
    char* lastName;

    void copy(const Person& other);
    void erase();
public:
    Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();
    void setFstName(const char* fst);
    void setLastName(const char* last);
    char* getFstName()const;
    char* getLastName()const;
    void printP()const;
    bool operator==(const Person& other);
    bool operator!=(const Person& other);
};
