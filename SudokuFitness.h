#pragma once

#include "Fitness.h"
#include <vector>
#include <iostream>

using namespace std;

class SudokuFitness: public Fitness
{
   public:
      SudokuFitness();
      int howFit(int sudoku[9][9]) const override;

   private:
      int calculateBoxConflicts(int startXPoint, int StartYPoint, 
         int sudoku[9][9]) const;
};