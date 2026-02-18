#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsBankUsers.h"
#include "clsIsInputValidate.h"
#include "clsPerson.h"
class clsFindUser:protected clsScreen
{
private:
	static void _PrintUserRecord(clsBankUsers User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.PhoneNumber;
		cout << "\nUser Name : " << User.UserName;
		cout << "\nPassword    : " << User.UserPassword;
		cout << "\nPermition     : " << User.UserPermition1;
		cout << "\n___________________\n";



	}


public:

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");

		string UserName;
		cout << "enter User Name you want\n";
		getline(cin >> ws, UserName);
		while (!clsBankUsers::IsUserExciset(UserName))
		{
			cout << "this client is not excist,enter another Account Number\n";
			getline(cin >> ws, UserName);

		}
		clsBankUsers User = clsBankUsers::Find(UserName);
		cout << "Account Number is Found :-)\n";
		_PrintUserRecord(User);


	}



};

