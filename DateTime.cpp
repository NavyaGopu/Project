#include "stdafx.h"
#include "DateTime.h"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

DateTime::DateTime(string datetime)
{
	// DD/MM/YYYY HH:MM
	istringstream iss(datetime);
	char dump;
	iss >> day >> dump >> month >> dump >> year >> hour >> dump >> minute;
}

string DateTime::getFormatted() const
{
	// DD/MM/YYYY HH:MM
	ostringstream oss;
	oss << setfill('0');
	oss << setw('2') << day << '/';
	oss << setw('2') << month << '/';
	oss << year << ' ';
	oss << setw('2') << hour << ':';
	oss << setw('2') << minute ;
	return oss.str();
}


