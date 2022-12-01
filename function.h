#ifndef SUDOKU_FUNCTION_H
#define SUDOKU_FUNCTION_H

#include <stdbool.h>
#include "struct.h"

int securityInputInt(int borneMin, int borneMax); // verif

Coordonnee askAndCheckUserCoordonnee(int); // verif
void playAMove(SudokuGrid , Coordonnee); // verif

bool isMatriceFull(SudokuGrid ); // verif

void printMatrice(SudokuGrid); // verif
void printMatriceWithMask(SudokuGrid , SudokuGrid ); // verif


#endif //SUDOKU_FUNCTION_H