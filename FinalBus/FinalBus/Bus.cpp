﻿#include"Bus.h"

void vline(char ch = '-')
{
	for (int i = 80; i > 0; i--)
		cout << ch;
}

//BUS

Bus::Bus()
{
	Number = 0;
	Driver = " ";
	Departure = " ";
	From = " ";
	To = " ";
	Price = 200000;
	Col = 5;
	Row = 8;
	seat_max = Row * Col;
	SetSeats();
}

Bed_Car::Bed_Car(int num)
{
	Number = num;
	Driver = " ";
	Departure = " ";
	From = " ";
	To = " ";
	Price = 400000;
	Col = 3;
	Row = 6;
	seat_max = Row * Col;
	SetSeats();
}

VIP::VIP(int num)
{
	Number = num;
	Driver = " ";
	Departure = " ";
	From = " ";
	To = " ";
	Price = 3000000;
	Col = 2;
	Row = 5;
	seat_max = Row * Col;
	SetSeats();
}

SuperVip::SuperVip(int num)
{
	Number = num;
	Driver = " ";
	Departure = " ";
	From = " ";
	To = " ";
	Price = 10000000;
	Col = 2;
	Row = 1;
	seat_max = Row * Col;
	SetSeats();
}

void Bus::SetSeats()
{
	Seats.resize(Row);
	for (int i = 0; i < Row; i++)
		Seats[i].resize(Col);

	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
		{
			Seats[i][j] = "Empty";
		}
}

void Bus::Install()// FOR ADMIN ONLY 
{
	cout << "Enter Bus No: ";
	cin >> Number;
	cin.ignore();

	cout << "\nEnter driver name: ";
	getline(cin, Driver);

	cout << "\nEnter Departure time: ";
	getline(cin, Departure);

	cout << "\nGoing From: ";
	getline(cin, From);

	cout << "\nTo: ";
	getline(cin, To);

	cout << "\nEnter Price: ";
	cin >> Price;
	cin.ignore();

	cout << "\nEnter Seat Rows and Cols: ";
	cin >> Row >> Col;
	cin.ignore();
	SetSeats();
	seat_max = Row * Col;

	cout << "\nEnter Discount Voucher code: ";
	getline(cin, Voucher);


}

vector<string> split(string haystack, string separator = " ")
{
	vector<string> a;
	size_t Startpos = 0;
	while (true)
	{
		size_t Foundpos = haystack.find(separator, Startpos);
		if (Foundpos != string::npos)
		{
			string Token = haystack.substr(Startpos, Foundpos - Startpos);
			Startpos = Foundpos + separator.length();
			a.push_back(Token);
		}
		else
		{
			a.push_back(haystack.substr(Startpos, haystack.length() - Startpos));
			break;
		}

	}
	return a;
}

void Bus::ShowSeat()
{
	int No = 1;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			cout << No << ". " << Seats[i][j] << "\t \t";
			No++;
		}
		cout << endl;
	}
}

void Bus::Show()// Show for Customer
{
	cout << "Bus No: " << Number << endl;
	ShowName();
	cout << "Driver: " << Driver << endl;
	cout << "Going From " << From << " To " << To << endl;
	cout << "Departure time: " << Departure << endl;
	cout << "Seat Available: " << seat_max << endl;
	ShowPrice();
}

bool Bus::CheckEmpty(int Seat)
{
	int Num = 1;
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
		{
			if (Num == Seat)
				if (strcmp(Seats[i][j].c_str(), "Empty") == 0)
					return true;
				else return false;
			Num++;
		}
	return false;
}

void Bus::NameRev(string Name, int Seat)
{
	int Num = 1;
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
		{
			if (Num == Seat)
				Seats[i][j] = Name;
			Num++;
		}
}

