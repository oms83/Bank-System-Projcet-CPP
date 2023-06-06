#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClients.h"
#include"clsInputValidate.h"
using namespace std;
class clsFindClientScreen : protected clsScreen
{
private:
	static void _PrintClientRecord(clsBankClients Client)
	{
		cout << "\n\n__________________________________________________\n";
		cout << setw(20) << "" << "Clinet Card";
		cout << "\n__________________________________________________\n";
		cout << "\nFirst Name        : " << Client.FirstName;
		cout << "\nLast Name         : " << Client.LastName;
		cout << "\nFull Name         : " << Client.FullName();
		cout << "\nAccount Number    : " << Client.GetAccountNumber();
		cout << "\nAccount Balance   : " << Client.AccountBalance;
		cout << "\nPinCode           : " << Client.PinCode;
		cout << "\nEmail             : " << Client.Email;
		cout << "\nPhone             : " << Client.Phone;
		cout << "\n__________________________________________________\n\n";
	}

public:

	static void FindClinet()
	{
		if (!CheckAccessRights(clsUsers::enPermissions::pFindClient))
		{
			return;
		}


		_DrawScreenHeader("Find Client Screen");
		cout << "\n\nPlease Enter Account Number: ";
		string AccountNumber = clsInputValidate<string>::ReadString();
		
		while (!clsBankClients::IsExistClient(AccountNumber))
		{
			cout << "\nPlease Enter Another Account Number, Becuase (" << AccountNumber << ") Is Not Found: ";
			AccountNumber = clsInputValidate<string>::ReadString();

		}

		clsBankClients Client = clsBankClients::Find(AccountNumber);
		_PrintClientRecord(Client);
		
	}
};

