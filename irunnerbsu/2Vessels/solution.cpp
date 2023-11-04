#include <iostream>
#include <iomanip>

int main()
{
  int N;
  double k1;
  double k2;
  std::cin >> N;
  k1 = 1;
  k2 = 1;
  bool flag = true;
  if (N >= 1 && N <= pow(1, 9))
    return 0;
  if (N == 1)
  {
    k1 -= 0.5;
    std::cout<< std::fixed << std::setprecision(9) << k1;
    return 0;
  }
  if (N == 2)
  {
    std::cout << std::fixed << std::setprecision(9) << k1;
    return 0;
  }
  if (N % 2 == 0)
  {
    k1 = 1;
    std::cout << std::fixed << std::setprecision(9) << k1;
    return 0;
  }
        k2 += ((k1) / (N + 1));
        k1 -= ((k1) / (N + 1));
  std::cout  << std::fixed << std::setprecision(9) << k1;
  return 0;
}