#include "SudokuOffspring.h"

SudokuOffspring::SudokuOffspring()
{

}

Sudoku* SudokuOffspring::makeOffspring(Sudoku*& sudokuPuzzle)
{
   double val;
   int numChange;

   vector<vector<int>> tempSudoku = sudokuPuzzle.getSudokuArray();
   for (int i = 0; i < tempSudoku.size(); i++)
   {
      for (int j = 0; j < tempSudoku[i].size(); i++)
      {
         val = rand();
         numChange = ran() % 10;
         if (val < 0.05) //%5
         {
            tempSudoku[i][j] = numChange;
         }
      }
   }
   return tempSudoku;
}