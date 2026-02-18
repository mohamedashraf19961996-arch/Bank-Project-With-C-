#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsCurency.h"
#include "clsIsInputValidate.h"
#include "clsPerson.h"
class clsFindCurrency:protected clsScreen
{
private:
	enum enChoic {
		enCurrencyCode=1,enCountryName=2
};
	static void _PrintCurrenyRecord(clsCurency Currency)
	{
		cout << "\Currency Card:";
		cout << "\n___________________";
		cout << "\nCountry Name   : " << Currency.GetCountryName();
		cout << "\nCurrency Code    : " << Currency.GetCountryCode();
		cout << "\nCurrency Name  : " << Currency.GetCurrencyName();
		cout << "\nRate       : " << Currency.GetCurrencyRate();
		cout << "\n___________________\n";







	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");
		cout << "Do you want to find Currency by [1] Currency code or [2] Country Name ?\n";
		short choice = clsIsInputValidate::ReadIntNumberBetween(1, 2, "invalid Number,Choose Number between[1]-[2] ");
		switch (choice)
		{
		case enChoic::enCurrencyCode:
		{
			string Currencycode;
			cout << "enter Currency code : ";
			Currencycode = clsIsInputValidate::ReadString();
			if (clsCurency::IsCurrencyExcisetByCode(Currencycode))
			{
				clsCurency Currency = clsCurency::FindByCode(Currencycode);

				_PrintCurrenyRecord(Currency);
			}
			else
			{
				cout << "this Currency is not found\n";
			}
			break;

		}
		case enChoic::enCountryName:
		{
			string CountryName;
			cout << "enter Country Name : ";
			CountryName = clsIsInputValidate::ReadString();
			if (clsCurency::IsCurrencyExcisetByCountryName(CountryName))
			{
				clsCurency Currency = clsCurency::FindByCountryName(CountryName);

				_PrintCurrenyRecord(Currency);
			}
			else
			{
				cout << "this Currency is not found\n";
			}
			break;

		}



		}
	}




};


