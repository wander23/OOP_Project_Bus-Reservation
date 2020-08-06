#pragma once
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

const float priceGoods = 10000;

class Date
{
protected:
    int _day, _month, _year;

public:
    Date();
    void input();
    void output();
};

class Ticket
{
protected:
    string _nameOfTrip;
    Date _date;
    int _price;
    int _goods;

public:
    Ticket();
    void input();
    void output();
    int getPrice();
};

class Person
{
protected:
    string _name, _sex;
    int _age;
    string _tel;
    string _email;
    //History h;

public:
    Person();
    void input();
    void output();
};

class User : public Person
{
protected:
    int _number;
    vector<Ticket> _ticket;
    int _sumPrice;
    //History _h;
public:
    User();
    void input();
    void output();
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
    History();
    void setName(string name);
    void setTel(string tel);
    void print();
};

class Bus
{
private:
    int Price;
    string Departure;
    string From;
    string To;
    int seat_max;
    int Row, Col;
    vector<vector<string>>Seats;
    string Driver;
    string Voucher;
public:
    int Number;
    void SetSeats();
    void Install();
    void Reverse();
    void Show();
    void ShowSeat();
    bool CheckEmpty(int No);
    void NameRev(string name, int Seat);
    Bus();
};

//Class cac loai xe dac biet 
class Bed_Car :public Bus
{
public:
   /* void Luggage();*/
};

class VIP : public Bus
{
public:
public:
    //void Luxury_Lounge();//Phong cho hang sang
    //void Install();
};

class SuperVip : public Bus//Xe rieng tai xe rieng
{
    //void Rent();//Thue xe va tai xe

};

class BusStation
{
private:
	vector<Bus> _bus;
	vector<Admin> _ad;
	vector<User> _user;
public:
	void setAdmin();
};

class Admin
{
protected:
	string adminUsername;
	string password;
	vector<Bus> bus;
	vector<string> userName;
	vector<string> feedback;
public:
	Admin() {
		adminUsername = "";
		password = "";
	}
};