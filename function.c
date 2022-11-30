#include "function.h"

void fillMatrix(int **mat, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            mat[i][j] = -1;
        }
    }
}

void fillMaskRandom(int **mat, int size, int numberOfCellShow) {
    int i, j, indexLig, indexCol;
    for (i = 0; i < numberOfCellShow; i++) {
        do {
            indexLig = rand() % size;
            indexCol = rand() % size;
        } while (mat[indexLig][indexCol] == 1);
        mat[indexLig][indexCol] = 1;
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (mat[i][j] != 1) {
                mat[i][j] = 0;
            }
        }
    }
}
