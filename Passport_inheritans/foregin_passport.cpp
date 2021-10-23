#include "foregin_passport.h"



void foregin_passport::add_visa()
{
	visa tmp;
	cout << "Enter Country: ";
	getline(cin, tmp.counry);
	cout << "Enter date release:\n";
	tmp.date_release.fill_date();
	cout << "Enter expiration date mount: ";
	int expir;
	do
	{
		cin >> expir;
	} while (expir<1);
	cin.get();
	tmp.data_validity.plus_mount(expir,tmp.date_release); // expir return max count day
	do
	{
		cout << "Enter number of days of stay in the country (min 1 max " << expir << "): ";
		cin >> tmp.number_of_day;
	} while (tmp.number_of_day < 1 && tmp.number_of_day > expir);
	cin.get();
	tmp.rest_day = tmp.number_of_day;
	visas.push_back(tmp);

}

void foregin_passport::print_visas()
{
	if (visas.empty()) {
		cout << "No visas";
	}
	else {
		for (int i = 0; i < visas.size(); i++)
		{
			visas[i].print_visa();
		}
	}
}

void foregin_passport::clo_minus_days()
{
	if (visas.empty()) {
		cout << "No visas";
	}
	else {
		for (int i = 0; i < visas.size(); i++)
		{
			cout << i+1 << " - " << visas[i].counry<<endl;
		}
	int choice;
	do
	{
	cout << "\nChoice country(min 1 max "<<visas.size()<<"): ";
	cin >> choice;
	} while (choice < 1 && choice > visas.size());
	int in_country;
	date entry;
	date departure;
	do
	{
		cout << "Enter date of entry in the country(date release: ";
		visas[choice - 1].date_release.get_date();
		cout << "  date validity: ";
		visas[choice - 1].data_validity.get_date();
		cout << "): \n";
		entry.fill_date();
	} while (entry < visas[choice-1].date_release && entry > visas[choice - 1].data_validity);
	do
	{
		cout << "Enter date of departure from the country(date entry ";
		entry.get_date();
		cout << "):\n";
		departure.fill_date();
	} while (departure < entry);

	if (departure == entry)in_country = 1;
	else in_country = departure - entry;
	
	if (visas[choice - 1].rest_day - in_country < 0) {
		string ban = "!!!ENTRY BAN!!!";
		cout << ban;
		visas[choice - 1].counry += " " + ban;
		visas[choice - 1].number_of_day = 0;
		visas[choice - 1].rest_day = 0;
	}
	else {
		visas[choice - 1].rest_day -= in_country;
	}
	}
}


