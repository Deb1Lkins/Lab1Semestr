#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  vector<string> words;
  size_t num;
  string str, res, result;
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  fin >> num;
  size_t begInd = 0;
  getline(fin, str);
  getline(fin, str);
  while (begInd <= str.size())
  {  
    res = str.substr(begInd, num);
    reverse(res.begin(), res.end());
    words.push_back(res);
    begInd += num;
    res.clear();
  }
  for (int i = 0; i < words.size(); i++)
    result += words[i];
  fout << result;
}