#include <iostream>
#include <cmath>
using namespace std;

int CheckX(int x)
{
	if (x <= -1 || x >= 1)
	{
		throw"неверное значение X";
	}
}
double CountX(double x, double e)
{
	
	double a = 1, res = 1;
	for (double i = 1; abs(a) > e; i += 2)
	{

		a *= (-1) * i * x / (i + 1);
		res += a;

	}

	return res;
}
int main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		double x;
		cout << "введите Х, лежащий в интервале от -1 до 1 - ";
		cin >> x;
		CheckX(x);
		int k;
		cout << "введите количесвто знаков после запятой - ";
		cin >> k;
		double e = pow(10, -k);
		
		
		cout.precision(k);
		cout << fixed << "свои вычисления - " << CountX(x,e);
		
		double a = 1 / (sqrt(1 + x));
		cout << "\nбиблиотечные вычисления - " << a << endl;
	}
	catch (const char* msg) { cout << msg; }



	return 0;
}