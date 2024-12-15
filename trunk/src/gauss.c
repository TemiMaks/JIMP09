#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mat_io.h"

int eliminate(Matrix *A, Matrix *B) {
    if (A->r != A->c || A->r != B->r || B->c != 1) {
        // Macierz A musi być kwadratowa, a B musi być wektorem kolumnowym
        return 1;
    }

    int n = A->r;

    for (int k = 0; k < n; ++k) {
        // Wybór elementu głównego
        int maxRow = k;
        for (int i = k + 1; i < n; ++i) {
            if (fabs(A->data[i][k]) > fabs(A->data[maxRow][k])) {
                maxRow = i;
            }
        }

        // Zamiana wierszy w A i B
        if (maxRow != k) {
            double *tempRow = A->data[k];
            A->data[k] = A->data[maxRow];
            A->data[maxRow] = tempRow;

            double tempB = B->data[k][0];
            B->data[k][0] = B->data[maxRow][0];
            B->data[maxRow][0] = tempB;
        }

        // Sprawdzenie czy element na diagonali jest zerem
        if (fabs(A->data[k][k]) < 1e-9) {
            return 1; // Macierz osobliwa
        }

        // Eliminacja Gaussa
        for (int i = k + 1; i < n; ++i) {
            double factor = A->data[i][k] / A->data[k][k];
            A->data[i][k] = 0; // Elementy poniżej diagonali w kolumnie k ustawiamy na 0
            for (int j = k + 1; j < n; ++j) {
                A->data[i][j] -= factor * A->data[k][j];
            }
            B->data[i][0] -= factor * B->data[k][0];
        }
    }

    return 0;
}
