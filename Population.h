#pragma once
#include "Puzzle.h"

class Population
{
   public:
   Population();

   virtual void cull() = 0;
   virtual void newGeneration() = 0;
   virtual int getBestFitness() = 0;
   virtual Puzzle*& getBestIndividual() = 0;
};