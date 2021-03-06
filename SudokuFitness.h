#pragma once
#include "Fitness.h"

class SudokuFitness : public Fitness
{
    public:
    SudokuFitness();
    int howFit(int sudoku[][9]) const;
};