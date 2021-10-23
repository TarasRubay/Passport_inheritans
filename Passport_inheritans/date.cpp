#include "date.h"	
void date::fill_array()
{
	for (int i = 0; i < 12; i++)
	{
		if (i == 1 && (this->year % 4 == 0) && (this->year % 100 != 0 || this->year % 100 == 0 && this->year % 400 == 0))this->arr[i] = 29;
		else if (i == 3 || i == 5 || i == 10 || i == 8)this->arr[i] = 30;
		else if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)this->arr[i] = 31;
		else this->arr[i] = 28;
	}
}

void date::fill_date()
{
	do {
		cout << "enter year: ";
		cin >> year;
	} while (year < 1);
	fill_array();
	
	do {
		cout << "enter mount: ";
		cin >> mount;
	} while (mount < 1 || mount > 12);

	do {
		cout << "enter day: ";
		cin >> day;
	} while (check_day());
}

void date::get_date()
{
	cout << setw(2) << this->day << "." << setw(2) << this->mount << "." << setw(4) << this->year;
}

void date::plus_year(int _year)
{
	date tmp;
	tmp.year = this->year + _year;
	tmp.fill_array();
	tmp.mount = this->mount;
	tmp.day = this->day;
	if (tmp.check_day())
		tmp++;
	*this = tmp;
}


void date::plus_mount(int& _mount, date& _date)
{
	int plus_year = 0;
	int plus_mount = 0;
	date tmp;
	while (_mount != 0) {
		if (_mount >= 12) {
			plus_year++;
			_mount -= 12;
		}
		else if ((_date.mount + _mount) > 12) {
				plus_year++;
				plus_mount = _date.mount + _mount;
				plus_mount -= 12;
				_mount = 0;
		}
		else if ((_date.mount + _mount) < 12) {
			plus_mount = _mount;
			_mount = 0;
		}
		
	}
	tmp = _date;
	tmp.mount += plus_mount;
	tmp.year += plus_year;
	tmp.fill_array();
	tmp.day = _date.day;
	if (tmp.check_day()) {
		tmp++;
	}
	*this = tmp;
	_mount = tmp - _date;
}

bool date::check_day()
{
	if (this->day >= 1 && this->day <= this->arr[mount - 1])
		return false;
	else 
		return true;
}

date::date(int _day, int _mount, int _year)
{
	this->day = _day;
	this->mount = _mount;
	this->year = _year;

}

date::date()
{
}

date::~date()
{
}

date& date::operator=(date& _date)
{
	this->day = _date.day;
	this->mount = _date.mount;
	this->year = _date.year;
	for (int i = 0; i < 12; i++)
	{
		this->arr[i] = _date.arr[i];
	}
	return *this;
}


date date::operator++()//infix
{
	if (this->day + 1 > this->arr[mount - 1]) {
		if (this->mount + 1 > 12) {
			this->year = this->year + 1;
			this->fill_array();
			this->mount = 1;
			this->day = 1;
			return *this;
		}
		else
		{
			this->mount = this->mount + 1;
			this->day = 1;
			return *this;
		}
	}
	else
	{
		this->day = this->day + 1;
		return *this;
	}
}

date date::operator++(int val)// postfix
{
	date tmp(*this);
	if (this->day + 1 > this->arr[mount - 1]) {
		if (this->mount + 1 > 12) {
			this->year = this->year + 1;
			this->fill_array();
			this->mount = 1;
			this->day = 1;
			return tmp;
		}
		else
		{
			this->mount = this->mount + 1;
			this->day = 1;
			return tmp;
		}
	}
	else
	{
		this->day = this->day + 1;
		return tmp;
	}
}

date date::operator--()//infix
{
	if (this->day - 1 < 1) {
		if (this->mount - 1 < 1) {
			this->year = this->year - 1;
			this->fill_array();
			this->mount = 12;
			this->day = 31;
			return *this;
		}
		else
		{
			this->mount = this->mount - 1;
			this->day = this->arr[mount - 1];
			return *this;
		}
	}
	else
	{
		this->day = this->day - 1;
		return *this;
	}
}
date date::operator--(int val)// postfix
{
	date tmp(*this);
	if (this->day - 1 < 1) {
		if (this->mount - 1 < 1) {
			this->year = this->year - 1;
			this->fill_array();
			this->mount = 12;
			this->day = 31;
			return tmp;
		}
		else
		{
			this->mount = this->mount - 1;
			this->day = this->arr[mount - 1];
			return tmp;
		}
	}
	else
	{
		this->day = this->day - 1;
		return tmp;
	}
}

int date::operator-(date _dat)
{
	int count = 0;
	if (*this < _dat) {
		while (*this != _dat)
		{
			_dat--;
			count++;
		}
	}
	else {
		while (*this != _dat)
		{
			_dat++;
			count++;
		}
	}
	return count;
}

date date::operator+(int _val)
{
	for (int i = 0; i < _val; i++)
	{
		this->operator++();
	}
	return *this;
}

bool date::operator<(date& _dat)
{
	if (this->year > _dat.year)
		return false;
	int count_L = 0, count_R = 0;
	date L;
	L.day = 1;
	L.mount = 1;
	L.year = this->year;
	for (int i = 0; i < 12; ++i)L.arr[i] = this->arr[i];
	while (L != *this) {
		L++;
		count_L++;
	}
	L.day = 1;
	L.mount = 1;
	L.year = _dat.year;
	for (int i = 0; i < 12; ++i)L.arr[i] = _dat.arr[i];
	while (L != _dat) {
		L++;
		count_R++;
	}
	if (count_L < count_R)
		return true;
	else
		return false;
}

bool date::operator>(date& _dat)
{
	return !this->operator<(_dat);
}

bool date::operator<=(date& _dat)
{
	if (this->operator<(_dat) || this->operator==(_dat))return true;
	else return false;
}

bool date::operator>=(date& _dat)
{
	return !this->operator<=(_dat);
}

bool date::operator==(date& _dat)
{
	if (this->day == _dat.day && this->mount == _dat.mount && this->year == _dat.year)return true;
	else return false;
}

bool date::operator!=(date& _dat)
{
	return !this->operator==(_dat);
}

