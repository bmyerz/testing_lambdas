
for e in 0 1 2 3; do
	for n in loop_no_hoisting; do
        echo compiling ${n}_O$e;
		g++ -O$e -std=c++11 $n.cpp -o ${n}_O$e.exe;
        gobjdump -S ${n}_O$e.exe > ${n}_O$e.S
	done
done


for e in O0 O1 O2 O3; do for i in 1 2 3; do echo $e; time ./loop_no_hoisting_$e.exe ; done; done
