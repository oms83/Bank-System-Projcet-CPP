#pragma once
#include<iostream>
#include<iomanip>
#include"clsUsers.h"
#include"clsGlobal.h"
#include"clsTime.h"
#include"clsDate.h"

using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << setw(36.5) << "" << "__________________________________________________\n"; //50
		
		cout << setw(51) << "" << Title << endl;
		
		if (SubTitle != "")
		{
			cout << setw(51) << "" << SubTitle << endl;
		}
		clsDate Date = clsDate::GetSystemDate();

		cout << setw(36.5) << "" << "__________________________________________________\n"; //50
		cout << setw(37) << "" << "User Name: " << CurrentUser.UserName << endl;
		cout << setw(37) << left << "" << "Date: " << clsDate::MonthShortName(Date.Month) << " " << clsDate::DayShortName(Date.Day, Date.Month, Date.Year) << "  " << clsDate::DateToString(clsDate()) << endl;
		cout << setw(37) << "" << "Time: " << clsTime::StringTime(clsTime()) << endl;
		cout << setw(36.5) << "" << "__________________________________________________\n\n"; //50

	}
	
	static bool CheckAccessRights(clsUsers::enPermissions Permission)
	{
		if (!CurrentUser.CheckToPremissions(Permission))
		{
			cout << setw(36.5) << "" << "__________________________________________________\n"; //50
			cout << setw(46) << "" << "Access Denied! Contact Your Admin" << endl;
			cout << setw(36.5) << "" << "__________________________________________________\n"; //50
			return false;
		}
		else
		{
			return true;
		}
	}
};

