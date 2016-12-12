// ProjectManagement.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include<stdarg.h>
#include<type_traits>
#include"project.h"
#include"task.h"
#include"Meeting.h"
#include"WorkDone.h"
#include"BugFix.h"
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include<process.h>
#include<stdio.h>

using namespace std;

char aa[1];

void intro();		//display welcome screen
void entry_menu();	//display entry menu on screen
void clrscr();		//clear screen

//***************************************************************
//    	function declaration for project
//****************************************************************

void write_project();	//write the record in binary file
void displayAll_proj();	//read all records from binary file
void displayAll();	//read all records from binary file
void display_sp(int);	//accept projno and read record from binary file
void modify_project(int);	//accept projno and update record of binary file
void delete_project(int);	//accept projno and delete selected records from binary file

//***************************************************************
//    	function declaration for task
//****************************************************************

void write_task(int,char*);	//write the record in binary file
//void write_task(int, char*);	//write the record in binary file
void displayAll_task();	//read all records from binary file
void display_st(int);	//accept projno and read record from binary file
void modify_task(int);	//accept projno and update record of binary file
void delete_task(int);	//accept projno and delete selected records from binary file

//***************************************************************
//    	function to write in file
//****************************************************************

void write_project()
{

	project proj;
	ofstream outFile;
	outFile.open("project.dat", ios::binary | ios::app);
	proj.getdata();
	outFile.write((char *)&proj, sizeof(project));
	outFile.close();
	cout << "\t Project record has been created \n";
	cout << "\n\t Create new task?[Y/N]: \n";
	cin >> aa ;
	if (!_strcmpi(aa,"Y")) {
		int projnumb = proj.retprojno();
		write_task(projnumb,aa);
	}
	else {
		cout << "\t task not created. \n";
	}
	cin.ignore();
	entry_menu();
};

void write_task(int projnum,char * aa)
{
	int projnumb = projnum;
	if(!is_empty<int>::value){
		task tk;
		ofstream outFile;
		outFile.open("task.dat", ios::binary | ios::app);
		tk.getdata(projnumb,aa);
		outFile.write((char *)&tk, sizeof(task));
		outFile.close();
		cout << "\t Task record has been created \n";
		int tasknumb = tk.rettaskno();
		Meeting meet;
		outFile.open("meeting.dat", ios::binary | ios::app);
		meet.getdata(projnumb, tasknumb);
		outFile.write((char *)&meet, sizeof(Meeting));
		outFile.close();
		WorkDone work;
		outFile.open("work.dat", ios::binary | ios::app);
		work.getdata(projnumb, tasknumb);
		outFile.write((char *)&work, sizeof(WorkDone));
		outFile.close();
		BugFix bug;
		outFile.open("bug.dat", ios::binary | ios::app);
		bug.getdata(projnumb, tasknumb);
		outFile.write((char *)&bug, sizeof(BugFix));
		outFile.close();
		cin.ignore();
		_getch();
	}
};

//***************************************************************
//    	function to read all records from file
//****************************************************************

