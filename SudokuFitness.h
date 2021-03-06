#pragma once

#include "Fitness.h"

class SudokuFitness: public Fitness
{
   public:
      SudokuFitness();
      int howFit(int sudoku[9][9]) const override;

   private:
      int calculateBoxConflicts(int startXPoint, int StartYPoint, int TwoDArray[9][9]) const;
};