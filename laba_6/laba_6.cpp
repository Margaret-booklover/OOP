// laba_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class except
{
public:
	char msg[80];
	except() { *msg = 0; }
	except(const char* s) { strcpy(msg, s); }
}; 

double fdiv(double a, double b)
{
	if (b)
	{
		cout << "+++" << endl;
		return (a / b);
	}
	else throw except("error: divider=0");
}

double fsqrt(double q)
{
	if (q < 0) throw except("error: sqrt");
	return sqrt(q);
}

double fasin(double r)
{
	if (r < -1 || r>1)
		throw except("error fasin");
	return asin(r);
}


int main()
{
	double x1, y1;
	cout << "x1="; cin >> x1;
	cout << "y1="; cin >> y1;
	try
	{
		cout << "z1=" << fdiv(x1, y1) << endl;
		cout << "z2=" << fsqrt(x1) << endl;
		cout << "z3=" << fasin(y1) << endl;
	}
	catch (except e)
	{
		cout << e.msg << endl;
	}
	cout << "end";
	return 0;
}

