#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
class clsClientList:protected clsScreen
{
private:
	static void PrintClientRecord(clsBankClient Client)
	{
		cout << setw(8) << left <<"" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.PhoneNumber;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode1;
		cout << "| " << setw(12) << left << Client.AccountBalance1;



	}


public :


	static	void ShowClientList()
	{
		vector<clsBankClient>VClient = clsBankClient::GetClientData();
		string Title = "Client List";
		string subTitle = " [ " + to_string(VClient.size()) + " ] Client(s)";
		_DrawScreenHeader(Title, subTitle);
		cout << setw(8)<<left<<"\n_______________________________________________________________";
		cout << "__________________________________________________\n" << endl;
cout << setw(8) << left<<""<< "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "\n_______________________________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (VClient.size() == 0)
		{
			cout << "No Client Excist\n";

		}
		else
		{
			for (clsBankClient& C : VClient)
			{
				PrintClientRecord(C);
				cout << endl;

			}
			cout << setw(8) << left << "\n_______________________________________________________________";
			cout << "__________________________________________________\n" << endl;

		}


	}





};

