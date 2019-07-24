#include "Railway.h"
#include"AdminMode.h"
#include"User.h"
#include<fstream>
#include<iostream>
using namespace std;
int Railway::getmode()
{
	return mode;
}
void Railway::gotomode()
{
	int m;
z:	printmenu();
	if (mode == 1)
	{
		m = e.adminmode();
		if (m == 6)
		{
			goto z;
		}
	}
	else if (mode == 2)
	{
		m = e.runmode();
		if (m == 0)
		{
			goto z;
		}
	}
	else if (mode == 3)
	{
		cout << "GoodBye\n";
	}
	else
	{
		cout << "Wrong choice\n";
		goto z;
	}
}
/*void Railway::loopprocess()
{
	ofstream f;
	f.open("process.txt");
	gotomode();
	f.close();
}/**/
void Railway::printmenu()
{
	cout << "*****Welcome to Railway Reservation*****" << endl << "Please choose the mode" << endl;
	cout << "1.Administrator Mode" << endl;
	cout << "2.User Mode Mode" << endl;
	cout << "3.Exit" << endl;
	cout << "Enter Your Choice : ";
	cin >> mode;
}
