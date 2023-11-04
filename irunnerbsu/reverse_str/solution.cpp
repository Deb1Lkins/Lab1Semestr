#include <iostream>
#include <fstream>
#include <string>
int main()
{
	size_t a, b;
	std::string str;
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	fin >> a >> b;
	getline(fin, str, '\0');
	size_t counter = 0;
	do
	{
		std:: swap(str[a + counter], str[b - counter]);
		counter++;
	}
	while (a + counter < b - counter);
	str.erase(str.find('\n'), 1);
	fout << str;
	return 0;
}