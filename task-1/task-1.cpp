#include <iostream>
#include <math.h>

#define PI 3.1415

double f1(int);
double f2(int, int = 1);
double f_cos(int, double = 0.5);
double f_sin(int, double = 0.5);
double f4(int, double);

int main(void)
{
	int n1 = 100, n2 = 1000, n3 = 10000;

	std::cout << "Задание 1. Показать, что ряд сходится." << std::endl;
	std::cout << "Сумма ряда при n=" << n1 << ' ' << f1(n1) << std::endl;
	std::cout << "Сумма ряда при n=" << n2 << ' ' << f1(n2) << std::endl;
	std::cout << "Сумма ряда при n=" << n3 << ' ' << f1(n3) << std::endl;
	std::cout << "Значение, к которому сходится ряд " << PI * PI / 6.0 << std::endl << std::endl;

	std::cout << "Задание 2. Показать, что ряд расходится." << std::endl;
	std::cout << "Сумма ряда при n=" << n1 << ' ' << f2(n1) << std::endl;
	std::cout << "Сумма ряда при n=" << n2 << ' ' << f2(n2) << std::endl;
	std::cout << "Сумма ряда при n=" << n3 << ' ' << f2(n3) << std::endl << std::endl;;
	
	std::cout << "Задание 3. Показать, что ряды сходятся" << std::endl;
	std::cout << "Сумма ряда косинуса при n=" << n1 << ' ' << f_cos(n1) << std::endl;
	std::cout << "Сумма ряда косинуса при n=" << n2 << ' ' << f_cos(n2) << std::endl;
	std::cout << "Сумма ряда косинуса при n=" << n3 << ' ' << f_cos(n3) << std::endl << std::endl;

	std::cout << "Сумма ряда синуса при n=" << n1 << ' ' << f_sin(n1) << std::endl;
	std::cout << "Сумма ряда синуса при n=" << n2 << ' ' << f_sin(n2) << std::endl;
	std::cout << "Сумма ряда синуса при n=" << n3 << ' ' << f_sin(n3) << std::endl << std::endl;

	std::cout << "Здаание 4. Показать, что ряд сходится к 0.5." << std::endl;
	double x1 = 0.9;
	std::cout << "Значение x=" << x1 << std::endl;
	std::cout << "Сумма ряда при n=" << n1 << ' ' << f4(n1, x1) << std::endl;
	std::cout << "Сумма ряда при n=" << n2 << ' ' << f4(n2, x1) << std::endl;
	std::cout << "Сумма ряда при n=" << n3 << ' ' << f4(n3, x1) << std::endl << std::endl;

	double x2 = 0.99;
	std::cout << "Значение x=" << x2 << std::endl;
	std::cout << "Сумма ряда при n=" << n1 << ' ' << f4(n1, x2) << std::endl;
	std::cout << "Сумма ряда при n=" << n2 << ' ' << f4(n2, x2) << std::endl;
	std::cout << "Сумма ряда при n=" << n3 << ' ' << f4(n3, x2) << std::endl << std::endl;

	double x3 = 0.999;
	std::cout << "Значение x=" << x3 << std::endl;
	std::cout << "Сумма ряда при n=" << n1 << ' ' << f4(n1, x3) << std::endl;
	std::cout << "Сумма ряда при n=" << n2 << ' ' << f4(n2, x3) << std::endl;
	std::cout << "Сумма ряда при n=" << n3 << ' ' << f4(n3, x3) << std::endl << std::endl;

	return 0;
}

double f1(int n)
{
	double s = 0.0;
	for(int i = 1; i <= n; i++){
		s += 1.0 / (double)(i * i);
	}
	return s;
}

double f2(int n, int y)
{
	double s = 0.0;
	for(int i = 1; i <= n; i++){
		s += 1.0 / pow(i, y);
	}
	return s;
}

double f_cos(int n, double a)
{
	double s = 0.0;
	for(int i = 1; i <= n; i++){
		s += cos(a * i) / i;
	}
	return s;
}

double f_sin(int n, double a)
{
	double s = 0.0;
	for(int i = 1; i <= n; i++){
		s += sin(a * i) / i;
	}
	return s;
}

double f4(int n, double x)
{
	double s = 0.0;
	for(int c = 0; c < n; c++){
		s += pow(-x, c);
	}
	return s;
}
