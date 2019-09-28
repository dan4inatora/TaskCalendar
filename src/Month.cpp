#include "Month.h"

void Month::copy(const Month& other)
{
    this->mname = other.mname;
    this->numdays = other.numdays;
    for(unsigned int i = 0; i < other.days.size(); i++)
    {
        this->days.push_back(other.days[i]);
    }
}

Month::Month()
{
    this->mname = January;
    this->numdays = 0;
}


Month& Month::operator=(const Month& other)
{
    if(this != &other)
    {

        this->copy(other);
    }
    return *this;
}

void Month::setMonthName(monthname m)
{
    this->mname = m;
}

void Month::setDays(int n)
{
    assert(n >=1 && n <= 31);
    this->numdays = n;
    for(int i = 0; i < this->numdays; i++)
    {
        Day *d = new Day();
        d->setDate(i + 1);
        days.push_back(*d);
    }
}

int Month::getNumdays()const{return this->numdays;}

monthname Month::getMname()const{return this->mname;}

vector<Day> Month::getDays()const
{
    vector<Day> day;
    for(unsigned int i = 0; i < this->days.size(); i++){
        day.push_back(this->days[i]);
    }
    return day;
}

void Month::printM()const
{

    switch(this->mname){
    case January:
        {
            cout<<"January"<<endl;
            break;
        }
    case February:
        {
            cout<<"February"<<endl;
            break;
        }
    case March:
        {
            cout<<"March"<<endl;
            break;
        }
    case April:
        {
            cout<<"April"<<endl;
            break;
        }
    case May:
        {
            cout<<"May"<<endl;
            break;
        }
    case June:
        {
            cout<<"June"<<endl;
            break;
        }
    case July:
        {
            cout<<"July"<<endl;
            break;
        }
    case August:
        {
            cout<<"August"<<endl;
            break;
        }
    case September:
        {
            cout<<"September"<<endl;
            break;
        }
    case October:
        {
            cout<<"October"<<endl;
            break;
        }
    case November:
        {
            cout<<"November"<<endl;
            break;
        }
    case December:
        {
            cout<<"December"<<endl;
            break;
        }
    }
    cout << "Mon   Tue   Wed   Thu   Fri   Sat   Sun" << endl;
    for(int i = 0; i < this->numdays; i++)
    {
        if(i < 9)
            cout << "0" << i + 1 <<"    ";
        else
            cout << i + 1 << "    ";
        if(i == 6 || i == 13 || i == 20 || i == 27)
            cout << endl;
    }
    cout << endl;
    cout << endl;
    for(unsigned int i = 0; i < this->days.size(); i++)
    {
        vector<Task*> tmp = this->days[i].getTasks();
        if(!tmp.empty())
        {
            if(i <= 9)
            cout << "Tasks for 0" << i + 1 << "." << this->mname + 1 << ": " << endl;

        else
            cout << "Tasks for " << i + 1 << "." << this->mname + 1<< ": " << endl;
        }
        this->days[i].printD();

    }
}

void Month::addTaskForDay(int n, Task* t)
{
    for(unsigned int i = 0; i < this->days.size(); i++)
    {
        if(this->days[i].getDate() == n)
            this->days[i].addTask(t);
    }
}

void Month::removeTaskForDay(int n, const Task* t)
{
      for(unsigned int i = 0; i < this->days.size(); i++){
        if(this->days[i].getDate() == n){
            this->days[i].removeTask(t);
        }
    }
}
