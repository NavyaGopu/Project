#include "stdafx.h"
#include "WorkDone.h"
#include <iostream>
#include <string>

using namespace std;

//***************************************************************
//    	function to insert record into the file
//****************************************************************

void WorkDone::getdata(int projnumb, int tasknum)
{
	projnumber = projnumb;
	tasknumber = tasknum;
	cout << "\n\t Enter Work number: ";
	cin >> workno;
	cin.ignore();
	cout << "\n\t Enter the start DateTime (DD/MM/YYYY HH:MM): ";
	cin.getline(start_datetime, sizeof(start_datetime));
	cout << "\n\t Enter the end DateTime (DD/MM/YYYY HH:MM): ";
	cin.getline(end_datetime, sizeof(end_datetime));
	cout << "\n\t Enter the work done: ";
	cin.getline(work, sizeof(work));
	cout << "\n\t Enter the work description: ";
	cin.getline(workdesc, sizeof(workdesc));
}

//***************************************************************
//    	function to display all records on screen
//****************************************************************

void WorkDone::showdata()
{
	cout << "	 " << start_datetime << " - " << end_datetime << " : " << work << " - " << workdesc << endl;
}

//***************************************************************
//    	function to display project number
//****************************************************************

int WorkDone::rettaskno()
{
	return tasknumber;
}

int WorkDone::retworkno()
{
	return workno;
}

int WorkDone::retprojno()
{
	return projnumber;
}

