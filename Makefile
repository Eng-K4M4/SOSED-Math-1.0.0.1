all: pro

pro:main.o 
	cc main.o -o math
	
main.o:main.c

clean:
	rm *.o math
