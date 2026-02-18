#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsBankClient.h"
#include "clsIsInputValidate.h"
#include "clsPerson.h"
class clsFindClient:protected clsScreen
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

	static void ShowFindClientScreen()
	{
		_DrawScreenHeader("Find Client Screen");

		string AccountNumber;
		cout << "enter Account Number you want\n";
		getline(cin >> ws, AccountNumber);
		while (!clsBankClient::IsClientExcist(AccountNumber))
		{
			cout << "this client is not excist,enter another Account Number\n";
			getline(cin >> ws, AccountNumber);

		}
		clsBankClient Client =	clsBankClient::Find(AccountNumber);
		cout << "Account Number is Found :-)\n";
		_PrintClientRecord(Client);


	}


};

