#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsIsInputValidate.h"
#include"clsBankClient.h"
#include "clsUtil.h"
class clsShowTotalBalance:protected clsScreen
{
private:
	static void _PrintClientsBalances(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance();
	}


public:

	static void ShowTotalBalance()
	{
		
		vector<clsBankClient>VClients = clsBankClient::GetClientData();
		_DrawScreenHeader("Total Balances Screen","Balances List( " + to_string(VClients.size()) + ") Client(s).");
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(25) << left << "" << "| "<< setw(15) << left << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (VClients.size() == 0)
		{
			cout << "No Client Excist\n";

		}
		else
		{

			for (clsBankClient& C : VClients)
			{
				_PrintClientsBalances(C);
				cout << endl;
			}
			cout << setw(25) << left << "" << "\t\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;

		}

		double TotalBalances = clsBankClient::GetTotalBalances();
		cout << "Total Balances : " << TotalBalances << endl;
		cout << clsUtil::NumberToText(TotalBalances) << endl;






	}




};

