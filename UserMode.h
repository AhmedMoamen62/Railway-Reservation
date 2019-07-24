#pragma once
#include"User.h"
#include"Train.h"
#include"Dynamicarray.h"
#include"passengerreserve.h"
#include<ctime>
class UserMode
{
protected:
	int t; //train number
	int y; //to know th choice
	int n; //Number of users
	int k; //passenger number in reservation
	Dynamicarray<passengerreserve*> P;
	Dynamicarray<Train*> T;
	Dynamicarray<User*> x;
public:
	UserMode();
	int runmode();
	int getusernumber();
	void reserve();
	int findtrain(int);
	void display(int,int,bool);
	void Enquiry();
	void cancel();
	void getword(string&);
};

