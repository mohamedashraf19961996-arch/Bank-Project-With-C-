#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <vector>
#include "clsString.h"
#include <iomanip>
#include <fstream>
using namespace std;
class clsDate:protected clsString
{
private:
	short _Day;
	short _Month;
	short _Year;
	short _Min;
	short _sec;
	short _Hou;
public:
	

		clsDate(string Date)
		{
		vector<string>VDate = SplitString(Date, "/");
		_Day = stoi(VDate[0]);
		_Month = stoi(VDate[1]);
		_Year = stoi(VDate[2]);

		}
		clsDate()
			{
			
			getsystemdate();

			}
	
		clsDate(short Days, short year)
	{
		getdatefromDayOrderinyear(Days, year);
	}
		void setDay(short Day)
		{
			 _Day = Day  ;
		}
		void setMonth(short Month)
		{
			_Month = Month;
		}
		void setYear(short Year)
		{
			_Year = Year;
		}
		void setDate(string Date)
	{
		vector<string>VDate = SplitString(Date, "/");

			 _Day = stoi(VDate[0]);
			 _Month = stoi(VDate[1]);
			 _Year = stoi(VDate[2]);

	}
		short GetDay()
		{

			return _Day;
		}
		short GetMonth()
		{
			return _Month;
		}
		short Getyear()
		{
			return _Year;
		}
		 string getDate()
	{
		/*vector<string>VDate;

		VDate.push_back(to_string(_Day));
		VDate.push_back(to_string(_Month));
		VDate.push_back(to_string(_Year));*/
			string Date;
			Date += to_string(_Day) + "/";
			Date += to_string(_Month) + "/";
			Date += to_string(_Year);

		
		return Date;
	}
		_declspec(property(get = getDate, put = setDate))string Date;

