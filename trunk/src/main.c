#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printf("Macierz A\n");
	printToScreen(A);
	printf("\n");
	printf("Macierz B\n");
	printToScreen(b);
	printf("\n");

	int res = eliminate(A,b);

	if (res == 1) {
    fprintf(stderr, "Błąd! Macierz jest osobliwa.\n");
    return 1;
	}

	x = createMatrix(b->r, 1);


	if (x != NULL) {
		int res = backsubst(x,A,b);

		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
