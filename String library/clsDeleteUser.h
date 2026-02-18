#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsBankUsers.h"
#include "clsIsInputValidate.h"

class clsDeleteUser:protected clsScreen
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
	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("Delete User Screen");
		cout << "enter User Name : ";
		string UserName = clsIsInputValidate::ReadString();
		cout << "enter Password : ";
		string UserPassword = clsIsInputValidate::ReadString();
		while (!clsBankUsers::IsUserExciset(UserName,UserPassword)||UserName=="Admin")
		{
			cout << "this User Name is Not Excist Or You can not delete Admin\n";
			UserName = clsIsInputValidate::ReadString();

			cout << "enter Password : ";
			string UserPassword = clsIsInputValidate::ReadString();
		}
		
		clsBankUsers User = clsBankUsers::Find(UserName,UserPassword);
		_PrintUserRecord(User);
		char Answer = 'n';
		cout << "Are you sure you want to delete this User \n";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			if (User.Delete())
			{
				cout << "User is Deleted succesfully\n";
				User.GetEmptyClientObject();
			}
			else {
				cout << "User is not deleted try again\n";

			}



		}






	}






};

