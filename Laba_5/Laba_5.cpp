#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <fstream>
#include "Header.h"
using namespace std;
int check(int max);
int main() 
{
	setlocale(LC_ALL, "rus");
	const int size_max = 200;
	char name[100], fam[100], fat[100], buf[100];
	int s, a, n, p;
	list<bank> mas;
	mas = bank::load_klient(mas);
	n = mas.size();
	do
	{
		cout << " На данный момент в системе зарегистрировано " << n << " клиентов" << endl;
		cout << "---------------Меню-----------" << endl;
		cout<< " 1 - добавить в конец " << endl;
		cout << " 2- добавить в заданную позицию " << endl;
		cout << " 3 - распечатать все " << endl;
		cout << " 4 -сортировать по уменьшению суммы на счете" << endl;
		cout << " 5 - удалить из начала списка" << endl;
		cout << " 6 - поиск по номеру счета" << endl;
		cout << " 7 - добавить число к полю" << endl;
		cout << " 8 - завершить работу" << endl;
		cout << "---------------------------------" << endl << "Введите номер меню..." << endl;
		p = check(8);
		switch (p)
		{
		case 1:
		{   if (n > size_max) cout << "количество клиентов в базе достигло максимума, невозможно добавить запись" << endl;
		else
		{
			cout << "Фамилия: ";
			cin >> fam;
			cout << "Имя: ";
			cin >> name;
			cout << "Отчество: ";
			cin >> fat;
			cout << "Номер счета: ";
			a = check(999999);
			cout << "Сумма : ";
			s = check(100000000);
			bank ob(fam, name, fat, a, s);
			mas.push_back(ob);
			n++;
			cout << "Регистрация прошла успешно" << endl;
		}
		break;
		}
		case 2:
		{
			if (n > size_max) cout << "количество клиентов в базе достигло максимума, невозможно добавить запись" << endl;
			else 
			{
				cout << "Введите номер, под которым клиент попадет в базу, от 1 до " << mas.size() << endl;
				int number = check(mas.size());
				cout << "Фамилия: ";
				cin >> fam;
				cout << "Имя: ";
				cin >> name;
				cout << "Отчество: ";
				cin >> fat;
				cout << "Номер счета: ";
				a = check(999999);
				cout << "Сумма : ";
				s = check(100000000);
				bank ob(fam, name, fat, a, s);
				list<bank>::iterator k = mas.begin();
				for (int i = 0; i < number - 1; i++)
				k++;
				mas.insert(k, ob);
				cout << "Регистрация прошла успешно" << endl;
				n++;
			}
			break;
		}
		case 3:
		{
			bank::printall(mas);
			break;
		}
		case 4:
		{
			mas.sort();		
			break;
		}
		case 5:
		{
			mas.erase(mas.begin());
			n--;
			break;
		}
		case 6:
		{
			bank::poisk(mas);
			break;
		}
		case 7:
		{
			cout << "Введите сумму: ";
			int plus;
			plus = check(1000000);
			cout << " Введите порядковый номер, от 1 до " << mas.size() << endl;
			int number;
			number = check(n);
			list<bank>::iterator k = mas.begin();
			for (int i = 0; i < number - 1; i++) k++;
		//	cout << "befor plus " << (*k).get_fam()<< endl;
			*k + plus;
		//	cout << "after plus " << (*k).get_fam() << endl;
		//	*k = *k + plus;
			cout << "after add " << (*k).get_fam() << endl;
			//k->sum = k->sum + plus;
		}
		}
	} while (p != 8);
	bank::save_klient(mas, n);
	system("pause");
	return 0;
}
