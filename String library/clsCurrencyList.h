#pragma once
#include<iostream>
#include <iomanip>
#include "clsCurency.h"
#include"clsScreen.h"
class clsCurrencyList:protected clsScreen
{
private:
	static void PrintCurrencyRecord(clsCurency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.GetCountryName();
		cout << "| " << setw(10) << left << Currency.GetCountryCode();
		cout << "| " << setw(40) << left << Currency.GetCurrencyName();
		cout << "| " << setw(15) << left << Currency.GetCurrencyRate();
		


	}



public:

	static	void ShowCurrencyList()
	{
		vector<clsCurency>VCurrency = clsCurency::GetCurrencyList();
		string Title = "Currency List";
		string subTitle = " [ " + to_string(VCurrency.size()) + " ] Currency(s)";
		_DrawScreenHeader(Title, subTitle);
		cout << setw(8) << left << "\n_______________________________________________________________";
		cout << "__________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country Name";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Currency";
		cout << "| " << left << setw(15) << "Rate";
		cout << setw(8) << left << "\n_______________________________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (VCurrency.size() == 0)
		{
			cout << "No Currency Excist\n";

		}
		else
		{
			for (clsCurency& C : VCurrency)
			{
				PrintCurrencyRecord(C);
				cout << endl;

			}
			cout << setw(8) << left << "\n_______________________________________________________________";
			cout << "__________________________________________________\n" << endl;

		}


	}



};

