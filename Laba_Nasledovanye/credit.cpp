#define _CRT_SECURE_NO_WARNINGS
#include "bank.h"
#include <iostream>
#include <iomanip>
using namespace std;
int credit::ccount = 0;
int check(int max);

void credit::operator<<(credit* ob)
{
	cout << setw(7) << ob->fam << setw(12) << ob->name << setw(15) << ob->father << setw(10) <<
		ob->account << setw(10) << ob->sum << setw(6) << ob->percent <<
		setw(15)<<ob->month<<setw(15)<<ob->sumpermonth<< endl;
}

void credit::save_klient(const char* filename)// сохранение данных на диске
{
	setlocale(0, "");
	FILE* file;
	file = fopen(filename, "w");
	if (file)
	{
		fprintf(file, "%d\n ", ccount);
		for (int i = 0; i < ccount; i++)
		{
			fprintf(file, "%15s ", this[i].fam);
			fprintf(file, "%15s ", this[i].name);
			fprintf(file, "%15s ", this[i].father);
			fprintf(file, "%15d ", this[i].account);
			fprintf(file, "%15.3f ", this[i].sum);
			fprintf(file, "%15.2f ", this[i].percent);
			fprintf(file, "%15d \n", this[i].month);
		}
	}
	else
		cout << "Нет доступа к файлу!" << endl;
	fclose(file);

}

void credit::sort()
{
	int t = 0;
	int flag;
	char buf[100];
	int tw;
	double tv;
	for (int j = 0; j < ccount; j++)
	{
		for (int i = 0; i < ccount - 1; i++)
		{
			if (this[i + 1].sum > this[i].sum) 
			{
				strcpy(buf, this[i].fam);
				this[i].fam = (char*)realloc(this[i].fam, sizeof(char) * (strlen(this[i + 1].fam) + 1));
				strcpy(this[i].fam, this[i + 1].fam);
				this[i + 1].fam = (char*)realloc(this[i + 1].fam, sizeof(char) * (strlen(this[i].fam) + 1));
				strcpy(this[i + 1].fam, buf);

				strcpy(buf, this[i].name);
				this[i].name = (char*)realloc(this[i].name, sizeof(char) * (strlen(this[i + 1].name) + 1));
				strcpy(this[i].name, this[i + 1].name);
				this[i + 1].name = (char*)realloc(this[i + 1].name, sizeof(char) * (strlen(this[i].name) + 1));
				strcpy(this[i + 1].name, buf);

				strcpy(buf, this[i].father);
				this[i].father = (char*)realloc(this[i].father, sizeof(char) * (strlen(this[i + 1].father) + 1));
				strcpy(this[i].father, this[i + 1].father);
				this[i + 1].father = (char*)realloc(this[i + 1].father, sizeof(char) * (strlen(this[i].father) + 1));
				strcpy(this[i + 1].father, buf);

				tw = this[i].account;
				this[i].account = this[i + 1].account;
				this[i + 1].account = tw;

				tv = this[i].sum;
				this[i].sum = this[i + 1].sum;
				this[i + 1].sum = tv;

				tv = this[i].percent;
				this[i].percent = this[i + 1].percent;
				this[i + 1].percent = tv;

				tw = this[i].month;
				this[i].month = this[i + 1].month;
				this[i + 1].month = tw;

				tv = this[i].sumpermonth;
				this[i].sumpermonth = this[i + 1].sumpermonth;
				this[i + 1].sumpermonth = tv;
			}
		}

	}
	int l = 2;
	cout << "Данные отсортированы, вывести их на экран?(1 - да, 0 - нет)" << endl;
	cin >> l;
	if (l==1) this->printall(this, ccount);
}

void credit::printall(credit* p, int n)
{
	cout<<endl<<"                  Таблица должников:" << endl;
	cout<<"-------------------------------------------------------------------------------------" << endl;
	cout << "№" << setw(10) << "Фамилия" << setw(12) << "Имя" << setw(12) << "Отчество" <<
		setw(10) << "Счет" << setw(10) << "Кредит" << setw(10) <<
		"Процент" <<setw(15)<<"Срок(мес.)"<<setw(20)<<"Ежемесячная выплата"<< endl;
	cout<<"----------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < n; cout << endl, i++)
	{
		cout << i + 1 << " ";
		p[i] << (&p[i]);
	}
}

void credit::load_klient(const char* filename)
{
	FILE* fp;;
	char buf[100];
	int n;
	if ((fp = fopen(filename, "r")) == NULL)	cout<<"файл не открыт для чтения" << endl;
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s", buf);
		this[i].fam = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
		strcpy(this[i].fam, buf);
		fscanf(fp, "%s", buf);
		this[i].name = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
		strcpy(this[i].name, buf);
		fscanf(fp, "%s", buf);
		this[i].father = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
		strcpy(this[i].father, buf);
		fscanf(fp, "%s", buf);
		this[i].account = atoi(buf);
		fscanf(fp, "%s", buf);
		this[i].sum = atof(buf);
		fscanf(fp, "%s", buf);
		this[i].percent = atof(buf);
		fscanf(fp, "%s", buf);
		this[i].month = atof(buf);
		this[i].sumpermonth = this[i].sum*(1+this[i].percent/100) / this[i].month;
	}
	ccount = n;
	fclose(fp);
}

