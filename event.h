#pragma once
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
using namespace std;


struct Date {
	int d, m, y;
};


struct Time {
	int h, m;
};

const int monthDays[12]= { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };

static vector<Date> dateVector;
class event
{
public:
	
	Date sd,ed;
	
	Time st, rt;
	
	int eventId;
	string name, place, done;

	event(void);

	
	static bool compare(Date, Date);
	void sortDate();
	void display();
	
	string	remainingTime(Date,Time,Time);
	void addEvent(vector<event>);
	void updateEvent(event);
	void DoneEvents(vector<event>, vector<event>);
	void deleteDateV(vector<event>);
};

