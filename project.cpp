#include "stdafx.h"
#include "project.h"
#include <iostream>
#include "DateTime.h"
#include <string>

using namespace std;

//***************************************************************
//    	function to insert record into the file
//****************************************************************

void project::getdata() 
{
	cout << "\n\t Enter project number: ";
	cin >> projno;
	cout << "\n\t Enter name of the project: ";
	cin.ignore();
	cin.getline(projname, sizeof(projname));
	cout << "\n\t Enter the project description: ";
	cin.getline(projdesc, sizeof(projdesc));
	cout << "\n\t Enter the start DateTime (DD/MM/YYYY HH:MM): ";
	cin.getline(start_datetime, sizeof(start_datetime));
	cout << "\n\t Enter the start DateTime (DD/MM/YYYY HH:MM): ";
	cin.getline(end_datetime, sizeof(end_datetime));
}		

//***************************************************************
//    	function to display all records on screen
//****************************************************************

void project::showdata()
{
	cout << "==============================================================================\n";
	cout << projno << "- Project name: " << projname << endl;
	cout << "------------------------------------------------------------------------------\n";
	cout << "Project description: " << projdesc << endl;
	cout << "Start date: " << start_datetime << endl;
	cout << "End date: " << end_datetime << endl;
}

//***************************************************************
//    	function to display project number
//****************************************************************

int project::retprojno()
{
	return projno;
}

//***************************************************************
//    	function to display date and time on screen
//****************************************************************

int project::getdatetime()
{
	return(0);
}
