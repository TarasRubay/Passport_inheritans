#pragma once
#include <iostream>
#include <string>
#include "date.h"
using namespace std;
class passport {
	string surname;
	string name;
	string pantronymic;
	string sex;
	date date_birght;
	date date_expiry;
	string nationality;
	string record_num;
	string document_num;
public:
	void set_surname();
	void set_name();
	void set_pantronymic();
	void set_sex();
	void set_date_birght();
	void set_date_expiry(int _expiry_year);
	void set_nationality();
	void set_record_num();
	void set_document_num();
	string get_surname();
	string get_name();
	string get_pantronymic();
	string get_sex();
	void get_date_birght();
	void get_date_expiry();
	string get_nationality();
	string get_record_num();
	string get_document_num();
};
void print();
