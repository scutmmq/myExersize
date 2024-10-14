#pragma once
#include<iostream>
#include"Person.h"
#include"Classmate.h"
#include"Friend.h"
#include"Colleague.h"
#include"Relative.h"
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
class AddressBook {
public:
	AddressBook();

	~AddressBook();

	void Show_Menu();//展示菜单

	void ExitSystem();//退出系统

	void AddPerson();//添加联系人

	int personNumbers;//联系人数量

	void save();//写文件

	Person** person;

	bool FileEmpty1, FileEmpty2, FileEmpty3, FileEmpty4;//判断文件是否为空

	bool FileExit1, FileExit2, FileExit3, FileExit4;//判断文件是否存在

	int get_people();//读文件统计人数

	void initial();//读文件初始化员工

	void ShowContacts();//显示联系人

	void DeleteContacts();//删除联系人

    int IsExist(string);//判断联系人是否存在

	void IfFileEmpty();//判断文件是否为空

	void ReviseContact();//修改联系人信息

	void FindContact();//查找联系人

	void SortContact();//排序联系人

	void SortName();//按姓名首字母排序

	void SortBirthday();//按生日日期排序

	void SortBaseMouth();//根据月份显示联系人
	
	void RecentBirthday();//查询近期生日联系人

	int Get_Days(int,int);//获取某年每月的当月总共天数

	void SendBlessing(int);//发送生日祝福

	void ShowBirthday(int,int,int,int,int,int);//展现生日信息
};