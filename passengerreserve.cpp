#include "passengerreserve.h"
#include<iostream>
using namespace std;
passengerreserve::passengerreserve()
{
	f = 1;
	con = 0;
	n = 0;
	train = 0;
	c = ' ';
	q = new int[3];
}
void passengerreserve::setcon(int a)
{
	con = a;
}
void passengerreserve::setdatares(int a,int b,int c)
{
	q[0] = a;
	q[1] = b;
	q[2] = c;
}
void passengerreserve::displaydatares()
{
	cout << q[0] << '/' << q[1] << '/' << q[2] << endl;
}
string passengerreserve::getcon()
{
	if (con == 1)
	{
		return "Military";
	}
	if (con == 2)
	{
		return "Senior cictizen";
	}
	if (con == 3)
	{
		return "Children below 5 years";
	}
	if (con == 4)
	{
		return "None";
	}
}
void passengerreserve::setpasnum(int a)
{
	f = a;
	p = new passenger[f];
}
int passengerreserve::getpasnum()
{
	return f;
}
void passengerreserve::setpass(int c,int a, string b)
{
	p[c].setage(a);
	p[c].setname(b);
}
void passengerreserve::setnumber(int a)
{
	n = a;
}
int passengerreserve::getnumber()
{
	return n;
}
void passengerreserve::displaypassenger()
{
	for (int i = 0; i < f; i++)
	{
		cout << "Passenger name : " << p[i].getname() << endl;
		cout << "Passenger age : " << p[i].getage() << endl;
	}
}
void passengerreserve::setclass(char e)
{
	c = e;
}
char passengerreserve::getclass()
{
	return c;
}
void passengerreserve::settrainnum(int a)
{
	train = a;
}
int passengerreserve::gettrainnum()
{
	return train;
}
