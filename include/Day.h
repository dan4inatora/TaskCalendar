#pragma once
#include "Task.h"
#include "BusinessTask.h"
#include "SchoolTask.h"
#include "Leisure.h"
#include <cassert>
#include <vector>

enum weekday{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday

};
class Day
{
    private:
        vector<Task*> tasks;
        int date;
        void copy(const Day& other);
        void erase();

    public:
        Day();
        Day(const Day& other);
        Day& operator = (const Day& other);
        ~Day();
        Task* getTaskbyName(const char * name);
        vector<Task*> getTasks()const;
        void addTask(Task* t);
        void removeTask(const Task* t);
        void setDate(int d);
        int getDate()const;
        void printD()const;
        bool operator == (const Day& other);
};


