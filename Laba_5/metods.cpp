#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include "Header.h"
#include <fstream>

bank::bank(char* fam, char* name, char* father, int account, double sum)
{
	this->fio.fam = new char[strlen(fam) + 1];
	strcpy(this->fio.fam, fam);
	this->fio.name = new char[strlen(name) + 1];
	strcpy(this->fio.name, name);;
	this->fio.father = new char[strlen(father) + 1];
	strcpy(this->fio.father, father);
	this->account = account;
	this->sum = sum;
}

fio::fio()
{
	name = new char[100];
	strcpy(name, "");
	fam = new char[100];
	strcpy(fam, "");
	father = new char[100];
	strcpy(father, "");

}

fio::fio(char* f, char* n, char* o)
{
	name = new char[100];
	strcpy(name, n);
	fam = new char[100];
	strcpy(fam, f);
	father = new char[100];
	strcpy(father, o);
}

fio::~fio()
{
	delete[] name;
	delete[] father;
	delete[] fam;
}

bank::bank()
{
	this->account = 123456;
	this->sum = 0;
}

bank::~bank()
{
	//	count--;
}

int check(int max)
{
	char vvod[15];
	gets_s(vvod);
	if (vvod[0] == NULL) gets_s(vvod);

	for (int i = 0; i < strlen(vvod); i++) {
		if ((vvod[i] < 48) || (vvod[i] > 57)) {
			cout << "������� �������� ����������!" << endl;
			int out = check(max);
			return out;
		}
	}
	if ((atoi(vvod) > max) || (atoi(vvod) < 0))
	{
		cout << "��������� ����� �� �������� � �������� ��������, ��������� ������������ ������" << endl;
		int out = check(max);
		return out;
	}
	return atoi(vvod);
}

inline std::ostream& operator<< (std::ostream& p, bank& ob)
{
//	std::copy(ob.begin(), ob.end(), std::ostream_iterator<bank>(cout, " "));
	p << ob.get_fam() << setw(10) << ob.get_name() << setw(10) <<ob.get_father() << setw(10)  << ob.account << setw(10) << ob.sum;
	return p;
}

void bank::poisk(list<bank> mas)
{
	int a;
	int i = 0;
	cout << "������ ����� �����: ";
	cin >> a;
	list<bank> temp;
	cout << endl;
	int flag = 0;
	for (list<bank>::iterator k = mas.begin(); k != mas.end(); ++k)
	{
		if (k->account == a)
		{
			if (flag == 0)
			{
				cout << endl << "                  ������� ������������������ ��������:" << endl;
				cout << "-------------------------------------------------------------------------------------" << endl;;
				cout << "�" << setw(15) << "�������" << setw(15) << "���" << setw(15) << "��������" <<
					setw(20) << "����� �����" << setw(20) << "����� �� �����" << endl;
				cout << "----------------------------------------------------------------------------------" << endl;
				flag++;
			}
			cout << i + 1 << " ";
			cout << *k;
			cout << endl;
			i++;
			
		}
	}
}

void bank::printall(std::list<bank> all)
{
	int i = 0;
	cout << endl << "                  ������� ������������������ ��������:" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;;
	cout << "�" << setw(15) << "�������" << setw(15) << "���" << setw(15) << "��������" <<
		setw(20) << "����� �����" << setw(20) << "����� �� �����" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	for (list<bank>::iterator k = all.begin(); k != all.end(); ++k)
	{
		cout << i + 1 << " ";
		i++;
		cout << *k;
		cout << endl;
	}
}

list<bank> bank::load_klient(std::list<bank> all)
{
	ifstream fp;
	fp.open("basa.txt", std::ios::app);
	char name[100], fam[100], fat[100], buf[100];
	int s, a, n, p;
	n = 0;
	if ((fp.is_open()) == NULL)	printf("���� �� ������ ��� ������\n");
	fp >> n;
	for (int i = 0; i < n; i++)
	{
		fp >> fam;
		fp >> name;
		fp >> fat;
		fp >> a;
		fp >> s;
		bank ob(fam, name, fat, a, s);
		all.push_back(ob);
	}
	fp.close();
	return all;
}

void bank::save_klient(std::list<bank> all, int n)
{
	ofstream ptr;
	ptr.open("basa.txt");
	if ((ptr.is_open()) == NULL)	printf("���� �� ������ ��� ������\n");
	ptr << n << endl;
	for (list<bank>::iterator k = all.begin(); k != all.end(); ++k)
	{
		ptr << k->get_fam() << " ";
		ptr << k->get_name() << " ";
		ptr << k->get_father() << " ";
		ptr << k->account << " ";
		ptr << k->sum << endl;
	}
	ptr.close();
}

bank bank::operator+(int n)
{
	cout << "from  operator+ befor plus " << get_fam() << endl;
	this->sum=this->sum + n;
	cout << "from  operator+ after plus " << get_fam() << endl;
	return *this;
}