void displayAll()
{
	int found = 0;
	project proj;
	task tk;
	Meeting meeting;
	WorkDone work;
	BugFix bug;
	ifstream inFile1;
	ifstream inFile2;
	ifstream inFile3;
	ifstream inFile4;
	ifstream inFile5;
	inFile1.open("project.dat", ios::binary);
	if (!inFile1)
	{
		cout << "File could not be open !! Press any Key...";
		_getch();
		return;
	};

	cout << "\n\n\n\t\t DISPLAY ALL RECORD !!!\n\n";
	while (inFile1.read((char *)&proj, sizeof(project)))
	{
		proj.showdata();
		inFile2.open("task.dat", ios::binary);
		if (!inFile2)
		{
			cout << "File could not be open !! Press any Key...";
			_getch();
			return;
		};
		while (inFile2.read((char *)&tk, sizeof(task)))
		{
			int tasknum = tk.rettaskno();
			int projnum_t = tk.retprojno();
			int projnum_p = proj.retprojno();
			if(tasknum >=0 && projnum_t == projnum_p){
			   tk.showdata();
			   inFile3.open("meeting.dat", ios::binary);
			   if (!inFile3)
			   {
				   cout << "File could not be open !! Press any Key...";
				   _getch();
				   return;
			   };
			   while (inFile3.read((char *)&meeting, sizeof(Meeting)))
			   {
				   int meetingnum = meeting.retmeetingno();
				   int tasknum_m = meeting.rettaskno();
				   int tasknum_t = tk.rettaskno();
				   if (meetingnum >= 0 && tasknum_t == tasknum_m) {
					   meeting.showdata();
				   }
			   }
			   inFile3.close();
//------------------------
			   inFile4.open("work.dat", ios::binary);
			   if (!inFile4)
			   {
				   cout << "File could not be open !! Press any Key...";
				   _getch();
				   return;
			   };
			   while (inFile4.read((char *)&work, sizeof(WorkDone)))
			   {
				   int worknum = work.retworkno();
				   int tasknum_w = work.rettaskno();
				   int tasknum_t = tk.rettaskno();
				   if (worknum >= 0 && tasknum_w == tasknum_t) {
					   work.showdata();
				   }
			   }
			   inFile4.close();
//------------------------
			   inFile5.open("bug.dat", ios::binary);
			   if (!inFile5)
			   {
				   cout << "File could not be open !! Press any Key...";
				   _getch();
				   return;
			   };
			   while (inFile5.read((char *)&bug, sizeof(BugFix)))
			   {
				   int bugnum = bug.retbugno();
				   int bugnum_b = bug.rettaskno();
				   int bugnum_t = tk.rettaskno();
				   if (tasknum >= 0 && bugnum_b == bugnum_t) {
					   bug.showdata();
				   }
			   }
			   inFile5.close();

			}
		}
		inFile2.close();
//		cout << "\n\n====================================\n";
	};
	inFile1.close();
	_getch();
	entry_menu();
};

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	project proj;
	ifstream inFile;
	inFile.open("project.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		_getch();
		return;
	};

	int flag = 0;
	while (inFile.read((char *)&proj, sizeof(project)))
	{
		if (proj.retprojno() == n)
		{
			proj.showdata();
			flag = 1;
		};
	};
	inFile.close();
	if (flag == 0)
		cout << "\n\nrecord not exist";
	_getch();
	entry_menu();
};

void display_st(int n)
{
	task tk;
	ifstream inFile;
	inFile.open("task.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		_getch();
		return;
	};

	int flag = 0;
	while (inFile.read((char *)&tk, sizeof(task)))
	{
		if (tk.rettaskno() == n)
		{
			tk.showdata();
			flag = 1;
		};
	};
	inFile.close();
	if (flag == 0)
		cout << "\n\nrecord not exist";
	_getch();
	entry_menu();
};

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_project(int n)
{
	int found = 0;
	project proj;
	fstream File;
	File.open("project.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		_getch();
		return;
	};
	while (File.read((char *)&proj, sizeof(project)) && found == 0)
	{
		if (proj.retprojno() == n)
		{
			proj.showdata();
			cout << "\n\nPlease enter new details of the project" << endl;
			proj.getdata();
			int pos = sizeof(proj);
			File.seekp(pos, ios::cur);
			File.write((char *)&proj, sizeof(project));
			cout << "\n\n\t Record Updated";
			found = 1;
		};
	};
	File.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
	_getch();
	entry_menu();
};

void modify_task(int n)
{
	int found = 0;
	task tk;
	fstream File;
	File.open("task.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		_getch();
		return;
	};
	while (File.read((char *)&tk, sizeof(task)) && found == 0)
	{
		if (tk.retprojno() == n)
		{
			tk.showdata();
			cout << "\n\nPlease enter new details of the project" << endl;
			int projnumb = n;
			char aa[2] = "Y";
			tk.getdata(projnumb,aa);
			int pos = sizeof(tk);
			File.seekp(pos, ios::cur);
			File.write((char *)&tk, sizeof(task));
			cout << "\n\n\t Record Updated";
			found = 1;
		};
	};
	File.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
	_getch();
	entry_menu();
};

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_project(int n)
{
	project proj;
	ifstream inFile;
	inFile.open("project.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		_getch();
		return;
	};
	ofstream outFile;
	outFile.open("Temp.dat", ios::out);
	inFile.seekg(0, ios::beg);
	while (inFile.read((char *)&proj, sizeof(project)))
	{
		if (proj.retprojno() != n)
		{
			outFile.write((char *)&proj, sizeof(project));
		};
	};
	outFile.close();
	inFile.close();
	remove("project.dat");
	rename("Temp.dat", "project.dat");
	cout << "\n\n\tRecord Deleted ..";
	_getch();
	entry_menu();
};

