#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsBankUsers.h"
#include <iomanip>
class clsListUsers :protected clsScreen
{
private:
	static void PrintUserRecord(clsBankUsers User)
	{
		cout << "| " <<setw(25) << left << User.FullName();
		cout << "| " << setw(25) << left << User.Email;
		cout << "| " << setw(15) << left << User.PhoneNumber;
		cout << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(10) << left << User.GetUserPassword();
		cout << "| " << setw(12) << left << User.UserPermition1;



	}


public:

	static	void ShowClientList()
	{
		
		vector<clsBankUsers>VUsers = clsBankUsers::GetUserList();
		string Title = "Users List";
		string subTitle = " [ " + to_string(VUsers.size()) + " ] User(s)";
		_DrawScreenHeader(Title, subTitle);
		cout << setw(8) << left << "\n_______________________________________________________________";
		cout << "__________________________________________________\n" << endl;
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(10) << "User Password";
		cout << "| " << left << setw(12) << "User Permition";
		cout << setw(8) << left << "\n_______________________________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (VUsers.size() == 0)
		{
			cout << "No Client Excist\n";

		}
		else
		{
			for (clsBankUsers& U : VUsers)
			{
				
				PrintUserRecord(U);
				cout << endl;

			}
			cout << setw(8) << left << "\n_______________________________________________________________";
			cout << "__________________________________________________\n" << endl;

		}


	}





};

