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

	void Show_Menu();//չʾ�˵�

	void ExitSystem();//�˳�ϵͳ

	void AddPerson();//�����ϵ��

	int personNumbers;//��ϵ������

	void save();//д�ļ�

	Person** person;

	bool FileEmpty1, FileEmpty2, FileEmpty3, FileEmpty4;//�ж��ļ��Ƿ�Ϊ��

	bool FileExit1, FileExit2, FileExit3, FileExit4;//�ж��ļ��Ƿ����

	int get_people();//���ļ�ͳ������

	void initial();//���ļ���ʼ��Ա��

	void ShowContacts();//��ʾ��ϵ��

	void DeleteContacts();//ɾ����ϵ��

    int IsExist(string);//�ж���ϵ���Ƿ����

	void IfFileEmpty();//�ж��ļ��Ƿ�Ϊ��

	void ReviseContact();//�޸���ϵ����Ϣ

	void FindContact();//������ϵ��

	void SortContact();//������ϵ��

	void SortName();//����������ĸ����

	void SortBirthday();//��������������

	void SortBaseMouth();//�����·���ʾ��ϵ��
	
	void RecentBirthday();//��ѯ����������ϵ��

	int Get_Days(int,int);//��ȡĳ��ÿ�µĵ����ܹ�����

	void SendBlessing(int);//��������ף��

	void ShowBirthday(int,int,int,int,int,int);//չ��������Ϣ
};