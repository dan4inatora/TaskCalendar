#pragma once
#include "Diapason.h"

class Task{
	private:
		static int counter;
		char * name;
		char * desc;
		Diapason diapason;
		void copy(const Task& other);
		void erase();

	public:
		Task();
		Task(const Task& other);
		Task& operator = (const Task& other);
		virtual ~Task();
		void setName(const char* _name);
    	void setDescription(const char* _description);
    	void setDiapason(const Diapason d);
		char* getName()const;
    	char* getDescription()const;
    	Diapason getDiapason()const;
    	virtual int getType()const;
    	virtual void print()const = 0;
    	static int getCount(){
    		return counter;
		}
        virtual bool operator == (Task& other) = 0;
        virtual bool operator != (Task& other) = 0;


};
