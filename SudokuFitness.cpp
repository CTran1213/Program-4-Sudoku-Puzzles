#include "SudokuFitness.h"

SudokuFitness::SudokuFitness()
{

}

int SudokuFitness::howFit(int sudoku[9][9]) const
{
   int rowConflicts = 0;
   int columnConflicts = 0;
   int boxConflicts = 0;

   bool conflictBooleans[9][9];

   /*checks conflicts in every row and column*/
   int row = 0;
   while(row<9){
      for(int column=0; column<9; column++){
         for(int index= column + 1; index<9; index++){
            if(sudoku[row][column] == sudoku[row][index]) {
               ++rowConflicts;
            }
            if(sudoku[column][row] == sudoku[index][row]){
               ++columnConflicts;
            }
         }
      }
      ++row;
   }

   for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
		{
			boxConflicts += calculateBoxConflicts(i*3, j*3, sudoku);  
		}
	}

   cout << "Row conflicts: " << rowConflicts << endl;
   cout << "Column conflicts: " << rowConflicts << endl;
   cout << "Box conflicts: " << rowConflicts << endl;
   return rowConflicts + columnConflicts + boxConflicts;
}

int SudokuFitness::calculateBoxConflicts(int startXPoint, int startYPoint, int TwoDArray[9][9]) const
{
   int boxConflicts;

   /*get all values in a box and puts in array*/
   int values[9];
   int value = 0;
	for (int i = 0; i< 3; i++){
		for (int j = 0; j < 3; j++){
			values[value] = TwoDArray[startXPoint + i][startYPoint + j];   
			++value;
		}
   }

   /*calculates conflicts in box*/
   for (int i = 0; i < 9; i++){
      for (int j = i+1; j < 9; j++){
         if(values[i] == values[j]) {
				++boxConflicts;
			}
      }
	}

   return boxConflicts;
}