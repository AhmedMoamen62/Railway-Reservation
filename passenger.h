#pragma once
#include<string>
using namespace std;
class passenger
{
	int age;
	string name;
public:
	passenger();
	void setname(string a);
	void setage(int a);
	int getage();
	string getname();
};

