#include "SudokuOffspring.h"

SudokuOffspring::SudokuOffspring()
{

}

Puzzle*& SudokuOffspring::makeOffspring(Puzzle*& sudokuPuzzle) 
{
   double val; //Random number used to get a 5% probability
   int numChange; //A number between and including 1-9

   Sudoku& sudoku = *(static_cast<Sudoku * >(sudokuPuzzle));

   vector<vector<int>> tempSudoku = sudoku.getSudokuArray();

   //iterate through the rows
   for (int i = 0; i < 9; i++)
   {
      //iterate through the columns
      for (int j = 0; j < 9; j++)
      {
         val = ((double)rand())/ (RAND_MAX + 1.0); //Random number between 0 and 1
         numChange = rand()%9 + 1; //Random number between and including 1-9
         if (tempSudoku[i][j] == 0) //Sets the box to a random number [1,9] if it is empty
         {
            sudoku.setSudokuBoxValue(numChange, i, j);
         }
         else if (val < 0.05 && !sudoku.isFixed(i,j)) //5%
         {
            sudoku.setSudokuBoxValue(numChange, i, j); //Changes the value if the box is not fixed AND val is less than .05 (5%)
         }
      }
   }
   return sudokuPuzzle;
}