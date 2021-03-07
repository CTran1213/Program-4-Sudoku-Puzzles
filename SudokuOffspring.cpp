#include "SudokuOffspring.h"

SudokuOffspring::SudokuOffspring()
{

}

Sudoku* SudokuOffspring::makeOffspring(Sudoku*& sudokuPuzzle)
{
   float val; //Random number used to get a 5% probability
   int numChange; //A number between and including 1-9
   srand((unsigned) time(NULL));//Generator so rand produces a diff number with every run

   //iterate through the rows
   for (int i = 0; i < 9; i++)
   {
      //iterate through the columns
      for (int j = 0; j < 9; j++)
      {
         val = (float)rand()/RAND_MAX; //Random number between 0 and 1
         numChange = (rand() % 9 + 1); //Random number between and including 1-9
         cout << val << endl;
         if (val < 0.05 && !sudokuPuzzle->isFixed(i,j)) //5%
         {
            sudokuPuzzle->setSudokuBoxValue(numChange, i, j); //Changes the value if the box is not fixed AND val is less than .05 (5%)
         }
      }
   }
   return sudokuPuzzle;
}