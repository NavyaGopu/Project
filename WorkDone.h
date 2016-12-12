#pragma once
//#include "TimeAllocation.h"

class WorkDone
{
	char start_datetime[20];
	char end_datetime[20];
	char work[30];
	char workdesc[50];
	int projnumber;
	int tasknumber;
	int workno;
public:
	void getdata(int projnumb, int tasknum);
	void showdata();
	int rettaskno();
	int retprojno();
	int retworkno();
};

