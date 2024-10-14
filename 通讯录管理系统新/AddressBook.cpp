#include<fstream>
#pragma comment(lib,"ws2_32.lib")
#include"AddressBook.h"
#define Filename1 "AddressBook1.txt"
#define Filename2 "AddressBook2.txt"
#define Filename3 "AddressBook3.txt"
#define Filename4 "AddressBook4.txt"
AddressBook::AddressBook() {
	
	//初始化文件存在判断标识
	FileExit1 = true;
	FileExit2 = true;
	FileExit3 = true;
	FileExit4 = true;

	//初始化空文件判断标识
	FileEmpty1 = false;
	FileEmpty2 = false;
	FileEmpty3 = false;
	FileEmpty4 = false;

	//判断四个文件是否存在，初始化数据
	ifstream ifs1;
	ifs1.open(Filename1, ios::in);
	if (!ifs1.is_open())FileExit1 = false;
	ifs1.close();

	ifstream ifs2;
	ifs2.open(Filename2, ios::in);
	if (!ifs2.is_open())FileExit2 = false;
	ifs2.close();

	ifstream ifs3;
	ifs3.open(Filename3, ios::in);
	if (!ifs3.is_open())FileExit3 = false;
	ifs3.close();

	ifstream ifs4;
	ifs4.open(Filename4, ios::in);
	if (!ifs4.is_open())FileExit4 = false;
	ifs4.close();

	//若文件不存在，初始化数据为空
	if (!FileExit1 && !FileExit2 && !FileExit3 && !FileExit4) {

		this->personNumbers = 0;

		this->person = nullptr;
		return;
	}

	//判断文件是否为空,并初始化空文件标识
	IfFileEmpty();

	//如果四个文件都为空，初始化数据
	if (FileEmpty1 && FileEmpty2 && FileEmpty3 && FileEmpty4) {
		
		this->personNumbers = 0;

		this->person = nullptr;

		return;
	}

	//若文件存在，读文件，初始化数据
	this->personNumbers = this->get_people();

	this->person = new Person * [personNumbers];
	//文件中的数据存在数组中
	this->initial();

}

AddressBook::~AddressBook() {
	if (this->person != nullptr) {
		delete[]this->person;
		this->person = nullptr;
	}
}

void AddressBook::Show_Menu() {
	cout << "欢迎使用通讯录管理系统！(输入选项后按回车键即可操作)" << endl;
	cout << "0.退出系统" << endl;
	cout << "1.添加联系人" << endl;
	cout << "2.显示联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.修改联系人信息" << endl;
	cout << "5.查找联系人" << endl;
	cout << "6.对联系人进行排序" << endl;
	cout << "7.给定月份显示联系人" << endl;
	cout << "8.查询近期生日联系人" << endl;
	cout << endl;
}

