#include"Classmate.h"

Classmate::Classmate(string name, string phone, string email, string birthday, int relationship, string school)
	:Person(name, phone, email, birthday, relationship), school(school)
{}

void Classmate::Show() {
	Person::Show();
	cout << "  ͬѧ: " << this->school << endl;
}

string Classmate::getmore() {
	return this->school;
}

void Classmate::ReviseMore() {
	string s;
	cin >> s;
	this->school = s;
}