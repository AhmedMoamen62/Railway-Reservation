#pragma once
class Seat
{
	int n;
	int fare;
	int res_seat;
public:
	Seat();
	void setnumber(int);
	void setfare(int);
	int getnumber();
	int getfare();
	void setreserve(int);
	int getreserve();
};

