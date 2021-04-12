# comentarios...

app.out: main.c ../lib/src/estudiante.h
	gcc -fPIC -c ../lib/src/estudiante.c -o ../lib/dynamic/estudiante.o
	gcc -shared -o ../lib/dynamic/libestudiante.so ../lib/dynamic/estudiante.o
	gcc main.c -L../lib/dynamic/ -lestudiante -o app.out
clean:
	rm app.out ../lib/dynamic/estudiante.o ../lib/dynamic/libestudiante.so 
