#pragma once
#include<iostream>
#include "Puzzle.h"
#include <ctype.h>
//#include "SudokuFitness.h"
using namespace std; 

class Sudoku : public Puzzle
{
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
         outstream << " |" << endl;
         if (i == 2 || i == 5) {
               outstream << "+-------+-------+-------+" << endl;
         }
      }
      outstream << "+-------+-------+-------+" << endl;
      return outstream;
   }

public:
   Sudoku();
   //~Sudoku();
   int getFitness();

private:
   int sudokuNumbers_[9][9];
   bool fixedValues_[9][9];
   //SudokuFitness fitnessObject_;
};