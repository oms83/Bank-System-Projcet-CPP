#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClients.h"
#include "clsInputValidate.h"

class clsTransferClientsScreen :protected clsScreen
{

private:
    static void _PrintClient(clsBankClients Client)
    {
        cout << "\n\n__________________________________________________\n";
        cout << setw(20) << "" << "Clinet Card";
        cout << "\n__________________________________________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n\n__________________________________________________\n";
        
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate<string>::ReadString();
        while (!clsBankClients::IsExistClient(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }
        return AccountNumber;
    }

    static float ReadAmount(clsBankClients SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate<float>::ReadPositiveNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate<double>::ReadPositiveNumber();
        }
        return Amount;
    }

public:

    static void ShowTransferScreen()
    {

        _DrawScreenHeader("\tTransfer Screen");

        clsBankClients SourceClient = clsBankClients::Find(_ReadAccountNumber());

        _PrintClient(SourceClient);

        clsBankClients DestinationClient = clsBankClients::Find(_ReadAccountNumber());

        while (DestinationClient.GetAccountNumber() == SourceClient.GetAccountNumber())
        {
            DestinationClient = clsBankClients::Find(_ReadAccountNumber());
        }

        _PrintClient(DestinationClient);

        float Amount = ReadAmount(SourceClient);


        cout << "\nAre you sure you want to perform this operation [Y/N] ? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
            {
                
                _PrintClient(SourceClient);
                _PrintClient(DestinationClient);

                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }



    }

};

