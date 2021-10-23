#include "passport.h"
#include<iomanip>
#include "foregin_passport.h"
int main() {
	passport pass;
	foregin_passport foreg_pass;
	int menu = 100, max_menu = 6, expir;
	int switch_on = menu;
	do
	{
		switch (switch_on)
		{
		case 100:
			do
			{
				print();
				cin >> switch_on;
				system("cls");
			} while (switch_on < 0 || switch_on > max_menu);
			cin.get();

			break;
		case 1:
			cout << "Enter Surname: ";
			pass.set_surname();
			cout << "Enter Name: ";
			pass.set_name();
			cout << "Enter Pantronymic: ";
			pass.set_pantronymic();
			cout << "Enter Sex: ";
			pass.set_sex();
			cout << "Enter Nationality: ";
			pass.set_nationality();
			cout << "Enter birght day: \n";
			pass.set_date_birght();
			do
			{
				cout << "Enter set expiry year: ";
				cin >> expir;
			} while (expir < 1);
			cin.get();
			cout << "Enter build passport date: \n";
			pass.set_date_expiry(expir);
			cout << "Enter Record num: ";
			pass.set_record_num();
			cout << "Enter Document num: ";
			pass.set_document_num();
			switch_on = menu;
			break;
		case 2:
			cout << "\nSurname: \t\t\t"<< pass.get_surname();
			cout << "\nName: \t\t\t\t"<< pass.get_name();
			cout << "\nPantronymic: \t\t\t"<< pass.get_pantronymic();
			cout << "\nEnter Sex: \t\t\t"<< pass.get_sex();
			cout << "\nNationality: \t\t\t"<<pass.get_nationality();
			cout << "\nBirght day: \t\t\t";
			pass.get_date_birght();
			cout << "\nexpiry: \t\t\t";
			pass.get_date_expiry();
			cout << "\nRecord num: \t\t\t"<< pass.get_record_num();
			cout << "\nDocument num: \t\t\t"<< pass.get_document_num();
			switch_on = menu;
			break;
		case 3:
			cout << "Enter Surname: ";
			foreg_pass.set_surname();
			cout << "Enter Name: ";
			foreg_pass.set_name();
			cout << "Enter Pantronymic: ";
			foreg_pass.set_pantronymic();
			cout << "Enter Sex: ";
			foreg_pass.set_sex();
			cout << "Enter Nationality: ";
			foreg_pass.set_nationality();
			cout << "Enter birght day: \n";
			foreg_pass.set_date_birght();
			do
			{
				cout << "Enter set expiry year: ";
				cin >> expir;
			} while (expir < 1);
			cin.get();
			cout << "Enter build passport date: \n";
			foreg_pass.set_date_expiry(expir);
			cout << "Enter Record num: ";
			foreg_pass.set_record_num();
			cout << "Enter Document num: ";
			foreg_pass.set_document_num();
			switch_on = menu;
			break;
		case 4:
			cout << "\nSurname: \t\t\t" << foreg_pass.get_surname();
			cout << "\nName: \t\t\t\t" << foreg_pass.get_name();
			cout << "\nPantronymic: \t\t\t" << foreg_pass.get_pantronymic();
			cout << "\nEnter Sex: \t\t\t" << foreg_pass.get_sex();
			cout << "\nNationality: \t\t\t" << foreg_pass.get_nationality();
			cout << "\nBirght day: \t\t\t";
			foreg_pass.get_date_birght();
			cout << "\nexpiry: \t\t\t";
			foreg_pass.get_date_expiry();
			cout << "\nRecord num: \t\t\t" << foreg_pass.get_record_num();
			cout << "\nDocument num: \t\t\t" << foreg_pass.get_document_num();
			switch_on = menu;
			cout << "\n\nVISA: \n";
			foreg_pass.print_visas(); 
			switch_on = menu;
			break;
		case 5:
			switch_on = menu;
			foreg_pass.add_visa();
			break;
		case 6:
			foreg_pass.clo_minus_days();
			switch_on = menu;
			break;
		case 7:
			switch_on = menu;
			break;
		case 8:
			switch_on = menu;
			break;
		case 9:
			switch_on = menu;
			break;

		default:
			break;
		}

	} while (switch_on != 0);
	return 0;
}

