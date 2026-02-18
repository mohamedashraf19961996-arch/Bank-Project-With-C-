#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include"clsUtil.h"
#include"clsIsInputValidate.h"
#include "clsLoginScreen.h"
#include "clsBankUsers.h"
#include "clsBankClient.h"
using namespace std;


int main()
{
	
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}
	
	
	
}
