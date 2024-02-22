#include "event.h"


event::event(void) {
	eventId = 0;
	place, name = " ";
	done = "no";
	
}

bool event::compare(Date date1, Date date2)
{
	if (date1.y < date2.y)
		return true;
	else if (date1.y == date2.y && date1.m < date2.m)
		return true;
	else if (date1.y == date2.y && date1.m == date2.m && date1.d < date2.d)
		return true;
	else
		return false;
}

void event::sortDate()
{
	sort(dateVector.begin(), dateVector.end(), compare);
}

void event::display()
{
	
	for (int i = 0; i <dateVector.size();i++)
	{
		
		cout << dateVector[i].d << " " << dateVector[i].m << " " << dateVector[i].y << endl;
			
	}
	
}



time_t t = time(NULL);
tm* timePtr = localtime(&t);


Date currentDate() {
	Date cd;
	
	cd.d = timePtr->tm_mday;

	cd.m = 0;
	if (timePtr->tm_mon == 12) {
		cd.m = 1;
	}
	cd.m = (timePtr->tm_mon) + 1;
	
	cd.y = timePtr->tm_year;
	cd.y += 1900;
	return cd;
}


string event::remainingTime(Date sd, Time st, Time rt)
{

	int remindingHours = 0;
	int remindingMinutes = 0;
	int remainingDays = 0;
	Date cd;

	cd = currentDate();

	
	/*const int monthDays[12]
		= { 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31 };*/


	long int n1 = cd.y * 365 + cd.d;
	for (int i = 0; i < cd.m - 1; i++)
		n1 += monthDays[i];



	long int n2 = sd.y * 365 + sd.d;
	for (int i = 0; i < sd.m - 1; i++)
		n2 += monthDays[i];


	remainingDays = n2 - n1;
	if (remainingDays <= 0)
	{
		done = "yes";

	}

	remindingHours = st.h - rt.h;
	remindingMinutes = st.m - rt.m;

	cout << "The remaining time for the event is: \n" << remainingDays << " days, " << remindingHours << " hours" << " and " << remindingMinutes << " minutes \n";
	return done;

}

void event::addEvent(vector<event>v) {

	int day, month, year;
	fstream file;
	string fileName;

	eventId++;
	
	cout << "Enter the event's name: \n";
	cin>>name;
	
	cout << "Enter the event's place: \n";
	cin >> place;

	cout << "Enter the event's start date (day,month,year): \n";
	cin >> day >> month >> year;
	
	for (int i = 0; i < v.size(); i++)
	{
		while (v[i].sd.d == day && v[i].sd.m == month && v[i].sd.y == year)
		{
			cout << "Invalid date.\n";
			cout << "Enter the event's start date (day,month,year): \n";
			cin >> day >> month >> year;

		}
		
	}

	sd.d = day;
	sd.m = month;
	sd.y = year;
	dateVector.push_back(sd);
	sortDate();

	cout << "Enter the event's end date (day,month,year): \n";
	cin >> ed.d >> ed.m >> ed.y;


	cout << "Enter the event's start time (hours,minutes): \n";
	cin >> st.h >> st.m;

	cout << "Enter the time you want us to remind you with on this day (hours,minutes): \n";
	cin >> rt.h >> rt.m;

	fileName = name + ".txt";
	file.open(fileName, ios::out);
	if (file.is_open())
	{
		file << name << endl;
		file << place << endl;
		file << "Start date is: " << sd.d << " " << sd.m << " " << sd.y << endl;
		file << "End date is: " << ed.d << " " << " " << ed.m << " " << ed.y << endl;
		file << "Event's start time is: " << st.h << ":" << st.m << endl;
		file << "Your Event Id is: " << eventId << endl;
		file.close();
	}

	done = remainingTime(sd,st,rt);
	cout << "Your event ID is: " << eventId << endl<<endl;
	
}

void event::updateEvent(event e)
{
	
	fstream file;
	string fName = e.name + ".txt";
	string newfname;
	int choice;
	cout << "To change name press 1\n To change place press 2\n To change Start date press 3\n To change End date press 4\n To change start time press 5\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		remove(fName.c_str());

		string newName;
		cin >> newName;
		e.name = newName;

		break;
	}
	case 2:
	{
		string newPlace;
		cin >> newPlace;
		e.place = newPlace;
		break;
	}
	case 3:
	{
		Date newSD;
		cin >> newSD.d >> newSD.m >> newSD.y;
		
		for (int i = 0; i < dateVector.size(); i++)
		{
			if (dateVector[i].d == e.sd.d && dateVector[i].m == e.sd.m && dateVector[i].y == e.sd.y)
			{
				dateVector[i].d = newSD.d;
				dateVector[i].m = newSD.m;
				dateVector[i].y = newSD.y;
			}
		}
		e.sd.d = newSD.d;
		e.sd.m = newSD.m;
		e.sd.y = newSD.y;

		break;

	}
	case 4:
	{
		Date newED;
		cin >> newED.d >> newED.m >> newED.y;
		e.ed.d = newED.d;
		e.ed.m = newED.m;
		e.ed.y = newED.y;
		break;
	}
	case 5:
	{
		Time newST;
		cin >> newST.h >> newST.m;
		e.st.h = newST.h;
		e.st.m = newST.m;
		break;
	}

	}
	newfname = e.name + ".txt";
	file.open(newfname, ios::out | ios::trunc);
	if (file.is_open())
	{
		file << e.name << endl;
		file << e.place << endl;
		file << "Start date is: " << e.sd.d << " " << e.sd.m << " " << e.sd.y << endl;
		file << "End date is: " << e.ed.d << " " << " " << e.ed.m << " " << e.ed.y << endl;
		file << "Event's start time is: " << e.st.h << ":" << e.st.m << endl;
		file << "Your Event Id is: " << e.eventId << endl;
		file.close();
	}

}

void event::DoneEvents(vector<event> v, vector<event> dv)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].done == "yes")
		{
			dv.push_back(v[i]);
			v.erase(v.begin() + i);
		}
	}
	for (int i = 0; i < dv.size(); i++)
	{
		cout << dv[i].name << endl;

	}
}

void event::deleteDateV(vector<event> v)
{
	dateVector.clear();
	for (int i = 0; i < v.size(); i++)
	{
		dateVector.push_back(v[i].sd);
	}
}





