#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClients.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsFindClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsClientsListScreen.h"
#include"clsTransectionScreen.h"
#include"clsManagerUsersScreen.h"
#include"clsGlobal.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyMenueScreen.h"

using namespace std;
class clsMainMenueScreen: protected clsScreen
{
private:

	enum enMainMenueOptions { ClientList = 1, AddNew = 2, DeleteClient = 3, eUpdateClient = 4, FindClient = 5, eTransection = 6, ManagerUsers = 7, LoginRegister = 8, CurrencyExchange = 9, LogoutScreen = 10 };

	static enMainMenueOptions _GetMainMenueOption()
	{
		return (enMainMenueOptions)clsInputValidate<short>::ReadNumberBetween(1, 10, "\t\t\t\t     Choose what do you want to do [1-10] ? ");
	}

	static void _BackToMainMenueScreen()
	{
		cout << setw(37) << left << "" << "Press any key to go back to main menue... ";

		system("pause>0");

		ShowMainMenueScreen();
	}

	static void _ShowClientsListScreen()
	{
		clsClientsListScreen::ClientsList();
	}

	static void _ShowAddNewScreen()
	{
		clsAddNewClientScreen::AddNewClient();
	}

	static void _ShowDeleteScreen()
	{
		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowClientUpdateScreen()
	{
		clsUpdateClientScreen::UpdateClient();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::FindClinet();
	}

	static void _ShowTransectionScreen()
	{
		clsTransectionScreen::ShowTransectionScreen();
	}

	static void _ShowManagerScreen()
	{
		clsManagerUsersScreen::ShowManagerMenueScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyMenueScreen::ShowCurrencyExchangeScreen();
	}

	static void _ShowLogoutScreen()
	{
		CurrentUser = clsUsers::Find("", "");
	}

	static void _ShowLoginRegisterListScreen()
	{
		clsLoginRegisterScreen::LoginRegisterList();
	}

	static void _PerformMainMenueOptions(enMainMenueOptions Options)
	{
		switch (Options)
		{
		case clsMainMenueScreen::ClientList:
		{
			system("cls");
			_ShowClientsListScreen();
			_BackToMainMenueScreen();
			break;
		}

		case clsMainMenueScreen::AddNew:
		{
			system("cls");
			_ShowAddNewScreen();
			_BackToMainMenueScreen();
			break;
		}

		case clsMainMenueScreen::DeleteClient:
		{
			system("cls");
			_ShowDeleteScreen();
			_BackToMainMenueScreen();
			break;
		}

		case clsMainMenueScreen::eUpdateClient:
		{
			system("cls");
			_ShowClientUpdateScreen();
			_BackToMainMenueScreen();
			break;
		}

		case clsMainMenueScreen::FindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_BackToMainMenueScreen();
			break;
		}

		case clsMainMenueScreen::eTransection:
		{
			system("cls");
			_ShowTransectionScreen();
			_BackToMainMenueScreen();

			break;
		}

		case clsMainMenueScreen::ManagerUsers:
		{
			system("cls");
			_ShowManagerScreen();
			_BackToMainMenueScreen();

			break;
		}

		case clsMainMenueScreen::LoginRegister:
		{
			system("cls");
			_ShowLoginRegisterListScreen();
			_BackToMainMenueScreen();
			break;
		}

		case clsMainMenueScreen::CurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_BackToMainMenueScreen();
			break;
		}

		case clsMainMenueScreen::LogoutScreen:
		{
			system("cls");
			_ShowLogoutScreen();
			break;
		}

		}
	}

public:

	static void ShowMainMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("Main Menue Screen");

		cout << "\n";
		cout << setw(36) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << " [1] Show Client List.\n";
		cout << setw(37) << left << "" << " [2] Add New Client.\n";
		cout << setw(37) << left << "" << " [3] Delete Client.\n";
		cout << setw(37) << left << "" << " [4] Update Client.\n";
		cout << setw(37) << left << "" << " [5] Find Client.\n";
		cout << setw(37) << left << "" << " [6] Transection.\n";
		cout << setw(37) << left << "" << " [7] Manager Users.\n";
		cout << setw(37) << left << "" << " [8] Login Register List.\n";
		cout << setw(37) << left << "" << " [9] Currency Exchange.\n";
		cout << setw(37) << left << "" << " [10] Logout.\n";
		cout << setw(36) << left << "" << "==================================================\n";

		cout << setw(37) << left << "" << "Choose what do you want to do [1-10] ? ";
		_PerformMainMenueOptions(_GetMainMenueOption());
	}
};

