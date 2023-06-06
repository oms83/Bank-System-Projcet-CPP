#pragma once
#include<iostream>
#include<string>
#include"clsCurrencyExchange.h"
#include"clsString.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void _Print(clsCurrencyExchange Currency)
	{
		cout << "\n\n__________________________________________________\n";
		cout << setw(20) << "" << "Currency Card";
		cout << "\n__________________________________________________\n";
		cout << "\nCountry    : " << Currency.Country;
		cout << "\nCode       : " << Currency.Code;
		cout << "\nName       : " << Currency.Name;
		cout << "\nRate/(1$)  : " << Currency.Rate;
		cout << "\n__________________________________________________\n\n";
	}

	static void _PrintEmptyMessage()
	{
		cout << "\n\nCurrency Not Found!\n\n";
	}

public:

	static void FindCurrency()
	{
		_DrawScreenHeader("Find Currency Screen");
		short Choice;
		cout << "\n\nFind By: [1] Code or [2] Country? ";
		Choice = clsInputValidate<short>::ReadPositiveNumber();
		
		string Answer1 = Choice == 1 ? "Code" : "Country";
		
		cout << "\nPlease Enter " << Answer1 << " : ";
		string Answer2 = clsInputValidate<string>::ReadString();

		clsCurrencyExchange Currency = ((Answer1 == "Code") ? clsCurrencyExchange::FindByCode(Answer2) : clsCurrencyExchange::FindByCountry(Answer2));

		clsCurrencyExchange::IsCurrencyExist(Currency.Code) == true ? _Print(Currency) : _PrintEmptyMessage();


		
		/*if (clsCurrencyExchange::IsCurrencyExist(Currency.Code))
		{
			_Print(Currency);
		}
		else
		{
			cout << "\n\nCurrency Not Found!\n\n";
		}*/


	}
};