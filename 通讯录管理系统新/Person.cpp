#include"Person.h"

Person::Person(string name, string phone, string email, string birthday, int relationship)
	:name(name), Phonenumber(phone), email(email), birthday(birthday), relationship(relationship)
{
}
void Person::Show() {
	cout << "����: " << this->name << " �ֻ���: " << this->Phonenumber
		<< "  ����: " << this->email << "  ����: " << this->birthday;
}