void AddressBook::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void AddressBook::AddPerson() {
	string name;
	string phone;
	string email;
	string birthday;
	int relationship;
	string school;
	string meetplace;
	string workplace;
	string callname;

	Person** newSpace = new Person * [personNumbers + 1];
	//原来空间下的数据，拷贝到新空间
	if (this->person != nullptr) {
		for (int i = 0; i < personNumbers; i++) {
			newSpace[i] = this->person[i];
		}
	}

	cout << "请选择所添加联系人的类别:" << endl;
	cout << "1.同学\t" << "2.同事\t" << "3.朋友\t" << "4.亲戚\t" << endl;
	cout << "请选择:";
	int choice = 0;
	cin >> choice;
	Person* people = nullptr;
	switch (choice) {
	case 1:
		relationship = choice;
		cout << "姓名: "; cin >> name;
		cout << "电话号码: "; cin >> phone;
		cout << "邮箱: "; cin >> email;
		cout << "生日(例如生于2004年1月1日,则输入20240101): "; cin >> birthday;
		cout << "学校: "; cin >> school;
		people = new Classmate(name, phone, email, birthday, relationship, school);
		break;
	case 2:
		relationship = choice;
		cout << "姓名: "; cin >> name;
		cout << "电话号码: "; cin >> phone;
		cout << "邮箱: "; cin >> email;
		cout << "生日(例如生于2004年1月1日,则输入20240101): "; cin >> birthday;
		cout << "工作地点: "; cin >> workplace;
		people = new Colleague(name, phone, email, birthday, relationship, workplace);
		break;
	case 3:
		relationship = choice;
		cout << "姓名: "; cin >> name;
		cout << "电话号码: "; cin >> phone;
		cout << "邮箱: "; cin >> email;
		cout << "生日(例如生于2004年1月1日,则输入20240101): "; cin >> birthday;
		cout << "认识地点: "; cin >> meetplace;
		people = new Friend(name, phone, email, birthday, relationship, meetplace);
		break;
	case 4:
		relationship = choice;
		cout << "姓名: "; cin >> name;
		cout << "电话号码: "; cin >> phone;
		cout << "邮箱: "; cin >> email;
		cout << "生日(例如生于2004年1月1日,则输入20240101): "; cin >> birthday;
		cout << "称呼: "; cin >> callname;
		people = new Relative(name, phone, email, birthday, relationship, callname);
		break;
	default:
		cout << "输入错误！请回到主菜单重新操作" << endl;
		system("pause");
		system("cls");
		return;
		break;
	}
	//创建的联系人保存到数组中
	newSpace[personNumbers] = people;

	if (person != nullptr)delete[]this->person;

	this->person = newSpace;


	this->personNumbers++;

	save();

	cout << "添加联系人成功" << endl;

	IfFileEmpty();

	system("pause");
	system("cls");
}


void AddressBook::save() {
	ofstream ofs1, ofs2, ofs3, ofs4;

	ofs1.open(Filename1, ios::out);
	for (int i = 0; i < this->personNumbers; i++) {
		if (this->person[i]->relationship == 1) {
			ofs1 << this->person[i]->name << " "
				<< this->person[i]->Phonenumber << " "
				<< this->person[i]->email << " "
				<< this->person[i]->birthday << " "
				<< this->person[i]->getmore() << endl;
		}
	}
	ofs1.close();

	ofs2.open(Filename2, ios::out);
	for (int i = 0; i < this->personNumbers; i++) {
		if (this->person[i]->relationship == 2) {
			ofs2 << this->person[i]->name << " "
				<< this->person[i]->Phonenumber << " "
				<< this->person[i]->email << " "
				<< this->person[i]->birthday << " "
				<< this->person[i]->getmore() << endl;
		}
	}
	ofs2.close();

	ofs3.open(Filename3, ios::out);
	for (int i = 0; i < this->personNumbers; i++) {
		if (this->person[i]->relationship == 3) {
			ofs3 << this->person[i]->name << " "
				<< this->person[i]->Phonenumber << " "
				<< this->person[i]->email << " "
				<< this->person[i]->birthday << " "
				<< this->person[i]->getmore() << endl;
		}
	}
	ofs3.close();

	ofs4.open(Filename4, ios::out);
	for (int i = 0; i < this->personNumbers; i++) {
		if (this->person[i]->relationship == 4) {
			ofs4 << this->person[i]->name << " "
				<< this->person[i]->Phonenumber << " "
				<< this->person[i]->email << " "
				<< this->person[i]->birthday << " "
				<< this->person[i]->getmore() << endl;
		}
	}
	ofs4.close();
}

int AddressBook::get_people() {
	//读四个文件
	ifstream ifs1, ifs2, ifs3, ifs4;

	int number = 0;//统计人数的变量
	ifs1.open(Filename1, ios::in);//读同学文件
	string buf;
	while (getline(ifs1, buf)) {
		number++;
	}
	ifs1.close();

	ifs2.open(Filename2, ios::in);//读同事文件
	while (getline(ifs2, buf)) {
		number++;
	}
	ifs2.close();

	ifs3.open(Filename3, ios::in);//读朋友文件
	while (getline(ifs3, buf)) {
		number++;
	}
	ifs3.close();

	ifs4.open(Filename4, ios::in);//读亲戚文件
	while (getline(ifs4, buf)) {
		number++;
	}
	ifs4.close();

	return number;
}

