#pragma once
#include<iostream>
#include"clsBankClients.h"
#include"clsInputValidate.h"
#include"clsString.h"
#include"clsScreen.h"

using namespace std;

class clsClientsListScreen : protected clsScreen
{

private:

    static void PrintClientsListRecord(clsBankClients Client)
    {
        cout << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(25) << left << Client.FullName();
        cout << "| " << setw(13) << left << Client.Phone;
        cout << "| " << setw(25) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(10) << left << Client.AccountBalance;
    }



public:

    static void ClientsList()
    {
        if (!CheckAccessRights(clsUsers::enPermissions::pListClients))
        {
            return;
        }


        vector <clsBankClients> vClients = clsBankClients::GetClientsList();

        string Title = "  Client List Screen";
        string SubTitle = "  (" + to_string(vClients.size()) + ") Client(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n" << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";
        cout << setw(6) << left << "";
        cout << "| " << setw(15) << left << "Account Number";
        cout << "| " << setw(25) << left << "Client Name";
        cout << "| " << setw(13) << left << "Phone";
        cout << "| " << setw(25) << left << "Email";
        cout << "| " << setw(10) << left << "Pin Code";
        cout << "| " << setw(10) << left << "Balance";
        cout << "\n";
        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";


        if (vClients.size() == 0)
        {
            cout << setw(6) << left << "No Clients Available In The System\n";
        }
        else
        {
            for (clsBankClients& C : vClients)
            {
                cout << setw(6) << left << "";
                PrintClientsListRecord(C);
                cout << "\n";
            }
        }

        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";
    }

    
};

