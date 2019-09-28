#include "Calendar.h"

void Calendar::copy(const Calendar& other)
{

    this->m_desc = new char[strlen(other.m_desc) + 1];
    strcpy(this->m_desc, other.m_desc);
    this->year = other.year;
    for(int i = 0; i < 12; i++)
    {
        this->months[i] = other.months[i];
    }
}

void Calendar::erase()
{
    delete[] this->m_desc;
}

Calendar::Calendar()
{
    this->m_desc = new char[0];
    strcpy(this->m_desc, "");
    this->year = 0;
}


Calendar::Calendar(int _year)
{
    this->setYear(_year);
    this->months[0].setMonthName(January);
    this->months[1].setMonthName(February);
    this->months[2].setMonthName(March);
    this->months[3].setMonthName(April);
    this->months[4].setMonthName(May);
    this->months[5].setMonthName(June);
    this->months[6].setMonthName(July);
    this->months[7].setMonthName(August);
    this->months[8].setMonthName(September);
    this->months[9].setMonthName(October);
    this->months[10].setMonthName(November);
    this->months[11].setMonthName(December);
    for(int i = 0; i < 12; i++)
    {
        switch(i)
        {
        case 3: case 5: case 8: case 10:
                this->months[i].setDays(30);
                break;
        case 1:
                {
                    if(this->year % 4 == 0)
                    {
                        if(this->year % 100 == 0)
                        {
                            if(this->year % 400 == 0)
                                this->months[i].setDays(29);
                            this->months[i].setDays(28);
                        }
                        this->months[i].setDays(29);
                    }
                    this->months[i].setDays(28);
                }
                break;
        default:
                this->months[i].setDays(31);
                break;
        }
    }
    this->m_desc = new char[0];
    strcpy(this->m_desc, "");
}

Calendar::Calendar(const Calendar& other){this->copy(other);}

Calendar& Calendar::operator=(const Calendar& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Calendar::~Calendar(){this->erase();}

void Calendar::setYear(int _year){this->year = _year;}

void Calendar::setDesc(const char * desc)
{
    this->m_desc = new char[strlen(desc) + 1];
    strcpy(this->m_desc, desc);
}

int Calendar::getYear()const{return this->year;}

char* Calendar::getDesc()const{return this->m_desc;}

void Calendar::printC()const
{

    cout << "Year: " << this->year << endl;
    cout << "Description: " << this->m_desc << endl;
    for(int i = 0; i < 12; i++)
    {

        this->months[i].printM();
    }
}

void Calendar::printbyDate(int day, int month)const
{
    vector<Day> tmp = this->months[month - 1].getDays();
    tmp[day - 1].printD();
}


void Calendar::addTask(Task* t, int day, int month)
{
    this->months[month - 1].addTaskForDay(day, t);
}

void Calendar::removeTask(Task* t, int day, int month)
{
        this->months[month - 1].removeTaskForDay(day, t);

}

void Calendar:: printMonth(int month)const{
    if(month < 1 || month > 12){
        cout<<"enter valid month";
    }
    else{
        this->months[month - 1].printM();
    }

}