void AddressBook::initial() {
	//读四个文件
	ifstream ifs1, ifs2, ifs3, ifs4;

	//类的数据
	string name;
	string phone;
	string email;
	string birthday;
	string themore;

	int index = 0;//指针下标

	ifs1.open(Filename1, ios::in);//读同学文件
	while (ifs1 >> name >> phone >> email >> birthday >> themore && ifs1.is_open()) {
		Person* people = nullptr;
		people = new Classmate(name, phone, email, birthday, 1, themore);
		this->person[index] = people;
		index++;
	}
	ifs1.close();

	ifs2.open(Filename2, ios::in);//读同事文件
	while (ifs2 >> name >> phone >> email >> birthday >> themore && ifs2.is_open()) {
		Person* people = nullptr;
		people = new Colleague(name, phone, email, birthday, 2, themore);
		this->person[index] = people;
		index++;
	}
	ifs2.close();

	ifs3.open(Filename3, ios::in);//读朋友文件
	while (ifs3 >> name >> phone >> email >> birthday >> themore && ifs3.is_open()) {
		Person* people = nullptr;
		people = new Friend(name, phone, email, birthday, 3, themore);
		this->person[index] = people;
		index++;
	}
	ifs3.close();

	ifs4.open(Filename4, ios::in);//读亲戚文件
	while (ifs4 >> name >> phone >> email >> birthday >> themore && ifs4.is_open()) {
		Person* people = nullptr;
		people = new Relative(name, phone, email, birthday, 4, themore);
		this->person[index] = people;
		index++;
	}
	ifs4.close();
}
void AddressBook::ShowContacts() {
		cout << "选择如下:" << endl
			<< "1.全部联系人\t" << "2.同学\t" << "3.同事\t" << "4.朋友\t" << "5.亲戚" << endl
			<< "请选择:";
		int choice;
		cin >> choice;
		Person** index = nullptr;
		int size = 0;
		switch (choice) {
		case 1:
			if ((!FileEmpty1 || !FileEmpty2 || !FileEmpty3 || !FileEmpty4)&&FileExit1 && FileExit2 && FileExit3 && FileExit4) {
				index = this->person;
				size = this->personNumbers;
				for (int i = 0; i < size; i++) {
					index[i]->Show();
				}
			}
			else {
				cout << "所有目录不存在联系人！" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!FileEmpty1 && FileExit1) {
				index = this->person;
				size = this->personNumbers;
				for (int i = 0; i < size; i++) {
					if (index[i]->relationship == 1) {
						index[i]->Show();
					}
				}
			}
			else {
				cout << "“同学”目录不存在联系人！" << endl;
			}
			system("pause");
			break;
		case 3:
			if (!FileEmpty2 && FileExit2) {
				index = this->person;
				size = this->personNumbers;
				for (int i = 0; i < size; i++) {
					if (index[i]->relationship == 2) {
						index[i]->Show();
					}
				}
			}
			else {
				cout << "“同事”目录不存在联系人！" << endl;
			}
			system("pause");
			break;
		case 4:
			if (!FileEmpty3&&FileExit3) {
				index = this->person;
				size = this->personNumbers;
				for (int i = 0; i < size; i++) {
					if (index[i]->relationship == 3) {
						index[i]->Show();
					}
				}
			}
			else {
				cout << "“朋友”目录不存在联系人！" << endl;
			}
			system("pause");
			break;
		case 5:
			if (!FileEmpty4&&FileExit4) {
				index = this->person;
				size = this->personNumbers;
				for (int i = 0; i < size; i++) {
					if (index[i]->relationship == 4) {
						index[i]->Show();
					}
				}
			}
			else {
				cout << "“亲戚”目录不存在联系人！" << endl;
			}
			system("pause");
			break;
		default:
			cout << "输入错误！请回到主菜单重新操作！" << endl;
			system("pause");
			system("cls");
			return;
			break;
	}
		system("cls");
}

