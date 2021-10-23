#pragma once
#include "passport.h"
#include <vector>
#include "date.h"
class foregin_passport :public passport
{
	struct visa {
		string counry;
		int number_of_day = 0;
		int rest_day = 0;
		date data_validity;
		date date_release;
		visa& operator=(visa& _visa) {
			this->counry = _visa.counry;
			this->number_of_day = _visa.number_of_day;
			this->rest_day = _visa.rest_day;
			this->data_validity = _visa.data_validity;
			this->date_release = _visa.date_release;
		}
		void print_visa() {
			cout << "\nCountry: \t\t" << counry;
			cout << "\nDate release: \t\t";
			date_release.get_date();
			cout << "\nExpiration date: \t";
			data_validity.get_date();
			cout << "\nNumber of day: \t\t" << number_of_day;
			cout << "\nRest of day: \t\t" << rest_day<<endl;
		}
	};
	visa* root;

public:
	vector<visa> visas;
	void add_visa();
	void print_visas();
	void clo_minus_days();
};