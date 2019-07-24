#pragma once
#include"UserMode.h"
#include<string>
using namespace std;
class AdminMode : public UserMode
{
	string password; //admin pass
public:
	AdminMode();
	void adminmenu();
	void usermanagement();
	void createUser();
	int adminmode();
	void displayusers();
	void createTrain();
	void displaydetail();
	void displaypassdet();
};

