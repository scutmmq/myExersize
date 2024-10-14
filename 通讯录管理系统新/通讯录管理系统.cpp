#include"AddressBook.h"
#include<string>
using namespace std;
int main() {
	AddressBook addressbook;
	int choice;
	while (true) {
		addressbook.Show_Menu();
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ:";
		cin >> choice;
		switch (choice) {
		case 0:
			addressbook.ExitSystem();
			break;
		case 1:
			addressbook.AddPerson();
			break;
		case 2:
			addressbook.ShowContacts();
			break;
		case 3:
			addressbook.DeleteContacts();
			break;
		case 4:
			addressbook.ReviseContact();
			break;
		case 5:
			addressbook.FindContact();
			break;
		case 6:
			addressbook.SortContact();
			break;
		case 7:
			addressbook.SortBaseMouth();
			break;
		case 8:
			addressbook.RecentBirthday();
			break;
		default:
			system("cls");
		}
	}
	system("pause");
	return 0;
}