#pragma once
#include"Person.h"
class Relative :public Person {
public:
	string callname;

	Relative(string, string, string, string, int, string);

	virtual void Show();

	virtual string getmore();

	virtual void ReviseMore();
};