void credit::poisk()   //поиск по номеру счета
{
	int flag;
	int akk;
	int x = 0;
	char buf1[150];
	cout<<"Введите номер счета: ";
	akk = check(10000000);
	credit* m = (credit*)malloc(ccount * sizeof(credit));
	for (int i = 0; i < ccount; i++)
	{
		if (this[i].account == akk)
		{
			m[x].fam = this[i].fam;
			m[x].name = this[i].name;
			m[x].father = this[i].father;
			m[x].account = this[i].account;
			m[x].sum = this[i].sum;
			m[x].percent = this[i].percent;
			m[x].month = this[i].month;
			m[x].sumpermonth= this[i].sumpermonth;
			x++;
		}
	}
	if (x > 0)
	{
		cout<<"найдено "<<x<<" совпадений. Осуществить вывод искомых писем?(1-да, 0-нет)" << endl;
		flag = check(2);
		if ((flag == 1) && (x > 0))
		{
			cout << endl << endl;
			printall(m, x);
			cout << endl;
		}
	}
	else throw except( "Не найдено ни одного соответствия" );
	free(m);
}

void credit::add_klient()
{
	char buff[50];
	cout << "Ввод осуществляется латиницей!!!" << endl << "Фамилия: ";
	cin >> buff;
	for (int i = 0; i < strlen(buff); i++)
	{
		if (isalpha(buff[i]) == 0) throw except("посторонние символы  в имени!");
	}
	this[ccount].fam = (char*)malloc((strlen(buff) + 1) * sizeof(char*));
	strcpy(this[ccount].fam, buff);
	printf("Имя: ");
	cin >> buff;
	for (int i = 0; i < strlen(buff); i++)
	{
		if (isalpha(buff[i]) == 0) throw except("посторонние символы  в имени!");
	}
	this[ccount].name = (char*)malloc((strlen(buff) + 1) * sizeof(char*));
	strcpy(this[ccount].name, buff);
	printf("Отчество: ");
	cin >> buff;
	for (int i = 0; i < strlen(buff); i++)
	{
		if (isalpha(buff[i]) == 0) throw except("посторонние символы  в имени!");
	}
	this[ccount].father = (char*)malloc((strlen(buff) + 1) * sizeof(char*));
	strcpy(this[ccount].father, buff);
	printf("Номер счета: ");
	this[ccount].account = check(10000000);
	printf("Сумма: ");
	this[ccount].sum = check(10000000);
	printf("Процент: ");
	this[ccount].percent = check(100);
	printf("Срок: ");
	this[ccount].month = check(1000);
	this[ccount].sumpermonth = this[ccount].sum * (1 + this[ccount].percent / 100) / this[ccount].month;
}

credit* operator+(credit& ob, int plus)
{
	ob.sum = ob.sum + plus;
	return &ob;
}

void credit::poisk_fio()   //поиск по номеру счета
{
	int flag;
	int akk;
	int x = 0;
	char buf1[150];
	char buf2[150];
	char buf3[150];
	cout << "Введите имя: ";
	cin >> buf1;
	for (int i = 0; i < strlen(buf1); i++)
	{
		if (isalpha(buf1[i]) == 0) throw except("посторонние символы  в имени!");
	}
	cout << "Введите фамилию: ";
	cin >> buf2;
	for (int i = 0; i < strlen(buf2); i++)
	{
		if (isalpha(buf2[i]) == 0) throw except("посторонние символы  в имени!");
	}
	cout << "Введите отчество: ";
	cin >> buf3;
	for (int i = 0; i < strlen(buf3); i++)
	{
		if (isalpha(buf3[i]) == 0) throw except("посторонние символы  в имени!");
	}
	credit* m = (credit*)malloc(ccount * sizeof(credit));
	for (int i = 0; i < ccount; i++)
	{
		if (strcmp(this[i].name, buf1) + strcmp(this[i].fam, buf2) + strcmp(this[i].father, buf3) == 0)
		{
			m[x].fam = this[i].fam;
			m[x].name = this[i].name;
			m[x].father = this[i].father;
			m[x].account = this[i].account;
			m[x].sum = this[i].sum;
			m[x].percent = this[i].percent;
			m[x].month = this[i].month;
			m[x].sumpermonth = this[i].sumpermonth;
			x++;
		}
	}
	if (x > 0)
	{
		cout << "найдено " << x << " совпадений. Осуществить вывод искомых писем?(1-да, 0-нет)" << endl;
		flag = check(2);
		if ((flag == 1) && (x > 0))
		{
			cout << endl << endl;
			printall(m, x);
			free(m);
			cout << endl;
		}
	}
	else throw except("Не найдено ни одного соответствия");
}

void credit::minus()
{
	int plus;
	cout << "Введите сумму: ";
	plus = check(10000000);
	int n;
	if (credit::ccount > 0)
	{
		cout << "Введите порядковый номер клиента в базе, от 1 до " << credit::ccount << endl;
		n = check(credit::ccount);
		if (plus > this[n - 1].sum) throw except("Попытка внесения большей, чем нужно,суммы!");
		else operator+(this[n - 1], -plus);
	}
	else throw except("Сначала нужно добавить клиента в базу, выбрав соответсвующий пункт меню");
}