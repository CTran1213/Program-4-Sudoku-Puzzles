//SudokuPopulation.h
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//This is the container for holding a large number of puzzle objects
//It uses a Fitness strategy to evaluate the quality of a Puzzle.
//It can "cull" Puzzles from the population (based on their fitness).
//It can use a PuzzleFactory and a Reproduction strategy to produce a new 
//generation of Puzzles from the most fit members of the old generation.
//It performs these operations when commanded by the main GeneticAlgorithm.
//The SudokuPopulation class implements all Population methods for Sudoku 
//objects, using a SudokuFitness object to accomplish its tasks.
#pragma once
#include "Population.h"
#include "Node.h"
#include "SudokuFactory.h"
#include "SudokuOffspring.h"
#include "SudokuFitness.h"
#include "Reproduction.h"
#include "PuzzleFactory.h"
#include <bits/stdc++.h> 
#include <deque>
using namespace std;


class SudokuPopulation : public Population
{
   public:
      //Constructor
      SudokuPopulation(int populationSize, Puzzle*& firstPuzzle);
      ~SudokuPopulation();

      //This method eliminates 90% of the least fit members in the population
      //Precondition: There are puzzles in the population
      //Postconditon: 90% of the puzzles in the population are deleted
      void cull(int percent);

      //This method Produces a new generation with 9 individuals for every 
      //single individual in the old generation—normally happens after the old
      // generation is culled. 
      //Precondition: 90% of the population is gone and there are puzzles in the
      // population
      //Postcondition: Mutated copies of the leftover puzzles in the population
      // are added into the population and the population size is the max number
      void newGeneration(int percent);

      //This method returns the best fitness number in the population
      //Precondition: none
      //Postcondition: Best fitness number is returned
      int getBestFitness();

      //This method returns the puzzle with the best fitness number in the 
      //population
      //Precondition: none
      //Postcondition: Puzzle with the best fitness number is returned
      Puzzle*& getBestIndividual();

      //This method is a QuickSort algorithm. This algorithm is a recursive 
      //algorithm that takes the midpoint as the pivot and partitions the given
      // vector around the pivot.This method accepts a vector to sort and the
      // beginning and end position it wants to sort. Uses the insertionSort 
      //method to quickly sort vector lengths that are less than 4
      //Precondition: none
      //Postcondition: Vector is sorted in O(nlogn) time. Returns true;
      bool sortPopulation(vector<Node*>& item_vector, int first, int last);

      //This method is an insertionSort algorithm. The vector is split into a 
      //sorted and unsorted side. The left hand side is sorted, and the right 
      //hand side is unsorted. The algorithm starts on the left sorting the 
      //numbers one by one. When the algorithm finds a number that is unsorted, 
      //it compares it to it's predecessor, sees if its in the right position, 
      //then moves it in the correct position in the sorted area if its not.
      //This method accepts a vector to sort and the beginning and end position 
      //it wants to sort
      //Precondition: None
      //Postcondition: Vector is sorted in O(N^2) time. Returns true.
      bool insertionSort(vector<Node*>& item_vector, int first, int last);

      vector<Node*> population_;
      int populationSize_;
};