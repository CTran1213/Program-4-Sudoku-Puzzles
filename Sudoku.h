#pragma once
#include<iostream>
#include "Puzzle.h"

using namespace std;

class Sudoku : public Puzzle
{
	friend istream& operator>>(istream& instream, Sudoku& p);
	friend ostream& operator<<(ostream& outstream, const Sudoku& p)
   {
      output << "+-------+-------+-------+" << endl;
      for (int i = 0; i < 9; i++) {
         output << "| ";
         for (int j = 0; j < 9; j++) {
               if (i == 3 || i == 6) {
                  output << "| ";
               }
               output << sudokuNumbers_[i][j] << " ";
         }
         output << " |" << endl;
         if (i == 3 || i == 6) {
               output << "+-------+-------+-------+" << endl;
         }
      }
      output << "+-------+-------+-------+" << endl;
      return output;
   }

public:
   Sudoku();
   ~Sudoku();

private:
   int sudokuNumbers_[9][9];
   bool fixedValues_[9][9];
   int fitnessNumber_;
};