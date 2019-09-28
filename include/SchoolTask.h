#pragma once
#include "Task.h"
using namespace std;

class SchoolTask : public Task
{

    private:
        char * subject_name;
        char * mats_read;
        void copy(const SchoolTask& other);
        void erase();
    public:
        SchoolTask();
        SchoolTask(const SchoolTask& other);
        SchoolTask& operator = (const SchoolTask& other);
        ~SchoolTask();
        int getType()const;
        void setSName(const char * n);
        void setMath(const char * m);
        char * getSName()const;
        char * getMath()const;
        void print()const;
        bool operator == (Task& other);
        bool operator != (Task& other);

};


