#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsBankUsers.h"
#include <iomanip>
#include "clsIsInputValidate.h"
class clsAddNewUserScreen:protected clsScreen
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
	static int _GiveUserPermition()
	{
		int Permition = 0;
		char Answer = 'n';
		cout << "what features do you want to give this User Access\n";
		cout << "Show Clients List [y]-[n]"; cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permition |= 1;
		}
		cout<<"Add New Client [y]-[n]"; cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permition |= 2;
		}
		cout << "Delete Client [y]-[n]"; cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permition |= 4;
		}
		cout << "Find Client [y]-[n]"; cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permition |= 8;
		}
		cout << "Update Client [y]-[n]"; cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permition |= 16;
		}
		cout << "Transaction [y]-[n]"; cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permition |= 32;
		}

		cout << "Manage Users [y]-[n]"; cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permition |= 64;
		}
		cout << "Log Register [y]-[n]"; cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permition |= 128;
		}
		cout << "Currency Menue [y]-[n]"; cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permition |= 256;
		}
		return Permition;
	}
	static void _ReadUserInfo(clsBankUsers & User)
	{

		cout << "enter your first Name ? ";
		User.FirstName = clsIsInputValidate::ReadString();

		cout << "enter your Last Name ? ";
		User.LastName = clsIsInputValidate::ReadString();

		cout << "enter your Email ? ";
		User.Email = clsIsInputValidate::ReadString();

		cout << "enter your Phone Number ? ";
		User.PhoneNumber = clsIsInputValidate::ReadString();

		cout << "enter your User Name ? ";
		User.UserName = clsIsInputValidate::ReadString();

		cout << "enter your User Password ";
		User.UserPassword = clsIsInputValidate::ReadString();
		char Answer = 'n';
		cout << "Do you want to give this User All permition\n";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			User.SetUserPermition(-1);
			return;
		}
		else
		{
			User.SetUserPermition(_GiveUserPermition());
		}
		



	}

public:

	static void AddNewUser()
	{
		_DrawScreenHeader("Add New User");
		cout << "enter User Name : ";
		string UserName = clsIsInputValidate::ReadString();

		while (clsBankUsers::IsUserExciset(UserName))
		{
			cout << "this User is excsit,enter another User Name : ";
			UserName = clsIsInputValidate::ReadString();
		}
		clsBankUsers NewUser = clsBankUsers::GetAddNewUserOpject(UserName);

		cout << "\nAdd New User\n";
		cout << "______________________\n";
		_ReadUserInfo(NewUser);

		clsBankUsers::enSaveResult SaveResult;

		SaveResult = NewUser.Save();
		_PrintUserRecord(NewUser);

		switch (SaveResult)
		{
		case clsBankUsers::svSucceed:
		{
			cout << "Added succed\n";
			break;
		}
		case clsBankUsers::svSaveFaildUserExeced:
		{
			cout << "your User Name is excist\n";
			break;
		}


		}









	}




};

