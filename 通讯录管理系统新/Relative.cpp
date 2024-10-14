#include"Relative.h"

Relative::Relative(string name, string phone, string email, string birthday, int relationship, string callname)
	:Person(name, phone, email, birthday, relationship), callname(callname)
{}

void Relative::Show() {
	Person::Show();
	cout << "  称呼: " << this->callname << endl;
}

string Relative::getmore() {
	return this->callname;
}

void Relative::ReviseMore() {
	string s;
	cin >> s;
	this->callname = s;
}