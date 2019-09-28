#pragma once
#include "Task.h"


enum leisures{
    family,
    gym,
    park,
    skydiving
};

class Leisure : public Task{

    private:
        leisures typeleisure;
        char * dest;
        void copy(const Leisure& other);
        void erase();
    public:
        Leisure();
       ~Leisure();
        Leisure(const Leisure& other);
        Leisure& operator=(const Leisure& other);
        int getType()const;
        void setLocation(const char * l);
        void setTypeleisure(leisures t);
        leisures getTypeleisure()const;
        char * getLocation()const;
        void print()const;
        void showweather()const;
        bool operator == (Task& other);
        bool operator != (Task& other);




};
