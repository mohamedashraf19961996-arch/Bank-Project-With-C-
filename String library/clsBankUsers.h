#pragma once
#include<iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsUtil.h"

class clsBankUsers:public clsPerson
{

private:
	enum enMode{eUpdateMode=1,eEmptyMode=2,eAddNew=3};
	enMode _Mode;
	string _UserName;
	string _UserPassword;
	int _UserPermation;
	bool _MarkForDelete = false;

	static clsBankUsers _ConvertLineToUserObject(string Line, string seprator = "#//#")
	{
		vector<string>VUsers;
		VUsers = clsString::SplitString(Line, seprator);

		return clsBankUsers(eUpdateMode, VUsers[0], VUsers[1], VUsers[2],
			VUsers[3], VUsers[4],clsUtil::DecryptText(VUsers[5],8), stoi(VUsers[6]));
	
	}
	static clsBankUsers	_GetEmptyUserObject()
	{

		return clsBankUsers(eEmptyMode, "", "", "", "", "", "", 0);

	}
	static vector<clsBankUsers>_LoadUsersDataFromFile()
	{
		vector<clsBankUsers>VUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankUsers User = _ConvertLineToUserObject(Line);
				VUsers.push_back(User);

			}

			MyFile.close();



		}

		return VUsers;

	}
	static string _ConverUserObjectToLine(clsBankUsers User, string Seperator = "#//#")
	{

		string stUserRecord = "";
		stUserRecord += User.FirstName + Seperator;
		stUserRecord += User.LastName + Seperator;
		stUserRecord +=User.Email + Seperator;
		stUserRecord +=User.PhoneNumber + Seperator;
		stUserRecord +=User.UserName + Seperator;
		stUserRecord +=clsUtil::EncryptText(User.UserPassword,8) + Seperator;
		stUserRecord +=to_string(User.UserPermition1);

		return stUserRecord;

	}
	static void _SaveUserDataToFile(vector<clsBankUsers>VUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsBankUsers& U : VUsers)
			{
				if (U._MarkForDelete == false)
				{
					string Line = _ConverUserObjectToLine(U);

					MyFile << Line << endl;

				}

			}

			MyFile.close();

		}





	}
	void _Update()
	{
		vector<clsBankUsers>VUsers = _LoadUsersDataFromFile();

		for (clsBankUsers& U : VUsers)
		{
			if (U.UserName == _UserName)
			{
				U = *this;
				break;

			}



		}
		_SaveUserDataToFile(VUsers);
	}

	void _AddDataToFile(string FileName, string line)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << line << endl;
		}
		MyFile.close();
	}
	void _AddNew()
	{
		_AddDataToFile("Users.txt", _ConverUserObjectToLine(*this));
	}
public:

	clsBankUsers(enMode Mode,string FirstName,string LastName,
		string Email,string PhoneNumber,string UserName,string UserPassword,int UserPermation)
		:clsPerson(FirstName,LastName,Email,PhoneNumber)
	{

		_Mode = Mode;
		_UserName = UserName;
		_UserPassword = UserPassword;
		_UserPermation = UserPermation;


	}

	bool IsEmpty()
	{

		if (_Mode == eEmptyMode)
		{
			return true;
		}
		else return false;

	}

	bool MarkedForDelete()
	{
		return _MarkForDelete;

	}

	void setUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
		 
	}
	_declspec(property(get = GetUserName, put = setUserName))string UserName;

	void setUserPassword(string UserPassword)
	{
		_UserPassword = UserPassword;
	}
	string GetUserPassword()
	{
		return _UserPassword;

	}
	_declspec(property(get = GetUserPassword, put = setUserPassword))string UserPassword;

	void SetUserPermition(int UserPermition)
	{
		_UserPermation = UserPermition;
	}
	int GetUserPermition()
	{
		return _UserPermation;
	}
	_declspec(property(get = GetUserPermition, put = setUserPermition))int UserPermition1;

	static clsBankUsers Find(string UserName)
	{
		vector<clsBankUsers>VUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankUsers User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName)
				{
					return User;
				}
				VUsers.push_back(User);
			}
			MyFile.close();

		}
		return _GetEmptyUserObject();


	}
	static clsBankUsers Find(string UserName,string UserPassword)
	{
		vector<clsBankUsers>VUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankUsers User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName && User.UserPassword==UserPassword)
				{
					return User;
				}
				VUsers.push_back(User);
			}
			MyFile.close();

		}
		return _GetEmptyUserObject();


	}
	static bool IsUserExciset(string UserName)
	{
		clsBankUsers User =Find(UserName);

		return (!User.IsEmpty());

	}
	static bool IsUserExciset(string UserName,string UserPassword)
	{
		clsBankUsers User = Find(UserName,UserPassword);

		return (!User.IsEmpty());

	}
	enum enSaveResult{svFaildEmptyOpject=1,svSucceed=2,svSaveFaildUserExeced};
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case eEmptyMode:
		{
			if (IsEmpty())
			{
				return svFaildEmptyOpject;
				break;
			}
		}
		case eUpdateMode:
		{

			_Update();
			return svSucceed;
			break;
		}
		case eAddNew:
		{
			if (IsUserExciset(_UserName))
			{
				return svSaveFaildUserExeced;

			}
			else {
				_AddNew();
				_Mode = eUpdateMode;
				return svSucceed;
			}



		}









		}





	}
	bool Delete()
	{
		vector<clsBankUsers>VUsers = _LoadUsersDataFromFile();
		for (clsBankUsers& U : VUsers)
		{
			if (U.UserName == _UserName&&U.UserPassword==_UserPassword)
			{
				U._MarkForDelete = true;
				break;


			}



		}
		_SaveUserDataToFile(VUsers);
		return true;




	}
	static clsBankUsers GetEmptyClientObject()
	{
		return _GetEmptyUserObject();

	}
	static vector<clsBankUsers>GetUserList()
	{
		return _LoadUsersDataFromFile();
	}
	static clsBankUsers GetAddNewUserOpject(string UserName)
	{
		clsBankUsers User(eAddNew, "", "", "","",UserName, "", 0);

		return User;


	}
	
	
};

