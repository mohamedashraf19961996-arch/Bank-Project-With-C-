#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsBankClient.h"
#include "clsIsInputValidate.h"

class clsUpdateClient:protected clsScreen
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
		Client.AccountBalance1 = clsIsInputValidate::ReadDblNumber<float, string>();





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
	static void UpdateClientInfo()
	{
		_DrawScreenHeader("Update Client Screen");
		string AccountNumber;
		cout << "enter Account Number you want to update : ";
		AccountNumber = clsIsInputValidate::ReadString();

		while (!clsBankClient::IsClientExcist(AccountNumber))
		{
			cout << "wrong Account Number,enter another Account Number : ";
			AccountNumber = clsIsInputValidate::ReadString();


		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientRecord(Client);

		cout << "\n\nUpdate Client Info\n";
		cout << "___________________________\n";
		_ReadClientInfo(Client);

		clsBankClient::enSaveResult SaveResult;
		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveSucceed:
		{
			_PrintClientRecord(Client);
			cout << "your update is done succefully\n";
			break;
		}
		case clsBankClient::enSaveField:
		{
			cout << "Update is faild,because Client is empty\n";
			break;
		}



		}

	}




};

