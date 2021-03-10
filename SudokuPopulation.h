#pragma once
#include "Population.h"
#include "Node.h"
#include "SudokuFactory.h"
#include "SudokuOffspring.h"
#include "SudokuFitness.h"
#include "Reproduction.h"

class SudokuPopulation : public Population
{
   public:
      SudokuPopulation();
      void cull();
      void newGeneration();
      int getBestFitness();
      Puzzle*& getBestIndividual();

      bool sortPopulation(vector<Node*>& item_vector, int first, int last);
      bool insertionSort(vector<Node*>& item_vector, int first, int last);

      vector<Node*> population_;
      int populationSize_;
};