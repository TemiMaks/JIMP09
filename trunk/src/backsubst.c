#include <stdio.h>
#include "backsubst.h"
#include "matrix.h"

int backsubst(Matrix *x, Matrix *A, Matrix *b) {
    // Sprawdzenie poprawności wejścia
    if (x == NULL | | A == NULL | | b == NULL) {
        fprintf(stderr, "Błąd! Jeden z wskaźników (x, A, b) jest NULL.\n");
        return 1;
    }
    if (A->r != A->c | | A->r != b->r | | b->c != 1 | | x->r != A->r | | x->c != 1) {
        fprintf(stderr, "Błąd! Nieprawidłowe wymiary macierzy.\n");
        return 1;
    }

    // Wykonanie podstawiania wstecznego
    for (int i = A->r - 1; i >= 0; i--) {
        // Sprawdzenie, czy element diagonalny jest zerowy
        if (A->data[i][i] == 0) {
            fprintf(stderr, "Błąd! Zerowy element diagonalny w wierszu %d.\n", i);
            return 1;
        }

        // Obliczenie wartości x[i]
        double sum = 0.0;
        for (int j = i + 1; j < A->c; j++) {
            sum += A->data[i][j] * x->data[j][0];
        }
        x->data[i][0] = (b->data[i][0] - sum) / A->data[i][i];
    }

    return 0; // Sukces
}
