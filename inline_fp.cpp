#include <iostream>
#include <cstdlib>

using namespace std;

__attribute__ ((noinline))
int64_t apply_many_times_fp(std::function<int64_t (int64_t)> f, int64_t n) {
    int64_t sum = 0;
    for (int64_t i=0; i<n; i++) {
        sum+=f(i);         // when inlined, gcc does a smart analysis on the for loop
    }
    return sum;
}

int main(int argc, char** argv) {


    int64_t x = 10;
    int64_t y = 20;

    int64_t z = apply_many_times_fp([=](int64_t i) {
        return i * (x+y);
    }, atoi(argv[1]));

    std::cout << z << std::endl;
}