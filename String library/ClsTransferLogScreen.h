#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "Global.h"
class ClsTransferLogScreen:protected clsScreen
{
private:

	static void PrintLogRecord(clsBankClient::stTransfirLogDate Log)
	{
		cout << "| " << left << setw(10) << Log.Amount;
		cout << "| " << left << setw(10) << Log.AccountNumber1;
		cout << "| " << left << setw(10) << Log.AccountNumber2;
		cout << "| " << left << setw(15) << Log.AccountBalance1;
		cout << "| " << left << setw(15) << Log.AccountBalance2;
		cout << "| " << left << setw(10) << Log.date;
		cout << "| " << left << setw(10) << Log.time;
		cout << "| " << left << setw(10) << Log.UserName;


	}





public:

	static	void ShowTransferLog()
	{
		vector<clsBankClient::stTransfirLogDate>VLog = clsBankClient::GetTransferLogDataFromFile();
		string Title = "Transfir Log";
		string subTitle = " [ " + to_string(VLog.size()) + " ] Log(s)";
		_DrawScreenHeader(Title, subTitle);
		cout << setw(8) << left << "\n_______________________________________________________________";
		cout << "__________________________________________________\n" << endl;
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "Ac.N 1";
		cout << "| " << left << setw(10) << "Ac.N 2";
		cout << "| " << left << setw(15) << "Ac.B 1";
		cout << "| " << left << setw(15) << "Ac.B 2";
		cout << "| " << left << setw(10) << "Date";
		cout << "| " << left << setw(10) << "Time";
		cout << "| " << left << setw(10) << "User Name";
		cout << setw(8) << left << "\n_______________________________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (VLog.size() == 0)
		{
			cout << "No Log Excist\n";

		}
		else
		{
			for (clsBankClient::stTransfirLogDate& L : VLog)
			{
				PrintLogRecord(L);
				cout << endl;

			}
			cout << setw(8) << left << "\n_______________________________________________________________";
			cout << "__________________________________________________\n" << endl;

		}


	}






};

