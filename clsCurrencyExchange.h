#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"

using namespace std;

const string CurrencyFileName = "Currency.txt";

class clsCurrencyExchange
{
private:

	string _Code;
	string _Country;
	string _Name;
	float _Rate;

	enum enMode
	{
		eEmptyMode = 0,
		eUpdateMode = 1,
	};
	enMode _Mode;
	
	static clsCurrencyExchange _ConvetLineToCurrencyObject(string Line, string Separator = "#//#")
	{
		vector <string> vCurrency = clsString::Split(Line, Separator);

		return clsCurrencyExchange(enMode::eUpdateMode , vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrencyExchange Currency, string Separator = "#//#")
	{
		string Line = "";
		Line += Currency.Country + Separator;
		Line += Currency.Code + Separator;
		Line += Currency.Name + Separator;
		Line += to_string(Currency.Rate);

		return Line;
	}

	static vector <clsCurrencyExchange> _LoadCurrenciesDataFromFile()
	{
		vector <clsCurrencyExchange> vCurrency;

		fstream MyFile;
		MyFile.open("Currency.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				
				clsCurrencyExchange Currency = _ConvetLineToCurrencyObject(Line);
				vCurrency.push_back(Currency);

			}

			MyFile.close();
		}

		return vCurrency;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrencyExchange> vCurrency)
	{
		fstream MyFile;
		MyFile.open("Currency.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;
			for (clsCurrencyExchange& C : vCurrency)
			{
				Line = _ConvertCurrencyObjectToLine(C);

				MyFile << Line << endl;
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsCurrencyExchange> vCurrency = _LoadCurrenciesDataFromFile();
		
		fstream MyFile;
		MyFile.open("Currency.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsCurrencyExchange& C : vCurrency)
			{
				if (C.Code == Code)
				{
					C = *this;
					break;
				}
			}
			MyFile.close();
		}

		_SaveCurrencyDataToFile(vCurrency);
	}
	static clsCurrencyExchange _GetEmptyObject()
	{
		return clsCurrencyExchange(enMode::eEmptyMode, "", "", "", 0);
	}
public:
	clsCurrencyExchange(enMode Mode, string Country, string Code, string Name, float Rate)
	{
		_Mode = Mode;
		_Code = Code;
		_Country = Country;
		_Name = Name;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::eEmptyMode;
	}

	void SetRate(float Rate)
	{
		_Rate = Rate;
	}

	void SetCode(string Code)
	{
		_Code = Code;
	}

	void SetCountry(string Country)
	{
		_Country = Country;
	}

	void SetName(string Name)
	{
		_Name = Name;
	}

	string GetCountry()
	{
		return _Country;
	}
	
	string GetCode()
	{
		return _Code;
	}

	string GetName()
	{
		return _Name;
	}

	float GetRate()
	{
		return _Rate;
	}

	_declspec(property(get = GetName, put = SetName))string Name;
	_declspec(property(get = GetCode, put = SetCode))string Code;
	_declspec(property(get = GetCountry, put = SetCountry))string Country;
	_declspec(property(get = GetRate, put = SetRate))float Rate;

	static vector <clsCurrencyExchange> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	static clsCurrencyExchange FindByCode(string Code)
	{
		Code = clsString::UpperAllString(Code);

		vector <clsCurrencyExchange> vCurrency = _LoadCurrenciesDataFromFile();

		for (clsCurrencyExchange& C : vCurrency)
		{
			if (clsString::UpperAllString(C.Code) == Code)
			{
				return C;
			}
		}

		return _GetEmptyObject();
	}

	static clsCurrencyExchange FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		vector <clsCurrencyExchange> vCurrency = _LoadCurrenciesDataFromFile();

		for (clsCurrencyExchange& C : vCurrency)
		{
			if (clsString::UpperAllString(C.Country) == Country)
			{
				return C;
			}
		}

		return _GetEmptyObject();
	}

	static bool IsCurrencyExist(string Code)
	{
		clsCurrencyExchange Currency = FindByCode(Code);

		return !Currency.IsEmpty();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate);
	}

	float ConvertToOtherCurrency(float Amount, clsCurrencyExchange Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.Code == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.Rate);

	}

};