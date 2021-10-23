#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class date {
	int year;
	int mount;
	int day;
	int arr[12];
	void fill_array();
	bool check_day();
	date(int _day, int _mount, int _year);
public:
	void fill_date();
	void get_date();
	void plus_year(int _year);
	void plus_mount(int& _mount, date& _date);
	date();
	~date();
	date& operator=(date& _date);
	date operator++();
	date operator++(int val);
	date operator--();
	date operator--(int val);
	int operator-(date _dat);
	date operator+(int _val);
	bool operator<(date& _dat);
	bool operator>(date& _dat);
	bool operator<=(date& _dat);
	bool operator>=(date& _dat);
	bool operator==(date& _dat);
	bool operator!=(date& _dat);
};