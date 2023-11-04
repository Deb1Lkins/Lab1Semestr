#include <iostream>
using std::cin;
using std::cout;
int main()
{
	long int a, b;
	cin >> a >> b;
	if (a < 1 || a > b)
	{
		return 0;
	}
	unsigned res = 0;
	if (a % 9 == 0)
	{
		res += 9;
	}
	else
	{
		res = a % 9;
	}
	
	int j = res + 1;
	long int c = (b - a) / 9;
	if (c >= 1)
	{
		res += c * 45;
	}
	long int size = b - a - c*9;
	for  (unsigned i = 0; i < size; i++)
	{
		if (j == 10)
		{
			j = 1;
		}
		res += j;
		j++;
	}
	cout << res;
	return 0;
}