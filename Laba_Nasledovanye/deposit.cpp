#define _CRT_SECURE_NO_WARNINGS
#include "bank.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int deposit::dcount = 0;

int check(int max);

void deposit::operator<<(deposit* ob)
{
	cout << setw(15) << ob->fam << setw(15) << ob->name << setw(15) << ob->father << setw(15) <<
		ob->account << setw(15) << ob->sum << endl;
}

void deposit::save_klient(const char* filename)// ���������� ������ �� �����
{
	setlocale(0, "");
	FILE* file;
	file = fopen(filename, "w");
	if (file)
	{
		fprintf(file, "%d\n ", dcount);
		for (int i = 0; i < dcount; i++)
		{
			fprintf(file, "%15s ", this[i].fam);
			fprintf(file, "%15s ", this[i].name);
			fprintf(file, "%15s ", this[i].father);
			fprintf(file, "%15d ", this[i].account);
			fprintf(file, "%15.3f \n", this[i].sum);
		}
	}
	else
		cout << "��� ������� � �����!" << endl;
	fclose(file);

}

void deposit::sort()
{
	std::cout << "�������� ������� ������������ ������" << endl;
	if (deposit::dcount > 0)
	{
		std::cout<< "sorting..." << endl;
		int t = 0;
		int flag;
		char buf[100];
		int tw;
		double tv;
		for (int j = 0; j < dcount; j++)
		{
			for (int i = 0; i < dcount - 1; i++)
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
				}
			}

		}
		int l;
		cout << "������ �������������, ������� �� �� �����?(1 - ��, 0- ���)" << endl;
		l=check(1);
		if (l == 1) this->printall(this, dcount);
	}
	else throw except("���������� ����������, ��� ��� ����������� ������");
}

void deposit::printall(deposit* p, int n)
{
	printf("\n                  ������� ����������:\n");
	printf("-------------------------------------------------------------------------------------\n");
	cout << "�" << setw(15) << "�������" << setw(15) << "���" << setw(15) << "��������" <<
		setw(20) << "����� �����" << setw(20) << "����� �� �����" << endl;
	printf("----------------------------------------------------------------------------------\n");
	for (int i = 0; i < n; cout << endl, i++)
	{
		cout << i + 1 << " ";
		p[i] << (&p[i]);
	}
}

void deposit::load_klient(const char* filename)
{
	FILE* fp;;
	char buf[100];
	int n;
	if ((fp = fopen(filename, "r")) == NULL)	printf("���� �� ������ ��� ������\n");
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
	}
	dcount = n;
	fclose(fp);
}

void deposit::poisk()   //����� �� ������ �����
{
	int flag;
	int akk;
	int x = 0;
	char buf1[150];
	printf("������� ����� �����: ");
	akk = check(10000000);
	deposit* m = (deposit*)malloc(dcount * sizeof(deposit));
	for (int i = 0; i < dcount; i++)
	{
		if (this[i].account == akk)
		{
			m[x].fam = this[i].fam;
			m[x].name = this[i].name;
			m[x].father = this[i].father;
			m[x].account = this[i].account;
			m[x].sum = this[i].sum;
			x++;
		}
	}
	if (x > 0)
	{
		printf("������� %d ����������. ����������� ����� ������� �����?(1-��, 0-���)\n", x);
		flag = check(2);
		if ((flag == 1) && (x > 0))
		{
			cout << endl << endl;
			printall(m, x);
			cout << endl;
		}
	}
	else cout << "�� ������� �� ������ ������������" << endl;
	free(m);
}

void deposit::add_klient()
{
	char buff[50];
	cout << "���� �������������� ���������!!!" << endl << "�������: ";
	cin >> buff;
	for (int i = 0; i < strlen(buff); i++)
	{
		if (isalpha(buff[i]) == 0) throw except("����������� �������  � �����!");
	}
	this[dcount].fam = (char*)malloc((strlen(buff) + 1) * sizeof(char*));
	strcpy(this[dcount].fam, buff);
	printf("���: ");
	cin >> buff;
	for (int i = 0; i < strlen(buff); i++)
	{
		if (isalpha(buff[i]) == 0) throw except("����������� �������  � �����!");
	}
	this[dcount].name = (char*)malloc((strlen(buff) + 1) * sizeof(char*));
	strcpy(this[dcount].name, buff);
	printf("��������: ");
	cin >> buff;
	for (int i = 0; i < strlen(buff); i++)
	{
		if (isalpha(buff[i]) == 0) throw except("����������� �������  � �����!");
	}
	this[dcount].father = (char*)malloc((strlen(buff) + 1) * sizeof(char*));
	strcpy(this[dcount].father, buff);
	printf("����� �����: ");
	this[dcount].account = check(10000000);
	printf("�����: ");
	this[dcount].sum = check(10000000);
}

void deposit::poisk_fio()   //����� �� ������ �����
{
	int flag;
	int akk;
	int x = 0;
	char buf1[150];
	char buf2[150];
	char buf3[150];
	cout<<"������� ���: ";
	cin >> buf1;
	for (int i = 0; i < strlen(buf1); i++)
	{
		if (isalpha(buf1[i]) == 0) throw except("����������� �������  � �����!");
	}
	cout << "������� �������: ";
	cin >> buf2;
	for (int i = 0; i < strlen(buf2); i++)
	{
		if (isalpha(buf2[i]) == 0) throw except("����������� �������  � �����!");
	}
	cout << "������� ��������: ";
	cin >> buf3;
	for (int i = 0; i < strlen(buf3); i++)
	{
		if (isalpha(buf3[i]) == 0) throw except("����������� �������  � �����!");
	}
	deposit* m = (deposit*)malloc(dcount * sizeof(deposit));
	for (int i = 0; i < dcount; i++)
	{
		if (strcmp(this[i].name,buf1) + strcmp(this[i].fam, buf2) + strcmp(this[i].father, buf3) == 0)
		{
			m[x].fam = this[i].fam;
			m[x].name = this[i].name;
			m[x].father = this[i].father;
			m[x].account = this[i].account;
			m[x].sum = this[i].sum;
			x++;
		}
	}
	if (x > 0)
	{
		cout << "������� " << x << " ����������. ����������� ����� ������� �����?(1-��, 0-���)" << endl;
		flag = check(2);
		if ((flag == 1) && (x > 0))
		{
			cout << endl << endl;
			printall(m, x);
			free(m);
			cout << endl;
		}
	}
	else throw except( "�� ������� �� ������ ������������");	
}

void deposit::minus()
{
	int plus;
	cout << "������� �����: ";
	plus = check(10000000);
	int n;
	if (deposit::dcount > 0)
	{
		cout << "������� ���������� ����� ������� � ����, �� 1 �� " << deposit::dcount << endl;
		n = check(deposit::dcount);
		if (plus > this[n - 1].sum) throw except("������� ������� �����, ������� ��� ��, ��� ���� �� �����!");
		else	operator+(this[n - 1], -plus);
	}
	else throw except("������� ����� �������� ������� � ����, ������ �������������� ����� ����");
}