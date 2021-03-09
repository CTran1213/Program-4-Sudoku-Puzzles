#pragma once
#include "Population.h"

class SudokuPopulation : public Population
{
   public:
   SudokuPopulation();
   void cull();
   void newGeneration();
   int getBestFitness();
   Puzzle*& getBestIndividual();
};