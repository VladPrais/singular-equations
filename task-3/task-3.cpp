#include <functional>
#include <iostream>

double simpson(std::function<double(double)>, double, double, int);
double f1(double);
double f2(double);
double f3(double);
double f4(double);

int main(void)
{
	double a = 1e-1, inf = 1e6;
	int nodes = (int)1e8;

	std::cout << "Задание 1." << std::endl;
	std::cout << "Значение интеграла " << simpson(f1, a, inf, nodes) << std::endl;;
	
	std::cout << "Задание 2." << std::endl;
	std::cout << "Значение интеграла " << simpson(f2, 2, inf, nodes) << std::endl;;
	
	std::cout << "Задание 3." << std::endl;
	std::cout << "Значение интеграла " << simpson(f3, -inf, inf, nodes) << std::endl;;

	std::cout << "Задание 4." << std::endl;
	std::cout << "Значение интеграла " << simpson(f4, 3, inf, nodes) << std::endl;;

	return 0;
}

double f4(double x)
{
	return 1.0 / (x * x - 3 * x + 2);
}

double f3(double x)
{
	return 1.0 / (1 + x * x);
}

double f2(double x)
{
	return 1.0 / (x * x + x - 2);
}

double f1(double x)
{
	return 1.0 / (x * x);
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
