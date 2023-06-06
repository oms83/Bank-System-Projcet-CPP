#pragma once
#include<iostream>
#include<vector>
#include"clsUsers.h"
#include"clsInputValidate.h"
#include"clsString.h"
#include"clsScreen.h"
#include"clsUsers.h"
using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{

private:

    static void PrintLoginRegisterListRecord(clsUsers::stLoginRegisterRecord LoginRegister)
    {
        cout << "| " << setw(20) << left << LoginRegister.DateTime;
        cout << "| " << setw(10) << left << LoginRegister.UserName;
        cout << "| " << setw(20) << left << LoginRegister.Password;
        cout << "| " << setw(8) << left << LoginRegister.Permissions;
    }



public:

    static void LoginRegisterList()
    {
        if (!CheckAccessRights(clsUsers::enPermissions::pLoginRegisterList))
        {
            return;
        }

        vector <clsUsers::stLoginRegisterRecord> vLoginRegister = clsUsers::GetLoginRegisterList();

        string Title = "Login Register List Screen";
        string SubTitle = "(" + to_string(vLoginRegister.size()) + ") Record(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n" << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";
        cout << setw(6) << left << "";
        cout << "| " << setw(20) << left << "Date/Time";
        cout << "| " << setw(10) << left << "User Name";
        cout << "| " << setw(20) << left << "Password";
        cout << "| " << setw(8) << left << "Permissions";
        cout << "\n";
        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";


        if (vLoginRegister.size() == 0)
        {
            cout << setw(6) << left << "No Record Available In The System\n";
        }
        else
        {
            for (clsUsers::stLoginRegisterRecord& C : vLoginRegister)
            {
                cout << setw(6) << left << "";
                PrintLoginRegisterListRecord(C);
                cout << "\n";
            }
        }

        cout << setw(6) << left << "" << "__________________________________________________";
        cout << "____________________________________________________________\n";
    }
};

