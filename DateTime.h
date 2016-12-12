#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class DateTime
{
public:
	DateTime(string);
	string getFormatted() const;
private:
	int minute;
	int hour;
	int day;
	int month;
	int year;
};

