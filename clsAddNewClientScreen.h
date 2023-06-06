#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClients.h"
#include"clsInputValidate.h"
#include"clsUsers.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
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
		cout << "\nAccount Balance   : " << Client.AccountBalance;
		cout << "\nPinCode           : " << Client.PinCode;
		cout << "\nEmail             : " << Client.Email;
		cout << "\nPhone             : " << Client.Phone;
		cout << "\n__________________________________________________\n\n";
	}

	static void _GetClientInfo(clsBankClients& Client)
	{
		cout << "\nEnter First Name     :  ";
		Client.FirstName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Last Name      :  ";
		Client.LastName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Email          :  ";
		Client.Email = clsInputValidate<string>::ReadString();

		cout << "\nEnter Phone          :  ";
		Client.Phone = clsInputValidate<string>::ReadString();

		cout << "\nEnter PinCode        :  ";
		Client.PinCode = clsInputValidate<string>::ReadString();

		cout << "\nAcc. Balance Name    :  ";
		Client.AccountBalance = clsInputValidate<float>::ReadPositiveNumber();

	}



public:

	static void AddNewClient()
	{
		if (!CheckAccessRights(clsUsers::enPermissions::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("Add New Client Screen");

		cout << "\nPlease Enter AccountNumber: ";
		string AccountNumber = clsInputValidate<string>::ReadString();


		while (clsBankClients::IsExistClient(AccountNumber))
		{
			cout << "\nPlease Enter Another Account Number, Becuase (" << AccountNumber << ") Is Found: ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}
		
		clsBankClients Client = clsBankClients::GetAddNewMode(AccountNumber);
		
		 _GetClientInfo(Client);

		_PrintClientRecord(Client);

		clsBankClients::enSaveResults Result;

		Result = Client.Save();
		
		switch (Result)
		{
		case clsBankClients::enSaveResults::eFaildIsExist:
		{
			cout << "\nClinet Already Is Exist!\n";
			break;
		}
		case clsBankClients::enSaveResults::eSaveSuccessfully:
		{
			
			_PrintClientRecord(Client);

			cout << "\nClinet Added Successfully!\n";
			break;
		}
		case clsBankClients::enSaveResults::eFaildIsEmpty:
		{
			cout << "\nClient Record is Empty\n";
			break;
		}
		
		}

	}


};