void delete_task(int n)
{
	task tk;
	ifstream inFile;
	inFile.open("task.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		_getch();
		return;
	};
	ofstream outFile;
	outFile.open("Temp.dat", ios::out);
	inFile.seekg(0, ios::beg);
	while (inFile.read((char *)&tk, sizeof(task)))
	{
		if (tk.rettaskno() != n)
		{
			outFile.write((char *)&tk, sizeof(task));
		};
	};
	outFile.close();
	inFile.close();
	remove("task.dat");
	rename("Temp.dat", "task.dat");
	cout << "\n\n\tRecord Deleted ..";
	_getch();
	entry_menu();
};

//***************************************************************
//    	function to clear screen
//****************************************************************
void clrscr()
{
	std::system("cls");
};

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
	cout << "*****************************************************************************************\n";
	cout << "\t Welcome to Project Management Application!!\n";
	cout << "\t Project Management is the discipline of planning, organizing, and\n";
	cout << "\t managing resources to bring about the successful completion of specific\n";
	cout << "\t project goals and objectives. \n";
	cout << "*****************************************************************************************\n";
	cout << "\t PROJECT MANAGEMENT APPLICATION \n";
	cout << "\t MADE BY : NAVYATEJA GOPU \n";
	cout << "\t UNIVERSITY : SHEFFIELD HALLAM UNIVERSITY \n";
	_getch();
};

//***************************************************************
//    	ENTRY / EDIT MENU FUNCTION
//****************************************************************

void entry_menu()
{
	char ch;
	int num;
	clrscr();
	cout << "******************************************************************************\n";
	cout << "\t ADMINISTRATOR MENU \n";
	cout << "******************************************************************************\n";
	cout << "\t ENTRY MENU \n";
	cout << "\t 1.CREATE PROJECT RECORD \n";
	cout << "\t 2.DISPLAY ALL RECORDS \n";
	cout << "\t 3.SEARCH PROJECT RECORD \n";
	cout << "\t 4.MODIFY PROJECT RECORD \n";
	cout << "\t 5.DELETE PROJECT RECORD \n";
	cout << "\t 6.DELETE TASK RECORD \n";
	cout << "\t 7.BACK TO MAIN MENU \n";
	cout << "\t Please Enter Your Choice (1-11) \n";
	cin >> ch;
	clrscr();
	switch (ch)
	{
	case '1':	write_project(); break;
	case '2':	displayAll(); break;
	case '3':	cout << "\n\n\tPlease Enter The project number: "; cin >> num;
		display_sp(num); break;
	case '4':	cout << "\n\n\tPlease Enter The project number: "; cin >> num;
		modify_project(num); break;
	case '5':	cout << "\n\n\tPlease Enter The project number: "; cin >> num;
		delete_project(num); break;
	case '6':	cout << "\n\n\tPlease Enter The task number: "; cin >> num;
		delete_task(num); break;
	case '7':	break;
	default:	cout << "\a"; entry_menu();
	};
};

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	char ch;
	cout.setf(ios::fixed | ios::showpoint);
	cout << setprecision(2); // program outputs decimal number to two decimal places
	clrscr();
	intro();
	do
	{
		clrscr();
		cout << "******************************************************************************\n";
		cout << "\t MAIN MENU \n";
		cout << "******************************************************************************\n";
		cout << "\t 01. CREATE/EDIT PROJECT \n";
		cout << "\t 02. EXIT \n";
		cout << "\t Please Select Your Option (1-2) \n";
		cin >> ch;
		clrscr();
		switch (ch)
		{
		case '1': entry_menu();
			break;
		case '2':
			break;
		default:cout << "\a";
		};
	} while (ch != '2');
	return 0;
};
