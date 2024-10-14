#pragma once
#include"Person.h"
class Friend :public Person {
public:
	string meetplace;

	Friend(string, string, string, string, int, string);

	virtual void Show();

	virtual string getmore();

	virtual void ReviseMore();
};