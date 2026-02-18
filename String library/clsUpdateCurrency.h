#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsCurency.h"
#include "clsIsInputValidate.h"

class clsUpdateCurrency:protected clsScreen
{
private:


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

	static void UpdateCurrencyRate()
	{
		_DrawScreenHeader("Update Currency Rate");
		string CurrencyCode;
		cout << "enter Currency Code : ";
		CurrencyCode = clsIsInputValidate::ReadString();
		while (!clsCurency::IsCurrencyExcisetByCode(CurrencyCode))
		{
			cout << "Currency was Not found\n";
			cout << "enter Currency Code : ";
			CurrencyCode = clsIsInputValidate::ReadString();


		}
		clsCurency Currency=clsCurency::FindByCode(CurrencyCode);
		_PrintCurrenyRecord(Currency);
		cout << "enter New rate : ";
		float rate = clsIsInputValidate::ReadDblNumber<float, string>();
		Currency.UpdateRate(rate);
		cout << "Update Rate done succefully\n";
		cout << "the new Update Currency record : \n";
		_PrintCurrenyRecord(Currency);


	}


};

