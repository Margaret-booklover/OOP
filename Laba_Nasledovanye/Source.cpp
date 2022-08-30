#define _CRT_SECURE_NO_WARNINGS
#include "bank.h"
#include <iostream>
#include <iomanip>
using namespace std;

int check(int max)
{
	char vvod[15];
	gets_s(vvod);
	if (vvod[0] == NULL) gets_s(vvod);
	for (int i = 0; i < strlen(vvod); i++) {
		if ((vvod[i] < 48) || (vvod[i] > 57)) {
			throw except("Введите числовую информацию!!");
			break;
		}
	}
	if ((atoi(vvod) > max) || (atoi(vvod) < 0))
	{
		throw except( "Введенное число не попадает в заданный диапазон, проверьте корректность данных" );
		int out = check(max);
		return out;
	}
	return atoi(vvod);
}

FIO::FIO()
{
	name = new char[100];
	strcpy(name, "Ivan");
	fam = new char[100];
	strcpy(fam, "Ivanov");
	father = new char[100];
	strcpy(father, "Ivanovich");

}

FIO::~FIO()
{
	delete[] name;
	delete[] father;
	delete[] fam;
}

deposit* operator+(deposit& ob, int plus)
{
	ob.sum = ob.sum + plus;
	return &ob;
}

void bank::add_klient()
{
	cout << "Работает функция базового класса"<<endl;
}

void bank::sort()
{
	cout << "Работает функция базового класса" << endl;
}

void bank::poisk()
{
	cout << "Работает функция базового класса" << endl;
}

void bank::load_klient(const char* filename)
{
	cout << "Работает функция базового класса" << endl;
}

void bank::save_klient(const char* filename)
{
	cout << "Работает функция базового класса" << endl;
}