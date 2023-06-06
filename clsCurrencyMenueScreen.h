#pragma once
#include<iostream> 
#include<iomanip>
#include"clsUtil.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCalculatorCurrencyScreen.h"
using namespace std;
class clsCurrencyMenueScreen : protected clsScreen
{
private:

	enum enCurrencyExchangeOptions { eCurrenciesList = 1, eFindCurrency = 2, eCurrenciesUpdate = 3, eCurreciesCalculator = 4, eMainMenue = 5 };

	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::CurrenciesList();
	}

	static void _ShowUpdateCurrenciesScreen()
	{
		clsUpdateCurrencyScreen::UpdateCurrency();
	}

	static void _ShowClaculatorCurrenciesBalances()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::FindCurrency();
	}

	static void _BackToCurrencyExchangeScreen()
	{
		cout << setw(37) << left << "" << "Press any key to go back to currency exchange menue... ";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	static enCurrencyExchangeOptions _GetCurrencyExchangesOptions()
	{
		return enCurrencyExchangeOptions(clsInputValidate<short>::ReadNumberBetween(1, 5, "\t\t\t\t     Choose what do you want to do [1-5] ? "));
	}

	static void PerformCurrencyExchangesOptions(enCurrencyExchangeOptions Option)
	{
		switch (Option)
		{
			case enCurrencyExchangeOptions::eCurrenciesList:
			{
				system("cls");
				_ShowCurrenciesListScreen();
				_BackToCurrencyExchangeScreen();
				break;
			}
			case enCurrencyExchangeOptions::eFindCurrency:
			{
				system("cls");
				_ShowFindCurrencyScreen();
				_BackToCurrencyExchangeScreen();
				break;
			}
			case enCurrencyExchangeOptions::eCurrenciesUpdate:
			{
				system("cls");
				_ShowUpdateCurrenciesScreen();
				_BackToCurrencyExchangeScreen();
				break;
			}
			case enCurrencyExchangeOptions::eCurreciesCalculator:
			{
				system("cls");
				_ShowClaculatorCurrenciesBalances();
				_BackToCurrencyExchangeScreen();
				break;
			}
			case enCurrencyExchangeOptions::eMainMenue:
			{
				system("cls");
				break;
			}
		}
	}



public:

	static void ShowCurrencyExchangeScreen()
	{
		system("cls");

		/*if (!CheckAccessRights(clsUsers::enPermissions::pCurrencyExchange))
		{
			return;
		}*/

		_DrawScreenHeader(" Currency Exchange Screen");

		cout << setw(36) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << " [1] Currencies List.\n";
		cout << setw(37) << left << "" << " [2] Find Currency.\n";
		cout << setw(37) << left << "" << " [3] Update Rate.\n";
		cout << setw(37) << left << "" << " [4] Currency Calculator.\n";
		cout << setw(37) << left << "" << " [5] Main Menue.\n";
		cout << setw(36) << left << "" << "==================================================\n";

		cout << setw(37) << left << "" << "Choose what do you want to do [1-5] ? ";

		PerformCurrencyExchangesOptions(_GetCurrencyExchangesOptions());
	}
};

