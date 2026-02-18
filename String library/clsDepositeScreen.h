#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsIsInputValidate.h"
#include"clsBankClient.h"
class clsDepositeScreen:protected clsScreen
{
private:

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "enter Account Number\n";
		getline(cin >> ws, AccountNumber);
		return AccountNumber;



	}
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

	static void ShowDepositeScreen()
	{
		_DrawScreenHeader("Deposite Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExcist(AccountNumber))
		{
			cout << "this client is not excist\n";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client=clsBankClient::Find(AccountNumber);
		_PrintClientRecord(Client);
		cout << "please enter amount to deposite\n";
		double Amount= clsIsInputValidate::ReadDblNumber<double, string>();
		cout << "Are you sure you want to do this transaction\n";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Client.Deposite(Amount);
			cout << "Deposite done succefully\n";
			cout << "Account Balance is " << Client.AccountBalance1 << endl;
		}


	}




};

