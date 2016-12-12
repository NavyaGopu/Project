#pragma once
//#include "TimeAllocation.h"

class Meeting 
{
	char start_datetime[20];
	char end_datetime[20];
	char location[20];
	char attendees[50];
	int projnumber;
	int tasknumber;
	int meetingno;
public:
	void getdata(int projnumb, int tasknum);
	void showdata();
	int rettaskno();
	int retprojno();
	int retmeetingno();
};

