#pragma once
#include "Reproduction.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <random>
#include <ctime>

using namespace std;

class SudokuOffspring: public Reproduction
{
   public:
   //Constructor
   SudokuOffspring();

   //This method creates a copy of the given puzzle and each sudoku box in the copy has a 
   //3% chance of mutating. If the given puzzle has any 0's in the grid, the 0's are changed 
   //to random number between 1-9.
   //Precondition: none
   //Postcondition: A copy of the given puzzle is returned
   Puzzle* makeOffspring(Puzzle*& sudokuPuzzle)  override;

};