#include "Day.h"

bool areEqual(vector<Task*> d, vector<Task*> d2){
    bool flag = true;
    if(d.size() != d2.size()){
        flag = false;
    }
    for(unsigned int i = 0; i < d.size(); i++){
        if(d[i] != d2[i]){
            flag = false;
        }
    }
    return flag;
}

void Day :: copy(const Day& other){
    this->date = other.date;

    for(unsigned int i = 0; i < this->tasks.size(); i++){
        this->tasks.pop_back();
    }
    for(unsigned int i = 0; i < other.tasks.size(); i++){
        this->tasks.push_back(other.tasks[i]);
    }
}

void Day :: erase(){
    for(unsigned int i = 0; i < this->tasks.size(); i++){
        this->tasks.pop_back();
    }
}
Day :: Day(){
    this->date = 0;

}


Day :: Day(const Day& other){
    this->copy(other);
}

Day& Day :: operator = (const Day& other){
    if (this != &other){
        this->erase();
        this->copy(other);
    }
    return *this;
}
Day :: ~Day(){
    for(unsigned int i = 0; i < this->tasks.size(); i++){
        this->tasks.pop_back();
    }
}
 Task* Day :: getTaskbyName(const char * name){
    Task * res;
    for(unsigned int i = 0; i < this->tasks.size(); i++){
        if(strcmp(this->tasks[i]->getName(), name) == 0){
            res = tasks[i];
        }
    }
    return res;
 }

 void Day :: addTask(Task* t){
    this->tasks.push_back(t);
 }

 void Day :: removeTask(const Task* t){
    for(unsigned int i = 0; i < this->tasks.size(); i++){
        if(this->tasks[i] == t){
            tasks.erase(tasks.begin() + i);
        }
    }
 }

 void Day :: setDate(int d){
    assert(d >= 1 && d <= 31);
    this->date = d;
 }


int Day :: getDate()const{
    return this->date;
}

void Day :: printD()const{

    for(unsigned int i = 0; i < this->tasks.size(); i++){
        this->tasks[i]->print();

    }


}
vector<Task*> Day :: getTasks()const{
    return this->tasks;
}

bool Day :: operator == (const Day& other){
    return (this->date == other.date  && areEqual(this->tasks, other.tasks));
}

