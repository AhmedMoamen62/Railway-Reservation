#pragma once
#include<string>
using namespace std;
class User
{
	string pass;
	int id;
public:
	User();
	void setuser(int a, string N);
	int getid();
	string getpass();
};

