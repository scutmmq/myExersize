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

	int relationship;//�����ϵ

	virtual void Show() = 0;//��ʾ������Ϣ

	virtual string getmore() = 0;//���ػ���֮��Ķ������ݣ������ص㡢ѧУ����ʶ�ص㡢�ƺ�

	virtual void ReviseMore() = 0;//�޸ĵ�������Ϣ
};
