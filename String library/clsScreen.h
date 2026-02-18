#pragma once
#include <iostream>
#include <iomanip>
#include "clsDate.h"
#include "Global.h"
using namespace std;

class clsScreen
{
private:

protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________\n\n";
        cout << setw(37) << left << "" << "\t\t\t" << Title;
        if (SubTitle != "")
        {
            cout <<endl<< setw(37) << left << "\t\t\t" << SubTitle;
        }
        cout <<"\n\n" << setw(37) << left << "" << "\t\t\t" << " User Name : " << CurrentUser.UserName;
        clsDate Date;
        cout << "\n\n" << setw(37) << left << "" << "\t\t\t" << "Date : " << Date.Date << endl;
        cout << setw(37) << left << "" << "\t\t\t" << "Date : " << Date.GetTime() << endl;

            
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }




};

