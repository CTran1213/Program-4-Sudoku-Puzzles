//Fitness.h
//3/12/2021
//@author: Faduma Farah
 //@studentID: 1727406
//Catherine Tran ID: 2021829
//Fitness is used by a Population to evaluate individual Puzzles.
//Fitness and its subclasses are implementations of the strategy design pattern.
//Fitness subclasses must implement a "howFit" method, which takes a Puzzle (subclass) object and returns an int. 
//Perhaps counter-intuitively, lower fitness values indicate more fit individuals (in other words, howFit is indicating how far a Puzzle is from perfection).

#pragma once 
#include <vector>
#include "Puzzle.h"
using namespace std;

class Fitness
{
   public:
      Fitness()
      {

      }

      virtual int howFit(Puzzle*& sudokuPuzzle) const = 0;
   
};
