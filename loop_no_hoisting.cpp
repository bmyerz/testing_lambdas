#include <iostream>


int main() {
  size_t times = 1024*1024*1024;

  float g = 56;

  float sum = 0;
  for (int i=0; i<times; i++) {
    [g,i,&sum] {
      sum += g*i;
    }();
  }

  std::cout << sum << std::endl;
}
