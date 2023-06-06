#pragma once
#include<iostream> 
#include<iomanip>
#include"clsUtil.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsUsers.h"
#include"clsTransferClientsScreen.h"
#include"clsTransferLogListScreen.h"

using namespace std;
class clsTransectionScreen : protected clsScreen
{
private:

	enum enTransectionOptions { eDeposit = 1, eWithdraw = 2, TotalBalances = 3, eTransfer = 4, eTransferLogList = 5, eBackToMainMenue = 6 };

	static void _ShowDepositScreen()
	{
		clsDepositScreen::DepositScreen();
	}

	static void _ShowWhithdrawScreen()
	{
		clsWithdrawScreen::WithdrawScreen();
	}

	static void _ShowTotalBalances()
	{
		clsTotalBalancesScreen::ClientsBalancesList();
	}

	static void _ShowTransferScreen()
	{
		clsTransferClientsScreen::ShowTransferScreen();
	}
	static void _ShowTansferLogListScreen()
	{
		clsTransferLogListScreen::TransferLogList();
	}
	/*static void _BackToMainMenue()
	{

	}*/

	static void _BackToTransectionScreen()
	{
		cout << setw(37) << left << "" << "Press any key to go back to transection menue... ";
		system("pause>0");
		ShowTransectionScreen();
	}

	static enTransectionOptions _GetTransectionsOptions()
	{
		return enTransectionOptions(clsInputValidate<short>::ReadNumberBetween(1, 6, "\t\t\t\t     Choose what do you want to do [1-6] ? "));
	}

	static void PerformTransectionsOptions(enTransectionOptions Option)
	{
		switch (Option)
		{
		case enTransectionOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_BackToTransectionScreen();
			break;
		}
		case enTransectionOptions::eWithdraw:
		{
			system("cls");
			_ShowWhithdrawScreen();
			_BackToTransectionScreen();
			break;
		}
		case enTransectionOptions::TotalBalances:
		{
			system("cls");
			_ShowTotalBalances();
			_BackToTransectionScreen();
			break;
		}
		case enTransectionOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_BackToTransectionScreen();
			break;
		}
		case enTransectionOptions::eTransferLogList:
		{
			system("cls");
			_ShowTansferLogListScreen();
			_BackToTransectionScreen();
			break;

		}
		case enTransectionOptions::eBackToMainMenue:
		{
			system("cls");
			break;
		}
		}
	}



public:

	static void ShowTransectionScreen()
	{
		system("cls");

		if (!CheckAccessRights(clsUsers::enPermissions::pTransection))
		{
			return;
		}

		_DrawScreenHeader(" Transection Screen");

		cout << setw(36) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << " [1] Deposit.\n";
		cout << setw(37) << left << "" << " [2] Withdraw.\n";
		cout << setw(37) << left << "" << " [3] Total Balance.\n";
		cout << setw(37) << left << "" << " [4] Transfer.\n";
		cout << setw(37) << left << "" << " [5] Transfer Log List.\n";
		cout << setw(37) << left << "" << " [6] Main Menue.\n";
		cout << setw(36) << left << "" << "==================================================\n";

		cout << setw(37) << left << "" << "Choose what do you want to do [1-6] ? ";

		PerformTransectionsOptions(_GetTransectionsOptions());
	}
};

