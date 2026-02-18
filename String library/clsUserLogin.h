#pragma once
#include <iostream>
#include"clsBankUsers.h"
#include "Global.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include"clsDate.h"
#include <string>
#include "clsScreen.h"
class clsUserLogin
{
private:

	string _UserName;
	string _Date;
	string _Time;
	string _UserPassword;
	int _UserPermition;
	enum enStatue { eLogIn = 1, eLogOut = 2 };
	enStatue _Statue;
	string _stringStatue;
	static clsUserLogin _ConvertLineToUserObject(string Line, string seprator = "#//#")
	{
		vector<string>VUsers;
		VUsers = clsString::SplitString(Line, seprator);

		return clsUserLogin(VUsers[0], VUsers[1], VUsers[2],
			clsUtil::DecryptText(VUsers[3],4), stoi(VUsers[4]),VUsers[5],eLogIn);

	}
	static vector<clsUserLogin>_LoadUsersDataFromFile()
	{
		vector<clsUserLogin>VUsers;
		fstream MyFile;
		MyFile.open("LoginUsers.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUserLogin User = _ConvertLineToUserObject(Line);
				VUsers.push_back(User);

			}

			MyFile.close();



		}

		return VUsers;

	}
	static string _ConverUserObjectToLine(clsUserLogin UserLogin, string Seperator = "#//#")
	{

		string stUserRecord = "";
		stUserRecord += UserLogin.GetUserUserDate() + Seperator;
		stUserRecord += UserLogin.GetUserTime() + Seperator;
		stUserRecord += UserLogin.GetUserUserName() + Seperator;
		stUserRecord += clsUtil::EncryptText(UserLogin.GetUserUserPassword(),4) + Seperator;
		stUserRecord += to_string(UserLogin.GetUserPermition()) + Seperator;
		stUserRecord += UserLogin.GetUserUserStatue();

		return stUserRecord;

	}
	static void _SaveUserDataToFile(vector<clsUserLogin>VUsersLogin)
	{
		fstream MyFile;
		MyFile.open("LoginUsers.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsUserLogin& U : VUsersLogin)
			{

				string Line = _ConverUserObjectToLine(U);

				MyFile << Line << endl;



			}

			MyFile.close();

		}





	}
	void _AddDataToFile(string line)
	{
		fstream MyFile;
		MyFile.open("LoginUsers.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << line << endl;
		}
		MyFile.close();
	}
	void _SaveUserToLoginFile()
	{
		_AddDataToFile(_ConverUserObjectToLine(*this));

	}
	void _SaveStatueMode()
	{
		switch (_Statue)
		{
		case eLogIn:
		{
			_stringStatue = "LogIn";
			_SaveUserToLoginFile();
			break;
		}
		case eLogOut:
		{
			_stringStatue = "LogOut";
			_SaveUserToLoginFile();
			break;
		}

		}




	}

public:

	clsUserLogin(string Date1, string Time1,
		string UserName, string UserPassword , int Permition,string Statue, enStatue enStatue )
	{

		_UserName = UserName;
		_UserPassword = UserPassword;
		_Date = Date1;
		_Time = Time1;
		_UserPermition = Permition;
		_stringStatue = Statue;
		_Statue = enStatue;
	}
	clsUserLogin()
	{
		clsDate CurrentDate;
		_UserName = CurrentUser.UserName;
		_UserPassword = CurrentUser.UserPassword;
		_Date = CurrentDate.getDate();
		_Time = CurrentDate.GetTime();
		_UserPermition = CurrentUser.GetUserPermition();
		_stringStatue = "";
		_Statue = eLogIn;
	}
	string GetUserUserName()
	{
		return _UserName;
	}
	string GetUserUserPassword()
	{
		return _UserPassword;
	}
	string GetUserTime()
	{
		return _Time;
	}
	string GetUserUserDate()
	{
		return _Date;
	}
	int GetUserPermition()
	{
		return _UserPermition;
	}
	void LogOut()
	{
		_Statue = eLogOut;
		_SaveStatueMode();
	}
	string GetUserUserStatue()
	{
		return _stringStatue;
	}
	void LogIn()
	{
		_SaveStatueMode();
	}
	static vector<clsUserLogin>GetUserLoginData()
	{
		
		return _LoadUsersDataFromFile();
	}

};