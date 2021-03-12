#pragma once
#include "Population.h"
#include "Node.h"
#include "SudokuFactory.h"
#include "SudokuOffspring.h"
#include "SudokuFitness.h"
#include "Reproduction.h"
#include "PuzzleFactory.h"
#include <deque>
using namespace std;


class SudokuPopulation : public Population
{
   public:
      SudokuPopulation(int populationSize, Puzzle*& firstPuzzle);
      ~SudokuPopulation();
      void cull(int percent);
      void newGeneration(int percent);
      int getBestFitness();
      Puzzle*& getBestIndividual();

      bool sortPopulation(vector<Node*>& item_vector, int first, int last);
      bool insertionSort(vector<Node*>& item_vector, int first, int last);

      vector<Node*> population_;
      int populationSize_;
};