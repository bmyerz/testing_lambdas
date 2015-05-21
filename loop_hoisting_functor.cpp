#include <iostream>


struct f {
  float g;
  float h;
  float* sum;
  int i;
  
  f(float g, float h, float* sum, int i) : g(g),h(h),sum(sum),i(i) { }

  void operator()() {
    *sum += g*h*i;
  }
};

int main() {
  size_t times = 1024*1024*1024;

  float g = 56;
  float h = 79;

  float sum = 0;
  for (int i=0; i<times; i++) {
    f(g,h,&sum,i)();
  }

  std::cout << sum << std::endl;
}
