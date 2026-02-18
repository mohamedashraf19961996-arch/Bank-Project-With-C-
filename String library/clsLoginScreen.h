#pragma once
#include <iostream>
#include<iomanip>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsUserLogin.h"
class clsLoginScreen :protected clsScreen
{
private:

	static bool _Login()
	{
		short LoginFailedCounter = 0;

		bool LoginFailed = false;

		do
		{
			if (LoginFailed)
			{
				LoginFailedCounter++;
				cout << "User Name|User Password is Invaild\n";
				cout << "you have " << 3-LoginFailedCounter << " trail(S)\n";
			}
			if (LoginFailedCounter == 3)
			{
				cout << "You are Locked\n";
				return false;
			}
			string UserName, UserPassword;
			cout << "enter User Name\n";
			UserName = clsIsInputValidate::ReadString();
			cout << "enter User Password\n";
			UserPassword = clsIsInputValidate::ReadString();
			CurrentUser = clsBankUsers::Find(UserName, UserPassword);
			LoginFailed = CurrentUser.IsEmpty();
		





		} while (LoginFailed);

		clsUserLogin UserLogin;
		UserLogin.LogIn();
		return clsMainScreen::ShowMainMenueScreen();
		


	}
	static void _GoBackToLogin()
	{
		cout << "Press any key to go back to login Screen\n";
		system("pause>0");
		ShowLoginScreen();


	}
	

public:
	static bool ShowLoginScreen()
	{
			system("cls");	
			_DrawScreenHeader("Login Screen");
			_Login();
			clsUserLogin UserLogin;
			UserLogin.LogOut();
			CurrentUser = clsBankUsers::Find("", "");
			return true;
				
			

			
	}


};

