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
	cout << "введите числитель - ";
	cin >> num;
	cout << "введите знаменатель - ";
	cin >> denom;
	fract.SetFract(num, denom);
}
int main()

{
	try
	{
		setlocale(LC_ALL, "ru");

		/*char ch;
		cout << "введите операцию над дроб€ми +, -, *, /, <, ++(1), --(2), (унарный минус)~, ^(обратна€ дробь) :\n";
		cin >> ch;
		switch (ch)
		{
		case '+':
		{

			Fraction fract_1;
			Fraction fract_2;
			Fraction fract_3;
			cout << "введите первую дробь\n";
			InPutFract(fract_1);
			cout << "введите вторую дробь\n";
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
			cout << "введите первую дробь\n";
			InPutFract(fract_1);
			cout << "введите вторую дробь\n";
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
			cout << "введите первую дробь\n";
			InPutFract(fract_1);
			cout << "введите вторую дробь\n";
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
			cout << "введите первую дробь\n";
			InPutFract(fract_1);
			cout << "введите вторую дробь\n";
			InPutFract(fract_2);
			fract_3 = fract_1 / fract_2;
			fract_3.PrintFract();
			break;
		}
		case '<':
		{
			Fraction fract_1;
			Fraction fract_2;
			cout << "введите первую дробь\n";
			InPutFract(fract_1);
			cout << "введите вторую дробь\n";
			InPutFract(fract_2);
			if (fract_1 > fract_2)
			{
				cout << "больше";
			}
			else
			{
				if (fract_1 < fract_2)
				{
					cout << "меньше";
				}
				else
				{
					if (fract_1 == fract_2)
					{
						cout << "равны дроби";
					}
				}
			}
			break;
		}
		case '1':
		{
			Fraction fract_1;
			cout << "введите дробь\n";
			InPutFract(fract_1);
			++fract_1;
			fract_1.PrintFract();
			break;
		}
		case '2':
		{
			Fraction fract_1;
			cout << "введите дробь\n";
			InPutFract(fract_1);
			fract_1--;
			fract_1.PrintFract();
			break;
		}
		case '~':
		{
			Fraction fract_1;
			Fraction fract_2;
			cout << "введите дробь\n";
			InPutFract(fract_1);
			fract_2 = -fract_1;
			fract_2.PrintFract();
			break;
		}
		case '^':
		{
			Fraction fract_1;
			Fraction fract_2;
			cout << "введите дробь\n";
			InPutFract(fract_1);
			fract_2 = ~fract_1;
			fract_2.PrintFract();
			break;
		}
		default: { throw"нет такой операции"; }
		}*/

		Fraction a, b;
		cin >> a;
		cout << a;
	}
	catch (const char* msg) { cout << msg; }
	return 0;
}
//–азработать пользовательский тип(класс) "ќЅџ Ќќ¬≈ЌЌџ≈ ƒ–ќЅ»".»сходный код класса оформить в виде двух файлов :
//заголовочного файла с  объ€влением класса и файла реализации методов.
//ƒробь хранить в  "канонической форме" : 
//если n Ц числитель, а d Ц знаменатель, то знак  хранитс€ в числителе(знаменатель всегда больше 0), а n и d Ц взаимнопростые.
//–еализовать все возможные арифметические операторы  над дроб€ми, операторы сравнени€, инкремента и декремента, унарный  минус, 
//оператор отрицани€ перегрузить, как оператор получени€ обратной дроби, 
//ввод с потока, вывод в поток, приведение к вещественному типу, 
//оператор присваивани€, составные операторы присваивани€.
// 
//ƒл€ обработки исключительных ситуаций использовать собственный класс(можно  простейший вариант).
//
//ƒл€ демонстрации возможностей класса написать головную  программу, в которой продемонстрировать работу с этим классом.
//ћеню  делать не надо.
//¬ комментари€х указать, что тестируете.
