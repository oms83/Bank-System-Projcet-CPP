#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
#include"clsTime.h"
#include"clsDate.h"

using namespace std;

const string ClinetsFileName = "Clients.txt";
const string TransfersLogFileName = "Transfer.txt";

class clsBankClients : public clsPerson
{

private:
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedToDelete = false;

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	static clsBankClients _ConvertLineDataToClientObject(string Line, string Separator = "#//#")
	{
		vector <string> sClient = clsString::Split(Line, Separator);
		return clsBankClients(enMode::UpdateMode, sClient[0], sClient[1], sClient[2], sClient[3], sClient[4], sClient[5], stof(sClient[6]));

	}

	static vector <clsBankClients>_LoadClientDataFromFile()
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		vector <clsBankClients> vClients;

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClients Client = _ConvertLineDataToClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}

		return vClients;
	}

	static clsBankClients _GetEmptyObject()
	{
		return clsBankClients(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertClientRecordToLine(clsBankClients Client, string Separator = "#//#")
	{
		string Line = "";

		Line += Client.FirstName + Separator;
		Line += Client.LastName + Separator;
		Line += Client.Email + Separator;
		Line += Client.Phone + Separator;
		Line += Client._AccountNumber + Separator;
		Line += Client._PinCode + Separator;
		Line += to_string(Client._AccountBalance);

		return Line;
	}

	static void _SaveClientDateToFile(vector <clsBankClients> vClient)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;
			for (clsBankClients& Client : vClient)
			{
				if (Client._MarkedToDelete != true)
				{
					Line = _ConvertClientRecordToLine(Client);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	void _AddNewClient()
	{
		_SaveOneClientDateToFile(*this);
	}

	void _Update()
	{
		vector <clsBankClients> vClients = _LoadClientDataFromFile();
		for (clsBankClients& Client : vClients)
		{
			if (Client._AccountNumber == _AccountNumber)
			{
				Client = *this;
			}
		}

		_SaveClientDateToFile(vClients);
	}

	static void _SaveOneClientDateToFile(clsBankClients Client)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			string Line = _ConvertClientRecordToLine(Client);;
			MyFile << Line << endl;

			MyFile.close();
		}
	}

	struct stTransferRecord;
	static stTransferRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferRecord TrnsferLogRecord;

		vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
		TrnsferLogRecord.dTime = vTrnsferLogRecordLine[0];
		TrnsferLogRecord.sAccountNumber = vTrnsferLogRecordLine[1];
		TrnsferLogRecord.dAccountNumber = vTrnsferLogRecordLine[2];
		TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		TrnsferLogRecord.sAccountBalance = stod(vTrnsferLogRecordLine[4]);
		TrnsferLogRecord.dAccountBalance = stod(vTrnsferLogRecordLine[5]);
		TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

		return TrnsferLogRecord;

	}

	string _PrepareTransferRecord(float Amount, clsBankClients DestinationClient, string UserName, string Seperator = "#//#")
	{
		string Line = "";
		Line += clsDate::DateToString(clsDate()) + "-" + clsTime::StringTime(clsTime()) + Seperator;
		Line += _AccountNumber + Seperator;
		Line += DestinationClient._AccountNumber + Seperator;
		Line += to_string(Amount) + Seperator;
		Line += to_string(_AccountBalance)+Seperator;
		Line += to_string(DestinationClient._AccountBalance) + Seperator;
		Line += UserName;

		return Line;

	}

	void _RegisterTransferLog(float Amount, clsBankClients DestinationClient, string UserName)
	{

		string stDataLine = _PrepareTransferRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("Transfer.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}



//--------------------------------------------------------------------------------------------------------------------------------------------

public: 
		
	struct stTransferRecord
	{
		string dTime;
		string sAccountNumber;
		string dAccountNumber;
		float sAccountBalance;
		float dAccountBalance;
		float Amount;
		string UserName;
	};


//				     1              2                3				 4             5             6                      7             8		
	clsBankClients(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	static clsBankClients Find(string AccountNumber, string PinCode="")
	{
	
		if (PinCode == "")
		{
			vector <clsBankClients> vClient = _LoadClientDataFromFile();

			for (clsBankClients& Client : vClient)
			{
				if (Client.GetAccountNumber() == AccountNumber)
				{
					return Client;
				}
			}
		}
		else if(PinCode!="")
		{
			vector <clsBankClients> vClient = _LoadClientDataFromFile();

			for (clsBankClients& Client : vClient)
			{
				if (Client.GetAccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					return Client;
				}
			}
		}

		return _GetEmptyObject();
	}

	static bool IsExistClient(string AccountNumber)
	{
		clsBankClients Client = Find(AccountNumber);
		return !Client.IsEmpty();
	}

	enum enSaveResults { eFaildIsExist = 1, eSaveSuccessfully = 2, eFaildIsEmpty = 3 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClients::enMode::EmptyMode:
		{
			return eFaildIsEmpty;
			break;
		}
		case clsBankClients::enMode::UpdateMode:
		{

			_Update();

			return eSaveSuccessfully;
			break;
		}

		case clsBankClients::enMode::AddNewMode:
		{
			if (IsExistClient(_AccountNumber))
			{
				return eFaildIsExist;
			}
			else if (this->IsEmpty())
			{
				return eFaildIsEmpty;
			}
			else
			{
				_AddNewClient();

				_Mode = enMode::UpdateMode;

				return eSaveSuccessfully;
			}
		}
		
			break;
		}
	}


	bool Delete()
	{
		vector <clsBankClients> vClients = _LoadClientDataFromFile();
		for (clsBankClients& Client : vClients)
		{
			if (Client._AccountNumber == _AccountNumber)
			{
				Client._MarkedToDelete = true;
			}
		}

		_SaveClientDateToFile(vClients);

		*this = _GetEmptyObject();

		return true;
	}
	

	static clsBankClients GetAddNewMode(string AccountNumber)
	{
		return clsBankClients(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector <clsBankClients> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}

	void Deposit(float Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	void Withdraw(float Amount)
	{
		_AccountBalance -= Amount;
		Save();
	}

	static float TotalBalances()
	{
		float Total = 0;

		vector <clsBankClients> vClients = _LoadClientDataFromFile();

		for (clsBankClients& Client : vClients)
		{
			Total += Client._AccountBalance;
		}

		return Total;
	}

	bool Transfer(float Amount, clsBankClients &Client, string UserName)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}

		this->Withdraw(Amount);

		Client.Deposit(Amount);

		_RegisterTransferLog(Amount, Client, UserName);
		return true;
	}

	static vector <stTransferRecord> GetTransferList()
	{
		vector <stTransferRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("Transfer.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stTransferRecord TransferRecord;

			while (getline(MyFile, Line))
			{

				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);

			}

			MyFile.close();

		}

		return vTransferLogRecord;
	}

};

