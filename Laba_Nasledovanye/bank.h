#pragma once
#include <iostream>
class bank;
class deposit;
class FIO
{
protected:
	char* name;
	char* fam;
	char* father;
public:
	friend class bank;
	FIO();
	~FIO();
	friend deposit* operator+(deposit& ob, int plus);
};

class bank    // базовый класс, от него пойдут две ветки: депозит и кредит
{
protected:
	FIO fio;
	int account;
public:
	void add_klient();
	virtual void sort();
	void poisk();
	void load_klient(const char* filename);
	void save_klient(const char* filename);

};

class deposit :public bank, public FIO
{
	double sum;
public:
	static int dcount;
	void minus();
	void poisk_fio();
	void printall(deposit* p, int n);
	void operator<<(deposit* ob);
	void poisk();
	void sort();
	void add_klient();
	friend deposit* operator+(deposit& ob, int plus);
	void load_klient(const char* filename);
	void save_klient(const char* filename);
};

class credit :protected bank, protected FIO
{
	double sum;
	double percent;
	int month;
	double sumpermonth;
public:
	void minus();
	static int ccount;
	void poisk_fio();
	void printall(credit* p, int n);
	void operator<<(credit* ob);
	void poisk();
	void sort();
	void add_klient();
	friend credit* operator+(credit& ob, int plus);
	void load_klient(const char* filename);
	void save_klient(const char* filename);
};

class except
{
public:
	char msg[80];
	except() { *msg = 0; }
	except(const char* s) { strcpy(msg, s); }
};
