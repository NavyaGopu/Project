#include "stdafx.h"
#include "BugFix.h"
#include <iostream>
#include <string>

using namespace std;

//***************************************************************
//    	function to insert record into the file
//****************************************************************

void BugFix::getdata(int projnumb, int tasknum)
{
	projnumber = projnumb;
	tasknumber = tasknum;
	cout << "\n\t Enter Bug number: ";
	cin >> bugno;
	cin.ignore();
	cout << "\n\t Enter the start DateTime (DD/MM/YYYY HH:MM): ";
	cin.getline(start_datetime, sizeof(start_datetime));
	cout << "\n\t Enter the end DateTime (DD/MM/YYYY HH:MM): ";
	cin.getline(end_datetime, sizeof(end_datetime));
	cout << "\n\t Enter the bug description: ";
	cin.getline(bugdesc, sizeof(bugdesc));
}

//***************************************************************
//    	function to display all records on screen
//****************************************************************

void BugFix::showdata()
{
	cout << "	 " << start_datetime << " - " << end_datetime << " : " << "Bug: " << bugno << " - " << bugdesc << endl;
}

//***************************************************************
//    	function to display project number
//****************************************************************

int BugFix::rettaskno()
{
	return tasknumber;
}
int BugFix::retbugno()
{
	return bugno;
}
int BugFix::retprojno()
{
	return projnumber;
}

