#pragma once
#include<iostream>
#include"clsUsers.h"
#include"clsInputValidate.h"
#include"clsString.h"
#include"clsScreen.h"
#include"clsUsers.h"

using namespace std;

class clsUsersListScreen : protected clsScreen
{

private:

    static void PrintUsersListRecord(clsUsers User)
    {
        cout << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(13) << left << User.Phone;
        cout << "| " << setw(10) << left << User.Permissions;
        cout << "| " << setw(25) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
    }



public:

    static void UsersList()
    {
        vector <clsUsers> vUsers = clsUsers::GetUsersList();

        string Title = "Users List Screen";
        string SubTitle = "(" + to_string(vUsers.size()) + ") User(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n" << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";
        cout << setw(6) << left << "";
        cout << "| " << setw(12) << left << "User Name";
        cout << "| " << setw(25) << left << "Full Name";
        cout << "| " << setw(13) << left << "Phone";
        cout << "| " << setw(25) << left << "Email";
        cout << "| " << setw(10) << left << "Password";
        cout << "| " << setw(10) << left << "Permissions";
        cout << "\n";
        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";


        if (vUsers.size() == 0)
        {
            cout << setw(6) << left << "No User Available In The System\n";
        }
        else
        {
            for (clsUsers& C : vUsers)
            {
                cout << setw(6) << left << "";
                PrintUsersListRecord(C);
                cout << "\n";
            }
        }

        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";
    }

};

