#include "User.h"
User::User()
{
	pass = " ";
	id = 0;
}
void User::setuser(int a, string N)
{
	id = a;
	pass = N;
}
int User::getid()
{
	return id;
}
string User::getpass()
{
	return pass;
}