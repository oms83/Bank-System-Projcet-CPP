#pragma once
#include<iostream> 
#include<iomanip>
#include"clsUtil.h"
#include"clsScreen.h"
#include"clsBankClients.h"
#include"clsInputValidate.h"
//#include"clsGlobal.h"

using namespace std;

class clsDepositScreen : protected clsScreen
{
private:

    static void _Print(clsBankClients Client)
    {
        cout << "\n__________________________________________________\n";
        cout << setw(20) << "" << "Clinet Card";
        cout << "\n__________________________________________________\n";
        cout << "\nFirst Name        : " << Client.FirstName;
        cout << "\nLast Name         : " << Client.LastName;
        cout << "\nFull Name         : " << Client.FullName();
        cout << "\nAccount Balance   : " << Client.AccountBalance;
        cout << "\nPinCode           : " << Client.PinCode;
        cout << "\nEmail             : " << Client.Email;
        cout << "\nPhone             : " << Client.Phone;
        cout << "\n__________________________________________________\n\n";
    }


public:
    static void DepositScreen()
    {

        _DrawScreenHeader("\t     Deposit Screen");

        cout << "\nEnter Account Number: ";
        string AccountNumber = clsInputValidate<string>::ReadString();

        while (!clsBankClients::IsExistClient(AccountNumber))
        {
            cout << "\n (" << AccountNumber << ") Account number is not found please enter another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();

        }

        clsBankClients Client = clsBankClients::Find(AccountNumber);

        _Print(Client);


        cout << "\nPlease enter deposit amount: ";
        float Amount = clsInputValidate<float>::ReadPositiveNumber("\nPlease enter deposit amount: ");

        char Answer;

        cout << "\nAre you sure you want to perform this transection [Y/N] ? ";
        cin >> Answer;

        if (tolower(Answer) == 'y')
        {
            Client.Deposit(Amount);

            cout << "\nAmount deposited successfully :-) \n";

            cout << "\nNew Balance is: " << Client.AccountBalance << endl;
        }
        else
        {
            cout << "\nThe options has been cancelled :-)\n";
        }


    }

    
};