int AddressBook::IsExist(string s) {
	int index = -1;
	for (int i = 0; i < this->personNumbers; i++) {
		if (this->person[i]->name == s) {
			index = i;
			return index;
		}
	}
	return index;
}

void AddressBook::DeleteContacts() {
	while (1) {
		cout << "请输入你所要删除联系人的姓名:";
		string del_name;
		cin >> del_name;
		if (this->IsExist(del_name) != -1) {

			int index = this->IsExist(del_name);

			for (int i = index; i < this->personNumbers - 1; i++) {
				//数据前移
				this->person[i] = this->person[i + 1];
			}
			this->personNumbers--;//更新人数

			//同步更新到文件里
			this->save();

			this->IfFileEmpty();

			cout << "删除联系人成功！" << endl;
		}
		else {
			cout << "联系人不存在！" << endl;
		}
		cout << "是否需要继续删除联系人？" << "  " << "1.是  2.否，回到主菜单" << endl;
		cout << "请选择:";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			break;
		case 2:
			system("cls");
			return;
		}
	}
}

void AddressBook::IfFileEmpty() {
	ifstream ifs1, ifs2, ifs3, ifs4;
	ifs1.open(Filename1, ios::in);
	char ch;
	ifs1 >> ch;
	if (ifs1.eof()) {
		FileEmpty1 = true;
	}
	else {
		FileEmpty1 = false;
	}
	ifs1.close();

	ifs2.open(Filename2, ios::in);
	ifs2 >> ch;
	if (ifs2.eof()) {
		FileEmpty2 = true;
	}
	else {
		FileEmpty2 = false;
	}
	ifs2.close();

	ifs3.open(Filename3, ios::in);
	ifs3 >> ch;
	if (ifs3.eof()) {
		FileEmpty3 = true;
	}
	else {
		FileEmpty3 = false;
	}
	ifs3.close();

	ifs4.open(Filename4, ios::in);
	ifs4 >> ch;
	if (ifs4.eof()) {
		FileEmpty4= true;
	}
	else {
		FileEmpty4 = false;
	}
	ifs4.close();
}

void AddressBook::ReviseContact() {
	cout << "请输入你要修改的联系人的姓名:";
	string rev_name;
	cin >> rev_name;
	if (IsExist(rev_name) != -1) {
		bool IfContinue = true;
		int index = IsExist(rev_name);
		while (IfContinue) {
			cout << "您要修改此联系人的哪一项信息?" << endl;
			cout << "1.姓名  2.电话号码  3.邮箱地址  4.生日日期  ";
			if (this->person[index]->relationship == 1) {
				cout << "5.学校" << endl;
			}
			if (this->person[index]->relationship == 2) {
				cout << "5.工作地点" << endl;
			}
			if (this->person[index]->relationship == 3) {
				cout << "5.认识地点" << endl;
			}
			if (this->person[index]->relationship == 4) {
				cout << "5.称呼" << endl;
			}
			cout << "请输入:";
			string s;
			int choice;
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "您要将ta的姓名修改为:";
				cin >> s;
				this->person[index]->name = s;
				break;
			case 2:
				cout << "您要将ta的电话号码修改为:";
				cin >> s;
				this->person[index]->Phonenumber = s;
				break;
			case 3:
				cout << "您要将ta的邮箱地址修改为:";
				cin >> s;
				this->person[index]->email = s;
				break;
			case 4:
				cout << "您要将ta的生日日期将修改为:";
				cin >> s;
				this->person[index]->birthday = s;
				break;
			case 5:
				if (this->person[index]->relationship == 1) {
					cout << "您要将你们一起读的学校修改为:" << endl;
					this->person[index]->ReviseMore();
				}
				if (this->person[index]->relationship == 2) {
					cout << "您要将你们的工作地点修改为:" << endl;
					this->person[index]->ReviseMore();
				}
				if (this->person[index]->relationship == 3) {
					cout << "您要将你们认识的地点修改为:" << endl;
					this->person[index]->ReviseMore();
				}
				if (this->person[index]->relationship == 4) {
					cout << "您要将你对ta的称呼修改为:" << endl;
					this->person[index]->ReviseMore();
				}
				break;
			default:
				cout << "输入有误！" << endl;
				cout << "回到主菜单重新操作！" << endl;
				system("pause");
				system("cls");
				return;
				break;
			}

			cout << "信息修改成功！" << endl;

			this->save();

			this->IfFileEmpty();

			cout << "您是否需要继续修改此联系人的信息？" << "  1.是  2.否" << endl;
			cout << "请选择:";
			int choice1;
			cin >> choice1;
			switch (choice1) {
			case 1:
				break;
			case 2:
				IfContinue = false;

				system("pause");
				system("cls");
			}
		}
	}
	else {
		cout << "联系人不存在！" << endl;
		cout << "将回到主菜单重新操作！" << endl;
		system("pause");
		system("cls");
		return;
	}

}

