#include "Diapason.h"


void checkData(const Time& s, const Time& e){

    bool flag = true;
    if(s.getHours() > e.getHours()){
        flag = false;
    }
    else if(s.getHours() == e.getHours()){
        if(s.getMins() > e.getMins()){
            flag = false;
        }
    }
    assert(flag);
}
Diapason::Diapason()
{
    this->start.setHours(0);
    this->start.setMins(0);
    this->start.setSecs(0);
    this->end.setHours(0);
    this->end.setMins(0);
    this->end.setSecs(0);
}

Diapason::Diapason(Time s, Time e)
{
    checkData(s,e);
    this->start = s;
    this->end = e;
}

void Diapason::setStart(Time s){this->start = s;}

void Diapason::setEnd(Time e){this->end = e;}

Time Diapason::getStart()const{return this->start;}

Time Diapason::getEnd()const{return this->end;}

Time Diapason::getPeriod()const
{

    Time s = this->start;
    Time e = this->end;

    checkData(s,e);
    return (e - s);
}

void Diapason::print()const
{
    this->start.print();
    cout << " - ";
    this->end.print();
}
