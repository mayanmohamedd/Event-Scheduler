#include"event.h"
using namespace std;

void main()
{
	vector<event> v,DoneVector;
	event e;
	string fName, name;
	int id=0,choice=0;
	
	while (true)
	{
		cout << "to add event press 1\n" << "to update event press 2\n" << "to delete event press 3\n" <<"to display name of done events press 4\n" <<"to sort events press 5\n" << "to exit press 6\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			e.addEvent(v);
			v.push_back(e);
			
			break;
		}
		case 2:
		{
			cout << "Enter id of event you want to update\n";
			cin >> id;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].eventId == id)
				{
					e = v.at(i);
					e.updateEvent(e);
				}
				else
				{
					cout << "There isn't an event with this ID\n";
				}
			}

			
			
			break;
		}
		case 3:
		{
			// delete 
			cout << "enter the name of the event you want to delete\n";
			cin >> name;
			if (v.size() == 0)
				cout << "There is no data to delete\n";
			else 
			{
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i].name == name)
					{
						fName = name + ".txt";
						v.erase(v.begin() + i);
						remove(fName.c_str());
					}

				}
				e.deleteDateV(v);
				cout << "Event deleted\n";

			}
			
			

			break;
		}
		case 4:
		{
			e.DoneEvents(v, DoneVector);
			for (int i = 0; i < DoneVector.size(); i++)
			{
				cout << DoneVector[i].name << endl;
			}
			break;
		}

		case 5:
		{
			
			e.sortDate();
			e.display(
			);
			
			break;
		}
		case 6:
		{
			exit(0);
		}
		
		default:
			break;
		}
		
		

	}

}