#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsIsInputValidate.h"
#include"clsBankClient.h"
class clsTransactionBetweenAccounts:protected clsScreen
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

	static void ShowTransactionBetweenAccountsScreen()
	{

		cout << "enter Account Number you want to withdraw from : ";
		string AccountNumber = clsIsInputValidate::ReadString();
		while (!clsBankClient::IsClientExcist(AccountNumber))
		{
			cout << "this Client is Not excist,enter Another One : ";
			AccountNumber = clsIsInputValidate::ReadString();
		}
		cout<< "enter Account Number you want to deposite to : ";
		string AccountNumber2 = clsIsInputValidate::ReadString();
		while (!clsBankClient::IsClientExcist(AccountNumber2))
		{
			cout << "this Client is Not excist,enter Another One : ";
			AccountNumber2 = clsIsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		clsBankClient Client2 = clsBankClient::Find(AccountNumber2);

		_PrintClientRecord(Client);
		cout << endl;
		_PrintClientRecord(Client2);
		cout << "enter Amount of Money you want to withdraw : ";
		double Amount = clsIsInputValidate::ReadDblNumber<double, string>();
		if (Client.TransactionBetween2Clients(Client2, Amount))
		{
			
			clsBankClient::enSaveResult SaveResult;
			clsBankClient::enSaveResult SaveResult1;

			SaveResult=	Client.Save();
			SaveResult1=Client2.Save();
			if (SaveResult == clsBankClient::enSaveSucceed && SaveResult1 == clsBankClient::enSaveSucceed)
			{
				cout << "transaction done succefully\n";
			}
			else {
				cout << "transaction is not allowed,conect your bank \n";
			}

		}
		else {
			cout << "your Account balance is not enouph to do this transaction\n";

		}


	}



};

