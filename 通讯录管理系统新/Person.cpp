#include"Person.h"

Person::Person(string name, string phone, string email, string birthday, int relationship)
	:name(name), Phonenumber(phone), email(email), birthday(birthday), relationship(relationship)
{
}
void Person::Show() {
	cout << "姓名: " << this->name << " 手机号: " << this->Phonenumber
		<< "  邮箱: " << this->email << "  生日: " << this->birthday;
}