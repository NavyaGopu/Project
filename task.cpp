#include "stdafx.h"
#include "task.h"
//#include "Meeting.h"
#include "DateTime.h"
#include <iostream>
#include <string>

using namespace std;

//***************************************************************
//    	function to insert record into the file
//****************************************************************

void task::getdata(int projnumb,char* aa)
{
	projnumber = projnumb;
//	string location;
//	string attendees;
	if(_strcmpi(aa,"Y")==0){
		cout << "\n\t Project number: " << projnumber;
		cout << "\n\t Enter task number: ";
		cin >> taskno;
		cout << "\n\t Enter name of the task: ";
		cin.ignore();
		cin.getline(taskname, sizeof(taskname));
		cout << "\n\t Enter the task description: ";
		cin.getline(taskdesc, sizeof(taskdesc));
		cout << "\n\t Enter the start DateTime (DD/MM/YYYY HH:MM): ";
		cin.getline(start_datetime, sizeof(start_datetime));
		cout << "\n\t Enter the start DateTime (DD/MM/YYYY HH:MM): ";
		cin.getline(end_datetime, sizeof(end_datetime));

	}
	else {
		cout << "\n\t No records created for project " << projnumber;
	}

}

//***************************************************************
//    	function to display all records on screen
//****************************************************************

void task::showdata()
{
	cout << "==============================================================================\n";
	cout << "    " << taskno << "- Task name: " << taskname << endl;
	cout << "------------------------------------------------------------------------------\n";
	cout << "    Task description: " << taskdesc << endl;
	cout << "	 Start date: " << start_datetime << endl;
	cout << "	 End date: " << end_datetime << endl;
}

//***************************************************************
//    	function to display project number
//****************************************************************

int task::rettaskno()
{
	return taskno;
}

int task::retprojno()
{
	return projnumber;
}


//***************************************************************
//    	function to display date and time on screen
//****************************************************************

int task::getdatetime()
{
	return(0);
}
