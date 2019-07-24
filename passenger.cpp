#include "passenger.h"
passenger::passenger()
{
	name = "";
	age = 0;
}
void passenger::setname(string a)
{
	name = a;
}
void passenger::setage(int a)
{
	age = a;
}
int passenger::getage()
{
	return age;
}
string passenger::getname()
{
	return name;
}
