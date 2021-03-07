#pragma once
#include "Puzzle.h"

class Reproduction
{
   public:
      Reproduction()
      {

      }

      virtual Puzzle makeOffspring(Puzzle*& p) = 0;
};