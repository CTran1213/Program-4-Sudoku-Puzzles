//Sudoku.h
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//The Sudoku class must hold the representation of a Sudoku puzzle, meaning it must know which numbers in the 
//9-by-9 grid are fixed (the ones given at the start of the puzzle) and which are variable (the ones written 
//in as a possible solution).
#pragma once
#include<iostream>
#include "Puzzle.h"
#include <ctype.h>
#include "SudokuFitness.h"
#include <vector>
using namespace std; 

class Sudoku : public Puzzle
{
	//This istream operator takes in a string of characters and uses the first 81 digits to populate the sudoku grid. 
	//Digits that are 0 are not fixed numbers and digits that are 1-9 are fixed numbers
	friend istream& operator>>(istream& instream, Sudoku& sudoku)
   {
      int count = 0;
      char character;
      int row = 0, column = 0;
      while(count < 81){
         cin >> character;
         if(isdigit(character)){
            ++count;
            if(column == 9){
               column = 0;
               ++row;
            }

            sudoku.sudokuNumbers_[row][column] = character - '0';
            if(sudoku.sudokuNumbers_[row][column] != 0){
               sudoku.fixedValues_[row][column] = true;
            }
            ++column;
         }
      } 
      
      return instream;
   }

	//This ostream operator produces a "human friendly" output as formatted text. 
	//Output a puzzle as 13 lines of text, with each line either being a separator or 
	//one containing the numbers in a row of the puzzle separated by single spaces. Use the 
	//'|', '+', and '-' characters to separate 3-by-3 blocks (so, each line of output should be 25 
	//printing characters long: 9 digits, 12 spaces, and 4 '|' for "non-divider" lines and 21 '-' 
	//and 4 '+' for "divider" lines). An example (very simple puzzle) is shown below.
	friend ostream& operator<<(ostream& outstream, const Sudoku& sudoku)
   {
      outstream << "+-------+-------+-------+" << endl;
      for (int i = 0; i < 9; i++) {
         outstream << "| ";
         for (int j = 0; j < 9; j++) {
               if (j == 3 || j == 6) {
                  outstream << "| ";
               }
               outstream << sudoku.sudokuNumbers_[i][j] << " ";
         }
         outstream << "|" << endl;
         if (i == 2 || i == 5) {
               outstream << "+-------+-------+-------+" << endl;
         }
      }
      outstream << "+-------+-------+-------+" << endl;
      return outstream;
   }

public:
   //Constructor. Resizes the vector to hold a 9-by-9 grid. Makes every fixed value false.
   Sudoku();

   //Destructor
   ~Sudoku();

   //2nd constructor that copies over a sudoku grid and its fixed values
   Sudoku(vector<vector<int>>& a, vector<vector<bool>>& b);

   //Returns the 9-by-9 vector. Is used in other classes to change or look at each box
   //Precondition: none
   //Postcondition: the sudoku is initialized and the vector is returned
   vector<vector<int>> getSudokuArray();

   //This method returns the 9-by-9 grid of fixed values. Is normally used with the sudoku array
   //Precondition: none
   //Postcondition: 9-by-9 grid of booleans are returned
   vector<vector<bool>> getFixedValues();

   //Returns a boolean letting the user know if the box at the specified row and column is fixed or not
   //Precondition: the sudoku is initialized
   //Postcondition: returns true if the box is fixed, false otherwise
   bool isFixed(int row, int column) const;
   
   //This method sets the value of the specified box
   //Precondition: None
   //Postcondition: The number at row,column is changed. returns true
   bool setSudokuBoxValue(int num, int row, int column);

private:
   //A 2D array that is the sudoku puzzle. It is a 9-by-9 grid that holds integers
   vector<vector<int>> sudokuNumbers_;
   
   //9-by-9 grid that holds booleans. Each box corresponds to a box in sudokuNumber_. 
   //True means the number is fixed and cannot be change, while false means the number 
   //isn't fixed and can be changed
   vector<vector<bool>> fixedValues_;
};
<<<<<<< HEAD

=======
>>>>>>> 8265093599aab94bfe6dd465e290aa558e6db326
