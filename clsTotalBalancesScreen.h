#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClients.h"
#include"clsUtil.h"
#include"clsScreen.h"

using namespace std;


class clsTotalBalancesScreen : protected clsScreen
{
private:

    static void _PrintClientsBalancesRecord(clsBankClients Client)
    {

        cout << "| " << setw(35) << left << Client.GetAccountNumber();
        cout << "| " << setw(35) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }


public:

    static void ClientsBalancesList()
    {
        vector <clsBankClients> vClients = clsBankClients::GetClientsList();

        string Title = "Total Balances Screen";
        string SubTitle = "(" + to_string(vClients.size()) + ") Client(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n" << setw(6) << left << "" << "__________________________________________________";
        cout << "_______________________________________________________\n";
        cout << setw(6) << left << "";
        cout << "| " << setw(35) << left << "Account Number";
        cout << "| " << setw(35) << left << "Client Name";
        cout << "| " << setw(12) << left << "Balance";
        cout << "\n";
        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "_______________________________________________________\n";


        if (vClients.size() == 0)
        {
            cout << setw(6) << left << "No Clients Available In The System\n";
        }
        else
        {
            for (clsBankClients& C : vClients)
            {
                cout << setw(6) << left << "";
                _PrintClientsBalancesRecord(C);
                cout << "\n";
            }
        }

        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "_______________________________________________________\n";

        int Total = clsBankClients::TotalBalances();
        cout << "\n" << setw(49) << left << "" << "Total Balances: " << Total << endl;
        cout << "\n" << setw(37) << left << "" << clsUtil::TextNumber(Total) << "\n\n\n";
    }

};

