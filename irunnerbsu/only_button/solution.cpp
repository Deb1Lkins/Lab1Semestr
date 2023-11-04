#include <iostream> 
int main() {  
  int n; 
  unsigned long long b = 0, a = 1; 
  std::cin >> n; 
  for (int i = 0; i < n; i++) { 
    b = b + a; a = b - a;
  } 
  std::cout << a << ' ' << b; 
  return 0;
}