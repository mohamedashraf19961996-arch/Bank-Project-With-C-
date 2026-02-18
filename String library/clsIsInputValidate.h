#pragma once
#include<iostream>
#include "clsDate.h"
class clsIsInputValidate
{
private:

public:

	template<typename T> static bool IsNumberBetween(T Number, T NumberFrom, T NumberTo)
	{
		if ((Number >= NumberFrom) && (Number <= NumberTo))
		{
			return true;
		}else
		return false;

	}
	static bool IsDateBetween(clsDate Date1, clsDate Date2, clsDate Date3)
	{
		if (!clsDate::CheckDateIsLess(Date2, Date3))
		{
			clsDate::swapdates(Date2, Date3);
		}
		
		if (clsDate::CompareDates(Date1, Date2)==clsDate::After)
		{
			if (clsDate::CompareDates(Date1, Date3) == clsDate::Before)
			{
				return true;
			}
		}

		return false;

	}	
	 template  <typename T,typename T2>  static T ReadIntNumberBetween(T to,T from,T2 message="invaild Number")
	{
		 T Number = ReadDblNumber<T,T2>();
			
			while (!IsNumberBetween(Number,to,from))
			{
				cout << message << endl;
				Number= ReadDblNumber<T,T2>();
			}
			return Number;
	}
	 template <typename T,typename T2> static T ReadDblNumber(T2 message = "invaild Number")
	{
		T Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message << endl;
			cin >> Number;



		}

		return Number;




	}
	static bool IsValideDate(clsDate Date)
	{

		return Date.GetDay() <= clsDate::NumberofdaysInMonthes(Date.Getyear(), Date.GetMonth()) && 1 >= Date.GetMonth() <= 12&&Date.Getyear()>0;
		


	}
	static string ReadString()
	{
		string S1="";
		getline(cin >> ws,S1);
		return S1;

	}

};

