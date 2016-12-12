#pragma once
class task
{
	int taskno;
	char aa[1];
	int projnumber;
	char taskname[100];
	char taskdesc[100];
	char start_datetime[20];
	char end_datetime[20];

public:
	void getdata(int projnumb,char* aa);
	void showdata();
	int rettaskno();
	int retprojno();
	int getdatetime();
};

