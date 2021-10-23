#include "passport.h"

void passport::set_surname()
{
	getline(cin, surname);
}

void passport::set_name()
{
	getline(cin, name);
}

void passport::set_pantronymic()
{
	getline(cin, pantronymic);
}

void passport::set_sex()
{
	getline(cin, sex);
}

void passport::set_date_birght()
{
	date_birght.fill_date();
}

void passport::set_date_expiry(int _expiry_year)
{
	date_expiry.fill_date();
	cin.get();
	date_expiry.plus_year(_expiry_year);
}

void passport::set_nationality()
{
	getline(cin, nationality);
}

void passport::set_record_num()
{
	getline(cin, record_num);
}

void passport::set_document_num()
{
	getline(cin, document_num);
}

string passport::get_surname()
{
	return surname;
}

string passport::get_name()
{
	return name;
}

string passport::get_pantronymic()
{
	return pantronymic;	// TODO: insert return statement here
}

string passport::get_sex()
{
	return sex;	// TODO: insert return statement here
}

void passport::get_date_birght()
{
	date_birght.get_date();
}

void passport::get_date_expiry()
{
	date_expiry.get_date();
}

string passport::get_nationality()
{
	return nationality;	// TODO: insert return statement here
}

string passport::get_record_num()
{
	return record_num;	// TODO: insert return statement here
}

string passport::get_document_num()
{
	return document_num;	// TODO: insert return statement here
}

void print()
{
		cout << "\n1 - fill data passport\n";
		cout << "2 - view data pasport\n";
		cout << "3 - fill data foregin passport\n";
		cout << "4 - view data foregin pasport\n";
		cout << "5 - add visa\n";
		cout << "6 - clo minus day for foregin pasport\n";
		cout << "0 - exit\n";
	
}
