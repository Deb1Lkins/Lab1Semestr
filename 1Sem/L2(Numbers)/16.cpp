//Task 16
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	cout << "��� �������� ����������� ����� � � � ���������� ����������� ��������� ����� � ������������� ���� �� ����� �\n";
	cout << "������� ����� � - ";
	cin >> a;
	cout << "������� ����� B - ";
	cin >> b;
	if (a <= 0 || b <= 0 || a > b)
	{
		cout << "��������� ����� �� ��������";
		return 0;
	}
	int num1 = a;
	int num2 = b;
	int r1 = 0, r2 = 0;
	int counter = 0;
	int c = 0;
	while (num1 > 0)
	{
		num1 /= 10;
		counter++;//����� �������� �����
	}
	while (num2 > 0)
	{
		r2 = num2 % 10;
		num1 = a;
		while (num1 > 0)
		{
			r1 = num1 % 10;
			num1 /= 10;

			if (r1 == r2)
			{
				c++;
			}

		}
		num2 /= 10;
	}
	if (counter == c)
	{
		cout << "���� ����������� ��������� ����� - " << a << ", ����� ������ ������ �� ����� - " << b;
	}
	else
	{
		cout << "����������� ���";
	}
	return 0;
}