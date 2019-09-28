#pragma once
#include "Day.h"
#include <cassert>


enum monthname{
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December

};

class Month
{
    public:
        Month();
        Month& operator = (const Month& other);
        void setDays(int n);
        int getNumdays()const;
        void setMonthName(monthname m);
        monthname getMname()const;
        vector<Day> getDays()const;
        void addTaskForDay(int n, Task* t);
        void removeTaskForDay(int n, const Task* t);
        void printM()const;


    private:
        monthname mname;
        int numdays;
        vector<Day> days;
        void copy(const Month& other);



};

