//Task 11-15
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int a,b;
	cout << "������� ������ ������� - ";
	cin >> a;
	cout << "������� ������� ������� - ";
	cin >> b;
	if (a <= 0 || b <= 0 || a > b)
	{
		cout << "��������� ��������� �� �����������";
		return 0;
	}
	//Task 11
	cout << "Task 11" << endl;

	int sum = 0;
	int s = 0;
	cout << "����������� ����� � �������� ����������:\n";
	for (int i = a; i < b; i++)
	{
		sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				sum += j;
			}
		}
		if (sum == i)
		{
			cout << i << ", ";
		}
	}

	//Task 12
	cout << "\nTask 12" << endl;
	cout << "����� ���������� � �������� ����������:\n";

	for (int i = a; i < b; i++)
	{
		int num = i;
		int count = 0;
		int sum = 0;
		int r = 0;
		while (num > 0)
		{
			num /= 10;
			count++;//����� �������� �����
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
	//Task 13
	cout << "\nTask 13" << endl;

	sum = 1; s = 0; //�������� ��������� ��� ������� �����
	int r = 0; // r - �������
	int p = 0; //������ �����
	cout << "������� ����� (����� ���� ����� = ������� �����) � �������� ����������:\n";
	for (int i = a; i < b; i++)
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
			p = i;
			int sum_p = 0;
			while (p > 0)
			{
				sum_p += p % 10;
				p /= 10;
			}
			sum = 1;
			for (int k = 2; k < sum_p; k++)
			{
				r = sum_p % k;
				if (r != 0)
				{
					sum++;
				}
				s = k;
			}
			if (sum == s)
			{
				cout << i << ", ";
			}

		}
	}
	//Task 14
	cout << "\nTask 14" << endl;
	cout << "�����, ����� ���� ������� = �������� ������������ �����, � �������� ����������:\n";

	r = 0; // r - �������
	for (int j = a; j < b; j++)
	{
		int max_n = 0;
		int num = j;
		for (int i = 9; i >= 0; i--)
		{
			sum = 0;
			while (num > max_n)
			{
				if ((num % 10) > max_n)
				{
					max_n = num % 10;
				}
				num /= 10;

			}
			num = j;
			while (num > 0)
			{
				sum += num % 10;
				num /= 10;
			}
			if (max_n * max_n == sum)
			{
				cout << j << ", ";
				break;
			}
		}

	}
	//Task 15
	cout << "Task 15" << endl;

	cout << "�����, ���������� ������ ������� ���� ������ ������������ ������������������ ���� � �������� ����������:\n";
	int r = 0; // r - �������
	int d = 0; // d - ������� ���-�� �����
	for (int i = a; i < b; i++)
	{
		int num = i;
		int count = 0; //������� ��������
		int d = 0;
		int r1 = 0, r2 = 0; // �������
		int k = 10;
		for (int j = 9; j > 0; j--)
		{
			while (num > 0)
			{
				r1 = num % 10;
				if (r1 < k)
				{
					k = r1;
					d++;
				}
				num /= 10;
				count++;

				r2 = r1;
			}
		}

		if (d == count)
		{
			cout << i << ", ";
		}


	}
	return 0;
}