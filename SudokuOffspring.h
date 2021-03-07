#pragma once
#include "Reproduction.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Sudoku.h"

using namespace std;

class SudokuOffspring: public Reproduction
{
   public:
   SudokuOffspring();
   Sudoku* makeOffspring(Sudoku*& sudokuPuzzle) override;
};