#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class clsTime
{
private:

	short _Hour;
	short _Minute;
	short _Second;

public:

	clsTime()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Hour, Minute, Second;

		_Hour = now->tm_hour;
		_Second = now->tm_sec;
		_Minute = now->tm_min;

	}

	static string StringTime(clsTime Time)
	{
		return to_string(Time._Hour) +"/" + to_string(Time._Minute) + "/" + to_string(Time._Second);
	}

};

