#include "stdafx.h"
#include "Meeting.h"
#include <iostream>
#include <string>

using namespace std;

//***************************************************************
//    	function to insert record into the file
//****************************************************************

void Meeting::getdata(int projnumb, int tasknum)
{
	projnumber = projnumb;
	tasknumber = tasknum;
		cout << "\n\t Enter Meeting number: ";
		cin >> meetingno;
		cin.ignore();
		cout << "\n\t Enter the start DateTime (DD/MM/YYYY HH:MM): ";
		cin.getline(start_datetime, sizeof(start_datetime));
		cout << "\n\t Enter the end DateTime (DD/MM/YYYY HH:MM): ";
		cin.getline(end_datetime, sizeof(end_datetime));
		cout << "\n\t Enter the location: ";
		cin.getline(location, sizeof(location));
		cout << "\n\t Enter the attendees: ";
		cin.getline(attendees, sizeof(attendees));
}

//***************************************************************
//    	function to display all records on screen
//****************************************************************

void Meeting::showdata()
{
	cout << "	 Time Allocations: " << endl;
	cout << "	 " << start_datetime << " - " << end_datetime << " : " << location << " - " << attendees << endl;
}

//***************************************************************
//    	function to display project number
//****************************************************************

int Meeting::rettaskno()
{
	return tasknumber;
}

int Meeting::retmeetingno()
{
	return meetingno;
}

int Meeting::retprojno()
{
	return projnumber;
}

