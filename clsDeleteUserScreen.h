#pragma once
#include<iostream>
#include"clsUsers.h"
#include"clsInputValidate.h"
#include"clsString.h"
#include"clsScreen.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:

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

    static void DeleteUser()
    {


        _DrawScreenHeader("Delete User Screen");

        cout << "\nEnter User name: ";
        string UserName = clsInputValidate<string>::ReadString();

        while (!clsUsers::IsUserExist(UserName))
        {
            cout << "\n (" << UserName << ") User name is not found please enter another one: ";
            UserName = clsInputValidate<string>::ReadString();
        }

        clsUsers User = clsUsers::Find(UserName);

        _Print(User);

        char Answer = 'Y';



        cout << "\nAre you sure, you want to delete this User [Y/N] ? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nAccount deleted Successfully :-)\n";
                _Print(User);
            }
            else
            {
                cout << "\nError User was not deleted :-(\n";
            }

        }
        else
        {
            cout << "\nThe options has been cancelled :-)\n";
        }

    }

};

