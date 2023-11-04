//Task 1-7
#include <iostream>
#include <iomanip>
#include <cmath>
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

	// 1
	cout << "Task 1" << endl;
	int r = 0; // r - остаток
	int d = 0; // d - счетчик кол-ва чисел
	for (int i = 0; i < 10; i++)
	{
		d = 0;
		num = n;
		while (num > 0)
		{
			r = num % 10;
			num /= 10;
			if (r == i)
			{
				d++;

				if (d == 2)
				{
					cout << "Цифры в числе не различны\n";
					goto stop1; // вынужденная мера((((
				}
			}

		}


	}
stop1:
	{
		if (d < 2)
		{
			cout << "Цифры в числе различны\n";
		}
	}

	// 2
	cout << "Task 2" << endl;

	num = n;
	r = 0; // r - остаток
	d = 0; // d - счетчик кол-ва чисел
	int res = 0;
	for (int i = 0; i <= 9; i++)
	{
		num = n;
		while (num > 0)
		{
			r = num % 10;
			num /= 10;
			if (r == 0)
			{
				cout << "Все циры удалены\n";
				goto stop2;
			}
			else
			{
				if (r == 1)
				{
					cout << "Все циры удалены\n";
					goto stop2;
				}
				else
				{
					if (r == i)
					{
						num = n;
						r = 0; // r - остаток
						d = 0; // d - счетчик кол-ва чисел
						int j = 0;
						while (num > 0)
						{
							r = num % 10;

							if (r % i != 0)
							{
								res += r * pow(10, j);
								j++;
							}
							num /= 10;
						}
						goto stop2;
					}
				}
			}
		}
	}

stop2:

	cout << "Конечное число - " << res << endl;



	//3
	cout << "Task 3" << endl;

	r = 0; // r - остаток
	int d1 = 0, d2 = 0; // d - счетчик кол-ва чисел
	int max_n = 0;
	for (int i = 0; i < 10; i++)
	{
		num = n;
		d1 = 0;
		while (num > 0)
		{
			r = num % 10;
			num /= 10;
			if (r == i)
			{
				d1++;
			}
		}
		if (d1 > d2)
		{
			d2 = d1;
			max_n = i;
		}
	}
	cout << num;

	int sum = 1;
	num = n;
	while (num > 0)
	{
		num /= 10;
		sum++;//колво разрядов числа
	}
	num = n;
	num = max_n + (num * 10) + (max_n * pow(10, sum));
	cout << num << endl;

	//4
	cout << "Task 4" << endl;
	r = 0; // r - остаток
	num = n;
	sum = 0;
	int ten = 0;
	int t = 0;
	while (num > 0)
	{
		num /= 10;
		sum++;//колво разрядов числа
	}
	if (sum % 2 == 0)
	{
		cout << "Количество цифр в числе четное" << endl;
	}
	else
	{
		num = n;
		t = sum + 1; //последний разряд будущего числа
		sum = (sum + 1) / 2 - 1; //середина числа
		ten = pow(10, sum);
		num /= ten;
		r = num % 10;

		num = n;
		num = (num * 10) + r + (r * pow(10, t));
		cout << num << endl;
	}

	//Task 5

	cout << "Task 5" << endl;
	num = 0;
	sum = 0;
	int sum1 = 0;
	int sum2 = 1;
	while (num < n)
	{
		sum = sum1 + sum2;
		sum1 = sum2;
		sum2 = sum;
		if (num + sum >= n)
		{
			break;
		}
		num += sum;
	}
	cout << "Сумма чисел Фибоначчи до заданного числа = " << num << endl;

	//Task 6

	cout << "Task 6" << endl;
	num = n;
	sum = 1;
	int s = 0;
	r = 0; // r - остаток
	cout << n << " - ";
	for (int j = 2; j < n; j++)
	{
		r = num % j;
		if (r != 0)
		{
			sum++;
		}
		s = j;
	}
	if (sum == s)
	{
		cout << "число простое";
	}
	else
	{
		for (int i = 2; i < n; i++)
		{
			while (num % i == 0)
			{
				r = num % i;
				if (r == 0)
				{
					cout << i << " * ";
					num /= i;
				}
			}
		}
		cout << "1";
	}
	cout << endl;

	//Task 7
	cout << "Task 7" << endl;
	int p1 = 1, p2 = 1; //простые числа
	t = 0; //счетчик Т пар близнецов
	s = 0;
	r = 0;
	sum = 1; // кол-во ненулевых остатков для p1
	int k = 0;
	for (int j = 2; j < n; j++)
	{
		for (int i = 2; i < j; i++)
		{
			r = j % i;
			if (r != 0)
			{
				sum++;
			}
			s = i;
		}
		if (sum == s)
		{
			p1 = j;
			k = abs(p1 - p2);
			if (k == 2)
			{
				t++;
			}
			p2 = p1;
		}
		sum = 1;
	}
	cout << "Количетсво пар близнецов до заданного числа = " << t;
	return 0;
}
/*sum = sum1 + sum2;
sum1 = sum2;
sum2 = sum;
числа фибоначчи
*/
