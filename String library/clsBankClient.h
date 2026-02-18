#pragma once
#include<iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"
class clsBankClient:public clsPerson
{
private:

	enum enMode{enEmptyMode=1,enUpdateMode=2,enAddNewMode=3};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;
	
	static clsBankClient _ConvertLineToClientObject(string Line,string seprator="#//#")
	{
		vector<string>VClient;
		VClient = clsString::SplitString(Line, seprator);

		return clsBankClient(VClient[0], VClient[1], VClient[2], VClient[3],
		enUpdateMode, VClient[4],clsUtil::DecryptText( VClient[5],4), stod(VClient[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient("", "", "", "",enEmptyMode, "", "", 0);

	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.PhoneNumber + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += clsUtil::EncryptText(Client._PinCode,4) + Seperator;
		stClientRecord += to_string(Client._AccountBalance);

		return stClientRecord;

	}

	static vector<clsBankClient>_LoadClientDataFromFile()
	{
		vector<clsBankClient>VClient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);



		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				VClient.push_back(Client);

			}

			MyFile.close();



		}

		return VClient;






	}

	static void _SaveClientDataToFile(vector<clsBankClient>VClient)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsBankClient& C : VClient)
			{
				if (C._MarkForDelete == false)
				{
					string Line = _ConverClientObjectToLine(C);

					MyFile << Line << endl;

				}
				
			}

			MyFile.close();

		}





	}

		void _Update()
	{
		vector<clsBankClient>VClient = _LoadClientDataFromFile();

		for (clsBankClient& C : VClient)
		{
			if (C.AccountNumber() ==_AccountNumber)
			{
				C = *this;
				break;

			}

		

		}
		_SaveClientDataToFile(VClient);
	}

		void _AddDataToFile(string FileName, string line)
		{
			fstream MyFile;
			MyFile.open(FileName, ios::out | ios::app);
			if (MyFile.is_open())
			{
				MyFile << line << endl;
				MyFile.close();
			}

		}
		 void _AddNew()
	{
		 _AddDataToFile("Clients.txt", _ConverClientObjectToLine(*this));
	}
		 void _SaveTransactiondatatoLog(clsBankClient Client2, double Amount, string seprator = "#//#")
		 {
			 string Line;
			 clsDate Date;
			 Line = to_string(Amount) + seprator;
			 Line += _AccountNumber + seprator;
			 Line += Client2.AccountNumber() + seprator;
			 Line += to_string(_AccountBalance) + seprator;
			 Line += to_string(Client2.AccountBalance1) + seprator;
			 Line += Date.getDate() + seprator;
			 Line += Date.GetTime() + seprator;
			 Line += CurrentUser.UserName;

			 fstream MyFile;
			 MyFile.open("TransactionLog.txt", ios::out | ios::app);
			 if (MyFile.is_open())
			 {
				 MyFile << Line << endl;
				 MyFile.close();
			 }



		 }
		

		 
