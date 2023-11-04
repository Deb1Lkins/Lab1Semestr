/*
* � �������, ��������� �� � ������������ ���������, ���������:
- ���������� ��������� �������, ������� ��������� ����� �;
- ����� ����� ������ ��������� �������, ������������� ����� ���������� ��������������
��������.
������������� ������ ����� �������, ����� ������� ������������� ��� ��������, ������� �,
� ����� � ��� ���������. ������� ���������� ��������� �� ��������.
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void CheckBorder(int min, int max)
{
	if (min > max)
	{
		throw "��������� ������� �� ��������";
	}
}
void InPutDigitsRandom(int* arr, int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (max + 1 - min) + min; //������
		//cin >> arr[i]; //���� � ����������
	}
}
void InPutDigitsHand(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{

		cin >> arr[i]; //���� � ����������
	}
}
void Menu(int* arr, int size)
{
	int choice;
	cout << "������� ������ ����� �� ������� 1(� ����) 2(������):\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		InPutDigitsHand(arr, size);
		break;
	}
	case 2:
	{
		int min, max; // ������� ��� �������
		cout << "������� ����� ������� ������� - ";
		cin >> min;
		cout << "������� ������ ������� ������� - ";
		cin >> max;
		CheckBorder(min, max);
		InPutDigitsRandom(arr, size, min, max);
		break;
	}
	}
}
void CheckSize(int size)
{
	if (size <= 0 || size > 100)
	{
		throw"�������� ������!";
	}
}


void CoutArr(int* arr, int size)
{
	cout << "arr:\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << setw(5);
	}
}
int ElUnderP(int* arr, int size, int p)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < p)
		{
			counter++;
		}
	}
	if (counter == 0)
	{
		throw "��� ��������� � ������� ������ ��������� ����� �";
	}
	cout << "\n���������� ��������� < p - " << counter << endl;
	return counter;
}
int SumElArr(int* arr, int size)
{
	int SumEl = 0;
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			j = i + 1;
		}
	}
	if (j == 0)
	{
		throw "��� ������������� �����";
	}
	for (int i = j; i < size; i++)
	{
		SumEl += arr[i];
	}
	cout << "\n����� ��������� ������� ����� ���������� �������������� ����� = " << SumEl << endl;
	return SumEl;
}
void ChangeArr(int* arr, int size,int p)
{
	for (int i = 0; i < size; i++)
	{
		int k = 0;
		if (arr[i] < p)
		{
			int temp = arr[i];
			for (int j = i; j > k; j--)
			{
				arr[j] = arr[j - 1];
			}
			arr[k] = temp;
			k++;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	try
	{
		/*const int MAXSIZE = 100;
		int arr[MAXSIZE];*/ //����������� ������
		int size;
		cout << "������� ������ �������\n";
		cin >> size;
		CheckSize(size);
		int* arr = new int[size];
		Menu(arr, size);
		CoutArr(arr, size);
		//����� �� ������� ������ P
		int p;
		cout << "\n������� ����� P - ";
		cin >> p; 
		ElUnderP(arr, size, p);
		//������
		//SumElArr(arr, size);
		// �������� ������� ������� �� p � ����� ���������
		cout << "\nchange ";
		ChangeArr(arr, size, p);
		CoutArr(arr, size);
		delete[]arr;
	} catch (const char* msg) { cout << msg; }
	return 0;
}