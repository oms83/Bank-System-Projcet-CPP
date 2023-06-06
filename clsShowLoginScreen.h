#pragma once
#include<iostream>
#include"clsUsers.h"
#include"clsInputValidate.h"
#include"clsString.h"
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsMainMenueScreen.h"
#include"clsGlobal.h"
using namespace std;

class clsShowLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		string UserName;
		string Password;
		bool Login = false;
		short Trails = 0;

		do
		{
			if (Login)
			{
				Trails++;

				if (Trails == 3)
				{
					return false;
				}

				cout << "\n\nYou Have " << 3 - Trails << " Invalid (UserName / Password)\n";
				
			}
			
			cout << "\n\nEnter User Name: ";
			UserName = clsInputValidate<string>::ReadString();
			cout << "Enter  PassWord: ";
			Password = clsInputValidate<string>::ReadString();

			CurrentUser = clsUsers::Find(UserName, Password);

			Login = CurrentUser.IsEmpty();


		} while (Login);

		
		CurrentUser.SaveLoginRegister();

		clsMainMenueScreen::ShowMainMenueScreen();
		
		return true;

		
	}


public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("   Login Screen");
		return _Login();
	}

};

