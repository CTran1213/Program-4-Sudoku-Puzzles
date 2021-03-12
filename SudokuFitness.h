//SudokuFitness.cpp
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//Implementation of SudokuFitness.h
//The SudokuFitness class implements "howFit" for Puzzle objects.
//The strategy we used to find the fitness number of a puzzle was counting the 
//number of conflicts in the rows, columns, and boxes
#pragma once

#include "Fitness.h"
#include "Sudoku.h"
#include <vector>
#include <iostream>

using namespace std;

class Sudoku;
class SudokuFitness: public Fitness
{
   public:
      //Constructor
      SudokuFitness();
      
      //This method takens in a puzzle and counts the number of conflicts in each row, 
      //column, and box. The conflicts are then added and that is the fitness number of the puzzle
      //Precondition: All variable/non-fixed boxes are not zeroes
      //Postcondition: A fitness number for the puzzle is returned. The number cannot be higher than 972
      int howFit(Puzzle*& sudokuPuzzle) const override;

   private:
      //This method accepts the position of the top left hand side of a 3-by-3 sudoku box and the sudoku array. 
      //It then iterates through the box and counts the number of conflicts.
      //Precondition: none
      //Postcondition: returns the number of conflicts in a box
      int calculateBoxConflicts(int startXPoint, int StartYPoint, 
         vector<vector<int>> sudoku) const;
};
