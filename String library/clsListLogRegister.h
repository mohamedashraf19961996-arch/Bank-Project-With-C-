#pragma once
#include <iostream>
#include"clsBankUsers.h"
#include "Global.h"
#include "clsString.h"
#include <vector>
#include"clsDate.h"
#include <string>
#include "clsScreen.h"
#include "clsUserLogin.h"
class clsListLogRegister:protected clsScreen 
{
private:
	static void _PrintRecord(clsUserLogin UserLogin)
	{
		cout << "| " << setw(25) << left << UserLogin.GetUserUserDate();
		cout << "| " << setw(25) << left << UserLogin.GetUserTime();
		cout << "| " << setw(15) << left << UserLogin.GetUserUserName();
		cout << "| " << setw(15) << left << UserLogin.GetUserUserPassword();
		cout << "| " << setw(10) << left << UserLogin.GetUserPermition();
		cout << "| " << setw(12) << left << UserLogin.GetUserUserStatue();



	}


public:

	static	void ShowLogRegisterList()
	{

		vector<clsUserLogin>VUserLogin = clsUserLogin::GetUserLoginData();
		string Title = "Log Register List";
		string subTitle = " [ " + to_string(VUserLogin.size()) + " ] Register(s)";
		_DrawScreenHeader(Title, subTitle);
		cout << setw(8) << left << "\n_______________________________________________________________";
		cout << "__________________________________________________\n" << endl;
		cout << "| " << left << setw(25) << "Date";
		cout << "| " << left << setw(25) << "Time";
		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(15) << "User Password";
		cout << "| " << left << setw(10) << "User Permition";
		cout << "| " << left << setw(12) << "User Statue";
		cout << setw(8) << left << "\n_______________________________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (VUserLogin.size() == 0)
		{
			cout << "No Client Excist\n";

		}
		else
		{
			for (clsUserLogin& U : VUserLogin)
			{

				_PrintRecord(U);
				cout << endl;

			}
			cout << setw(8) << left << "\n_______________________________________________________________";
			cout << "__________________________________________________\n" << endl;

		}

	}

};

