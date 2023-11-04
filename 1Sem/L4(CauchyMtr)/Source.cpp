/*
�� ��������� ���� �������� X(P) � Y(Q) ��������� ������� ���� �� �������
a[i,j]=1/(x[i]+y[j]).
����� ����� ��������� ������� �������.
*/
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
bool ChekSize(int size)
{
	if (size <= 0 || size > 100)
	{
		throw "��������� ������� �� ��������";
	}
	return true;
}
bool CheckBorder(int min, int max)
{
	if (min > max)
	{
		throw "��������� ������� �� ��������";
	}
	return true;
}
void InPutDigits(int* arr, int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
		//cin >> arr[i]; //���� � ����������
	}
}
void InPutArr(double** arr, int rows, int cols, int* arrI, int* arrJ)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arrI[i] + arrJ[j] == 0)
			{
				throw "\n��� ���������� ��������� ���������� �������, ���������� ��������� ���� 1/0";
			}
			arr[i][j] = 1.0 / (arrI[i] + arrJ[j]);
		}
	}
}
void SumArrCols(double** arr, int rows, int cols)
{
	long double sum = 0;
	for (int i = 0; i < cols; i++)
	{
		sum = 0;
		for (int j = 0; j < rows; j++)
		{

			sum += arr[j][i];

		}
		cout << "����� ��������� " << i + 1 << " ������� = " << sum << endl;
	}
}
void PrintArr(int* arr, int& size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(5) << arr[i];
	}
}
void OutPutArr(double** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(13) << arr[i][j];
		}
		cout << endl;
	}
}
void DeleteArr(double**& arr, int rows, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	try
	{
		int size_x, size_y;//����������� ��������
		cout << "������� ������ ������� ������� - ";
		cin >> size_x;
		cout << "������� ������ ������� ������� - ";
		cin >> size_y;
		ChekSize(size_x);
		ChekSize(size_y);
		int* arrX = new int[size_x];
		int* arrY = new int[size_y];
		int min, max; // ������� ��� �������
		cout << "������� ����� ������� ������� - ";
		cin >> min;
		cout << "������� ������ ������� ������� - ";
		cin >> max;
		CheckBorder(min, max);
		InPutDigits(arrX, size_x, min, max);
		InPutDigits(arrY, size_y, min, max);

		cout << "\narr X(p):\n";
		PrintArr(arrX, size_x);
		cout << "\narr Y(q):\n";
		PrintArr(arrY, size_y);

		int rows = size_x, cols = size_y;
		double** arr = new double* [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new double[cols];
		}
		InPutArr(arr, rows, cols, arrX, arrY);
		cout << "\n��������� ������:\n";
		OutPutArr(arr, rows, cols);
		SumArrCols(arr, rows, cols);
		delete[] arrX;
		delete[] arrY;
		DeleteArr(arr, rows, cols);
	} catch (const char* msg) { cout << msg; }
	return 0;
}