#include "fraction.h"
#include <iostream>
#include <algorithm>
#include <fstream>
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::fstream;
int GCD(int a, int b)
{
	return b ? GCD(b, a % b) : a;
}
void InPutFract(class Fraction& fract)
{
	int num, denom;
	cout << "������� ��������� - ";
	cin >> num;
	cout << "������� ����������� - ";
	cin >> denom;
	fract.SetFract(num, denom);
}
int main()

{
	try
	{
		setlocale(LC_ALL, "ru");

		/*char ch;
		cout << "������� �������� ��� ������� +, -, *, /, <, ++(1), --(2), (������� �����)~, ^(�������� �����) :\n";
		cin >> ch;
		switch (ch)
		{
		case '+':
		{

			Fraction fract_1;
			Fraction fract_2;
			Fraction fract_3;
			cout << "������� ������ �����\n";
			InPutFract(fract_1);
			cout << "������� ������ �����\n";
			InPutFract(fract_2);
			fract_3 = fract_1 + fract_2;
			fract_3.PrintFract();
			break;
		}
		case '-':
		{
			Fraction fract_1;
			Fraction fract_2;
			Fraction fract_3;
			cout << "������� ������ �����\n";
			InPutFract(fract_1);
			cout << "������� ������ �����\n";
			InPutFract(fract_2);
			fract_3 = fract_1 - fract_2;
			fract_3.PrintFract();
			break;
		}
		case '*':
		{
			Fraction fract_1;
			Fraction fract_2;
			Fraction fract_3;
			cout << "������� ������ �����\n";
			InPutFract(fract_1);
			cout << "������� ������ �����\n";
			InPutFract(fract_2);
			fract_3 = fract_1 * fract_2;
			fract_3.PrintFract();
			break;
		}
		case '/':
		{
			Fraction fract_1;
			Fraction fract_2;
			Fraction fract_3;
			cout << "������� ������ �����\n";
			InPutFract(fract_1);
			cout << "������� ������ �����\n";
			InPutFract(fract_2);
			fract_3 = fract_1 / fract_2;
			fract_3.PrintFract();
			break;
		}
		case '<':
		{
			Fraction fract_1;
			Fraction fract_2;
			cout << "������� ������ �����\n";
			InPutFract(fract_1);
			cout << "������� ������ �����\n";
			InPutFract(fract_2);
			if (fract_1 > fract_2)
			{
				cout << "������";
			}
			else
			{
				if (fract_1 < fract_2)
				{
					cout << "������";
				}
				else
				{
					if (fract_1 == fract_2)
					{
						cout << "����� �����";
					}
				}
			}
			break;
		}
		case '1':
		{
			Fraction fract_1;
			cout << "������� �����\n";
			InPutFract(fract_1);
			++fract_1;
			fract_1.PrintFract();
			break;
		}
		case '2':
		{
			Fraction fract_1;
			cout << "������� �����\n";
			InPutFract(fract_1);
			fract_1--;
			fract_1.PrintFract();
			break;
		}
		case '~':
		{
			Fraction fract_1;
			Fraction fract_2;
			cout << "������� �����\n";
			InPutFract(fract_1);
			fract_2 = -fract_1;
			fract_2.PrintFract();
			break;
		}
		case '^':
		{
			Fraction fract_1;
			Fraction fract_2;
			cout << "������� �����\n";
			InPutFract(fract_1);
			fract_2 = ~fract_1;
			fract_2.PrintFract();
			break;
		}
		default: { throw"��� ����� ��������"; }
		}*/

		Fraction a, b;
		cin >> a;
		cout << a;
	}
	catch (const char* msg) { cout << msg; }
	return 0;
}
//����������� ���������������� ���(�����) "������������ �����".�������� ��� ������ �������� � ���� ���� ������ :
//������������� ����� �  ����������� ������ � ����� ���������� �������.
//����� ������� �  "������������ �����" : 
//���� n � ���������, � d � �����������, �� ����  �������� � ���������(����������� ������ ������ 0), � n � d � ��������������.
//����������� ��� ��������� �������������� ���������  ��� �������, ��������� ���������, ���������� � ����������, �������  �����, 
//�������� ��������� �����������, ��� �������� ��������� �������� �����, 
//���� � ������, ����� � �����, ���������� � ������������� ����, 
//�������� ������������, ��������� ��������� ������������.
// 
//��� ��������� �������������� �������� ������������ ����������� �����(�����  ���������� �������).
//
//��� ������������ ������������ ������ �������� ��������  ���������, � ������� ������������������ ������ � ���� �������.
//����  ������ �� ����.
//� ������������ �������, ��� ����������.