void AddressBook::FindContact() {
	cout << "请输入您要查找的联系人的姓名:";
	string s;
	cin >> s;
	if (this->IsExist(s) != -1) {
		int index = this->IsExist(s);
		cout << "您所查找的联系人的信息为:" << endl;
		this->person[index]->Show();
	}
	else {
		cout << "联系人不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}

void AddressBook::SortContact() {
	cout << "您需要按什么来排序:" << "  1.按姓名首字母排序  2.按生日日期排序" << endl;
	cout << "请选择:";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:

		this->SortName();

		this->save();
		
		cout << "排序成功！" << endl;

		this->ShowContacts();

		break;
	case 2:
		
		this->SortBirthday();

		this->save();

		cout << "排序成功！" << endl;

		this->ShowContacts();
		break;
	}
}

void AddressBook::SortName() {
	for (int i = 0; i < this->personNumbers - 1; i++) {
		for (int j = 0; j < personNumbers - 1 - i; j++) {
			if (this->person[j]->name > this->person[j + 1]->name) {
				Person* temp = person[j];
				person[j] = person[j + 1];
				person[j + 1] = temp;
			}
		}
	}
}

void AddressBook::SortBirthday() {
	for (int i = 0; i < this->personNumbers - 1; i++) {
		for (int j = 0; j < personNumbers - 1 - i; j++) {
			if (this->person[j]->birthday > this->person[j + 1]->birthday) {
				Person* temp = person[j];
				person[j] = person[j + 1];
				person[j + 1] = temp;
			}
		}
	}
}

void AddressBook::SortBaseMouth() {
	int number = 0;
	cout << "您要给定的出生月份为?(例:九月输入9)" << endl;
	cout << "请输入:";
	int mouth;
	cin >> mouth;
	for (int i = 0; i < this->personNumbers; i++) {
		int m = atoi(this->person[i]->birthday.data()) / 100 % 100;
		if (m == mouth)number++;
	}
	if (number > 0) {
		cout << "出生在" << mouth << "月的联系人的人数为: " << number << endl;
		cout << "他们的信息如下:" << endl;
		for (int i = 0; i < this->personNumbers; i++) {
			int m = atoi(this->person[i]->birthday.data()) / 100 % 100;
			if (m == mouth) {
				this->person[i]->Show();
			}
		}
	}
	else {
		cout << "通讯录中没有出生在" << mouth << "月的联系人！" << endl;
	}
	system("pause");
	system("cls");
}

void AddressBook::RecentBirthday() {

	cout << "请输日期(例如2024年9月1日，年输入2024，月输入9，日输入1,星期五输入5):" << endl;
	cout << "年:"; 
	int year;
	cin >> year;
	cout << "月:";
	int month;
	cin >> month;
	cout << "日:";
	int day;
	cin >> day;
	cout << "星期:";
	int week;
	cin >> week;

	int days;//本月的天数
	int number = 0;//人数
	days = this->Get_Days(year, month);
	for (int i = 0; i < this->personNumbers; i++) {
		int m; int d;
		m = atoi(this->person[i]->birthday.data()) / 100 % 100;
		d = atoi(this->person[i]->birthday.data()) % 100;
		
		if (m == month) {
			if (d-day < 5 && d-day >= 0) {
				number++;
			}
		}
		if (m - month == 1) {
			if (days - day + d < 5 && days - day + d >= 0) {
				number++;
			}
		}
		if (month == 12 && m == 1) {
			if (days - day + d < 5 && days - day + d >= 0) {
				number++;
			}
		}
	}
	if (number > 0) {
		cout << "当前时间:" << year << "年" << month << "月" << day << "日" << endl;
		cout << "五天内一共有" << number << "位联系人要过生日" << endl;
		cout << "他们的信息如下:" << endl;
		for (int i = 0; i < this->personNumbers; i++) {
			int m; int d;
			m = atoi(this->person[i]->birthday.data()) / 100 % 100;
			d = atoi(this->person[i]->birthday.data()) % 100;
			if (m == month) {
				if (d-day < 5 && d-day>=0) {
					this->ShowBirthday(year, month, day, week, days, i);
				}
			}
			if (m - month == 1) {
				if (days - day + d < 5 && days - day + d >= 0) {
					this->ShowBirthday(year, month, day, week, days, i);
				}
			}
			if (month == 12 && m == 1) {
				if (days - day + d < 5 && days - day + d >= 0) {
					this->ShowBirthday(year, month, day, week, days, i);
				}
			}
		}
		int choice;
		cout << "您今天需要发送生日祝福吗？  1.是  2.否" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			break;
		case 2:
			system("pause");
			system("cls");
			return;
			break;
		}
		int temp = 1;
		while (temp) {
			cout << "您要给哪位联系人发送生日祝福,请输入ta的姓名:";
			string s;
			cin >> s;
			int n = this->IsExist(s);
			this->SendBlessing(n);
			cout << "发送成功！内容如下:" << endl;
			cout << this->person[n]->name << endl << "        祝生日快乐，健康幸福。" << endl << "                                莫明钦" << endl;
			cout << "是否需要继续向其他联系人发送生日祝福:    1.是   2.否" << endl;
			cin >> choice;
			switch(choice) {
			case 1:
				break;
			case 2:
				temp = 0;
				break;
			}
		}
	}
	else {
		cout << "未查询到近五日要过生日的联系人！" << endl;
	}
	system("pause");
	system("cls");
}

