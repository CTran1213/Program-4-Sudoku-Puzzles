//Fitness.h
//3/12/2021
//@author: Faduma Farah
 //@studentID: 1727406
//Catherine Tran ID: 2021829
//Fitness is used by a Population to evaluate individual Puzzles.
//Fitness and its subclasses are implementations of the strategy design pattern.
//Fitness subclasses must implement a "howFit" method, which takes a Puzzle 
//(subclass) object and returns an int. Perhaps counter-intuitively, lower 
//fitness values indicate more fit individuals (in other words, howFit is 
//indicating how far a Puzzle is from perfection).

#pragma once 
#include <vector>
#include "Puzzle.h"
using namespace std;

class Fitness
{
   public:
      //Constructor
      Fitness()
      {

      }
      
      //Virtual method that will be implemented in SudokuFitness.h
      //This method takens in a puzzle and counts the number of conflicts in
      // each row, column, and box. The conflicts are then added and that is 
      //the fitness number of the puzzle
      //Precondition: All variable/non-fixed boxes are not zeroes
      //Postcondition: A fitness number for the puzzle is returned. The number
      // cannot be higher than 972
      virtual int howFit(Puzzle*& sudokuPuzzle) const = 0;
   
};
