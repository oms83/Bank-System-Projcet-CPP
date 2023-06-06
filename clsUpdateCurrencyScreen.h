#pragma once
#include<iostream>
#include<string>
#include"clsCurrencyExchange.h"
#include"clsString.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyScreen : protected clsScreen
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

	static void _GetCurrencyRate(clsCurrencyExchange &Currency)
	{
		cout << "\nPlaese Enter Currency Rate: ";
		Currency.Rate = clsInputValidate<float>::ReadPositiveNumber();
	}

public:

	static void UpdateCurrency()
	{
		_DrawScreenHeader("Update Currency Screen");


		cout << "\nPlease Enter Currency Code : ";
		string Code = clsInputValidate<string>::ReadString();

		while (!clsCurrencyExchange::IsCurrencyExist(Code))
		{
			cout << "\n(" << Code << ") Not Found! Please Enter Another Currency Code : ";
			Code = clsInputValidate<string>::ReadString();
		}

		clsCurrencyExchange Currency = clsCurrencyExchange::FindByCode(Code);
		_Print(Currency);

		char Answer = 'Y';
		cout << "\nAre You Sure You Want To Update This Currency [Y/N] ? ";
		cin >> Answer;


		if (toupper(Answer) == 'Y')
		{
			_GetCurrencyRate(Currency);
			Currency.UpdateRate(Currency.Rate);
			_Print(Currency);

		}
		else
		{
			cout << "\nTh Option is Cancelled\n\n";
		}


	}
};