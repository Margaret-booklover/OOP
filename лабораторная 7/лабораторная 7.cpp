#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
	//friend bank* operator+(bank& ob, int plus);
	fio(char* f, char* n, char* o);
};

class bank
{
	fio fio;
public:
	int account;
	double sum;
	//static int count;
	bank();
	bank(char* fam, char* name, char* father, int account, double sum);
	~bank();
	/*	void save_klient(bank* all, const char* filename);
		void add_klient(bank*& all);
		void printall(int n);
		void sort(bank* s);
		void poisk(bank* s);
		char* get_fam() { return this->fio.fam; }
		char* get_name() { return this->fio.name; }
		char* get_father() { return this->fio.father; }
		void operator<<(bank* ob);
		friend bank* operator+(bank& ob, int plus);*/
};
bank::bank(char* fam, char* name, char* father, int account, double sum)
{
	this->fio.fam = fam;
	this->fio.name = name;
	this->fio.father = father;
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

int main() {
	setlocale(LC_ALL, "rus");
	const int size_max = 200;
	const char* filename = "basa.txt";
	cout << "hello!" << endl;
	//list<bank> mas;
	//list<bank> ::iterator tv1 = mas.begin();
	FILE* fp;
	char name[100], fam[100], fat[100], buf[100];
	int s, a, n;
	if ((fp = fopen(filename, "r")) == NULL)	printf("файл не открыт для чтения\n");
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s", fam);
		fscanf(fp, "%s", name);
		fscanf(fp, "%s", fat);
		fscanf(fp, "%s", buf);
		a = atoi(buf);
		fscanf(fp, "%s", buf);
		s = atoi(buf);
	//	bank p(fam, name, fat, a, s);
	//	mas.push_back(p);
	}
//	bank::count = n;
	fclose(fp);
	system("pause");
	return 0;
}
