#include "UserMode.h"
#include"User.h"
#include<windows.h>
using namespace std;
UserMode::UserMode()
{
	n = 0;
	t = 0;
}
int UserMode::runmode()
{
	int m;
	int z;
	string s;
	cout << "Enter Your ID : ";
	cin >> z;
	cout << "Enter Your Password (without spaces) : ";
	getword(s);
	for (int i = 0; i < n; i++)
	{
		if (s == x.getel(i + 1)->getpass() && z == x.getel(i + 1)->getid())
		{
		l:  cout << "*****Welcome to User Menu*****" << endl;
			cout << "1.Reserve" << endl << "2.Cancell" << endl << "3.Enquiry" << endl << "4.Return to main menu" << endl;
			cout << "Enter Your Choice : ";
			cin >> m;
			if (m == 1)
			{
				cout << "1.Reserve\n2.Return to main menu\n";
				cin >> y;
				if (y == 1)
				{
					reserve();
				}
				goto l;
			}
			else if (m == 2)
			{
				cancel();
				goto l;
			}
			else if (m == 3)
			{
				Enquiry();
				goto l;
			}
			else if (m == 4)
			{
				return 0;
			}
			else
			{
				cout << "Wrong choice\n";
				goto l;
			}
		}
	}
	cout << "There's No User Found with this password and id ask the admin if you don't have user" << endl;
	return 0;
}
int UserMode::getusernumber()
{
	return n;
}
void UserMode::reserve()
{
	int train_no, seat_no,w,age;
	string train_name, des, board,name;
	bool flag = 1;
	char c;
	passengerreserve* h = new passengerreserve();
	int* q = new int[3];
	time_t now = time(0);
	tm* tl = localtime(&now);
	int year = tl->tm_year + 1900;
	int month = tl->tm_mon + 1;
	int day = tl->tm_mday;
	h->setdatares(day,month,year);
	cout << "Enter Details as following : " << endl;
	cout << "Train Number : ";
	cin >> train_no;
	for (int i = 0; i < t; i++)
	{
		if (T.getel(i + 1)->getnum() == train_no)
		{
			flag = 0;
			w = i + 1;
			break;
		}
	}
	if (flag == 1)
	{
		cout << "********Wrong Train Number********\n*****Enter Train Number form database*****\n";
		goto l;
	}
	h->settrainnum(train_no);
	cout << "Train Name : ";
	cin.ignore();
	getline(cin, train_name);
	if (T.getel(w)->getname() != train_name)
	{
		cout << "********Wrong Train Name********\n*****Enter Train Name form database*****\n";
		goto l;
	}
	cout << "Boarding Point : ";
	getline(cin, board);
	if (T.getel(w)->getbp() != board)
	{
		cout << "********Wrong Boarding Point********\n*****The train won't take off from " << board << "*****\n";
		goto l;
	}
	cout << "Destination Point : ";
	getline(cin, des);
	if (T.getel(w)->getdp() != des)
	{
		cout << "********Wrong Boarding Point********\n*****The train won't go to " << des << "*****\n";
		goto l;
	}
	cout << "Number of Seats Required : ";
	cin >> seat_no;
	h->setpasnum(seat_no);
	for (int i = 0; i < seat_no; i++)
	{
		cout << "Passenger Name : ";
		cin.ignore();
		getline(cin,name);
		cout << "Passenger age : ";
		cin >> age;
		h->setpass(i,age,name);
	}
	cout << "Enter the class (f for first class or s for second class) : ";
	cin >> c;
	h->setclass(c);
	if (T.getel(w)->getseat(c) - T.getel(w)->getres(c) < seat_no)
	{
		cout << "Sorry,There's no empty seats\nThe available seats are " << T.getel(w)->getseat(c) - T.getel(w)->getres(c) << endl;
		goto l;
	}
	T.getel(w)->reserveseat(c,seat_no);
p:	cout << "Date of travelling (day month year) : ";
	cin >> q[0] >> q[1] >> q[2];
	if (q[0] > 31 || q[1] > 12 || q[2] < year || (q[1] < month && q[0] < day && q[2] == year))
	{
		cout << "Wrong Date\n";
		goto p;
	}
	if (!(T.getel(w)->checkdata(q)))
	{
		cout << "The train won't take off in that data\n";
		goto p;
	}
m:	cout << "Enter the concession category :\n1.Military\n2.Senior citizen\n3.Children below 5 years\n4.None\n";
	cin >> y;
	if (y > 4)
	{
		cout << "Wrong choice\n";
		goto m;
	}
	h->setcon(y);
	k++;
	h->setnumber(k);
	P.add(h);
	cout << "********End of Getting Details********\n";
	display(k,w,1);
l: cout << "Go to Admin Mode\n";
}
int UserMode::findtrain(int a)
{
	if (t == 0)
	{
		return 0;
	}
	for (int i = 0; i < t; i++)
	{
		if (T.getel(i + 1)->getnum() == a)
		{
			return i + 1;
		}
	}
}
void UserMode::display(int a,int b,bool c)
{
	cout << "ــــــــــــــــــــــــــــــــــــــــ\n";
	if (c == 1)
	{
		cout << "Passenger number (Please record this number with you) : " << a << endl;
	}
	else
	{
		cout << "Passenger number : " << a << endl;
	}
	cout << "Train number : " << T.getel(b)->getnum() << endl;
	cout << "Train name : " << T.getel(b)->getname() << endl;
	cout << "Boarding point : " << T.getel(b)->getbp() << endl;
	cout << "Destination point : " << T.getel(b)->getdp() << endl;
	if (c == 1)
	{
		cout << "Number of seats reserved : " << P.getel(a)->getpasnum() << endl;
	}
	else
	{
		cout << "Number of seats cancelled : " << P.getel(a)->getpasnum() << endl;
	}
	P.getel(a)->displaypassenger();
	cout << "Your class : " << P.getel(a)->getclass() << endl;
	if (c == 1)
	{
		cout << "Date of Reservation : ";
	}
	else
	{
		cout << "Date of Cancellation : ";
	}
	P.getel(a)->displaydatares();
	cout << "Your concession category : " << P.getel(a)->getcon() << endl;
	if (c == 1)
	{
		cout << "You must pay : " << (P.getel(a)->getpasnum())*(T.getel(b)->getfare(P.getel(a)->getclass())) << endl;
	}
	else
	{
		cout << "You can collect : " << (P.getel(a)->getpasnum())*(T.getel(b)->getfare(P.getel(a)->getclass())) << endl;
	}
	cout << "ــــــــــــــــــــــــــــــــــــــــ\n";
	if (c == 1)
	{
		cout << "..............Your ticket is reserved..............\n";
		cout << "..............END OF RESERVATION..............\n";
		cout << "ــــــــــــــــــــــــــــــــــــــــ\n";
	}
	else
	{
		cout << "..............Your ticket is cancelled..............\n";
		cout << "..............END OF CANCELLATION..............\n";
		cout << "ــــــــــــــــــــــــــــــــــــــــ\n";
	}
}
void UserMode::Enquiry()
{
	if (t == 0)
	{
		cout << "Thers's no trains right now\n";
		return;
	}
	for (int i = 0; i < t; i++)
	{
		cout << "Train number : " << T.getel(i + 1)->getnum() << endl;
		cout << "Train name : " << T.getel(i + 1)->getname() << endl;
		cout << "Boarding point : " << T.getel(i + 1)->getbp() << endl;
		cout << "Destination point : " << T.getel(i + 1)->getdp() << endl;
		cout << "Number of seats available in first class & fare per ticket (number fare) : " << T.getel(i + 1)->getseat('f') - T.getel(i + 1)->getres('f') << " " << T.getel(i + 1)->getfare('f') << endl;
		cout << "Number of seats available in second class & fare per ticket (number fare) : " << T.getel(i + 1)->getseat('s') - T.getel(i + 1)->getres('s') << " " << T.getel(i + 1)->getfare('s') << endl;
		cout << "Date of travelling (day month year) : ";
		T.getel(i + 1)->printdata();
		cout << "ــــــــــــــــــــــــــــــــــــــــ\n";
	}
}
void UserMode::cancel()
{
	int flag = 1;
	if (k == 0)
	{
		flag = 2;
		goto e;
	}
	int pass,w;
	int* q = new int[3];
	time_t now = time(0);
	tm* tl = localtime(&now);
	int year = tl->tm_year + 1900;
	int month = tl->tm_mon + 1;
	int day = tl->tm_mday;
l:	cout << "Enter Details as following : " << endl;
	cout << "Passenger Number : ";
	cin >> pass;
	for (int i = 0; i < k; i++)
	{
		if (P.getel(i + 1)->getnumber() == pass)
		{
			flag = 0;
			w = i + 1;
			break;
		}
	}
	if (flag == 1)
	{
		cout << "********Wrong Passenger Number********\n";
		goto l;
	}
	int j = findtrain(P.getel(w)->gettrainnum());
p:	cout << "Date of cancellation (day month year) : ";
	cin >> q[0] >> q[1] >> q[2];
	if (q[0] > 31 || q[1] > 12 || q[2] < year || (q[1] < month && q[0] < day && q[2] == year))
	{
		cout << "Wrong Date\n";
		goto p;
	}
	if (!(T.getel(j)->checkdata(q)))
	{
		cout << "The train won't take off in that data\n";
		goto p;
	}
	cout << "********End of Getting Details********\n";
	display(w,j,0);
	T.getel(j)->reserveseat(P.getel(w)->getclass(),0 - P.getel(w)->getpasnum());
	P.removeel(w);
	k--;
e:	if (flag == 2)
    {
	cout << "Theres's no passenger has reserved before\n";
    }
}
 void UserMode::getword(string& a)
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mod = 0;
	GetConsoleMode(hStdin, &mod);
	SetConsoleMode(hStdin, mod & (~ENABLE_ECHO_INPUT));
	cin >> a;
	cout << endl;
	SetConsoleMode(hStdin, mod);
}
