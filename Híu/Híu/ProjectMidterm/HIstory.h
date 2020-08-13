#include<iostream>
#include<vector>
#include<string>
using namespace std;

const float priceGoods = 10000;

class Date
{
protected:
    int _day, _month, _year;

public:
    Date()
    {
        this->_day = this->_month = this->_year = 0;
    }
    ~Date()
    {
        this->_day = this->_month = this->_year = 0;
    }
    void input()
    {
        cout << "Enter Day: ";
        cin >> this->_day;
        cout << "Enter month: ";
        cin >> this->_month;
        cout << "Enter year: ";
        cin >> this->_year;
    }
    void output()
    {
        cout << "Day/Month/Year: " << this->_day << "/" << this->_month << "/" << this->_year << endl;
    }
};

class Ticket
{
protected:
    string _nameOfTrip;
    Date _date;
    int _price;
    float _goods;

public:
    Ticket()
    {
        this->_nameOfTrip = "";
        this->_price = 0;
        this->_goods = 0;
    }
    ~Ticket()
    {
        this->_nameOfTrip = "";
        this->_price = 0;
        this->_goods = 0;
    }
    void input()
    {
        cin.ignore();
        cout << "Enter name of trip: "; fflush(stdin); getline(cin, this->_nameOfTrip);
        cout << "Enter Date: " << endl;
        _date.input();
        cout << "Enter price: "; cin >> this->_price;
        cout << "Enter goods's weight: "; cin >> this->_goods;
    }
    void output()
    {
        cout << "Name of trip: " << this->_nameOfTrip << endl;
        cout << "Date: " << endl << "\t";
        this->_date.output();
        cout << "Price: " << this->_price << endl;
        cout << "goods's Weight: " << this->_goods << endl;
    }
    int getPrice()
    {
        return this->_price + this->_goods * priceGoods;
    }
};

class Person
{
protected:
    string _name, _sex;
    int _age;
    string _tel;
    string _email;
    History h;

public:
    Person()
    {
        this->_name = this->_sex = this->_email = this->_tel = "";
        this->_age = 0;
  
    }
    ~Person()
    {
        this->_name = this->_sex = this->_email = this->_tel = "";
        this->_age = 0;
    }
    void input()
    {
        cin.ignore();
        cout << "Enter name: "; fflush(stdin); getline(cin, this->_name);
        //h.setName(this->_name);
        cout << "Enter gender: "; fflush(stdin); getline(cin, this->_sex);
        cout << "Enter age: "; cin >> this->_age;
        cin.ignore();
        cout << "Enter tel: "; fflush(stdin); getline(cin, this->_tel);
       // h.setTel(this->_tel);
        cout << "Enter email: "; fflush(stdin); getline(cin, this->_email);
        h.setName(_name);
        h.setTel(_tel);
    }

    void output()
    {
        cout << "Name: " << this->_name << endl;
        cout << "Gender: " << this->_sex << endl;
        cout << "Age: " << this->_age << endl;
        cout << "Telephone: " << this->_tel << endl;
        cout << "Email: " << this->_email << endl;
    }
   
};

class User : public Person
{
protected:
    int _number;
    Ticket _ticket[1000];
    int _sumPrice;
    int _cancel;
    //History _h;
public:
    User()
    {
        _number = 0;
        _ticket[this->_number];
        _sumPrice = 0;
    }
    ~User()
    {
        _number = 0;
        delete[]_ticket;
        _sumPrice = 0;
    }
    void input()
    {
        Person::input();
        cout << "Enter the number of ticket that users bought: "; cin >> this->_number;
 
        for (int i = 0; i < this->_number; ++i)
        {
            cout << "\t#" << i + 1 << endl;
            _ticket[i].input();
            _sumPrice += _ticket[i].getPrice();
        }
    }
    void output()
    {
        cout << "INFORMATION: " << endl;
        Person::output();
        cout << "- TRIP: " << endl;
        for (int i = 0; i < this->_number; ++i)
        {
            _ticket[i].output();
            cout << endl;
        }
        cout << "==> SUM OF MONEY = " << this->_sumPrice;
        cout << endl;
    }
    //void cancelTrip() {
    //    int number;
    //    string c;
    //    do
    //    {
    //        cout << "Do you want to cancel this trip?(Y/N) ";         
    //        getline(cin, c);
    //    } while (c == "Y" || c=="y" || c=="N" || c=="n");
    //    if (c == "Y" || c == "y") {
    //        number = 0;
    //        number++;
    //        _cancel = number;
    //        cout << "You have canceled this trip." << _cancel << endl;
    //    }     
    //}
};

class History {
protected:
    string _name;
    string _tel;
    int weightOfGoods;
    int totalMoneySpent;
    //vector<string> _feedback;
    //vector<string> _typeBus;
    //vector<string> _Admin;
public:
    History() {
        this->_name = this->_tel = "";
    }
    History(string name, string tel) {
        this->_name = name;
        this->_tel = tel;
    }
    void setName(string name) {
        this->_name = name;
    }
    void setTel(string tel) {
        this->_tel = tel;
    }
    void print() {
        cout << "#1" << endl;
        cout << "Name: " << this->_name << endl;
        cout << "Tel: " << this->_tel << endl;
    }
};