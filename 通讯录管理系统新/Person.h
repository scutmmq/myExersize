#pragma once
#include<iostream>
#include<string>
using namespace std;
class Person {
public:
	Person(string, string, string, string, int);

	string name;

	string Phonenumber;

	string email;

	string birthday;

	int relationship;//人物关系

	virtual void Show() = 0;//显示人物信息

	virtual string getmore() = 0;//返回基类之外的额外数据，工作地点、学校、认识地点、称呼

	virtual void ReviseMore() = 0;//修改第六项信息
};
