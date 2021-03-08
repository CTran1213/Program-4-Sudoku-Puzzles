#include "SudokuOffspring.h"

SudokuOffspring::SudokuOffspring()
{

}

Puzzle* SudokuOffspring::makeOffspring(Puzzle*& sudokuPuzzle) 
{
   int val; //Random number used to get a 5% probability
   int numChange;

   default_random_engine generator;
   uniform_int_distribution<int> uniform1(1,9); //A number between and including 1-9
   
   default_random_engine generator2;
   uniform_int_distribution<int> uniform2(0,100);

   Sudoku& sudoku = *(static_cast<Sudoku * >(sudokuPuzzle));

   vector<vector<int>> tempSudoku = sudoku.getSudokuArray();

   //iterate through the rows
   for (int i = 0; i < 9; i++)
   {
      //iterate through the columns
      for (int j = 0; j < 9; j++)
      {
         val = uniform2(generator2); //Random number between 0 and 100
         numChange = uniform1(generator); //Random number between and including 1-9
         if (tempSudoku[i][j] == 0)
         {
            sudoku.setSudokuBoxValue(numChange, i, j);
         }
         else if (val < 5 && !sudoku.isFixed(i,j)) //5%
         {
            sudoku.setSudokuBoxValue(numChange, i, j); //Changes the value if the box is not fixed AND val is less than .05 (5%)
         }
      }
   }
   return sudokuPuzzle;
}