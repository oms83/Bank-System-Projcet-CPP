#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsString.h"
#include"clsScreen.h"
#include"clsUsersListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include"clsUsers.h"
#include"clsMainMenueScreen.h"
using namespace std;




class clsManagerUsersScreen : protected clsScreen
{

private:

	enum enManagerMenueOptions { eUsersList = 1, eAddNewUsers = 2, eDeleteUsers = 3, eUpdateUsers = 4, eFindUsers = 5, eMainMenue = 6 };

	static enManagerMenueOptions _GetManagerMenueOption()
	{
		return (enManagerMenueOptions)clsInputValidate<short>::ReadNumberBetween(1, 6, "\t\t\t\t     Choose what do you want to do [1-6] ? ");
	}

	static void _BackToMangerMenueScreen()
	{
		cout << setw(37) << left << "" << "Press any key to go back to manager menue... ";

		system("pause>0");

		ShowManagerMenueScreen();
	}

	static void _ShowUsersListScreen()
	{
		clsUsersListScreen::UsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::AddNewUser();
	}

	static void _ShowDeleteUsersScreen()
	{
		clsDeleteUserScreen::DeleteUser();
	}

	static void _ShowUpdateUsersScreen()
	{
		clsUpdateUserScreen::UpdateUser();
	}

	static void _ShowFindUsersScreen()
	{
		clsFindUserScreen::FindUser();
	}


	static void _ShowMainMenueScreen()
	{
	}


	static void _PerformManagerMenueOptions(enManagerMenueOptions Options)
	{
		switch (Options)
		{
		case enManagerMenueOptions::eUsersList:
		{
			system("cls");
			_ShowUsersListScreen();
			_BackToMangerMenueScreen();
			break;
		}

		case enManagerMenueOptions::eAddNewUsers:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_BackToMangerMenueScreen();
			break;
		}

		case enManagerMenueOptions::eDeleteUsers:
		{
			system("cls");
			_ShowDeleteUsersScreen();
			_BackToMangerMenueScreen();
			break;
		}

		case enManagerMenueOptions::eUpdateUsers:
		{
			system("cls");
			_ShowUpdateUsersScreen();
			_BackToMangerMenueScreen();
			break;
		}

		case enManagerMenueOptions::eFindUsers:
		{
			system("cls");
			_ShowFindUsersScreen();
			_BackToMangerMenueScreen();
			break;
		}

		case enManagerMenueOptions::eMainMenue:
		{
			system("cls");

			break;
		}

		}
	}


public:

	static void ShowManagerMenueScreen()
	{
		system("cls");

		if (!CheckAccessRights(clsUsers::enPermissions::pManagerUsers))
		{
			return;
		}

		_DrawScreenHeader("Manager Users Screen");

		cout << setw(36) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << " [1] Show User List.\n";
		cout << setw(37) << left << "" << " [2] Add New User.\n";
		cout << setw(37) << left << "" << " [3] Delete User.\n";
		cout << setw(37) << left << "" << " [4] Update User.\n";
		cout << setw(37) << left << "" << " [5] Find User.\n";
		cout << setw(37) << left << "" << " [6] Main Menue.\n";
		cout << setw(36) << left << "" << "==================================================\n";

		cout << setw(37) << left << "" << "Choose what do you want to do [1-6] ? ";

		_PerformManagerMenueOptions(_GetManagerMenueOption());
	}
};


