#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUsers.h"
using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:

	static void _Print(clsUsers User)
	{
		cout << "\n\n__________________________________________________\n";
		cout << setw(20) << "" << "Clinet Card";
		cout << "\n__________________________________________________\n";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n__________________________________________________\n\n";
	}




public:

	static void FindUser()
	{
		_DrawScreenHeader("Find User Screen");

		cout << "Enter User Name: ";
		string UserName = clsInputValidate<string>::ReadString();

		while (!clsUsers::IsUserExist(UserName))
		{
			cout << "Enter User Name: ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUsers User = clsUsers::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser founded\n";
		}
		else
		{
			cout << "\nUser was not founded\n";
		}

		_Print(User);

	}
};

