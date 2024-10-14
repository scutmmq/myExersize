#pragma once
#include"Person.h"
class Classmate :public Person {
public:
	string school;

	Classmate(string, string, string, string, int, string);

	virtual void Show();

	virtual string getmore();

	virtual void ReviseMore();
};
