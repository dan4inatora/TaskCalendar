#pragma once
#include "Task.h"
#include "Person.h"
#include<vector>

class BusinessTask : public Task{
	private:
		vector<Person> people;
		char * location;
		char * host;
		void copy(const BusinessTask& other);
		void erase();
	public:
		BusinessTask();
		BusinessTask(const BusinessTask& other);
		BusinessTask& operator = (const BusinessTask& other);
		~BusinessTask();
		void addPeople(const Person& person);
		void removePeople(const Person& person);
		void setLocation(const char* location);
		void setHost(const char* host);
		void setPeople(vector<Person> _people);
		char * getLocation()const;
		char * getHost()const;
		int getType()const;
		vector<Person> getPeople()const;
		Time getDuration()const;
		void print()const;
		bool operator == (Task& other);
		bool operator != (Task& other);


};