public:
	static	struct stTransfirLogDate
	{

		double Amount;
		string AccountNumber1;
		string AccountNumber2;
		double AccountBalance1;
		double AccountBalance2;
		string date;
		string time;
		string UserName;






	};
	clsBankClient(string FirstName,string LastName,string Email,string PhoneNumber,enMode Mode,
		string AccountNumber,string PinCode,float AccountBalance):clsPerson(FirstName,LastName,Email,PhoneNumber)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	
	bool IsEmpty()
	{
		if (_Mode == enEmptyMode)
		{
			return true;

		}else return false;

	}
	
	string AccountNumber()
	{
		return _AccountNumber;
	}
	static clsBankClient GetEmptyClientObject()
	{
		return _GetEmptyClientObject();

	}
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;


	}
	string PinCode()
	{
		return _PinCode;
	}
	_declspec(property(get = PinCode, put = SetPinCode))string PinCode1;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;


	}
	float AccountBalance()
	{
		return _AccountBalance;
	}
	_declspec(property(get = AccountBalance, put = SetAccountBalance))float AccountBalance1;

	/*void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << PhoneNumber;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}*/
	
	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient>VClient ;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
			
				if (Client.AccountNumber() == AccountNumber)
				{
					return Client;
				}
				VClient.push_back(Client);
			}
			MyFile.close();

		}
		return _GetEmptyClientObject();


	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector<clsBankClient>VClient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber&&Client.PinCode()==PinCode)
				{
					return Client;
				}
				VClient.push_back(Client);

			}
			MyFile.close();

		}
		return _GetEmptyClientObject();



	}

	static bool IsClientExcist(string AccountNumber)
	{

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		
		if (Client.IsEmpty())
		{
			return false;
		}
		else return true;

	}

	enum enSaveResult{enSaveSucceed=1,enSaveField=2,enAddedSucceed};
	
	enSaveResult Save()
	{
		
		switch (_Mode)
		{
		case enEmptyMode:
		{

			return enSaveField;
			break;

		}
		case enUpdateMode:
		{
			_Update();
			return enSaveSucceed;
			break;
		}
		case enAddNewMode:
		{
			_AddNew();

			_Mode = enUpdateMode;
			return enAddedSucceed;
			break;

		}
		}
	}

	static clsBankClient GetAddNewClientOpject(string AccountNumber)
	{
		clsBankClient NewClient("","","","",enAddNewMode,AccountNumber,"",0);
	
		return NewClient;


	}
	bool Delete()
	{
		vector<clsBankClient>VClient = _LoadClientDataFromFile();
		for (clsBankClient& C : VClient)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkForDelete = true;
				break;


			}

			

		}
		_SaveClientDataToFile(VClient);
		return true;




	}

	static vector<clsBankClient>GetClientData()
	{
		return _LoadClientDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient>Vclients = _LoadClientDataFromFile();
		double totalbalances = 0;
		for (clsBankClient& C : Vclients)
		{
			totalbalances += C.AccountBalance();
		}
		return totalbalances;




	}

	 void Deposite(double Amount)
	{
		 _AccountBalance += Amount;
		 Save();
	}
	 void Withdraw(double Amount)
	 {

		 _AccountBalance -= Amount;
		 Save();
	 }
	 
	 bool TransactionBetween2Clients(clsBankClient &Client2,double Amount)
	 {
		
		 if (Amount > _AccountBalance)
		 {
			 return false;
		 }
		 else
		 {
			 _AccountBalance -= Amount;
			 Client2._AccountBalance += Amount;
			 _SaveTransactiondatatoLog(Client2, Amount);
			 return true;
			 
		 }
		 

	 }

	
	 static vector<stTransfirLogDate>GetTransferLogDataFromFile()
	 {
		 vector<stTransfirLogDate>VTransfirLog;
		 fstream MyFile;
		 MyFile.open("TransactionLog.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;
			 while (getline(MyFile, Line))
			 {
				 stTransfirLogDate Log = ConvertLineToLogstruct(Line);
				 VTransfirLog.push_back(Log);

			 }

			 MyFile.close();



		 }

		 return VTransfirLog;








	 }
	 static stTransfirLogDate ConvertLineToLogstruct(string Line, string seprator = "#//#")
	 {
		 stTransfirLogDate Log;
		 vector<string>VTlog;
		 VTlog = clsString::SplitString(Line, seprator);

		 Log.Amount = stod(VTlog[0]);
		 Log.AccountNumber1 = VTlog[1];
		 Log.AccountNumber2 = VTlog[2];
		 Log.AccountBalance1 = stod(VTlog[3]);
		 Log.AccountBalance2 = stod(VTlog[4]);
		 Log.date = VTlog[5];
		 Log.time = VTlog[6];
		 Log.UserName = VTlog[7];
		 return Log;
	 }
	
};

