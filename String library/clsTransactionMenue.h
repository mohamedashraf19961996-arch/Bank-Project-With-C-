#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsIsInputValidate.h"
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include "clsShowTotalBalance.h"
#include "clsTransactionBetweenAccounts.h"
#include "ClsTransferLogScreen.h"
class clsTransactionMenue:protected clsScreen
{
private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3,eTransactionBetweenAcoount=4 ,eTransfirLog=5,eShowMainMenue = 6
    };
    static int _ReadTransactionOption()
    {
        cout << setw(37) << left << "" << "Choose What do you want to do[1]-[6] : ";
        string Message = "Invalid Number,Choose Number between [1]-[6]";
        int from = 1;
        int to = 6;
        int option=clsIsInputValidate::ReadIntNumberBetween<int>(from,to,Message);
        return option;



    }
    static void _GoBackToTransactionScreen()
    {
        cout << "press any key to go back to transaction screen\n";
        system("pause>0");
        ShowTransactionsScreen();



    }
    static void _ShowDepositeScreen()
    {
        clsDepositeScreen::ShowDepositeScreen();


    }
    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTotalBalanceScreen()
    {
        clsShowTotalBalance::ShowTotalBalance();
    }
    static void _ShowTransfirLogScreen()
    {
        ClsTransferLogScreen::ShowTransferLog();
    }
    static void _ShowTransactionBetweenAccounts()
    {

        clsTransactionBetweenAccounts::ShowTransactionBetweenAccountsScreen();

    }
    static void _ShowMainMenueScreen()
    {
        

    }
    static void _PerformTransactionsMenueOptions(enTransactionsMenueOptions Option)
    {
        switch (Option)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositeScreen();
            _GoBackToTransactionScreen();
            break;


        }
        case enTransactionsMenueOptions::eWithdraw:
        {

            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionScreen();
            break;
        }
        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionScreen();
            break;

        }case enTransactionsMenueOptions::eTransactionBetweenAcoount:
        {
            system("cls");
            _ShowTransactionBetweenAccounts();
            _GoBackToTransactionScreen();
            break;


        }
        case enTransactionsMenueOptions::eTransfirLog:
        {
            system("cls");
            _ShowTransfirLogScreen();
            _GoBackToTransactionScreen();
            break;




        }
        default :{break;}

        }






}
public:

    static void ShowTransactionsScreen()
    {
        system("cls");
        _DrawScreenHeader("Transactions Screen");
        cout << setw(37) << left << "" << "===========================================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
        cout << setw(37) << left << "" << "===========================================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposite.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transaction between Accounts.\n";
        cout << setw(37) << left << "" << "\t[5] Transfir Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================================\n";
        _PerformTransactionsMenueOptions((enTransactionsMenueOptions)_ReadTransactionOption());





    }




};

