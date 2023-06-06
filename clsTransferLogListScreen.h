#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClients.h"
#include "clsInputValidate.h"
#include<vector>

using namespace std;

class clsTransferLogListScreen : protected clsScreen
{
private:

    static void PrintTransferLogListRecord(clsBankClients::stTransferRecord LogTransfer)
    {
        cout << "| " << setw(25) << left << LogTransfer.dTime;
        cout << "| " << setw(10) << left << LogTransfer.sAccountNumber;
        cout << "| " << setw(8) << left << LogTransfer.dAccountNumber;
        cout << "| " << setw(10) << left << LogTransfer.Amount;
        cout << "| " << setw(10) << left << LogTransfer.sAccountBalance;
        cout << "| " << setw(10) << left << LogTransfer.dAccountBalance;
        cout << "| " << setw(10) << left << LogTransfer.UserName;
    }


public:

    static void TransferLogList()
    {
        vector <clsBankClients::stTransferRecord> vTransferLog = clsBankClients::GetTransferList();

        string Title = "Transfer Log List Screen";
        string SubTitle = "(" + to_string(vTransferLog.size()) + ") User(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n" << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";
        cout << setw(6) << left << "";
        cout << "| " << setw(25) << left << "Date/Time";
        cout << "| " << setw(10) << left << "s.Acct";
        cout << "| " << setw(10) << left << "d.Acct";
        cout << "| " << setw(8) << left << "Amount";
        cout << "| " << setw(10) << left << "s.Balance";
        cout << "| " << setw(10) << left << "d.Balance";
        cout << "| " << setw(10) << left << "User";
        cout << "\n";
        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";


        if (vTransferLog.size() == 0)
        {
            cout << setw(6) << left << "\t\t\t\t    No User Available In The System\n";
        }
        else
        {
            for (clsBankClients::stTransferRecord& LogTransfer : vTransferLog)
            {
                cout << setw(6) << left << "";
                PrintTransferLogListRecord(LogTransfer);
                cout << "\n";
            }
        }

        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";
    }
};
