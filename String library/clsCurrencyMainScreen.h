#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsIsInputValidate.h"
#include "clsCurrencyList.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrency.h"
#include "clsCurrencyCalcExg.h"
class clsCurrencyMainScreen:protected clsScreen
{
private:
    enum enCurrencyMenue {
        eCurrenciesList=1,eFindCurrency=2,eUpdateCurrencyRate=3,eCurruncyCaluclatourEx=4,eMainMenue=5
    };
    static void _GoBackToCurrencyScreen()
    {
        cout << "press any key to go back to transaction screen\n";
        system("pause>0");
        ShowCurrencyMainScreen();



    }
    static void _ShowCurrencyList()
    {
        clsCurrencyList::ShowCurrencyList();
    }
    static void _ShowFindCurrency()
    {
        clsFindCurrency::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateCurrencyRate()
    {
        clsUpdateCurrency::UpdateCurrencyRate();
    }
    static void _ShowCurrencyCalculatorExg()
    {
        clsCurrencyCalcExg::ShowCurrencyCalculatorScreen();
    }
    static void _ShowMainMenue()
    {

    }

    static int _ReadCurrencyOption()
    {
        cout << setw(37) << left << "" << "Choose What do you want to do[1]-[5] : ";
        int Option = clsIsInputValidate::ReadIntNumberBetween(1, 5, "Invalid Number,Choose Number between [1]-[5]");
        return Option;




    }
    static bool   _PerformCurrencyMenueOptions(short Choice)
    {
        switch (Choice)
        {
        case enCurrencyMenue::eCurrenciesList:
        {
            system("cls");
            _ShowCurrencyList();
            _GoBackToCurrencyScreen();
            break;
        }
        case enCurrencyMenue::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrency();
            _GoBackToCurrencyScreen();
            break;
        }
        case enCurrencyMenue::eUpdateCurrencyRate:
        {
            system("cls");
            _ShowUpdateCurrencyRate();
            _GoBackToCurrencyScreen();
            break;
        }
        case enCurrencyMenue::eCurruncyCaluclatourEx:
        {
            system("cls");
            _ShowCurrencyCalculatorExg();
            _GoBackToCurrencyScreen();
            break;
        }
        case enCurrencyMenue::eMainMenue:
        {
            system("cls");

            return true;


        }

        system("cls");

        return true;


        }



    }

public:

	static void ShowCurrencyMainScreen()
	{
        system("cls");
        _DrawScreenHeader("Currency Main Screen");
        cout << setw(37) << left << "" << "===========================================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Menue\n";
        cout << setw(37) << left << "" << "===========================================================\n";
        cout << setw(37) << left << "" << "\t[1] Currencies List .\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Currency Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator Exchange.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================================\n";
        _PerformCurrencyMenueOptions((enCurrencyMenue)_ReadCurrencyOption());









	}



};

