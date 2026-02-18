#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsBankClient.h"
#include "clsIsInputValidate.h"

class clsDeleteClient:protected clsScreen
{
private:
	static void _PrintClientRecord(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.PhoneNumber;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode1;
		cout << "\nBalance     : " << Client.AccountBalance1;
		cout << "\n___________________\n";



	}

public:

	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("Delete Client Screen");
		cout << "enter Account Number : ";
		string AccountNumber = clsIsInputValidate::ReadString();
		while (!clsBankClient::IsClientExcist(AccountNumber))
		{
			cout << "this Account Number is Not Excist\n";
			AccountNumber = clsIsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientRecord(Client);
		char Answer = 'n';
		cout << "Are you sure you want to delete this Account Number\n";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			if (Client.Delete())
			{
				cout << "Account Number is Deleted succesfully\n";
				Client.GetEmptyClientObject();
			}
			else {
				cout << "Account Number is not deleted try again\n";

			}



		}






	}


};

