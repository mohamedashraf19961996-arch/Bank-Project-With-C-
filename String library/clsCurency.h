#pragma once
#include<iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsUtil.h"

class clsCurency
{
private:
	enum enMode {
		eUpdateMode = 1, eEmptyMode = 2
	};
	enMode _Mode;
	string _CountryName;
	string _CountryCode;
	string _CurrencyName;
	double _CurrenyRate;

	static clsCurency _ConvertLineToCurrencyObject(string Line, string seprator = "#//#")
	{
		vector<string>VCurrency;
		VCurrency = clsString::SplitString(Line, seprator);

		return clsCurency( eUpdateMode,VCurrency[0], VCurrency[1], VCurrency[2], stod(VCurrency[3]));

	}
	static vector<clsCurency>_LoadCurrencyDataFromFile()
	{
		vector<clsCurency>VCurrency;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurency Curency = _ConvertLineToCurrencyObject(Line);
				VCurrency.push_back(Curency);

			}

			MyFile.close();



		}

		return VCurrency;

	}
	static string _ConvertCurrencyObjectToLine(clsCurency Cuurency, string Seperator = "#//#")
	{

		string Record = "";
		Record += Cuurency.GetCountryName() + Seperator;
		Record += Cuurency.GetCountryCode() + Seperator;
		Record += Cuurency.GetCurrencyName() + Seperator;
		Record += to_string(Cuurency.GetCurrencyRate());

		return Record;

	};
	static void _SaveUserDataToFile(vector<clsCurency>VUsers)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsCurency& U : VUsers)
			{
				
				
					string Line = _ConvertCurrencyObjectToLine(U);

					MyFile << Line << endl;

				

			}

			MyFile.close();

		}





	}
	void _UpdateRate()
	{
		vector<clsCurency>VCurrency = _LoadCurrencyDataFromFile();

		for (clsCurency& U : VCurrency)
		{
			if (U.GetCountryCode() == _CountryCode)
			{
				U = *this;
				break;

			}



		}
		_SaveUserDataToFile(VCurrency);
	}
	static clsCurency _GetEmptyCurrencyObject()
	{

		return clsCurency(eEmptyMode, "", "","", 0);

	}


public:



	clsCurency(enMode Mode ,string CountryName, string Countrycode, string currenyName, float Currecnyrate)
	{
		_CountryName = CountryName;
		_CountryCode = Countrycode;
		_CurrencyName = currenyName;
		_CurrenyRate = Currecnyrate;
		_Mode = Mode;
	}
	string GetCountryName()
	{
		return _CountryName;

	}
	string GetCountryCode()
	{
		return _CountryCode;

	}
	string GetCurrencyName()
	{
		return _CurrencyName;

	}
	float GetCurrencyRate()
	{
		return _CurrenyRate;

	}
	void UpdateRate(float Rate)
	{
		_CurrenyRate = Rate;
		_UpdateRate();
	}
	static clsCurency FindByCountryName(string CountryName)
	{
		vector<clsCurency>VCurrency;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::LowerAllString(Currency.GetCountryName()) == clsString::LowerAllString(CountryName))
				{
					return Currency;
				}
				VCurrency.push_back(Currency);
			}
			MyFile.close();

		}
		return _GetEmptyCurrencyObject();

	}
	static clsCurency FindByCode(string CountryCode)
	{
		vector<clsCurency>VCurrency;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::LowerAllString(Currency.GetCountryCode()) == clsString::LowerAllString( CountryCode))
				{
					return Currency;
				}
				VCurrency.push_back(Currency);
			}
			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}
	bool IsEmpty()
	{

		if (_Mode == eEmptyMode)
		{
			return true;
		}
		else return false;

	}
	static bool IsCurrencyExcisetByCode(string CurrencyCode)
	{
		clsCurency Currency = FindByCode(CurrencyCode);

		return (!Currency.IsEmpty());

	}
	static bool IsCurrencyExcisetByCountryName(string CountryName)
	{
		clsCurency Currency = FindByCountryName(CountryName);

		return (!Currency.IsEmpty());

	}
	static vector<clsCurency>GetCurrencyList()
	{
		return _LoadCurrencyDataFromFile();
	}
};



