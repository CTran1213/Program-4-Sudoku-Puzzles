//SudokuOffspring.h
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//Declaration or class emthods and data members
//The SudokuFitness class implements "makeOffspring" for Puzzle objects. It uses the 
//mutation operator from genetic programming to create a copy of the given Puzzle 
//which has a 3% chance of mutation

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

   //This method creates a copy of the given puzzle and each sudoku box in the
   // copy has a 3% chance of mutating. If the given puzzle has any 0's in the
   // grid, the 0's are changed to random number between 1-9.
   //Precondition: none
   //Postcondition: A copy of the given puzzle is returned
   Puzzle* makeOffspring(Puzzle*& sudokuPuzzle)  override;

};