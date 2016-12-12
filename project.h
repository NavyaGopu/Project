#pragma once
class project
{
	int projno;
	char projname[100];
	char projdesc[100];
	char start_datetime[20];
	char end_datetime[20];
public:
	void getdata();		
	void showdata();	
	int retprojno();
	int getdatetime();

};

