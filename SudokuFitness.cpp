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
//column, and box. The conflicts are then added and that is the fitness number 
//of the puzzle
//Precondition: All variable/non-fixed boxes are not zeroes
//Postcondition: A fitness number for the puzzle is returned. The number cannot
// be higher than 972
int SudokuFitness::howFit(Puzzle*& sudokuPuzzle) const
{
   /*initializes variables for each type of conflict*/
   int rowConflicts = 0;
   int columnConflicts = 0;
   int boxConflicts = 0;

   /*converts the parameter to a Sudoku object*/
   Sudoku& s = *(static_cast<Sudoku * >(sudokuPuzzle)); 

   /*gets the int 2D array from the parameter*/
   vector<vector<int>> sudoku = s.getSudokuArray();
   /*checks conflicts in every row and column*/

   int row = 0;//initializes row counter to 0
   /*Loops through all 9 rows*/
   while(row<9){
      /*Loops through all 9 squares of a row*/
      for(int column=0; column<9; column++){
         /*Loops agains through the squares only starting at column and 
         going until the end of that row*/
         for(int index= column + 1; index<9; index++){
            /*checks if a square conflcits with another in the row*/
            if(sudoku[row][column] == sudoku[row][index]){
               ++rowConflicts;//increaces row conflict by 1
            }
            /*checks if a column conflcits with another in the row*/
            if(sudoku[column][row] == sudoku[index][row]){
               ++columnConflicts;//increaces column conflict by 1
            }
         }
      }
      ++row;//iterates row variable by 1
   }

   /*loops three times for each row of boxes in the 2D array*/
   for (int i = 0; i < 3; i++){
      /*loops three times for each box in a row*/
		for (int j = 0; j < 3; j++){
         /*passes in the x and y for a square and the whole 2D array and 
         //returns the box conflict
         for a particulat box*/
			boxConflicts += calculateBoxConflicts(i*3, j*3, sudoku); 
		}
	}
   /*returns the sum of all the conflicts*/
   return rowConflicts + columnConflicts + boxConflicts;
}

//This method accepts the position of the top left hand side of a 3-by-3 sudok
//u box and the sudoku array. 
//It then iterates through the box and counts the number of conflicts.
//Precondition: none
//Postcondition: returns the number of conflicts in a box
int SudokuFitness::calculateBoxConflicts(int startXPoint, int startYPoint, 
   vector<vector<int>> sudoku) const
{
   //initializes the box conflicts variable
   int boxConflicts = 0;

   /*get all values in a box and puts in array*/
   vector<int> values;
   /*Loops 3 times for each row in a box*/
	for (int i = 0; i< 3; i++){
      /*Loops three times again for each square in one row in a box*/
		for (int j = 0; j < 3; j++){
         //pushes the value at a particulat square to the values array
         values.push_back(sudoku[startXPoint + i][startYPoint + j]);
      }
   }

   /*calculates conflicts in box*/
   /*Loops nine times for each box value*/
   for (int i = 0; i < 9; i++){
      /*Loops starting at i until end to check if a value conflicts with i*/
      for (int j = i+1; j < 9; j++){
         /*checks for conflict*/
         if(values[i] == values[j]){
				++boxConflicts;//increaces box conflicts by 1
			}
      }
	}
   return boxConflicts;//returns box conflicts int
}
