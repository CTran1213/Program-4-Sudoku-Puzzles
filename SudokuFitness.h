#pragma once

#include "Fitness.h"
#include <vector>
#include <iostream>

using namespace std;

class Sudoku;
class SudokuFitness: public Fitness
{
   public:
      SudokuFitness();
      int howFit(Puzzle*& sudokuPuzzle) const override;

   private:
      int calculateBoxConflicts(int startXPoint, int StartYPoint, 
         vector<vector<int>> sudoku) const;
};