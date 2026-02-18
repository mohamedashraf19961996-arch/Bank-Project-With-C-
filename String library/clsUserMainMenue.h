#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include"clsIsInputValidate.h"
#include "clsListUsers.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUser.h"
#include "clsUpdateUserScreen.h"
#include"clsFindUser.h"
class clsUserMainMenue:protected clsScreen
{
private:
	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};
	static int _ReadUserMenueChoice()
	{
		cout << setw(37) << left << "" << "choose Number between [1]-[6] : ";
		int choice = clsIsInputValidate::ReadIntNumberBetween<int,string>(1, 6, "Invaild Number,enter Number between [1]-[6]");

		return choice;




	}
	static void _GoBackToUsersMenue()
	{
		cout << "\npress any key to Go back to Users Manage Menue\n";
		system("pause>0");
		ShowUsersMenueScreen();

	}
	static void _ShowListUsersScreen()
	{
		clsListUsers::ShowClientList();
	}
	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::AddNewUser();
	}
	static void _ShowDeleteUserScreen()
	{
		clsDeleteUser::ShowDeleteClientScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::UpdateUserInfo();
	}
	static void _ShowFindUserScreen()
	{
		clsFindUser::ShowFindUserScreen();
	}
	
	static bool _PerformUserMenue(int Choice)
	{
		switch (Choice)
		{
		case enManageUsersMenueOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToUsersMenue();
			break;

		}
		case enManageUsersMenueOptions:: eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eMainMenue:
		{
			
			return true;

		}









		}







	 }
public:
	static void  ShowUsersMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("Users Screen");
		cout << setw(37) << left << "" << "===========================================================\n";
		cout << setw(37) << left << "" << "\t\t\tManage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Users List Screen.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================================\n";
		_PerformUserMenue((enManageUsersMenueOptions)_ReadUserMenueChoice());



	}


};

