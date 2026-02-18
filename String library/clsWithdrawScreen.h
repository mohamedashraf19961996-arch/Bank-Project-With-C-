#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsIsInputValidate.h"
#include"clsBankClient.h"
class clsWithdrawScreen:protected clsScreen
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");

		cout << "enter Account Number : ";
		string AccountNumber = clsIsInputValidate::ReadString();
		
		while (!clsBankClient::IsClientExcist(AccountNumber))
		{
			cout << "this Account Number is not excist,enter Another Account Number : ";
			AccountNumber = clsIsInputValidate::ReadString();
		}

		clsBankClient Client =clsBankClient::Find(AccountNumber);
		_PrintClientRecord(Client);
		double Amount;
		cout << "enter Amount you want to withdraw\n";
		cin >> Amount;
		while (Client.AccountBalance1 < Amount)
		{
			cout << "Cannot withdraw,Insuffecient balance : \n";
			cout << "your balance is : " << Client.AccountBalance1 << endl;
			cout << "Amount to Withdraw is : " << Amount << endl;
			cout << "enter Amount to Withdraw\n";
			cin >> Amount;
		}
		cout << "Are you sure you want to make this transaction\n";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Client.Withdraw(Amount);
			cout << "Withdraw done succefully\n";
			cout << "Your balance is " << Client.AccountBalance1 << endl;

		}
		

	}



};

