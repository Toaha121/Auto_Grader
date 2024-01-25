ShamsToahaAymanA1: ShamsToahaAymanA1.o ShamsToahaAymanA1Main.o
	gcc -Wall -std=c99 ShamsToahaAymanA1.o ShamsToahaAymanA1Main.c -o ShamsToahaAymanA1

ShamsToahaAymanA1.o: ShamsToahaAymanA1.c givenA1.h
	gcc -Wall -std=c99 -c ShamsToahaAymanA1.c

ShamsToahaAymanA1Main.o: ShamsToahaAymanA1Main.c givenA1.h
	gcc -Wall -std=c99 -c ShamsToahaAymanA1Main.c

clean:
	rm *.o ShamsToahaAymanA1
