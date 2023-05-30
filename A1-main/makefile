alaskarovAdelineA1: alaskarovAdelineA1.o alaskarovAdelineA1Main.o
        gcc -Wall -std=c99 alaskarovAdelineA1.o alaskarovAdelineA1Main.c -o alaskarovAdelineA1 -lm
alaskarovAdelineA1.o: alaskarovAdelineA1.c givenA1.h
        gcc -Wall -std=c99 -c alaskarovAdelineA1.c
alaskarovAdelineA1Main.o: alaskarovAdelineA1Main.c givenA1.h
        gcc -Wall -std=c99 -c alaskarovAdelineA1Main.c
clean:
        rm *.o alaskarovAdelineA1
