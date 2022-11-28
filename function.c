#include "function.h"

SudokuGrid createSudoku(int size) {
    int i;
    SudokuGrid matrice;
    matrice.matrice = (int **) malloc(sizeof(int *) * size);
    for (i = 0; i < size; i++) {
        matrice.matrice[i] = malloc(sizeof(int) * size);
    }
    matrice.size = size;
    return matrice;
}


SudokuGrid createdUserSudokuGrid(SudokuGrid solutionMatrix, SudokuGrid maskMatrix) {
    SudokuGrid userTakusuGrid;
    int **mask;
    mask = maskMatrix.matrice;
    userTakusuGrid = createSudoku(solutionMatrix.size);
    int i, j;
    for (i = 0; i < solutionMatrix.size; i++) {
        for (j = 0; j < solutionMatrix.size; j++) {
            if (mask[i][j] == 1) {
                (userTakusuGrid.matrice[i][j]) = (solutionMatrix.matrice[i][j]);
            } else {
                (userTakusuGrid.matrice[i][j]) = -1;
            }
        }
    }
    return userTakusuGrid;
}

SudokuGrid createGameSudokuGrid(int size) {
    SudokuGrid gameGrid;
    gameGrid = createSudoku(size);
    int **grid;
    grid = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(sizeof(int) * size);
    }
    createGrid9(grid);
    gameGrid.matrice = grid;
    return gameGrid;
}
