#include "Task.h"


void Task :: copy(const Task& other){
			this->name = new char[strlen(other.name) + 1];
			strcpy(this->name, other.name);
			this->desc = new char[strlen(other.desc) + 1];
			strcpy(this->desc, other.desc);

}
void Task :: erase(){
			delete[]this->name;
			delete[]this->desc;
}
Task :: Task(){
	this->name = new char[strlen("None") + 1];
	strcpy(this->name, "None");
	this->desc = new char[strlen("None") + 1];
	strcpy(this->desc, "None");
	counter++;
}
Task :: Task(const Task& other){
	this->copy(other);
	counter++;
}
Task& Task :: operator = (const Task& other){
	if(this != &other){
		this->erase();
		this->copy(other);
	}
	return *this;
}

Task :: ~Task(){
	this->erase();
}

void Task :: setName(const char* _name){
	this->name = new char[strlen(_name) + 1];
	strcpy(this->name, _name);
}

void Task :: setDescription(const char* _description){
	this->desc = new char[strlen(_description) + 1];
	strcpy(this->desc, _description);
}

void Task :: setDiapason(const Diapason d){
	this->diapason = d;
}


char* Task :: getName()const{
	return this->name;
}

char* Task :: getDescription()const{
	return this->desc;
}

Diapason Task :: getDiapason()const{
	return this->diapason;
}

int Task :: getType()const{
	return 0;
}

void Task :: print()const{
	cout<<"Task name: "<< this->name<<endl;
	cout<<"Task description: "<<this->desc<<endl;
	cout<<"Task type: ";
	if(this->getType() == 1){
        cout<<"BusinessTask"<<endl;
	}
	else if(this->getType() == 2){
        cout<<"Schooltask"<<endl;
	}
	else if(this->getType() == 3){
        cout<<"Leisure"<<endl;
	}
	this->diapason.print();
	cout<<endl;
}
