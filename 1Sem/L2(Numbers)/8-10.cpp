//Task 8-10
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, num;
	cout << "Введите число - ";
	cin >> n;
	if (n <= 0)
	{
		cout << "Введенное число не натуральное";
		return 0;
	}

	//Task 8
	cout << "Task 8" << endl;

	num = n;
	int sum = 1;
	int s = 0;
	int r = 0; // r - остаток
	cout << "Простые числа до заданного числа:\n";
	for (int i = 3; i < n; i++)
	{
		sum = 1;
		for (int j = 2; j < i; j++)
		{
			r = i % j;
			if (r != 0)
			{
				sum++;
			}
			s = j;
		}
		if (sum == s)
		{
			cout << "1, " << i;
		}
	}
	

	//Task 9
	cout << "\nTask 9" << endl;
	cout << "Дружественные числа до заданного числа:\n";
	num = n;
	int sum1 = 0;
	int sum2 = 0;
	int d1 = 0;
	int d2 = 0;
	for (int j = 2; j < n; j++)
	{
		sum1 = 0;
		d1 = j;
		sum2 = 0;
		for (int i = 1; i < j ; i++)
		{
			if (d1 % i == 0)
			{
				sum1 += i;
			}
		}
		d2 = sum1;
		for (int k = 1; k < d2; k++)
		{
			if (d2 % k == 0)
			{
					sum2 += k;
			}
		}
		if (d1 == sum2 && d1 != d2)
		{

			cout << d1 << " - " << d2 << ",\n";
			j = d2;
		}
	}

	//Task 10
	cout << "\nTask 10" << endl;
	cout << "Числа Армстронга до заданного числа:\n";
	for (int i = 10; i < n; i++)
	{
		num = i;
		int count = 0;
		int sum = 0;
		int r = 0;
		while (num > 0)
		{
			num /= 10;
			count++;//колво разрядов числа
		}
		num = i;
		while (num > 0)
		{
			r = num % 10;
			num /= 10;
			sum += pow(r, count);
		}
		if (sum == i)
		{
			cout << i << ", ";
		}
	}
	return 0;
}