#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsBankClient.h"
#include "clsIsInputValidate.h"

class clsAddNewClient:protected clsScreen
{

private:

	static void _ReadClientInfo(clsBankClient& Client)
	{

		cout << "enter your first Name ? ";
		Client.FirstName = clsIsInputValidate::ReadString();

		cout << "enter your Last Name ? ";
		Client.LastName = clsIsInputValidate::ReadString();

		cout << "enter your Email ? ";
		Client.Email = clsIsInputValidate::ReadString();

		cout << "enter your Phone Number ? ";
		Client.PhoneNumber = clsIsInputValidate::ReadString();

		cout << "enter your Pin Code? ";
		Client.PinCode1 = clsIsInputValidate::ReadString();

		cout << "enter your Account Balance ? ";
		Client.AccountBalance1 = clsIsInputValidate::ReadDblNumber<float,string>();





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
	static void AddNewClient()
	{
		_DrawScreenHeader("Add New Client");
		cout << "enter Account Number : ";
		string AccountNumber = clsIsInputValidate::ReadString();

		while (clsBankClient::IsClientExcist(AccountNumber))
		{
			cout << "this Client is excsit,enter another Account Number : ";
			AccountNumber = clsIsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientOpject(AccountNumber);

		cout << "\nAdd New Client\n";
		cout << "______________________\n";
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResult SaveResult;

		SaveResult = NewClient.Save();
		_PrintClientRecord(NewClient);

		switch (SaveResult)
		{
		case clsBankClient::enAddedSucceed:
		{
			cout << "Added succed\n";
			break;
		}
		case clsBankClient::enSaveField:
		{
			cout << "your Account Number is excist\n";
			break;
		}


		}









	}


};

