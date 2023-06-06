#pragma once
#include<iostream>
#include<string>
#include"clsCurrencyExchange.h"
#include"clsString.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;

class clsCurrencyCalculatorScreen :protected clsScreen

{
private:

    static float _ReadAmount()
    {
        cout << "\nEnter Amount to Exchange: ";
        float Amount = 0;

        Amount = clsInputValidate<float>::ReadPositiveNumber();
        return Amount;
    }

    static clsCurrencyExchange _GetCurrency(string Message)
    {

        string CurrencyCode;
        cout << Message << endl;

        CurrencyCode = clsInputValidate<string>::ReadString();

        while (!clsCurrencyExchange::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate<string>::ReadString();
        }

        clsCurrencyExchange Currency = clsCurrencyExchange::FindByCode(CurrencyCode);
        return Currency;

    }


    static  void _PrintCurrencyCard(clsCurrencyExchange Currency, string Title = "Currency Card:")
    {
        cout << "\n\n__________________________________________________\n";
        cout << setw(20) << "" << Title;
        cout << "\n__________________________________________________\n";
        cout << "\nCountry    : " << Currency.Country;
        cout << "\nCode       : " << Currency.Code;
        cout << "\nName       : " << Currency.Name;
        cout << "\nRate/(1$)  : " << Currency.Rate;
        cout << "\n__________________________________________________\n\n";

    }

    static void _PrintCalculationsResults(float Amount, clsCurrencyExchange Currency1, clsCurrencyExchange Currency2)
    {

        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.Code << " = " << AmountInUSD << " USD\n";

        if (Currency2.Code == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.Code << " = " << AmountInCurrrency2 << " " << Currency2.Code;

    }


public:

    static void ShowCurrencyCalculatorScreen()
    {
        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");

            _DrawScreenHeader("Calculator Currency Screen");

            clsCurrencyExchange CurrencyFrom = _GetCurrency("Please Enter Currency1 Code: ");
            clsCurrencyExchange CurrencyTo = _GetCurrency("Please Enter Currency2 Code: ");
            float Amount = _ReadAmount();

            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want to perform another calculation [Y/N] ? ";
            cin >> Continue;

        }
        
        cout << "\n\n";

    }
};




//using namespace std;
//
//class clsCalculatorCurrencyScreen : protected clsScreen
//{
//private:
//	static void _Print(clsCurrencyExchange Currency)
//	{
//		cout << "\n\n__________________________________________________\n";
//		cout << setw(20) << "" << "Currency Card";
//		cout << "\n__________________________________________________\n";
//		cout << "\nCountry    : " << Currency.Country;
//		cout << "\nCode       : " << Currency.Code;
//		cout << "\nName       : " << Currency.Name;
//		cout << "\nRate/(1$)  : " << Currency.Rate;
//		cout << "\n__________________________________________________\n\n";
//	}
//	
//	static float _FromUsdToAnother(clsCurrencyExchange AnotherCurrency, float Amount)
//	{
//		return AnotherCurrency.Rate * Amount;
//	}
//
//	static float _FromAnotherToUsd(clsCurrencyExchange AnotherCurrency, float Amount)
//	{
//		return Amount / AnotherCurrency.Rate;
//	}
//
//
//public:
//
//	static void CalculatorCurrency()
//	{
//
//		char Answer = 'Y';
//
//		do
//		{
//			system("cls");
//
//			_DrawScreenHeader("Calculator Currency Screen");
//			
//			cout << "\nPlease Enter Currency1 Code : ";
//			string Code1 = clsInputValidate::ReadString();
//
//			while (!clsCurrencyExchange::IsCurrencyExist(Code1))
//			{
//				cout << "\n(" << Code1 << ") Not Found! Please Enter Another Currency Code : ";
//				Code1 = clsInputValidate::ReadString();
//			}
//
//
//			cout << "\nPlease Enter Currency2 Code : ";
//			string Code2 = clsInputValidate::ReadString();
//
//			while (!clsCurrencyExchange::IsCurrencyExist(Code2))
//			{
//				cout << "\n(" << Code2 << ") Not Found! Please Enter Another Currency Code : ";
//				Code2 = clsInputValidate::ReadString();
//			}
//
//
//			clsCurrencyExchange Currency1 = clsCurrencyExchange::FindByCode(Code1);
//			_Print(Currency1);
//
//			clsCurrencyExchange Currency2 = clsCurrencyExchange::FindByCode(Code2);
//			_Print(Currency2);
//
//			cout << "\nPlaese Enter Amount To Exchange: ";
//			float Amount = clsInputValidate::ReadFloatNumber();
//
//
//
//			if (clsString::UpperAllString(Currency2.Code) == "USD")
//			{
//				cout << "\nConvert From:\n";
//				_Print(Currency1);
//				cout << Amount << " " << Currency1.Code << " = " << _FromAnotherToUsd(Currency1, Amount) << " USD" << endl;
//			}
//
//			else if (clsString::UpperAllString(Currency1.Code) == "USD")
//			{
//				cout << "\nConvert From:\n";
//				_Print(Currency2);
//				cout << Amount << " " << Currency2.Code << " = " << _FromUsdToAnother(Currency2, Amount) << " USD" << endl;
//			}
//
//			else if (clsString::UpperAllString(Code1) != "USD" && clsString::UpperAllString(Code2) != "USD")
//			{
//				cout << "\nConvert From:\n";
//				_Print(Currency1);
//
//				float AmountOfUsd = _FromAnotherToUsd(Currency1, Amount);
//				cout << Amount << " " << Currency1.Code << " = " <<  AmountOfUsd << " USD" << endl;
//
//				cout << "\nConverting From Usd To:\n";
//
//				_Print(Currency2);
//
//				cout << Amount << " " << Currency2.Code << " = " << _FromUsdToAnother(Currency2, AmountOfUsd) << " USD" << endl << endl;
//
//			}
//
//
//			cout << "\nDo You Want To Perform Another Calculation [Y/N] ? ";
//			cin >> Answer;
//
//
//		} while (toupper(Answer) == 'Y');
//
//		cout << "\n\n";
//	}
//};