#include "AdminMode.h"
AdminMode::AdminMode()
{
	password = "1234567";
}
void AdminMode::adminmenu()
{
	cout << endl << "*****Admininstration Menu*****" << endl << "1.Create detail Database" << endl << "2.Add details" << endl << "3.Display details" << endl << "4.User Managment" << endl << "5.Display Passenger details" << endl << "6.Return to main menu" << endl;
	cout << "Enter Your Choice : ";
	cin >> y;
}
void AdminMode::usermanagement()
{
	cout << endl << "*****Welcome to User Management Menu*****" << endl << "1.Create id Database" << endl << "2.Add details" << endl << "3.Display details" << endl << "4.Return to main menu" << endl;
	cout << "Enter Your Choice : ";
	cin >> y;
}
void AdminMode::createUser()
{
	int id;
	string pass;
b:	cout << "Enter Your ID : ";
	cin >> id;
	if (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (id == x.getel(i + 1)->getid())
			{
				cout << "This id has been taken please choose another one\n";
				goto b;
			}
		}
	}
	cout << "Enter Your Password (without spaces) : ";
	getword(pass);
	cout << endl;
	User* t;
	t = new User();
	t->setuser(id, pass);
	x.add(t);
	n++;
	cout << "Your new User is created successfully" << endl;
}
void AdminMode::createTrain()
{
	int no, seat_no, fare ;
	string  des, board,name;
	int* q = new int[3];
	Train* z = new Train();
b:	cout << "Enter Details as following :\n";
	cout << "Train Number : ";
	cin >> no;
	if (t != 0)
	{
		for (int i = 0; i < t; i++)
		{
			if (no == T.getel(i + 1)->getnum())
			{
				cout << "This train number has been taken please choose another one\n";
				goto b;
			}
		}
	}
	z->setnum(no);
	cout << "Train Name : ";
	cin.ignore();
	getline(cin, name);
	z->setname(name);
	cout << "Boarding Point : ";
	getline(cin, board);
	z->setbp(board);
	cout << "Destination Point : ";
	getline(cin, des);
	z->setdp(des);
	cout << "Number of seats in first class & fare per ticket (number fare) : ";
	cin >> seat_no >> fare;
	z->setseat('f', seat_no, fare);
	cout << "Number of seats in second class & fare per ticket (number fare) : ";
	cin >> seat_no >> fare;
	z->setseat('s', seat_no, fare);
p:	cout << "Date of travelling (day month year) : ";
	cin >> q[0] >> q[1] >> q[2];
	time_t now = time(0);
	tm* tl = localtime(&now);
	int year = tl ->tm_year + 1900;
	int month = tl->tm_mon + 1;
	int day = tl->tm_mday;
	if (q[0] > 31 || q[1] > 12 || q[2] < year || (q[1] < month && q[0] < day && q[2] == year))
	{
		cout << "Wrong Date\n";
		goto p;
	}
	z->setdata(q);
	cout << endl;
	T.add(z);
	t++;
	cout << "Your new Train is created successfully" << endl;
}
int AdminMode::adminmode()
{
	cout << "Please Enter Administrator password : ";
	string m;
	getword(m);
	if (password == m)
	{
	l:	adminmenu();
		if (y == 1)
		{
		q:	createTrain();
		r:  cout << "Do you want to add one more Record ?" << endl << "y for Yes \nn for No\n";
			char x;
			cin >> x;
			if (x == 'y')
			{
				goto q;
			}
			else if (x == 'n')
			{
				goto l;
			}
			else
			{
				cout << "Wrong choice\n";
				goto r;
			}
		}
		else if (y == 2)
		{
			createTrain();
			goto l;
		}
		else if (y == 3)
		{
			displaydetail();
			goto l;
		}
		else if (y == 4)
		{
		m:  usermanagement();
			if (y == 1)
			{
			o:	createUser();
			p:  cout << "Do you want to add one more Record ?" << endl << "y for Yes \nn for No\n";
				char x;
				cin >> x;
				if (x == 'y')
				{
					goto o;
				}
				else if (x == 'n')
				{
					goto m;
				}
				else
				{
					cout << "Wrong choice\n";
					goto p;
				}
			}
			else if (y == 2)
			{
				createUser();
				goto m;
			}
			else if (y == 3)
			{
				displayusers();
				goto m;
			}
			else if (y == 4)
			{
				goto l;
			}
			else
			{
				cout << "wrong choice\n";
				goto m;
			}
		}
		else if (y == 5)
		{
			displaypassdet();
			goto l;
		}
		else if (y == 6)
		{
			return 6;
		}
		else
		{
			cout << "Wrong choice\n";
			goto l;
		}
	}
	else
	{
		cout << "Wrong password" << endl;
		adminmode();
	}
}
void AdminMode::displayusers()
{
	if (n == 0)
	{
		cout << "There's no users please create database first\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "User Number " << i + 1 << " :" << endl << "ID : " << x.getel(i + 1)->getid() << endl << "Password : " << x.getel(i + 1)->getpass() << endl;
	}
}
void AdminMode::displaydetail()
{
	if (t == 0)
	{
		cout << "There's no trains please create database first\n";
		return;
	}
	for (int i = 0; i < t; i++)
	{
		cout << "Train number " << i + 1 << endl;
		T.getel(i + 1)->printtrain();
		cout << "ــــــــــــــــــــ"<<endl;
	}
}
void AdminMode::displaypassdet()
{
	if (k == 0)
	{
		cout << "There's no passengers\n";
		return;
	}
	for (int i = 0; i < k; i++)
	{
		int j = findtrain(P.getel(i + 1)->gettrainnum());
		cout << "ــــــــــــــــــــــــــــــــــــ\n";
		cout << "Passenger number : " << i + 1 << endl;
		cout << "Train number : " << T.getel(j)->getnum() << endl;
		cout << "Train name : " << T.getel(j)->getname() << endl;
		cout << "Boarding point : " << T.getel(j)->getbp() << endl;
		cout << "Destination point : " << T.getel(j)->getdp() << endl;
		cout << "Number of seats reserved : " << P.getel(i + 1)->getpasnum() << endl;
		P.getel(i + 1)->displaypassenger();
		cout << "Your class : " << P.getel(i + 1)->getclass() << endl;
		cout << "Date of Reservation : ";
		P.getel(i + 1)->displaydatares();
		cout << "Your concession category : " << P.getel(i + 1)->getcon() << endl;
		cout << "You must pay : " << (P.getel(i + 1)->getpasnum())*(T.getel(j)->getfare(P.getel(i + 1)->getclass())) << endl;
		cout << "ــــــــــــــــــــــــــــــــــــ\n";
	}
}
