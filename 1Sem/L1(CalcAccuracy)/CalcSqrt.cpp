#include <iostream>
#include <cmath>
using namespace std;

int CheckX(int x)
{
	if (x <= -1 || x >= 1)
	{
		throw"�������� �������� X";
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
		cout << "������� �, ������� � ��������� �� -1 �� 1 - ";
		cin >> x;
		CheckX(x);
		int k;
		cout << "������� ���������� ������ ����� ������� - ";
		cin >> k;
		double e = pow(10, -k);
		
		
		cout.precision(k);
		cout << fixed << "���� ���������� - " << CountX(x,e);
		
		double a = 1 / (sqrt(1 + x));
		cout << "\n������������ ���������� - " << a << endl;
	}
	catch (const char* msg) { cout << msg; }



	return 0;
}