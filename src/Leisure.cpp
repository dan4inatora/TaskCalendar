#include "Leisure.h"

void Leisure :: copy(const Leisure& other){
    this->dest = new char[strlen(other.dest) + 1];
    strcpy(this->dest, other.dest);
    this->typeleisure = other.typeleisure;
}

void Leisure :: erase(){
    delete[] this->dest;
}

int Leisure :: getType()const{
    return 3;
}

Leisure::Leisure() : Task()
{
    this->dest = new char[strlen("Plovediv") + 1];
    strcpy(this->dest, "Plovediv");
    this->typeleisure = family;
}

Leisure :: Leisure(const Leisure& other) : Task(other){
    this->copy(other);
}
Leisure& Leisure :: operator = (const Leisure& other){
    if(this != &other){

        Task::operator=(other);
        this->erase();
        this->copy(other);
    }
    return *this;
}

Leisure::~Leisure()
{
    this->erase();
}

void Leisure:: setLocation(const char * l){
    this->dest = new char[strlen(l) + 1];
    strcpy(this->dest, l);
}

void Leisure:: setTypeleisure(leisures t){
    this->typeleisure = t;
}

leisures Leisure:: getTypeleisure()const{
    return this->typeleisure;
}

char * Leisure :: getLocation()const{
    return this->dest;
}

void Leisure :: print()const{
    Task::print();
    cout<<"TypeofLeisure: ";
    switch(this->typeleisure){
    case family:
        {
            cout<<"family"<<endl;
            break;
        }
    case gym:
    {
        cout<<"gym"<<endl;
        break;
    }
    case park:
        {
            cout<<"park"<<endl;
            break;
        }
    case skydiving:
        {
            cout<<"skydiving"<<endl;
            break;
        }

    }
    cout<<"Current destination :"<<this->dest<<endl;
    cout<<endl;
}
void Leisure :: showweather()const{

    string fst = "start chrome https://www.sinoptik.bg/search?q={";
    fst += this->dest;
    string snd = "}";
    fst += snd;
    system(fst.c_str());

 }
bool Leisure :: operator == (Task& other){
    if(this->getType() != other.getType()){
        return false;
    }
    else{
        Leisure * temp = dynamic_cast<Leisure*>(&other);
        return(this->getType() == temp->getType() && this->typeleisure == temp->getTypeleisure() && strcmp(this->dest,temp->getLocation()) == 0);
    }

}

bool Leisure :: operator != (Task& other){
    if(this->getType() != other.getType()){
        return true;
    }
    else{
        Leisure * temp = dynamic_cast<Leisure*>(&other);
        if(this->getType() == temp->getType() && this->typeleisure == temp->getTypeleisure() && strcmp(this->dest,temp->getLocation()) == 0){
            return false;
        }
        else{
            return true;
        }
    }

}

