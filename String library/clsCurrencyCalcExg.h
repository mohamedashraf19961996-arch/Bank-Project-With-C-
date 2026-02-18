#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsCurency.h"
#include "clsIsInputValidate.h"

class clsCurrencyCalcExg:protected clsScreen
{
private:

	static void _PrintCurrenyRecord(clsCurency Currency,clsCurency Currency2,double Amount)
	{
		cout << "\Currency Card:";
		cout << "\n___________________";
		cout << "\nCurrency 1 : " << Currency.GetCurrencyName()<<endl;
		cout << "\nCurrency 2 : " << Currency2.GetCurrencyName()<<endl;
		cout << "\nAmount After exgange : " << Amount << " " << Currency2.GetCountryCode();
		cout << "\n___________________\n";
	}
	static double _CalculateRate(clsCurency Cur1,double Amount)
	{
		double AmountAfterExg;
		AmountAfterExg =Amount / Cur1.GetCurrencyRate();
		return AmountAfterExg;
	}
	static double _CalculatetheMoneyAfterExchangetodollar(double Amount,clsCurency Cur2)
	{
		double AmountAfter = Amount * Cur2.GetCurrencyRate();
		return AmountAfter;


	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		_DrawScreenHeader("CurrencyCalculatorScreen");
		cout << "enter Currency Code 1 : ";
		string CurrencyCode = clsIsInputValidate::ReadString();
		while (!clsCurency::IsCurrencyExcisetByCode(CurrencyCode))
		{
			cout << "this Currency is not found\n";
			cout << "enter Currency Code 1 : ";
			 CurrencyCode = clsIsInputValidate::ReadString();

		}
		cout << "enter Currency Code 2 : ";
		string CurrencyCode2 = clsIsInputValidate::ReadString();
		while (!clsCurency::IsCurrencyExcisetByCode(CurrencyCode2))
		{
			cout << "this Currency is not found\n";
			cout << "enter Currency Code 2 : ";
			CurrencyCode2 = clsIsInputValidate::ReadString();

		}
		clsCurency Currency1 = clsCurency::FindByCode(CurrencyCode);
		clsCurency Currency2 = clsCurency::FindByCode(CurrencyCode2);
		cout << "enter Amount you want to Calculate : ";
		double Amount = clsIsInputValidate::ReadDblNumber<double, string>();
		cout << endl;
		if (CurrencyCode2 == "USD")
		{
			double AmountAfterExg =	_CalculateRate(Currency1, Amount);
			cout << "the amount of " << Currency1.GetCurrencyName() << " is " << AmountAfterExg << " USD \n" << endl;
			_PrintCurrenyRecord(Currency1, Currency2, AmountAfterExg);
		}
		else
		{
			double AmountAfterExchangetodollar = _CalculateRate(Currency1, Amount);
			double AmountAfterExgangetoanotherCurrency = _CalculatetheMoneyAfterExchangetodollar(AmountAfterExchangetodollar, Currency2);
			cout << "the amount of " << Currency1.GetCurrencyName() << " is " 
				<< AmountAfterExgangetoanotherCurrency <<" " << Currency2.GetCountryCode()<<endl;
			_PrintCurrenyRecord(Currency1, Currency2, AmountAfterExgangetoanotherCurrency);

		}
		cout << "Do you want to Calculate again\n";
		char answer = 'n';
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			system("cls");
			ShowCurrencyCalculatorScreen();
		}




	}




};

