/*
* В массиве, состоящем из п вещественных элементов, вычислить:
- количество элементов массива, меньших заданному числу Р;
- сумму целых частей элементов массива, расположенных после последнего отрицательного
элемента.
Преобразовать массив таким образом, чтобы сначала располагались все элементы, меньшие Р,
а потом — все остальные. Порядок следования элементов не изменять.
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void CheckBorder(int min, int max)
{
	if (min > max)
	{
		throw "введенные границы не подходят";
	}
}
void InPutDigitsRandom(int* arr, int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (max + 1 - min) + min; //рандом
		//cin >> arr[i]; //ввод с клавиатуры
	}
}
void InPutDigitsHand(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{

		cin >> arr[i]; //ввод с клавиатуры
	}
}
void Menu(int* arr, int size)
{
	int choice;
	cout << "введите способ ввода эл массива 1(с руки) 2(рандом):\n";
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
		int min, max; // границы для рандома
		cout << "введите левую границу массива - ";
		cin >> min;
		cout << "введите правую границу массива - ";
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
		throw"неверный размер!";
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
		throw "нет элементов в массиве меньше задданого числа Р";
	}
	cout << "\nколичество элементов < p - " << counter << endl;
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
		throw "нет отрицательных чисел";
	}
	for (int i = j; i < size; i++)
	{
		SumEl += arr[i];
	}
	cout << "\nсумма элементов массива после последнего отрицательного числа = " << SumEl << endl;
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
		int arr[MAXSIZE];*/ //статический массив
		int size;
		cout << "введите размер массива\n";
		cin >> size;
		CheckSize(size);
		int* arr = new int[size];
		Menu(arr, size);
		CoutArr(arr, size);
		//колво эл массива меньеш P
		int p;
		cout << "\nвведите число P - ";
		cin >> p; 
		ElUnderP(arr, size, p);
		//суммма
		//SumElArr(arr, size);
		// изменить порядок массива до p а потом остальные
		cout << "\nchange ";
		ChangeArr(arr, size, p);
		CoutArr(arr, size);
		delete[]arr;
	} catch (const char* msg) { cout << msg; }
	return 0;
}