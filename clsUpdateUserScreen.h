#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsPerson.h"
#include"clsScreen.h"
#include"clsUsers.h"

using namespace std;


class clsUpdateUserScreen : protected clsScreen
{

private:


		static void _GetPermissinos(clsUsers& User)
		{
			cout << "Enter Permissinos: \n\n";

			char Answer = 'Y';
			cout << "Do you want to give full access [Y/N] ? ";
			cin >> Answer;

			cout << "\nDo you want to give access to: \n\n";
			User.Permissions = 0;

			if (toupper(Answer) == 'Y')
			{
				User.Permissions = clsUsers::enPermissions::eAll;
			}
			else
			{
				cout << "\nShow Client List [Y/N]? ";
				cin >> Answer;
				if (toupper(Answer) == 'Y')
				{
					User.Permissions += clsUsers::enPermissions::pListClients;
				}

				cout << "\nAdd New Client [Y/N]? ";
				cin >> Answer;
				if (toupper(Answer) == 'Y')
				{
					User.Permissions += clsUsers::enPermissions::pAddNewClient;
				}

				cout << "\nDelete Client [Y/N]? ";
				cin >> Answer;
				if (toupper(Answer) == 'Y')
				{
					User.Permissions += clsUsers::enPermissions::pAddNewClient;
				}

				cout << "\nUpdate Client [Y/N]? ";
				cin >> Answer;
				if (toupper(Answer) == 'Y')
				{
					User.Permissions += clsUsers::enPermissions::pUpdateClient;
				}

				cout << "\nFind Client [Y/N]? ";
				cin >> Answer;
				if (toupper(Answer) == 'Y')
				{
					User.Permissions += clsUsers::enPermissions::pFindClient;
				}

				cout << "\nTransection [Y/N]? ";
				cin >> Answer;
				if (toupper(Answer) == 'Y')
				{
					User.Permissions += clsUsers::enPermissions::pTransection;
				}

				cout << "\nManager Users [Y/N]? ";
				cin >> Answer;
				if (toupper(Answer) == 'Y')
				{
					User.Permissions += clsUsers::enPermissions::pManagerUsers;
				}

				cout << "\nLogin Register List [Y/N]? ";
				cin >> Answer;
				if (toupper(Answer) == 'Y')
				{
					User.Permissions += clsUsers::enPermissions::pLoginRegisterList;
				}

				cout << "\nCurrency Exchange [Y/N]? ";
				cin >> Answer;
				if (toupper(Answer) == 'Y')
				{
					User.Permissions += clsUsers::enPermissions::pCurrencyExchange;
				}

				if (User.Permissions == 511)
				{
					User.Permissions = clsUsers::enPermissions::eAll;
				}

			}

		}

		static void _ReadUserInfo(clsUsers& User)
		{
			cout << "\nEnter First Name: ";
			User.FirstName = clsInputValidate<string>::ReadString();

			cout << "\nEnter Last Name: ";
			User.LastName = clsInputValidate<string>::ReadString();

			cout << "\nEnter Email: ";
			User.Email = clsInputValidate<string>::ReadString();

			cout << "\nEnter Phone: ";
			User.Phone = clsInputValidate<string>::ReadString();

			cout << "\nEnter Password: ";
			User.Password = clsInputValidate<string>::ReadString();

			_GetPermissinos(User);


		}

		static void _Print(clsUsers User)
		{
			cout << "\n\n__________________________________________________\n";
			cout << setw(20) << "" << "Clinet Card";
			cout << "\n__________________________________________________\n";
			cout << "\nFirstName   : " << User.FirstName;
			cout << "\nLastName    : " << User.LastName;
			cout << "\nFull Name   : " << User.FullName();
			cout << "\nEmail       : " << User.Email;
			cout << "\nPhone       : " << User.Phone;
			cout << "\nUser Name   : " << User.UserName;
			cout << "\nPassword    : " << User.Password;
			cout << "\nPermissions : " << User.Permissions;
			cout << "\n__________________________________________________\n\n";
		}




public:

    static void UpdateUser()
    {


        _DrawScreenHeader("Update Users Screen");

        cout << "\nEnter User Name: ";
        string AccountNumber = clsInputValidate<string>::ReadString();

        while (!clsUsers::IsUserExist(AccountNumber))
        {
            cout << "\n (" << AccountNumber << ") User Name is not found please enter another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }

        clsUsers User = clsUsers::Find(AccountNumber);

        _Print(User);

        char Answer = 'Y';



		_ReadUserInfo(User);


        clsUsers::enSaveResults Results;
        Results = User.Save();

        switch (Results)
        {
        case clsUsers::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError user was not saved because it's Empty";
            _Print(User);
            break;
        }


        case clsUsers::enSaveResults::svSucceeded:
        {
            cout << "\nuser Updated Successfully :-)\n";
            _Print(User);
            break;
        }

        }

    }
};

