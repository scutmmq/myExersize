#pragma once
#include"Person.h"
class Colleague :public Person {
public:
	Colleague(string, string, string, string, int, string);

	string workplace;

	virtual void Show();

	virtual string getmore();

	virtual void ReviseMore();
};