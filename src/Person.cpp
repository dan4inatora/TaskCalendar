#include "Person.h"


void Person :: copy(const Person& other){
    	this->fstName = new char[strlen(other.fstName) + 1];
    	strcpy(this->fstName, other.fstName);
    	this->lastName = new char[strlen(other.lastName) + 1];
    	strcpy(this->lastName, other.lastName);
}
void Person :: erase(){
    	delete[]this->fstName;
    	delete[]this->lastName;
}

Person :: Person(){
	    this->fstName = new char[strlen("None") + 1];
    	strcpy(this->fstName, "None");
    	this->lastName = new char[strlen("None") + 1];
    	strcpy(this->lastName, "None");
}
Person ::  Person(const Person& other){
	this->copy(other);
}

Person& Person :: operator=(const Person& other){
	if(this != &other){
		this->erase();
		this->copy(other);
	}
	return *this;
}

Person :: ~Person(){
	this->erase();
}

void Person :: setFstName(const char* fst){
	    this->fstName = new char[strlen(fst) + 1];
    	strcpy(this->fstName, fst);
}

void Person :: setLastName(const char* last){
	    this->lastName = new char[strlen(last) + 1];
    	strcpy(this->lastName, last);
}

char* Person :: getFstName()const{
	return this->fstName;
}

char* Person :: getLastName()const{
	return this->lastName;
}

void Person :: printP()const{
	cout<<"First name : "<< this->fstName<<" Last name : "<< this->lastName<<endl;
}

bool Person::operator==(const Person& other)
{
     if(strcmp(this->fstName,other.fstName) == 0 && strcmp(this->fstName,other.fstName) == 0){
        return true;
     }
     else{
        return false;
     }
}

bool Person::operator!=(const Person& other)
{
     if(strcmp(this->fstName,other.fstName) == 0 && strcmp(this->fstName,other.fstName) == 0){
        return false;
     }
     else{
        return true;
     }
}
