#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"clsPerson.h"
#include"clsInputValidate.h"
#include"clsString.h"
#include"clsUtil.h"
#include"clsDate.h"
#include"clsTime.h"

const string UsersFileName = "Users.txt";
const string LoginRegisterFileName = "Register.txt";

class clsUsers :public clsPerson
{
private:
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedToDelete = false;

	enum enMode { EmptyMode = 1, UpdateMode = 2, AddNewMode = 3 };

	enMode _Mode;

	static clsUsers _ConverLineToUserObject(string Line, string Separator = "#//#")
	{
		vector <string> vUser = clsString::Split(Line, Separator);
		return clsUsers(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], clsUtil::DecryptText(vUser[5], 2), stoi(vUser[6]));

	}

	static vector <clsUsers> _LoadUserDataFromFile()
	{

		vector <clsUsers> vUser;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUsers User = _ConverLineToUserObject(Line);
				vUser.push_back(User);
			}
			MyFile.close();
		}

		return vUser;
	}

	static clsUsers _GetEmptyUserObject()
	{
		return clsUsers(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertUserObjectToLine(clsUsers User, string Separator = "#//#")
	{
		string Line = "";
		Line += User.FirstName + Separator;
		Line += User.LastName + Separator;
		Line += User.Email + Separator;
		Line += User.Phone + Separator;
		Line += User._UserName + Separator;
		Line += clsUtil::EncryptText(User.Password, 2) + Separator;
		Line += to_string(User._Permissions);

		return Line;
	}

	static void _SaveUsersDateToFile(vector <clsUsers> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;
			for (clsUsers& U : vUsers)
			{
				if (U._MarkedToDelete == false)
				{
					Line = _ConvertUserObjectToLine(U);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	void _AddUserDateLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::app | ios::out);
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
		}
		MyFile.close();
	}

	void _AddNew()
	{
		_AddUserDateLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _Update()
	{
		vector <clsUsers> vUsers = _LoadUserDataFromFile();

		for (clsUsers& User : vUsers)
		{
			if (User._UserName == _UserName)
			{
				User = *this;
				break;
			}
		}

		_SaveUsersDateToFile(vUsers);

	}

	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{

		stLoginRegisterRecord LoginRegisterRecord;


		vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2], 2);
		LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

		return LoginRegisterRecord;

	}

	string _PrepareLoginRecord(string Separator = "#//#")
	{
		string Line = "";
		Line += clsDate::DateToString(clsDate()) + "-" + clsTime::StringTime(clsTime()) + Separator;
		Line += UserName + Separator;
		Line += clsUtil::EncryptText(Password, 2) + Separator;
		Line += to_string(Permissions);

		return Line;
	}



public:

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransection = 32, pManagerUsers = 64,
		pLoginRegisterList = 128, pCurrencyExchange = 256

	};

	clsUsers(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}
	
	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	void SetUserPassword(string Password)
	{
		_Password = Password;
	}

	void SetUserPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	string GetUserName()
	{
		return _UserName;
	}

	string GetPassword()
	{
		return _Password;
	}

	int GetPermission()
	{
		return _Permissions;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	__declspec(property(get = GetPassword, put = SetUserPassword)) string Password;
	__declspec(property(get = GetPermission, put = SetUserPermissions)) int Permissions;

	static clsUsers Find(string UserName, string Password = "")
	{
		vector <clsUsers> vUsers = _LoadUserDataFromFile();

		if (Password == "")
		{
			for (clsUsers& User : vUsers)
			{
				if (User._UserName == UserName)
				{
					return User;
				}
			}
		}
		
		else if (Password != "")
		{
			for (clsUsers& User : vUsers)
			{
				if (User._UserName == UserName && User.Password == Password)
				{
					return User;
				}
			}
		}

		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		vector <clsUsers> vUsers = _LoadUserDataFromFile();

		for (clsUsers& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				return true;
			}
		}


		return false;
	}

	static vector <clsUsers> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}

	
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
			break;
		}
		case enMode::UpdateMode:
		{
			//_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserNameExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
			}


			break;
		}
		}
	}

	
	static clsUsers GetAddNewClientObject(string UserName)
	{
		return clsUsers(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete()
	{
		vector <clsUsers> vUsers = _LoadUserDataFromFile();

		fstream MyFile;

		string Line;

		for (clsUsers& U : vUsers)
		{
			if (U.GetUserName() == _UserName)
			{
				U._MarkedToDelete = true;
				break;
			}
		}
		_SaveUsersDateToFile(vUsers);
		*this = _GetEmptyUserObject();

		return true;
	}

	bool CheckToPremissions(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
		{
			return true;
		}
		else if ((this->Permissions & Permission) == Permission)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void SaveLoginRegister()
	{
		string Line = _PrepareLoginRecord();

		fstream MyFile;
		MyFile.open("Register.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	static vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLogin;

		fstream MyFile;

		MyFile.open("Register.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				
				stLoginRegisterRecord Login = _ConvertLoginRegisterLineToRecord(Line);

				vLogin.push_back(Login);

			}
		}

		return vLogin;

	}
	
};

