#pragma once
#include "passenger.h"
class passengerreserve 
{
	int* q;
	int con,n,f,train; //f passenger numbers & n number of passenger & con concession
	passenger* p;
	char c;
public:
	passengerreserve();
	void setcon(int);
	void setdatares(int,int,int);
	void displaydatares();
	string getcon();
	void setpasnum(int);
	int getpasnum();
	void setpass(int,int, string);
	void setnumber(int);
	int getnumber();
	void displaypassenger();
	void setclass(char e);
	char getclass();
	void settrainnum(int a);
	int gettrainnum();
};

