#pragma once
//#include "TimeAllocation.h"

class BugFix
{
	char start_datetime[20];
	char end_datetime[20];
	char work[30];
	char bugdesc[50];
	int projnumber;
	int tasknumber;
	int bugno;
public:
	void getdata(int projnumb, int tasknum);
	void showdata();
	int rettaskno();
	int retprojno();
	int retbugno();
};

