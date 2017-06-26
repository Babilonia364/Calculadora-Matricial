VMTrixie:	main.o	ICCCrusaders.o
	gcc main.o ICCCrusaders.o -o VMTrixie

main.o:	main.c
	gcc -c main.c

ICCCrusaders.o:	ICCCrusaders.c	ICCCrusaders.h
	gcc -c ICCCrusaders.c

clean:
	rm *.o