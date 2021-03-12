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
   SudokuOffspring();
   Puzzle* makeOffspring(Puzzle*& sudokuPuzzle)  override;

   private:
};