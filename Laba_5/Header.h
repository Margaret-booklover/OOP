#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <iomanip>
#include <windows.h> 
#include <iterator>
#include <algorithm> 
#include <list>
using namespace std;

class bank;
class fio
{
	char* name;
	char* fam;
	char* father;
public:
	friend class bank;
	fio();
	~fio();
	fio(char* f, char* n, char* o);
};

class bank
{
	fio fio;
public:
	int account;
	double sum;
	bank();
	bank(char* fam, char* name, char* father, int account, double sum);
	~bank();
	void printall(std::list<bank*> all);
	char* get_name() { return fio.name; }
	char* get_fam() { return fio.fam; }
	char* get_father() { return fio.father; }
	friend inline std::ostream& operator<< (std::ostream& p,bank& ob);
	static void printall(std::list<bank> all);
	static list<bank> load_klient(std::list<bank> all);
	static void poisk(list<bank> mas);
	bank operator+(int n);
	static void save_klient(std::list<bank> all,int n);
	bool operator<(const bank& cmp) const {
		return sum > cmp.sum;  //потому что по убыванию
	}
	bank(const bank& ob) 
	{
		cout << "from  bank(const bank& ob) " << endl;
		delete[] fio.fam;
		fio.fam=new char[strlen(ob.fio.fam)+1];
		strcpy(fio.fam, ob.fio.fam);
		delete[] fio.name;
		fio.name = new char[strlen(ob.fio.name) + 1];
		strcpy(fio.name, ob.fio.name);
		delete[] fio.father;
		fio.father = new char[strlen(ob.fio.father) + 1];
		strcpy(fio.father, ob.fio.father);
		account = ob.account;
		sum = ob.sum;
	}
};
