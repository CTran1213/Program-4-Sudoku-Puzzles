#include "SudokuFitness.h"

SudokuFitness::SudokuFitness()
{

}

int SudokuFitness::howFit(int sudoku[][9]) const
{
   int conflicts = 0;
   for(int i=0; i<9; i++){
      for(int j=0; j<9; j++){
         int index = sudoku[i][j];
         
      }
   }
   return conflicts;
}