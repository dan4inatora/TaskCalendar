#include "Time.h"
#include "Diapason.h"
#include "Task.h"
#include "Person.h"
#include "BusinessTask.h"
#include "Leisure.h"
#include "SchoolTask.h"
#include "Day.h"
#include "Month.h"
#include "Calendar.h"
int Task :: counter = 0;
using namespace std;

int main()
{
   /* Time t;
    t.print();
    cout<<endl;
    Time t2(2,31,3);
    t2.print();
    cout<<endl;
    t.setHours(5);
    t.setMins(44);
    t.setSecs(12);
    t.print();
    cout<<endl;
    Time t3 = t - t2;
    t3.print();
    cout<<endl;
    Diapason d(t2,t);
    d.print();
    cout<<endl;
    d.getPeriod().print();
    cout<<endl;
    cout<<endl;
    BusinessTask bus;
    bus.print();
    cout<<endl;
    Person p;
    bus.addPeople(p);
    Person p2;
    p2.setFstName("kolio");
    p2.setLastName("seducer");
    bus.addPeople(p2);
    bus.setDiapason(d);
    bus.removePeople(p2);
    bus.print();
    cout<<endl;

    BusinessTask b3 = bus;

    if(b3 == bus){
        cout<<"YASSS";
    }
    else{
        cout<<"NOOOO";
    }
    cout<<endl;
    Leisure l;
    l.print();
    l.setLocation("nOWHERE");

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    Day one;
    one.addTask(&l);
    one.addTask(&b3);
    one.printD();

    Day two = one;
    cout<<endl;
    if(two == one){
        cout<<"YaaaassSSS";
    }
    else{
        cout<<"NEUNNN";
    }

        cout<<endl;
    cout<<endl;
    vector<Task*> ta = two.getTasks();
    for(unsigned int i = 0; i < ta.size(); i++){
      ta[i]->print();
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    Leisure l;
    BusinessTask bus;
    Month m;
    m.setDays(22);
    m.addTaskForDay(2,&l);
    m.removeTaskForDay(2,&l);
    m.addTaskForDay(2,&bus);
    m.printM();
*/
    Calendar c(2018);
    Leisure l;
    BusinessTask b;
    c.addTask(&b, 3, 11);
    c.addTask(&l, 6, 10);
    c.addTask(&l, 6, 12);
    c.printC();

//можеше да пробвам да направя месеците да не почват от първи

    return 0;


}
