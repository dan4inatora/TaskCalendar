#include "Month.h"
#include <cassert>
class Calendar
{
    public:
        Calendar();
        Calendar(int year);
        Calendar(const Calendar& other);
        Calendar& operator = (const Calendar& other);
        ~Calendar();
        void setYear(int y);
        int getYear()const;
        void setDesc(const char * desc);
        char * getDesc()const;
        void printC()const;
        void printMonth(int month)const;
        void printbyDate(int day, int month)const;
        void addTask(Task* t, int day, int month);
        void removeTask(Task* t, int day, int month);


    protected:

    private:
        char * m_desc;
        int year;
        Month months[12];
        void copy(const Calendar& other);
        void erase();
};

