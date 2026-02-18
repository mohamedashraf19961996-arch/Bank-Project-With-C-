#pragma once
#include<iostream>
#include "clsIsInputValidate.h"
#include<iomanip>
#include "clsScreen.h"
#include "clsClientList.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include"clsFindClient.h"
#include"clsTransactionMenue.h"
#include"clsUserMainMenue.h"
#include "Global.h"
#include "clsUserLogin.h"
#include "clsListLogRegister.h"
#include "clsCurrencyMainScreen.h"
using namespace std;
class clsMainScreen :protected clsScreen
{
private:
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7,eLogRegister=8 ,eCurrencyMenue=9,eLogout = 10
	};
	static int _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose What do you want to do[1]-[10] : ";
		int Option = clsIsInputValidate::ReadIntNumberBetween<int>(1, 10, "Invalid Number,Choose Number between [1]-[10]");
		return Option;

	}
	static void _GiveMenuePermition(int MenuePermition)
	{
		if ((CurrentUser.GetUserPermition() & MenuePermition) != MenuePermition)
		{
			system("cls");
			_DrawScreenHeader("Access Denay,Contact your Admin");
			_BackToMainMenue();
		}
		


	}
	static void _ShowListClients()
	{
		
			clsClientList::ShowClientList();

	}
	static void _ShowAddNewClient()
	{
			clsAddNewClient::AddNewClient();
		
	}
	static void _DeleteClient()
	{
			clsDeleteClient::ShowDeleteClientScreen();
		
	}
	static void _UpdateClient()
	{
			clsUpdateClient::UpdateClientInfo();
		
	}
	static void _FindClient()
	{
			clsFindClient::ShowFindClientScreen();
		
	}
	static void _Transactions()
	{
		
			clsTransactionMenue::ShowTransactionsScreen();
		
	}
	static void _ManageUsers()
	{
		
		
			clsUserMainMenue::ShowUsersMenueScreen();
		
	}
	static void _LogOut()
	{

		
	}
	static void _ShowLogRegisterList()
	{

		clsListLogRegister::ShowLogRegisterList();


	}
	static void _BackToMainMenue()
	{
		cout << "press any key to back to main menue\n";
		system("pause>0");
		ShowMainMenueScreen();


	}
	static void _ShowCurrencyMenue()
	{
		clsCurrencyMainScreen::ShowCurrencyMainScreen();
	}
	static bool _PerformMainMenue(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListClients:
		{
			system("cls");
			_GiveMenuePermition(1);
			_ShowListClients();
			_BackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
		{
			system("cls");
			_GiveMenuePermition(2);
			_ShowAddNewClient();
			_BackToMainMenue();
			break;

		}
		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_GiveMenuePermition(4);
			_DeleteClient();
			_BackToMainMenue();
			break;
		}
		case enMainMenueOptions::eUpdateClient:
		{
			system("cls");
			_GiveMenuePermition(8);
			_UpdateClient();
			_BackToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			system("cls");
			_GiveMenuePermition(16);
			_FindClient();
			_BackToMainMenue();
			break;
		}
		case enMainMenueOptions::eShowTransactionsMenue:
		{
			system("cls");
			_GiveMenuePermition(32);
			_Transactions();
			_BackToMainMenue();
			break;
		}
		case enMainMenueOptions::eManageUsers:
		{
			system("cls");
			_GiveMenuePermition(64);
			_ManageUsers();
			_BackToMainMenue();
			break;
		}case enMainMenueOptions::eLogRegister:
		{
			system("cls");
			_GiveMenuePermition(128);
			_ShowLogRegisterList();
			_BackToMainMenue();
			break;

		}
		case enMainMenueOptions::eCurrencyMenue:
		{
			system("cls");
			_GiveMenuePermition(256);
			_ShowCurrencyMenue();
			_BackToMainMenue();
			break;

		}
		case enMainMenueOptions::eLogout:
		{
			
			system("cls");
			/*_LogOut();*/
			return true;
			break;
			
			
		}






		}




	}




public:

	static bool  ShowMainMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");
		cout << setw(37) << left << "" << "===========================================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List Screen.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Register Log.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Menue.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================================\n";
		return _PerformMainMenue((enMainMenueOptions)_ReadMainMenueOption());



	}




};

