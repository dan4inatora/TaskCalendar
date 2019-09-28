#pragma once
#include<iostream>
#include<cstring>
#include <cassert>
#include <math.h>

using namespace std;

class Time{
	private:
		int hours;
		int minutes;
		int seconds;
	public:
		Time();
		Time(int h, int m, int s);
		void setHours(int h);
		void setMins(int m);
		void setSecs(int s);
		int getHours()const;
		int getMins()const;
		int getSecs()const;
		void print()const;
		Time& operator-(const Time& other);
		Time& operator=(const Time& other);
};
