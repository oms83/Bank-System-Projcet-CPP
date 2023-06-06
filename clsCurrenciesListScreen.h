#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrencyExchange.h"

class clsCurrenciesListScreen : protected clsScreen
{

private:

    static void PrintCurrenciesListRecord(clsCurrencyExchange Currency)
    {
        cout << "| " << setw(35) << left << Currency.Country;
        cout << "| " << setw(15) << left << Currency.Code;
        cout << "| " << setw(40) << left << Currency.Name;
        cout << "| " << setw(10) << left << Currency.Rate;
    }



public:

    static void CurrenciesList()
    {
       
        vector <clsCurrencyExchange> vCurrencies = clsCurrencyExchange::GetCurrenciesList();

        string Title = " Currencies List Screen";
        string SubTitle = " (" + to_string(vCurrencies.size()) + ") Client(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n" << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";
        cout << setw(6) << left << "";
        cout << "| " << setw(35) << left << "Country";
        cout << "| " << setw(15) << left << "Code";
        cout << "| " << setw(40) << left << "Name";
        cout << "| " << setw(10) << left << "Rate/(1$)";
        cout << "\n";
        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";


        if (vCurrencies.size() == 0)
        {
            cout << setw(40) << left << "" << "No Currencies Available In The System\n";
        }
        else
        {
            for (clsCurrencyExchange& C : vCurrencies)
            {
                cout << setw(6) << left << "";
                PrintCurrenciesListRecord(C);
                cout << "\n";
            }
        }

        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";
    }


};