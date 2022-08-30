#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "bank.h"
#include "Windows.h"
using namespace std;
int check(int max);

int main() {
	setlocale(LC_ALL, "rus");
	const char* name = "deposit.txt";
	const char* filename = "credit.txt";
	const int size_max = 200;
	deposit* dep = new deposit[size_max];
	credit* cre = new credit[size_max];	
	dep->load_klient(name);
	cre->load_klient(filename);
	int n, p;
	n = 0;
	int flag = -1;
	std::cout << "Добрый день!" << endl;
	Sleep(1000);
	cout << "Добро пожаловать в электронную систему банка Русский Стандарт!" << endl;
	Sleep(1000);
	cout << "С кем вы хотели бы поработать в первую очередь? (1 - заемщики, 0 - вкладчики)" << endl;
	try
	{
		cout << "Демонстрация работы с виртуальными функциями" << endl;
		deposit::dcount = 0;
		deposit ob1;   //объект производного класса
		bank* pbank = &ob1;  //на него указывает указатель базового класса
		pbank->sort();   //пытаемся вызвать с помощью этого указателя функцию сортировки элементов производного класса 
		flag=check(1);
		do
		{
			switch (flag)
			{
			case 1:
			{
				do
				{
					if (flag == 3) break;
					cout << "На данный момент в системе зарегистрировано " << credit::ccount << " заёмщиков" << endl;
					cout << "---------------Меню-----------" << endl << "1 - добавить нового заёмщика" << endl;
					cout << " 2- распечатать информацию о всех заёмщиках" << endl << " 3 - найти заёмщика по номеру счета" << endl;
					cout << "4 - сортировать по уменьшению суммы на счете" << endl << " 5 - платеж по кредиту" << endl;
					cout << "6 - Перейти на работу с вкладчиками" << endl << "7 - Поиск по имени" << endl;
					cout << "8 - завершить работу" << endl;
					cout << "---------------------------------" << endl << " Введите номер меню..." << endl;
					p = check(8);
					switch (p)
					{
					case 1:
					{   
						if (credit::ccount > size_max) throw except("количество клиентов в базе достигло максимума, невозможно добавить запись");
					else {
						cre->add_klient();
						credit::ccount++;
						cout << "Регистрация прошла успешно" << endl;
					}
					break;
					}
					case 2:
					{
						cre->printall(cre, credit::ccount);
						break;
					}
					case 3:
					{
						cre->poisk();
						break;
					}
					case 4:
					{
						cre->sort();
						break;
					}
					case 5:
					{
						cre->minus();
						break;
					}
					case 6:
					{
						flag = 2;
						break;
					}
					case 7:
					{
						cre->poisk_fio();
						break;
					}
					case 8:
					{
						flag = 3;
						break;
					}
					}
				} while (flag == 1);
			}
			case 0:
			{
				do
				{
					if (flag == 3) break;
					cout << "На данный момент в системе зарегистрировано " << deposit::dcount << " вкладчиков" << endl;
					cout << "---------------Меню-----------" << endl << "1 - добавить нового вкладчика" << endl;
					cout << " 2- распечатать информацию о всех вкладчиках" << endl << " 3 - найти вкладчика по номеру счета" << endl;
					cout << "4 - сортировать по уменьшению суммы на счете" << endl << " 5 - списать сумму" << endl;
					cout << "6 - Перейти на работу с заёмщиками" << endl << "7 - Поиск по имени" << endl;
					cout << "8 - завершить работу" << endl;
					cout << "---------------------------------" << endl << " Введите номер меню..." << endl;
					p = check(8);
					switch (p)
					{
					case 1:
					{   if (deposit::dcount > size_max) throw except("количество клиентов в базе достигло максимума, невозможно добавить запись");
					else {
						dep->add_klient();
						deposit::dcount++;
						cout << "Регистрация прошла успешно" << endl;
					}
					break;
					}
					case 2:
					{
						dep->printall(dep, deposit::dcount);
						break;
					}
					case 3:
					{
						dep->poisk();
						break;
					}
					case 4:
					{
						dep->sort();
						break;
					}
					case 5:
					{
						dep->minus();
						break;
					}
					case 6:
					{
						flag = 1;
						break;
					}
					case 7:
					{
						dep->poisk_fio();
						break;
					}
					case 8:
					{
						flag = 3;
						break;
					}
					}
				} while (flag == 0);
			}
			}
		} while (flag != 3);
	}
	catch (except e)
	{
		cout << e.msg << endl;
	}
	dep->save_klient(name);
	delete[]dep;
	cre->save_klient(filename);
	delete[]cre;
	return 0;
}
