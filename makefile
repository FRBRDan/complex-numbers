mycomp: complex.o mycomp.o mycomp_funcs.o
	gcc -ansi -Wall -g complex.o mycomp.o mycomp_funcs.o -o mycomp -lm
complex.o: complex.c complex.h
	gcc -c -ansi -Wall complex.c -o complex.o -lm
mycomp.o: mycomp.c mycomp.h
	gcc -c -ansi -Wall mycomp.c -o mycomp.o
mycomp_funcs.o: mycomp_funcs.c mycomp.h
	gcc -c -ansi -Wall mycomp_funcs.c -o mycomp_funcs.o