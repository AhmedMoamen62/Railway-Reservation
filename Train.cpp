#include "Train.h"
#include<iostream>
using namespace std;
Train::Train()
{
	n = 0;
	name = " ";
	dp = " ";
	bp = " ";
	s[0].setfare(0);
	s[0].setnumber(0);
	s[1].setfare(0);
	s[1].setnumber(0);
}
void Train::setnum(int a)
{
	n = a;
}
void Train::setname(string a)
{
	name = a;
}
void Train::setdp(string a)
{
	dp = a;
}
void Train::setbp(string a)
{
	bp = a;
}
int Train::getnum()
{
	return n;
}
string Train::getname()
{
	return name;
}
string Train::getdp()
{
	return dp;
}
string Train::getbp()
{
	return bp;
}
void Train::setseat(const char q,int w,int e)
{
	if (q == 'f')
	{
		s[0].setnumber(w);
		s[0].setfare(e);
		return;
	}
	if (q == 's')
	{
		s[1].setnumber(w);
		s[1].setfare(e);
		return;
	}
}
void Train::setdata(int* a)
{
	data = a;
}
void Train::printdata()
{
	for (int i = 0; i < 3; i++)
	{
		cout << data[i];
		if (i != 2)
		{
			cout << '/';
		}
	}
	cout << endl;
}
void Train::printtrain()
{
	cout <<getnum()<<endl<<getname()<<endl<<getbp()<<endl<<getdp()<<endl<<"class f\n"<<s[0].getnumber()<<"    "<<s[0].getfare()<<endl<< "class s\n" << s[1].getnumber() << "    " << s[1].getfare()<<endl;
	printdata();
}
void Train::reserveseat(char c,int a)
{
	if (c == 'f')
	{
		s[0].setreserve(a);
		return;
	}
	if (c == 's')
	{
		s[1].setreserve(a);
		return;
	}
}
bool Train::checkdata(int* a)
{
	if (data[0] == a[0] && data[1] == a[1] && data[2] == a[2])
	{
		return true;
	}
	return false;
}
int Train::getres(char a)
{
	if (a == 'f')
	{
		return s[0].getreserve();
	}
	if (a == 's')
	{
		return s[1].getreserve();
	}
}
int Train::getseat(char a)
{
	if (a == 'f')
	{
		return s[0].getnumber();
	}
	if (a == 's')
	{
		return s[1].getnumber();
	}
}
int Train::getfare(char c)
{
	if (c == 'f')
	{
		return s[0].getfare();
	}
	if (c == 's')
	{
		return s[1].getfare();
	}
}
