#include "function.h"
#include <time.h>

int main() {
    srand(time(NULL));
    SudokuGrid other = createMaskSudokuGrid(9, 60, 1), ttg = createGameSudokuGrid(9), truc;
    printMatrice(other);
    truc = createdUserSudokuGrid(ttg, other);
    printMatrice(truc);
    truc=play_sudoku(truc);
    return 0;
}