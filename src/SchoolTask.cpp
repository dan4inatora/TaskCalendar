#include "SchoolTask.h"


void SchoolTask :: copy(const SchoolTask& other){
    this->subject_name = new char[strlen(other.subject_name) + 1];
    this->mats_read = new char[strlen(other.mats_read) + 1];
    strcpy(this->subject_name, other.subject_name);
    strcpy(this->mats_read, other.mats_read);
}

void SchoolTask :: erase(){
    delete[]this->subject_name;
    delete[]this->mats_read;
}
SchoolTask::SchoolTask() : Task()
{
    this->subject_name = new char[strlen("None") + 1];
    this->mats_read = new char[strlen("None") + 1];
    strcpy(this->subject_name, "None");
    strcpy(this->mats_read, "None");
}
SchoolTask :: SchoolTask(const SchoolTask& other) : Task(other){
    this->copy(other);
}
SchoolTask& SchoolTask :: operator = (const SchoolTask& other){

    if(this != &other){
        Task ::operator=(other);
        this->erase();
        this->copy(other);
    }
    return *this;
}
SchoolTask::~SchoolTask()
{
    this->erase();
}
int SchoolTask :: getType()const{
    return 2;
}

void SchoolTask ::setSName(const char * n){

    this->subject_name = new char[strlen(n) + 1];
    strcpy(this->subject_name, n);
}

void SchoolTask :: setMath(const char * m){

    this->mats_read = new char[strlen(m) + 1];
    strcpy(this->mats_read, m);
}

char * SchoolTask :: getSName()const{
    return this->subject_name;
}

char * SchoolTask :: getMath()const{
    return this->mats_read;
}

void SchoolTask ::print()const{
    Task ::print();
    cout<<this->subject_name<<endl;
    cout<<this->mats_read<<endl;
    cout<<endl;
}
bool SchoolTask :: operator == (Task& other){
    if(this->getType() != other.getType()){
        return false;
    }
    else{

        SchoolTask * temp = dynamic_cast<SchoolTask*>(&other);
        return(this->getType() == temp->getType() && strcmp(this->subject_name, temp->getSName()) == 0 && strcmp(this->mats_read, temp->getMath()) == 0);

    }
}

bool SchoolTask :: operator != (Task& other){
    if(this->getType() != other.getType()){
        return true;
    }
    else{

        SchoolTask * temp = dynamic_cast<SchoolTask*>(&other);
        if(this->getType() == temp->getType() && strcmp(this->subject_name, temp->getSName()) == 0 && strcmp(this->mats_read, temp->getMath()) == 0){
            return false;
        }
        else{
            return true;
        }

    }
}



