#include <iostream>
using std::cin;
using std::cout;
int main()
{
	long long int n;
	cin >> n;
	if (n < 2 || n > 100000)
	{
		return 0;
	}
	long long int res = 1;
	for (long long int i = 2; i <= n; i++)
	{
		res += i * i;
	}
	cout << res;
	return 0;
}