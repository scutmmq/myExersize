#include"Colleague.h"

Colleague::Colleague(string name, string phone, string email, string birthday, int relationship, string workplace) :
	Person(name, phone, email, birthday, relationship), workplace(workplace) {}

void Colleague::Show() {
	Person::Show();
	cout << " 工作地点: " << workplace << endl;
}

string Colleague::getmore() {
	return this->workplace;
}

void Colleague::ReviseMore() {
	string s;
	cin >> s;
	this->workplace = s;
}