		enum dayorder { sun = 0, mon = 1, tue = 2, wes = 3, th = 4, fri = 5, sat = 6 };
		string GetTime()
		{
			string time;
			time += to_string(_Hou) + " : ";
			time+=to_string(_Min) + " : ";
			time += to_string(_sec);
			return time;

		}
		short GetMin()
		{
			return _Min;
		}
		static bool IsYearisleep(short year)
	{
		return  ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));


	}
		bool IsYearisleep()
	{
		return IsYearisleep(_Year);
	}

		static short NumberOfDayInyear(short year)
	{
		return IsYearisleep(year) ? 366 : 365;
	}
		short NumberOfDayInyear()
	{
		return NumberOfDayInyear(_Year);
	}

		static long NumberOfHoursInTheyear(short year)
	{
		return NumberOfDayInyear(year) * 24;
	}
		long NumberOfHoursInTheyear()
	{
		return NumberOfHoursInTheyear(_Year);
	}

		static long NumberOfMinutesInTheYear(short year)
	{
		return NumberOfHoursInTheyear(year) * 60;
	}
		long NumberOfMinutesInTheYear()
		{
		return NumberOfMinutesInTheYear(_Year);
		}

		static	short NumberofdaysInMonthes(short year, short month)
	{
		if (month < 0 || month>12)
		{
			return 0;
		}
		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (month == 2) ? (IsYearisleep(year) ? 29 : 28) : NumberOfDays[month - 1];

	}
		short NumberofdaysInMonthes()
{
	return NumberofdaysInMonthes(_Year, _Month);
}

		static	short NumberOfHoursInMonthes(short year, short month)
	{
		return NumberofdaysInMonthes(year, month) * 24;

	}
		short NumberOfHoursInMonthes()
{
	return NumberOfHoursInMonthes(_Year, _Month);
}

		static	long NumberOfMinutesInMonthes(short year, short month)
	{
		return NumberOfHoursInMonthes(year, month) * 60;

	}
		long NumberOfMinutesInMonthes()
		{
			return NumberOfMinutesInMonthes(_Year, _Month);
		}

		static	long NumberOfSecondsInMonthes(short year, short month)
		{
			return NumberOfMinutesInMonthes(year, month) * 60;

		}
		long NumberOfSecondsInMonthes()
		{
			return NumberOfSecondsInMonthes(_Year, _Month);
		}

		static	int Calculatetheday(short day, short month, short year)
		{
			int a = (14 - month) / 12;
			int y = year - a;
			int m = month + 12 * a - 2;

			int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

			return d;



		}
		int Calculatetheday()
	{
		return Calculatetheday(_Day, _Month, _Year);
	}

		string CalculatetheDayOrder(short day, short month, short year)
		{

			switch (Calculatetheday(day, month, year))
			{
			case dayorder::sun:
			{
				return "sunday";
			}
			case dayorder::mon:
			{
				return "monday";

			}case dayorder::tue:
			{
				return "tuesday";

			}case dayorder::wes:
			{
				return "wensday";

			}case dayorder::th:
			{
				return "thuresday";

			}
			case dayorder::fri:
			{
				return "friday";

			}
			default:
			{
				return "saturday";
			}
			}





		}
		string CalculatetheDayOrder()
		{
			return CalculatetheDayOrder(_Day, _Month, _Year);
		}

		string MontheName(short month)
		{
			string monthesname[12] = { "january","february","march","april","may","june","july","august","september","october","november","december" };
			return monthesname[month - 1];
		}
		string MontheName()
		{
			return MontheName(_Month);
		}

		void PrintMonthCalinder(short year, short month)
		{
			int NumberOfDays;
			int current = Calculatetheday(1, month, year);
			NumberOfDays = NumberofdaysInMonthes(year, month);

			printf("\n\n  ------------%s-------------\n", MontheName(month).c_str());
			printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
			int i;
			for (i = 0; i < current; i++)
			{
				printf("     ");
			}

			for (int j = 1; j <= NumberOfDays; j++)
			{
				printf("%5d", j);

				if (++i == 7)
				{
					i = 0;
					printf("\n");
				}

			}

			printf("\n\n___________________________________\n");


		}
		void PrintMonthCalinder()
		{
			PrintMonthCalinder(_Year, _Month);
		}

		static	int CalculatNumberOfDayFromTheBegainOfTheYear(short day, short month, short year)
		{
			int totalday = 0;
			for (int i = 1; i < month; i++)
			{
				totalday += NumberofdaysInMonthes(year, i);



			}

			return  totalday + day;



		}
		int CalculatNumberOfDayFromTheBegainOfTheYear()
		{
			return CalculatNumberOfDayFromTheBegainOfTheYear(_Day, _Month, _Year);



		}

		void getdatefromDayOrderinyear(short dayorder,short year)
		{
			 
			short remainingDays = dayorder;
			short monthdays = 0;
			_Year = year;
			_Month = 1;

			while (true)
			{
				monthdays = NumberofdaysInMonthes(year,_Month);
				if (remainingDays > monthdays)
				{
					remainingDays -= monthdays;
					_Month++;

				}
				else
				{
					_Day = remainingDays;
					break;
				}




			}


			




		}

		static void adddaysToDate(int day,clsDate &Date)
		{
			short remainingday = day + CalculatNumberOfDayFromTheBegainOfTheYear(Date._Day, Date._Month, Date._Year);
			short monthday = 0;

			Date._Month=1;

			while (true)
			{
				monthday = NumberofdaysInMonthes(Date._Year,Date._Month);
				if (remainingday > monthday)
				{
					remainingday -= monthday;
					Date._Month++;
				}
				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}
				else if (remainingday < 31) {

					Date._Day= remainingday;
					break;
				}


			}
			
		}
		void adddays(short day)
		{
			return adddaysToDate(day, *this);
		}

		static bool CheckDateIsLess(clsDate date1, clsDate date2)
		{
			return (date1.Getyear() < date2.Getyear()) ? true : ((date1.Getyear() == date2.Getyear()) ? (date1.GetMonth() < date2.GetMonth() ? true : (date1.GetMonth() == date2.GetMonth() ? date1.GetDay() < date2.GetDay() : false)) : false);
		}
		bool CheckDateIsLess(clsDate date2)
		{
			return CheckDateIsLess(*this, date2);

		}

		static bool IsDateisEqualdate2(clsDate date1, clsDate date2)
		{
			return (date1.Getyear() == date2.Getyear()) ? ((date1.GetMonth() == date2.GetMonth()) ? ((date1.GetDay() == date2.GetDay() ? true : false)) : false) : false;
		}
		bool IsDateisEqualdate2(clsDate Date)
		{
			return IsDateisEqualdate2(*this, Date);
		}

		static bool Islastdayinmonth(clsDate date)
		{
			return date.GetDay() == NumberofdaysInMonthes(date.Getyear(),date.GetMonth());
		}
		bool Islastdayinmonth()
		{
			return Islastdayinmonth(*this);
		}

		static bool islastmonthinyear(clsDate date)
		{
			return date.GetMonth() == 12;
		}
		bool islastmonthinyear()
		{
			return islastmonthinyear(*this);
		}

		static	void increaseDatebyoneday(clsDate &date)
		{
			if (Islastdayinmonth(date))
			{
				if (islastmonthinyear(date))
				{
					date._Day=1;
					date._Month=1;
					date._Year++;
				}
				else
				{
					date._Day = 1;
					date._Month++;
				}
			}
			else
			{
				date._Day++;
			}
			
		}
		void increaseDatebyoneday()
		{
			increaseDatebyoneday(*this);
		}

		static void	increaseDateByxDays(clsDate &date,short days)
		{
			for (int i = 0; i < days; i++)
			{
				increaseDatebyoneday(date);
			}
		}
		void	increaseDateByxDays(short days)
		{
			return 	increaseDateByxDays(*this, days);
		}

		static	void increaseDateByOneWeek(clsDate &date)
		{
			increaseDateByxDays(date, 7);


		}
		void increaseDateByOneWeek()
		{
			increaseDateByOneWeek(*this);
		}
		
		static	void swapdates(clsDate& date, clsDate& date2)
		{
			clsDate tempdate;

			tempdate._Year = date._Year;
			tempdate._Month = date._Month;
			tempdate._Day = date._Day;

			date._Year = date2._Year;
			date._Month = date2._Month;
			date._Day = date2._Day;

			date2._Year = tempdate._Year;
			date2._Month = tempdate._Month;
			date2._Day = tempdate._Day;


		}
		void swapdates(clsDate &Date)
	{
		swapdates(*this, Date);
	}

		static	short Calculatedifferancedaysbetween2dates(clsDate date1, clsDate date2, bool includeendday = false)
	{
		int count = 0;
		short SwapFlagValue = 1;

		if (!CheckDateIsLess(date1, date2))
		{
			swapdates(date1, date2);
			SwapFlagValue = -1;

		}

		while (CheckDateIsLess(date1, date2))
		{
			increaseDatebyoneday(date1);
			count++;
		}



		return includeendday ? ++count * SwapFlagValue : count * SwapFlagValue;
	}
		short Calculatedifferancedaysbetween2dates(clsDate Date,bool includeEndDay=false )
	{

		return Calculatedifferancedaysbetween2dates(*this, includeEndDay);


	}

		static void increasedateByOneMonth(clsDate &date)
	{
		if (Islastdayinmonth(date))
		{
			if (islastmonthinyear(date))
			{

				date._Month = 1;
				date._Year++;
			}
			else if (NumberofdaysInMonthes(date._Year, date._Month) == NumberofdaysInMonthes(date._Year, date._Month + 1))
			{
				date._Month++;
			}
			else if (date._Month == 1 && IsYearisleep(date._Year))
			{

				date._Month = 3;
				date._Day = 1;

			}
			else if (date._Month == 1)
			{
				date._Month = 3;
				date._Day = 2;

			}
			else if (date._Month == 2 && IsYearisleep(date._Year))
			{
				date._Month++;
				date._Day = 29;

			}
			else {

				date._Month++;
			}


		}
		else if (date._Month == 12)
		{

			date._Month = 1;
			date._Year++;

		}
		else if (IsYearisleep(date._Year) && date._Month == 1 && date._Day == 30)
		{
			date._Month = 3;
			date._Day = 1;

		}
		else if (!IsYearisleep(date._Year) && date._Month == 1 && date._Day == 30)
		{
			date._Month = 3;
			date._Day = 2;

		}
		else {

			date._Month++;
		}


		






	}
		void increasedateByOneMonth()
	{
		increasedateByOneMonth(*this);
	}

		static void IncreaseDateByOneYear(clsDate &Date)
		{
			for (int i = 1; i <= 12; i++)
			{
				increasedateByOneMonth(Date);
			}


		}
		void IncreaseDateByOneYear()
		{
			IncreaseDateByOneYear(*this);
		}

		static	void IncreaseDateByXYear(clsDate &Date,short Years)
		{
			for (int i = 1; i <= Years; i++)
			{
				IncreaseDateByOneYear(Date);
			}
		}
		void IncreaseDateByXYear(short Years)
		{
			IncreaseDateByXYear(*this, Years);
		}

		static	void IncreaseDateByXMonths(clsDate &Date, short Months)
		{
			for (int i = 1; i <= Months; i++)
			{
				increasedateByOneMonth(Date);
			}

		}
		void IncreaseDateByXMonths(short Months)
		{
			IncreaseDateByXMonths(*this, Months);
		}

		static	void increaseDateByDecade(clsDate &Date)
		{
			IncreaseDateByXYear(Date,10);
		}
		void increaseDateByDecade()
		{
			increaseDateByDecade(*this);
		}

		void getsystemdate()
		{
			;

			time_t t = time(0);
			tm* now = localtime(&t);

			_Year = now->tm_year + 1900;
			_Month = now->tm_mon + 1;
			_Day = now->tm_mday;
			_Min = now->tm_min;
			_sec = now->tm_sec;
			if (now->tm_hour > 12)
			{
				_Hou = now->tm_hour - 12;
			}
			else
			{
				_Hou = now->tm_hour;
			}
		}

		static void DecreaseDateByOneDay(clsDate &Date)
		{
			if (Date._Day == 1)
			{
				if (Date._Month == 1)
				{
					Date._Month = 12;
					Date._Day = 31;
					Date._Year--;
				}
				else
				{

					Date._Month--;
					Date._Day = NumberofdaysInMonthes(Date._Month, Date._Year);
				}
			}
			else
			{
				Date._Day--;
			}

			
		}

		void DecreaseDateByOneDay()
		{
			DecreaseDateByOneDay(*this);
		}

		static void DecreaseDateByOneWeek(clsDate& Date)
		{

			for (int i = 1; i <= 7; i++)
			{
				 DecreaseDateByOneDay(Date);
			}

			
		}

		void DecreaseDateByOneWeek()
		{
			DecreaseDateByOneWeek(*this);
		}

		static void DecreaseDateByXWeeks(short Weeks, clsDate& Date)
		{

			for (short i = 1; i <= Weeks; i++)
			{
				 DecreaseDateByOneWeek(Date);
			}

		}

		void DecreaseDateByXWeeks(short Weeks)
		{
			DecreaseDateByXWeeks(Weeks, *this);
		}

		static void DecreaseDateByOneMonth(clsDate& Date)
		{

			if (Date._Month == 1)
			{
				Date._Month = 12;
				Date._Year--;
			}
			else
				Date._Month--;


			//last check day in date should not exceed max days in the current month
		   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
		   // be 28/2/2022
			short NumberOfDaysInCurrentMonth = NumberofdaysInMonthes(Date._Month, Date._Year);
			if (Date._Day > NumberOfDaysInCurrentMonth)
			{
				Date._Day = NumberOfDaysInCurrentMonth;
			}


			
		}

		void DecreaseDateByOneMonth()
		{
			DecreaseDateByOneMonth(*this);
		}

		static void DecreaseDateByXDays(short Days, clsDate& Date)
		{

			for (short i = 1; i <= Days; i++)
			{
				DecreaseDateByOneDay(Date);
			}
			
		}

		void DecreaseDateByXDays(short Days)
		{
			DecreaseDateByXDays(Days, *this);
		}

		static void DecreaseDateByXMonths(short Months, clsDate& Date)
		{

			for (short i = 1; i <= Months; i++)
			{
				 DecreaseDateByOneMonth(Date);
			}
					}

		void DecreaseDateByXMonths(short Months)
		{
			DecreaseDateByXMonths(Months, *this);
		}

		static void DecreaseDateByOneYear(clsDate& Date)
		{

			Date._Year--;
			
		}

		void DecreaseDateByOneYear()
		{
			DecreaseDateByOneYear(*this);
		}

		static void DecreaseDateByXYears(short Years, clsDate& Date)
		{

			Date._Year -= Years;
		
		}

		void DecreaseDateByXYears(short Years)
		{
			DecreaseDateByXYears(Years, *this);
		}

		static void DecreaseDateByOneDecade(clsDate& Date)
		{
			//Period of 10 years
			Date._Year -= 10;
			
		}

		void DecreaseDateByOneDecade()
		{
			DecreaseDateByOneDecade(*this);
		}

		static void DecreaseDateByXDecades(short Decades, clsDate& Date)
		{

			Date._Year -= Decades * 10;
			
		}

		void DecreaseDateByXDecades(short Decades)
		{
			DecreaseDateByXDecades(Decades, *this);
		}

		static void DecreaseDateByOneCentury(clsDate& Date)
		{
			//Period of 100 years
			Date._Year -= 100;
			
		}

		void DecreaseDateByOneCentury()
		{
			DecreaseDateByOneCentury(*this);
		}

		static void DecreaseDateByOneMillennium(clsDate& Date)
		{
			//Period of 1000 years
			Date._Year -= 1000;
			
		}

		void DecreaseDateByOneMillennium()
		{
			DecreaseDateByOneMillennium(*this);
		}


		static short IsEndOfWeek(clsDate Date)
		{
			return  Calculatetheday(Date._Day, Date._Month, Date._Year) == 6;
		}

		short IsEndOfWeek()
		{
			return IsEndOfWeek(*this);
		}

		static bool IsWeekEnd(clsDate Date)
		{
			//Weekends are Fri and Sat
			short DayIndex = Calculatetheday(Date._Day, Date._Month, Date._Year);
			return  (DayIndex == 5 || DayIndex == 6);
		}

		bool IsWeekEnd()
		{
			return  IsWeekEnd(*this);
		}

		static bool IsBusinessDay(clsDate Date)
		{
			//Weekends are Sun,Mon,Tue,Wed and Thur

		   /*
			short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
			return  (DayIndex >= 5 && DayIndex <= 4);
		   */

		   //shorter method is to invert the IsWeekEnd: this will save updating code.
			return !IsWeekEnd(Date);

		}

		bool IsBusinessDay()
		{
			return  IsBusinessDay(*this);
		}

		static short DaysUntilTheEndOfWeek(clsDate Date)
		{
			return 6 - Calculatetheday(Date._Day, Date._Month, Date._Year);
		}

		short DaysUntilTheEndOfWeek()
		{
			return  DaysUntilTheEndOfWeek(*this);
		}

		static short DaysUntilTheEndOfMonth(clsDate Date1)
		{

			clsDate EndOfMontDate;
			EndOfMontDate._Day =NumberofdaysInMonthes(Date1._Month, Date1._Year);
			EndOfMontDate._Month = Date1._Month;
			EndOfMontDate._Year = Date1._Year;

			return Calculatedifferancedaysbetween2dates(Date1, EndOfMontDate, true);

		}

		short DaysUntilTheEndOfMonth()
		{
			return DaysUntilTheEndOfMonth(*this);
		}

		static short DaysUntilTheEndOfYear(clsDate Date1)
		{

			clsDate EndOfYearDate;
			EndOfYearDate._Day = 31;
			EndOfYearDate._Month = 12;
			EndOfYearDate._Year = Date1._Year;

			return Calculatedifferancedaysbetween2dates(Date1, EndOfYearDate, true);

		}

		short DaysUntilTheEndOfYear()
		{
			return  DaysUntilTheEndOfYear(*this);
		}

		//i added this method to calculate business days between 2 days
		static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
		{

			short Days = 0;
			while (IsDate1AfterDate2(DateFrom, DateTo))
			{
				if (IsBusinessDay(DateFrom))
					Days++;

				 increaseDatebyoneday(DateFrom);
			}

			return Days;

		}

		static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
		{
			/*short Days = 0;
			while (IsDate1BeforeDate2(DateFrom, DateTo))
			{
				if (IsBusinessDay(DateFrom))
					Days++;

				DateFrom = AddOneDay(DateFrom);
			}*/

			return CalculateBusinessDays(DateFrom, DateTo);

		}
		//above method is eough , no need to have method for the object

		static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
		{

			short WeekEndCounter = 0;

			for (short i = 1; i <= VacationDays; i++)
			{

				if (IsWeekEnd(DateFrom))
					WeekEndCounter++;

				 increaseDatebyoneday(DateFrom);
			}
			//to add weekends 
			for (short i = 1; i <= WeekEndCounter; i++)
			{ increaseDatebyoneday(DateFrom);}

			return DateFrom;
		}

		static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
		{
			return (!CheckDateIsLess(Date1, Date2) && !IsDate1AfterDate2(Date1, Date2));

		}

		bool IsDateAfterDate2(clsDate Date2)
		{
			return IsDate1AfterDate2(*this, Date2);
		}

		enum enDateCompare { Before = -1, Equal = 0, After = 1 };

		static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
		{
			if (CheckDateIsLess(Date1, Date2))
				return enDateCompare::Before;

			if (IsDateisEqualdate2(Date1, Date2))
				return enDateCompare::Equal;

			/* if (IsDate1AfterDate2(Date1,Date2))
				 return enDateCompare::After;*/

				 //this is faster
			return enDateCompare::After;

		}

		enDateCompare CompareDates(clsDate Date2)
		{
			return CompareDates(*this, Date2);
		}



};


