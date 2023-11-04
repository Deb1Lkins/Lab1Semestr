/*9. Задан текстовый файл input.txt. 
Требуется определить строки этого  файла, содержащие максимальную по длине подстроку, состоящую из  одинаковых символов латинского алфавита. 
Заглавные и строчные буквы не  различаются. Если таких строк несколько, найти первые 10. 
Результат  вывести на консоль в форме, удобной для чтения. */
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
using std::string;
using std::cout;
using std::cin;
void CheckFile(std::ifstream& fin)
{
	if (fin.fail())
	{
		throw" файл не существует  ";
	}
	if (!fin.is_open())
	{
		throw " ошибка файл не может открыться  ";
	}
	if (fin.peek() == EOF)
	{
		throw"  файл пуст ";
	}
}
void InPutEnglSymbols(string& str)
{
	for (size_t i = 64; i < 123; i++)
	{
		if ((i > 64 && i < 91) || (i > 96 && i < 123))
		{

			str += (char)i;

		}
		continue;
	}
}
void FindCounterOfsymbols(string& temp, int& max_counter, int& counter)
{
	transform(temp.begin(), temp.end(), temp.begin(), tolower);
	for (size_t l = 0; l < temp.size(); l++)
	{
		if (temp[l] == temp[l + 1])
		{
			counter++;
		}
		else
		{
			if (max_counter <= counter)
			{
				max_counter = counter;
			}
			counter = 0;
		}
	}
}
int FindMaxOfUndString(string& str, string all_engl_symbols)
{
	int counter = 0, max_counter = 0;
	int j;
	for (int i = 0; i < str.size(); i++)
	{
		i = str.find_first_of(all_engl_symbols);
		if (i + 1 == str.size())
		{
			break;
		}
		j = str.find_first_not_of(all_engl_symbols, i);
		string temp = str.substr(i, j - i);
		FindCounterOfsymbols(temp, max_counter, counter);
		i = j;
	}
	return max_counter;
}
void FindMaxString(int* arr, int counter_of_rows, int& max_counter)
{
	for (int i = 0; i < counter_of_rows; i++)
	{
		if (max_counter < arr[i])
		{
			max_counter = arr[i];
		}
	}
}
void PrintStrings(std::ifstream& fin,int* arr, int max_counter, int counter_of_rows)
{
	string str;
	int counter = 0;
	for (int i = 0; i < counter_of_rows; i++)
	{
		getline(fin, str);
		if (arr[i] == max_counter)
		{
			cout << str << "\n";
			counter++;
			if (counter==10)
			{
				break;
			}
		}
		str = "";
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		std::ifstream fin("in.txt");
		CheckFile(fin);
		string str;
		string all_engl_symbols;
		InPutEnglSymbols(all_engl_symbols);
		int counter_of_rows = 0;
		int arr[100];
		int k = 0;
		int max_counter = 0;
		while (getline(fin, str))
		{
			counter_of_rows++;
			arr[k++] = FindMaxOfUndString(str, all_engl_symbols);
		}
		fin.clear();
		fin.seekg(0);
		str = "";
		FindMaxString(arr, counter_of_rows, max_counter);
		PrintStrings(fin, arr, max_counter, counter_of_rows);
	} catch (const char* msg) { cout << msg; }
}