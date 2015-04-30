
CC=g++
CFLAGS=-g -std=c++11 -O3

EXES=inline_fp \
noinline_fp \
inline_template \
noinline_template 

%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

test: $(EXES)
	for i in $(EXES); do echo $$i; time ./$$i 1000000000; done
