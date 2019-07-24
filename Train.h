#pragma once
#include<string>
#include"Seat.h"
using namespace std;
class Train
{
	int n;
	string name;
	string bp;
	string dp;
	Seat* s = new Seat[2];
	int* data;
public:
	Train();
	void setnum(int a);
	void setname(string);
	void setdp(string);
	void setbp(string);
	int getnum();
	string getname();
	string getdp();
	string getbp();
	void setseat(const char, int,int);
	void setdata(int*);
	void printdata();
	void printtrain();
	void reserveseat(char,int);
	bool checkdata(int*);
	int getres(char);
	int getseat(char);
	int getfare(char c);
};