int AddressBook::Get_Days(int y,int m) {

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		return 31;
	}

	else if (m != 2) {
		return 30;
	}

	else {
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
			return 29;
		}
		else {
			return 28;
		}
	}
}

void AddressBook::SendBlessing(int i) {
	//打开网络权限
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//连接qq邮箱服务器
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(587);//QQ邮箱的端口号为587
	memcpy(&local.sin_addr, gethostbyname("smtp.qq.com")->h_addr, sizeof(struct in_addr));
	//连接
	connect(sock, (struct sockaddr*)&local, sizeof(struct sockaddr));
	char buff[1024] = { 0 };
	recv(sock, buff, 1024, 0);

	//发送 
	string SendBuff = "HELO MSG\r\n";
	send(sock, SendBuff.c_str(), SendBuff.length(), 0);

	memset(buff, 0, 1024);
	recv(sock, buff, 1024, 0);

	SendBuff = "AUTH LOGIN\r\n";
	send(sock, SendBuff.c_str(), SendBuff.length(), 0);

	memset(buff, 0, 1024);
	recv(sock, buff, 1024, 0);

	//发送用户名
	SendBuff = "MjAxODE0Nzc0OUBxcS5jb20=\r\n";//BASE64编码的QQ邮箱账号
	send(sock, SendBuff.c_str(), SendBuff.length(), 0);

	memset(buff, 0, 1024);
	recv(sock, buff, 1024, 0);

	//发送识别码 
	SendBuff = "aml2Ymp4aGdkYnV1YmRnZA==\r\n";//BASE64编码的SMTP服务器授权码
	send(sock, SendBuff.c_str(), SendBuff.length(), 0);

	memset(buff, 0, 1024);
	recv(sock, buff, 1024, 0);

	//登录账号成功

	//发件人邮箱信息
	SendBuff = "MAIL FROM:<2018147749@qq.com>\r\n";
	send(sock, SendBuff.c_str(), SendBuff.length(), 0);

	memset(buff, 0, 1024);
	recv(sock, buff, 1024, 0);

	//发送收件人邮箱2680454202@qq.com
	SendBuff = "RCPT TO:<";
	SendBuff += this->person[i]->email;
	SendBuff += ">\r\n";
	send(sock, SendBuff.c_str(), SendBuff.length(), 0);

	memset(buff, 0, 1024);
	recv(sock, buff, 1024, 0);

	//发送DATA
	SendBuff = "DATA\r\n";
	send(sock, SendBuff.c_str(), SendBuff.length(), 0);

	memset(buff, 0, 1024);
	recv(sock, buff, 1024, 0);

	//<CR><LF>.<CR><LF>
		//发送数据
	SendBuff = "From:莫明钦 <2018147749@qq.com>\r\n";
	SendBuff += "subject:生日祝福\r\n\r\n";//标题
	SendBuff += this->person[i]->name;
	SendBuff += "\n        祝生日快乐，健康幸福。\n                                莫明钦\r\n\r\n";//正文
	SendBuff += "\r\n\.\r\n";//结束符
	send(sock, SendBuff.c_str(), SendBuff.length(), 0);

	memset(buff, 0, 1024);
	recv(sock, buff, 1024, 0);


	SendBuff = "Quit\r\n";
	send(sock, SendBuff.c_str(), SendBuff.length(), 0);

	memset(buff, 0, 1024);
	recv(sock, buff, 1024, 0);
}

