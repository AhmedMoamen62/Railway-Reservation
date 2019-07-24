#include "Seat.h"
Seat::Seat()
{
	n = 0;
	fare = 0;
	res_seat = 0;
}
void Seat::setnumber(int a)
{
	n = a;
}
void Seat::setfare(int a)
{
	fare = a;
}
int Seat::getnumber()
{
	return n;
}
int Seat::getfare()
{
	return fare;
}
void Seat::setreserve(int a)
{
	res_seat += a;
}
int Seat::getreserve()
{
	return res_seat;
}
