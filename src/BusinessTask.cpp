#include "BusinessTask.h"

bool peopleEq(vector<Person>& people, vector<Person>& people2){
    bool flag = true;
    if(people.size() != people2.size()){
        flag = false;
    }
    else{
        for(unsigned int i = 0; i < people.size(); i++){
            if(people[i] != people2[i]){
                flag = false;
            }
        }
    }
    return flag;
}

void BusinessTask :: copy(const BusinessTask& other){

    this->location = new char[strlen(other.location) + 1];
    strcpy(this->location, other.location);
    this->host = new char[strlen(other.host) + 1];
    strcpy(this->host, other.host);
    this->people = other.people;


}

void BusinessTask :: erase(){

    delete[]this->location;
    delete[]this->host;

}
int BusinessTask :: getType()const{
	return 1;
}

BusinessTask :: BusinessTask() : Task(){
	this->location = new char[strlen("None") + 1];
	strcpy(this->location, "None");
	this->host = new char[strlen("None") + 1];
	strcpy(this->host, "None");


}
BusinessTask :: BusinessTask(const BusinessTask& other) : Task(other){
	this->copy(other);
}

BusinessTask& BusinessTask :: operator = (const BusinessTask& other){
	if(this != &other){
		Task :: operator=(other);
		this->erase();
		this->copy(other);
	}
	return *this;
}

BusinessTask :: ~BusinessTask(){
	this->erase();
}

void BusinessTask :: setLocation(const char* location){
		this->location = new char[strlen(location) + 1];
		strcpy(this->location, location);
}

void BusinessTask :: setHost(const char* host){
		this->host = new char[strlen(host) + 1];
		strcpy(this->host, host);
}

void BusinessTask :: setPeople(vector<Person> _people){
	this->people = _people;
}

char * BusinessTask :: getLocation()const{
	return this->location;
}

char * BusinessTask :: getHost()const{
	return this->host;
}

vector<Person> BusinessTask :: getPeople()const{
	return this->people;
}

void BusinessTask :: print()const{
	Task::print();
	cout<<"people in this meeting: "<<endl;
	for(unsigned int i = 0; i < this->people.size(); i++){
		people[i].printP();
	}
	cout<<"Location: "<<this->location<<endl;
	cout<<"Host: "<<this->host;
	cout<<endl;
}

Time BusinessTask :: getDuration()const{
	return this->getDiapason().getPeriod();
}
void BusinessTask :: addPeople(const Person& person){
	this->people.push_back(person);
}

void BusinessTask :: removePeople(const Person& person){
	for(unsigned int i = 0; i < this->people.size(); i++){
		if(people[i] == person){
			people.erase(people.begin() + i);
		}
	}
}
bool BusinessTask :: operator == (Task& other){
   if(this->getType() != other.getType()){
    return false;
   }
   else{

        BusinessTask * temp = dynamic_cast<BusinessTask*>(&other);
        return (this->getType() == temp->getType() && strcmp(this->location, temp->getLocation()) == 0 && strcmp(this->host, temp->getHost()) == 0 && peopleEq(this->people, temp->people));

   }

}
bool BusinessTask :: operator != (Task& other){
   if(this->getType() != other.getType()){
    return true;
   }
   else{

        BusinessTask * temp = dynamic_cast<BusinessTask*>(&other);
        if (this->getType() == temp->getType() && strcmp(this->location, temp->getLocation()) == 0 && strcmp(this->host, temp->getHost()) == 0 && peopleEq(this->people, temp->people)){
            return false;
        }
        else{
            return true;
        }

   }

}

