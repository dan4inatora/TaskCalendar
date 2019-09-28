#include "Time.h"

Time :: Time(){
	this->hours = 0;
	this->seconds = 0;
	this->minutes = 0;
}

Time :: Time(int h, int m, int s){
    assert(h >= 0 && h < 24);
    assert(m >= 0 && m < 60);
    assert(s >= 0 && s < 60);
    this->hours = h;
    this->minutes = m;
    this->seconds = s;

}

void Time::setHours(int h)
{
    assert(h >= 0 && h < 24);
    this->hours = h;
}

void Time::setMins(int m)
{
    assert(m >= 0 && m < 60);
    this->minutes = m;
}

void Time::setSecs(int s)
{
    assert(s >= 0 && s < 60);
    this->seconds = s;
}

int Time::getHours()const{return this->hours;}

int Time::getMins()const{return this->minutes;}

int Time::getSecs()const{return this->seconds;}

void Time::print()const
{
    if(this->hours <= 9)
        cout << "0" << this ->hours << ":";
    else
        cout << this->hours << ":";
    if(this->minutes <= 9)
        cout << "0" << this->minutes << ":";
    else
        cout << this->minutes << ":";
    if(this->seconds <= 9)
        cout << "0" << this->seconds;
    else
        cout << this->seconds;
}

Time& Time::operator-(const Time& other)
{
    Time * t = new Time();
    if((this->seconds - other.seconds) >= 0){
        t->setSecs(this->seconds - other.seconds);
        if((this->minutes - other.minutes) >= 0){

            t->setMins(this->minutes - other.minutes);

            if((this->hours - other.hours) >=0){
                t->setHours(this->hours - other.hours);
            }
            else{
                t->setHours(24 - abs(this->hours - other.hours));
            }
        }
        else{
            t->setMins (60 -abs(this->minutes - other.minutes));
            if((this->hours - other.hours - 1) >= 0){
                t->setHours(this->hours - other.hours - 1);
            }
            else{
               t->setHours(24 - abs(this->hours - other.hours));
            }
        }
    }
    else{
        t->setSecs (60 - abs(this->seconds - other.seconds));
        if((this->minutes - other.minutes - 1) >= 0){
            t->setMins(this->minutes - other.minutes - 1);

            if((this->hours - other.hours) >=0){
                t->setHours(this->hours - other.hours);
            }
            else{
                t->setHours(24 - abs(this->hours - other.hours));
            }

        }
        else{
            t->setMins(60 - abs(this->minutes - other.minutes) - 1);

            if((this->hours - other.hours - 1) >= 0){
                t->setHours(this->hours - other.hours - 1);
            }
            else{
                t->setHours (24 - abs(this->hours - other.hours)- 1);
            }
        }
    }
    return *t;
}

Time& Time :: operator = (const Time& other){
	this->hours = other.hours;
	this->minutes = other.minutes;
	this->seconds = other.seconds;
	return *this;
}
