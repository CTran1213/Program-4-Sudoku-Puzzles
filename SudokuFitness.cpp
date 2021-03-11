//SudokuFitness.cpp
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//Implementation of SudokuFitness.h
//The SudokuFitness class implements "howFit" for Puzzle objects.
//The strategy we used to find the fitness number of a puzzle was counting the 
//number of conflicts in the rows, columns, and boxes

#include "SudokuFitness.h"

//Constructor
SudokuFitness::SudokuFitness()
{

}

//This method takens in a puzzle and counts the number of conflicts in each row, 
//column, and box. The conflicts are then added and that is the fitness number of the puzzle
//Precondition: All variable/non-fixed boxes are not zeroes
//Postcondition: A fitness number for the puzzle is returned. The number cannot be higher than 972
int SudokuFitness::howFit(Puzzle*& sudokuPuzzle) const
{
   int rowConflicts = 0;
   int columnConflicts = 0;
   int boxConflicts = 0;

   //Sudoku& s = *(static_cast<Sudoku*>(sudokuPuzzle));

   vector<vector<int>> sudoku = sudokuPuzzle->getSudokuArray();
   /*checks conflicts in every row and column*/
   int row = 0;
   while(row<9){
      for(int column=0; column<9; column++){
         for(int index= column + 1; index<9; index++){
            if(sudoku[row][column] == sudoku[row][index]){
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
		for (int j = 0; j < 3; j++){
			boxConflicts += calculateBoxConflicts(i*3, j*3, sudoku);  
		}
	}
   return rowConflicts + columnConflicts + boxConflicts;
}

//This method accepts the position of the top left hand side of a 3-by-3 sudoku box and the sudoku array. 
//It then iterates through the box and counts the number of conflicts.
//Precondition: none
//Postcondition: returns the number of conflicts in a box
int SudokuFitness::calculateBoxConflicts(int startXPoint, int startYPoint, 
   vector<vector<int>> sudoku) const
{
   int boxConflicts = 0;

   /*get all values in a box and puts in array*/
   vector<int> values;
	for (int i = 0; i< 3; i++){
		for (int j = 0; j < 3; j++){
         values.push_back(sudoku[startXPoint + i][startYPoint + j]);
      }
   }

   /*calculates conflicts in box*/
   for (int i = 0; i < 9; i++){
      for (int j = i+1; j < 9; j++){
         if(values[i] == values[j]){
				++boxConflicts;
			}
      }
	}

   return boxConflicts;
}
