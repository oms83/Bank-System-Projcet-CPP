#pragma once
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include "clsUsers.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

	static void _GetPermissinos(clsUsers& User)
	{
		cout << "Enter Permissinos: \n\n";

		char Answer = 'Y';
		cout << "Do you want to give full access [Y/N] ? ";
		cin >> Answer;

		cout << "\nDo you want to give access to: \n\n";
		User.Permissions = 0;

		if (toupper(Answer) == 'Y')
		{
			User.Permissions = clsUsers::enPermissions::eAll;
		}
		else
		{
			cout << "\nShow Client List [Y/N]? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				User.Permissions += clsUsers::enPermissions::pListClients;
			}

			cout << "\nAdd New Client [Y/N]? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				User.Permissions += clsUsers::enPermissions::pAddNewClient;
			}

			cout << "\nDelete Client [Y/N]? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				User.Permissions += clsUsers::enPermissions::pAddNewClient;
			}

			cout << "\nUpdate Client [Y/N]? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				User.Permissions += clsUsers::enPermissions::pUpdateClient;
			}

			cout << "\nFind Client [Y/N]? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				User.Permissions += clsUsers::enPermissions::pFindClient;
			}

			cout << "\nTransection [Y/N]? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				User.Permissions += clsUsers::enPermissions::pTransection;
			}

			cout << "\nManager Users [Y/N]? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				User.Permissions += clsUsers::enPermissions::pManagerUsers;
			}

			cout << "\nLogin Register List [Y/N]? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				User.Permissions += clsUsers::enPermissions::pLoginRegisterList;
			}

			if (User.Permissions == 255)
			{
				User.Permissions = clsUsers::enPermissions::eAll;
			}

		}

	}

	static void _ReadClientInfo(clsUsers& User)
	{
		cout << "\nEnter First Name: ";
		User.FirstName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Last Name: ";
		User.LastName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate<string>::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate<string>::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate<string>::ReadString();

		_GetPermissinos(User);


	}

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

	static void AddNewUser()
	{
		_DrawScreenHeader("Add New User Screen");

		cout << "Enter User Name: ";
		string UserName = clsInputValidate<string>::ReadString();
		while (clsUsers::IsUserExist(UserName))
		{
			cout << "(" << UserName << ") User Name is Found, Enter Anouther User Name: ";
			UserName = clsInputValidate<string>::ReadString();

		}

		clsUsers NewUser = clsUsers::GetAddNewClientObject(UserName);
		_ReadClientInfo(NewUser);

		clsUsers::enSaveResults SaveResults;
		SaveResults = NewUser.Save();
		switch (SaveResults)
		{
		case clsUsers::svFaildEmptyObject:
			cout << "\nObject is empty\n";
			break;
		case clsUsers::svSucceeded:
			cout << "\nUser is adedd successfully\n";
			break;
		case clsUsers::svFaildUserNameExists:
			cout << "\nSave faild because user name is founded\n";
			break;
		default:
			break;
		}

		_Print(NewUser);

	}


};

