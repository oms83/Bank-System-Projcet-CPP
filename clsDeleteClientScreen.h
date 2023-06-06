
#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClients.h"
#include"clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
{
private:
	static void _PrintClientRecord(clsBankClients Client)
	{
		cout << "\n__________________________________________________\n";
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

	static void DeleteClient()
	{
		if (!CheckAccessRights(clsUsers::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("Delete Client Screen");

		cout << "\nPlease Enter AccountNumber: ";
		string AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsBankClients::IsExistClient(AccountNumber))
		{
			cout << "\nPlease Enter Another Account Number, Becuase (" << AccountNumber << ") Is Not Found: ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClients Client = clsBankClients::Find(AccountNumber);
		_PrintClientRecord(Client);


		char Answer = 'Y';

		cout << "\nAre you sure you want to delete this client [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Client.Delete();

			_PrintClientRecord(Client);

			cout << "\nClient Deleted Successfully!\n";
		}
		else
		{
			cout << "\nClient Update is cancelld!\n";
		}

	}


};

