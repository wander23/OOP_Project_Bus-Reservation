#include"Bus.h"

//BUS
Bus::Bus()
{
	Number = 0;
	Driver = " ";
	Departure = " ";
	From = " ";
	To = " ";
	Price = 0;
	Col = 5;
	Row = 8;
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
	cout << "Bus No: ";
	cin >> Number;
	cin.ignore();

	cout << "Enter driver name: ";
	getline(cin, Driver);

	cout << "Enter Departure time: ";
	getline(cin, Departure);

	cout << "Going From: ";
	getline(cin, From);

	cout << "To: ";
	getline(cin, To);

	cout << "Enter Price: ";
	cin >> Price;
	cin.ignore();

	cout << "Enter Seat Rows and Cols: ";
	cin >> Row >> Col;
	cin.ignore();
	SetSeats();
	seat_max = Row * Col;

	cout << "Enter Discount Voucher code: ";
	getline(cin, Voucher);


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
	cout << "Driver: " << Driver << endl;
	cout << "Going From " << From << " To " << To << endl;
	cout << "Departure time: " << Departure << endl;
	cout << "Seat Available: " << seat_max << endl;
	cout << "Price per ticket: " << Price << endl;
}

bool Bus::CheckEmpty(int Seat)
{
	int Num = 1;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Num == Seat)
				if (Seats[i][j] == "Empty")
					return true;
				else return false;
			Num++;
		}
	}
	return false;
}

void Bus::NameRev(string Name, int Seat)
{
	int Num = 1;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Num == Seat)
				Seats[i][j] = Name;
			Num++;
		}
	}
}

void Bus::Reverse()// For Customer
{
	int Seat_no , num_of_people;
	string Name, customer_Voucher;
	cout << "How many people: ";
	cin >> num_of_people;
	cin.ignore();
	for (int i = 0; i < num_of_people; i++)
	{
		cout << "Enter name: ";
		getline(cin, Name);
	top:
		cout << "Seat you want to Reverse: ";
		cin >> Seat_no;
		cin.ignore();

		if (Seat_no > seat_max)
		{
			cout << "There are only " << seat_max << " in this bus" << endl;

			system("pause");
			goto top;
		}

		if (CheckEmpty(Seat_no))
		{
			NameRev(Name, Seat_no);
			seat_max--;
		}
		else
		{
			cout << "This seat is already reverse." << endl;
			goto top;
		}
	}

	cout << "Enter Voucher(type no if you dont have): ";
	getline(cin, customer_Voucher);
	if (customer_Voucher == Voucher)
		cout << "You have 50% discount" << endl << "Bill:	" << (Price * num_of_people) * 50/100 << endl;
	else
		cout << "Bill: " << Price * num_of_people << endl;
}

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
	cout << "goods's Weight: " << _goods << endl;
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
	cin.ignore();
	cout << "Enter name: ";
	getline(cin, _name);

	cout << "Enter gender: ";
	getline(cin,_sex);

	cout << "Enter age: "; 
	cin >> _age;
	cin.ignore();

	cout << "Enter tel: "; 
	getline(cin, _tel);

	cout << "Enter email: ";
	getline(cin, _email);

	//h.setName(_name);
	//h.setTel(_tel);
}

void Person::output()
{
	cout << "Name: " << _name << endl;
	cout << "Gender: " << _sex << endl;
	cout << "Age: " << _age << endl;
	cout << "Telephone: " << _tel << endl;
	cout << "Email: " << _email << endl;
}

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

	for (int i = 0; i < this->_number; ++i)
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

History::History() {
	_name = _tel = " ";
}
void History::setName(string name) {
	_name = name;
}
void History::setTel(string tel) {
	_tel = tel;
}
void History::print() {
	cout << "#1" << endl;
	cout << "Name: " << _name << endl;
	cout << "Tel: " << _tel << endl;
}