void AddressBook::ShowBirthday(int y,int m,int d,int w,int days,int i) {
	int month = atoi(this->person[i]->birthday.data()) / 100 % 100;
	int day = atoi(this->person[i]->birthday.data()) % 100;
	cout << month << "月" << day << "日";
	if (m == month) {
		w = w + day - d;
	}

	if (month - m == 1) {
		w = w + days - d + day;
	}

	if (month == 1 && m == 12) {
		w = w + days - d + day;
	}

	if (w > 7) {
		w = w - 7;
	}

	if (w == 1) {
		cout << "(星期一)";
	}
	if (w == 2) {
		cout << "(星期二)";
	}
	if (w == 3) {
		cout << "(星期三)";
	}
	if (w == 4) {
		cout << "(星期四)";
	}
	if (w == 5) {
		cout << "(星期五)";
	}
	if (w == 6) {
		cout << "(星期六)";
	}
	if (w == 7) {
		cout << "(星期日)";
	}
	if (this->person[i]->relationship == 1) {
		cout << " 同学: " << this->person[i]->name << " 邮箱: " << this->person[i]->email << " 电话: " << this->person[i]->Phonenumber << endl;
	}
	if (this->person[i]->relationship == 2) {
		cout << " 同事: " << this->person[i]->name << " 邮箱: " << this->person[i]->email << " 电话: " << this->person[i]->Phonenumber << endl;
	}
	if (this->person[i]->relationship == 3) {
		cout << " 朋友: " << this->person[i]->name << " 邮箱: " << this->person[i]->email << " 电话: " << this->person[i]->Phonenumber << endl;
	}	
	if (this->person[i]->relationship == 4) {
		cout <<" "<<this->person[i]->getmore() << ": " << this->person[i]->name << " 邮箱: " << this->person[i]->email << " 电话: " << this->person[i]->Phonenumber << endl;
	}
}