void Bus::Reserve()// For Customer
{
	int Seat_no, num_of_people, Weight;
	int bill;
	string Name, customer_Voucher, haystack;
	vector<string>s_seats;

	cout << "Enter name: ";
	getline(cin, Name);

	cout << "What seats you want to Reverse: ";
	getline(cin, haystack);

	s_seats = split(haystack);
	num_of_people = s_seats.size();

	for (int i = 0; i < num_of_people; i++)
	{
		Seat_no = stoi(s_seats[i]);
	top:
		if (Seat_no > seat_max)
		{
			cout << "Seat " << Seat_no << " is out of max seats. Please try again. " << endl;
			cout << "Seat: ";
			cin >> Seat_no;
			cin.ignore();
			cout << endl;
			goto top;
		}

		if (CheckEmpty(Seat_no))
		{
			NameRev(Name, Seat_no);
			seat_max--;
		}
		else
		{
			cout << "Seat " << Seat_no << " is already reverse. Please try again" << endl;
			cout << "Seat: ";
			cin >> Seat_no;
			cin.ignore();
			goto top;
		}

	}
	cout << "Enter Weight of your luggages: ";
	cin >> Weight;
	cin.ignore();
	bill = (Price * num_of_people) + (Weight * priceGoods);
	cout << "Enter Voucher(type no if you dont have): ";
	getline(cin, customer_Voucher);
	if (customer_Voucher == Voucher)
	{
		bill /= 2;
		cout << "You have 50% discount" << endl << "Bill:	" << bill << endl;
	}
	else
		cout << "Bill: " << bill << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Date
Date::Date()
{
	_day = _month = _year = 0;
}
void Date::input()
{
	cout << "Enter Day: ";
	cin >> _day;
	cout << "Enter month: ";
	cin >> _month;
	cout << "Enter year: ";
	cin >> _year;
}
void Date::output()
{
	cout << "Day/Month/Year: " << _day << "/" << _month << "/" << _year << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Ticket
Ticket::Ticket()
{
	_nameOfTrip = "";
	_price = 0;
	_goods = 0;
}

void Ticket::input()
{
	cin.ignore();

	cout << "Enter name of trip: ";
	getline(cin, _nameOfTrip);

	cout << "Enter Date: " << endl;
	_date.input();

	cout << "Enter price: ";
	cin >> _price;

	cout << "Enter goods's weight: ";
	cin >> _goods;
}

void Ticket::output()
{
	cout << "Name of trip: " << _nameOfTrip << endl;
	cout << "Date: " << endl << "\t";
	_date.output();
	cout << "Price: " << _price << endl;
	cout << "Goods's Weight: " << _goods << endl;
}
int Ticket::getPrice()
{
	return _price + _goods * priceGoods;
}

//Person
Person::Person()
{
	_name = _sex = _email = _tel = "";
	_age = 0;
}

void Person::input()
{
	cout << "\nEnter name: ";
	getline(cin, _name);

	cout << "\nEnter gender: ";
	getline(cin, _sex);

	cout << "\nEnter age: ";
	cin >> _age;
	cin.ignore();

	cout << "\nEnter tel: ";
	getline(cin, _tel);

	cout << "\nEnter email: ";
	getline(cin, _email);
}

void Person::output()
{
	cout << "\nName: " << _name << endl;
	cout << "Gender: " << _sex << endl;
	cout << "Age: " << _age << endl;
	cout << "Telephone: " << _tel << endl;
	cout << "Email: " << _email << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//User
User::User()
{
	_number = 0;
	_sumPrice = 0;
}

void User::input()
{
	Person::input();
	cout << "Enter the number of ticket that users bought: ";
	cin >> _number;

	for (int i = 0; i < _number; ++i)
	{
		cout << "\t#" << i + 1 << endl;
		_ticket[i].input();
		_sumPrice += _ticket[i].getPrice();
	}
}
void User::output()
{
	cout << "INFORMATION: " << endl;
	Person::output();
	cout << "- TRIP: " << endl;
	for (int i = 0; i < _number; ++i)
	{
		_ticket[i].output();
		cout << endl;
	}
	cout << "==> SUM OF MONEY = " << _sumPrice;
	cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//History
History::History() {
	_name = _tel = " ";
}


void History::setName(string name) {
	_name = name;
}


void History::setTelephone(string telephone) {
	_tel = telephone;
}


void History::setFeedback(string feedBack){
	_feedback = feedBack;
}


string History::getFeedback()
{
	return _feedback;
}


int History::getPayment()
{
	return _payment;
}


int History::getGoods()
{
	return _goods;
}


void History::print() {
	cout << "\n#" << Q << endl;
	cout << "Name: " << _name << endl;
	cout << "Tel: " << _tel << endl;
	cout << "Goods: " << _goods << endl;
	cout << "Payment: " << _payment << endl;
	cout << "Feedback: " << _feedback << endl;
	cout << "Typenbus: " << _typebus << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//BusStation
void BusStation::printOutAccount()
{
	for (int i = 0; i < _ad.size(); i++) {
		cout << _ad[i].getUsername() << _ad[i].getPassword() << "\n";
	}
}


void BusStation::setAdmin()
{
	Admin admin1;
	Admin admin2;
	Admin admin3;
	Admin admin4;

	admin1.setUsername("phunganhkhoa");
	admin1.setPassword("19127449");
	admin2.setUsername("ngodangkhoa");
	admin2.setPassword("19127444");
	admin3.setUsername("huynhcaonhathieu");
	admin3.setPassword("19127399");
	admin4.setUsername("ngohuyanh");
	admin4.setPassword("19127095");

	_ad.push_back(admin1);
	_ad.push_back(admin2);
	_ad.push_back(admin3);
	_ad.push_back(admin4);
} 


bool BusStation::logInForAdmin(int &serial)
{
	bool validateAdmin = false;
	int numberOfWrongInput = 0;
	string username = "";
	string password = "";

	while (!validateAdmin) {
		cout << "Username: ";
		getline(cin, username);
		fflush(stdin);
		cout << "Password: ";
		getline(cin, password);
		for (int i = 0; i < _ad.size(); i++) {
			if (_ad[i].getUsername() == username && _ad[i].getPassword() == password) {
				serial = i;
				return true;
			}
		}

		if (!validateAdmin) {
			cout << "Wrong Username or Password ! Please press Enter to try again ! " << "\n";
			numberOfWrongInput++;
			system("pause");
		}

		if (numberOfWrongInput == 3) {
			system("cls");
			cout << "You have entered wrong Username or Password 3 times ! Please press Enter to exit program ! " << "\n";
			system("pause");
			return false;
		}

		username.clear();
		password.clear();
		system("cls");
	}
	return false;
}


void BusStation::Install()
{
	int choice;

	while (true)
	{
		cout << "Chon loai xe ban muon Tao: " << endl;
		cout << "1. Xe khach ngoi " << endl;
		cout << "2. Xe giuong nam " << endl;
		cout << "3. Xe Vip " << endl;
		cout << "4. Xe Rieng, Tai xe rieng" << endl;
		cout << "5. Exit" << endl;

		cout << "Lua chon cua ban la: ";
		cin >> choice;
		cin.ignore();

		if (choice == 5)
		{
			system("pause");
			system("cls");
			break;
		}

		system("cls");

		switch (choice)
		{
		case 1:
		{
			int Num;
			cout << "ADMIN SETUP" << endl;
			cout << "Enter the number of bus you want to Install: ";
			cin >> Num;
			cin.ignore();
			for (int i = 0; i < Num; i++)
			{
				Bus a;
				//a.Install();
				_bus.push_back(new Bus(a));
				//system("cls");
			}
			cout << endl;
			system("pause");
			system("cls");

			break;
		}

		case 2:
		{
			int Num;
			cout << "ADMIN SETUP" << endl;
			cout << "Enter number bus you want to Install: ";
			cin >> Num;
			cin.ignore();
			for (int i = 0; i < Num; i++)
			{
				Bed_Car b(i + 1);
				//b.Install();
				addBed_car(b);
				//system("cls");
			}

			cout << endl;
			system("pause");
			system("cls");

			break;
		}

		case 3:
		{
			int Num;
			cout << "ADMIN SETUP" << endl;
			cout << "Enter number bus you want to Install: ";
			cin >> Num;
			cin.ignore();
			for (int i = 0; i < Num; i++)
			{
				VIP c(i + 1);
				//c.Install();
				addVip(c);
				//system("cls");
			}

			cout << endl;
			system("pause");
			system("cls");

			break;
		}

		case 4:
		{
			int Num;
			cout << "ADMIN SETUP" << endl;
			cout << "Enter number bus you want to Install: ";
			cin >> Num;
			cin.ignore();
			for (int i = 0; i < Num; i++)
			{
				SuperVip d(i + 1);
				//b.Install();
				addVipCar(d);
				//system("cls");
			}

			cout << endl;
			system("pause");
			system("cls");

			break;
		}
		}
	}
}


void BusStation::Rev()
{
	int Bus_no;

	cout << "CUSTOMER: " << endl;
	cout << "Buses availabile: " << endl;

	for (int i = 0; i < _bus.size(); i++)
	{
		_bus[i]->Show();
		cout << endl;
	}

	cout << endl;

	cout << "Enter Bus No: ";
	cin >> Bus_no;
	cin.ignore();

	for (int i = 0; i < _bus.size(); i++)
	{
		if (_bus[i]->Number == Bus_no)
		{
			system("cls");
			_bus[i]->ShowSeat();
			_bus[i]->Reserve();
			system("pause");
			system("cls");
			_bus[i]->ShowSeat();
			system("pause");
			break;
		}
		else
		{
			continue;
		}
	}

}


void BusStation::saveInfoIntoHistory(int serial) {
	string name, telephone, feedback;
	History history;
	cout << "Fill your name: ";
	getline(cin, name);
	history.setName(name);
	cout << "Fill your telephone: ";
	getline(cin, telephone);
	history.setTelephone(telephone);
	cout << "Give feedback: ";
	getline(cin, feedback);
	history.setFeedback(feedback);

	_ad[serial].addHistory(history);
}


void BusStation::readFeedback(int serial)
{
	vector<History> temp;
	temp = _ad[serial].getHistory();

	for (int i = 0; i < temp.size(); i++) {
		cout << "Feedback " << i + 1 << ": " << "\n";
		cout << temp[i].getFeedback();
	}

	temp.clear();
	return;
}


int BusStation::showMoney(int serial)
{
	int totalOfMoney = 0;

	vector<History> temp;
	temp = _ad[serial].getHistory();

	for (int i = 0; i < temp.size(); i++) {
		totalOfMoney += temp[i].getPayment();
	}

	temp.clear();
	return totalOfMoney;
}


int BusStation::showGoods(int serial)
{
	int totalOfGoods = 0;

	vector<History> temp;
	temp = _ad[serial].getHistory();

	for (int i = 0; i < temp.size(); i++) {
		totalOfGoods += temp[i].getGoods();
	}

	temp.clear();
	return totalOfGoods;
}


void BusStation::addVip(VIP b)
{
	_bus.push_back(new VIP(b));
}


void BusStation::addVipCar(SuperVip c)
{
	_bus.push_back(new SuperVip(c));
}


void BusStation::addBed_car(Bed_Car a)
{
	_bus.push_back(new Bed_Car(a));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Admin
void Admin::setUsername(string str)
{
	_username = str;
}


void Admin::setPassword(string str)
{
	_password = str;
}


string Admin::getUsername()
{
	return _username;
}


string Admin::getPassword()
{
	return _password;
}


void Admin::addHistory(const History &history)
{
	_history.push_back(history);
}


vector<History> Admin::getHistory()
{
	return _history;
}

//void OptionInstall()
//{
//
//}
//
//void OptionRev()
//{
//
//}
