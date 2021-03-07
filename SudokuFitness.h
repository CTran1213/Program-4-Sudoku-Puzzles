#pragma once

#include "Fitness.h"
#include <vector>
#include <iostream>

using namespace std;

class SudokuFitness: public Fitness
{
   public:
      SudokuFitness();
      int howFit(vector<vector<int>> sudoku) const override;

   private:
      int calculateBoxConflicts(int startXPoint, int StartYPoint, 
         vector<vector<int>> sudoku) const;
};