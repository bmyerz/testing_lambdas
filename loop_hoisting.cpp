#include <iostream>


int main() {
  size_t times = 1024*1024*1024;

  float g = 56;
  float h = 79;

  float sum = 0;
  for (int i=0; i<times; i++) {
    [g,h,i,&sum] {
      sum += g*h*i;
    }();
  }

  std::cout << sum << std::endl;
}
