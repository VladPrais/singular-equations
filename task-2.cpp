#include <functional>
#include <iostream>
#include <math.h>

double f1(double);
double f2(double);
double f3(double);
double f4(double);
double f5(double);

double integr(std::function<double(double)>, double, double, int);
double simpson(std::function<double(double)>, double, double, int);

double pi = 3.1415;

int main(void)
{
	int nodes = (int)1e6;

	std::cout << "Задание 3" << std::endl;
	std::cout << "Формула Симпсона " << simpson(f3, 0.0, 2.0 * pi, nodes) << std::endl;
	std::cout << "Формула прямоугольника " << integr(f3, 0.0, 2.0 * pi, nodes) << std::endl;

	std::cout << "Задание 4" << std::endl;
	std::cout << "Формула Симпсона " << simpson(f4, 1.0 / cbrt(3), cbrt(3), nodes) << std::endl;
	std::cout << "Формула прямоугольника " << integr(f4, 1.0 / cbrt(3), cbrt(3), nodes) << std::endl;

	double b = 0.999999;
	std::cout << "Задание 5" << std::endl;
	std::cout << "Формула Симпсона " << simpson(f5, -b, b, nodes) << std::endl;
	std::cout << "Формула прямоугольника " << integr(f5, -b, b, nodes) << std::endl;

	return 0;
}

double f3(double x)
{
	return x * x * cos(x);
}

double f4(double x)
{
	return 1.0 / (1 + x * x);
}

double f5(double x)
{
	return 1.0 / sqrt(1 - x * x);
}

double integr(std::function<double(double)> f, double a, double b, int nodes)
{
	double s = 0.0;
	double h = (b - a) / (double)nodes;

	for(int i = 0; i < nodes; i++){
		s += f(a + h * i) * h;
	}

	return s;
}

double simpson(std::function<double(double)> f, double a, double b, int nodes)
{
	double s = 0.0;
	double h = (b - a) / (double)nodes;

	for(int i = 1; i < nodes; i++){
		double val = f(a + h * i);
		if(i % 2){
			s += 4 * val;
			continue;
		}
		s += 2 * val;
	}

	return h / 3.0 * (s + f(a) + f(b));
}
