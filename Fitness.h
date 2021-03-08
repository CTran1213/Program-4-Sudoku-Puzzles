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