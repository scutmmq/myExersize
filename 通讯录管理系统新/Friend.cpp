#include"Friend.h"

Friend::Friend(string name, string phone, string email, string birthday, int relationship, string meetplace)
	:Person(name, phone, email, birthday, relationship), meetplace(meetplace) {}

void Friend::Show() {
	Person::Show();
	cout << "  认识的地点: " << this->getmore() << endl;
}

string Friend::getmore() {
	return this->meetplace;
}

void Friend::ReviseMore() {
	string s;
	cin >> s;
	this->meetplace = s;
}