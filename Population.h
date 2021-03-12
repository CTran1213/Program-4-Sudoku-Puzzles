//Population.h
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//This is the container for holding a large number of puzzle (subclass) objects.
//It uses a Fitness strategy to evaluate the quality of a Puzzle.
//It can "cull" Puzzles from the population (based on their fitness).
//It can use a PuzzleFactory and a Reproduction strategy to produce a new generation 
//of Puzzles from the most fit members of the old generation.
//It performs these operations when commanded by the main GeneticAlgorithm.
//Population or its subclasses must implement constructors (that create an initial, 
//random set of Puzzles), a "cull" method (that eliminates the X% least fit members of 
//a generation), a "newGeneration" method (that produces a new generation with N 
//individuals for every single individual in the old generation — presumably after the 
//old generation has been culled, so that the population size stays constant from one 
//generation to the next), a "bestFitness" method (that returns the fitness of the best 
//Puzzle in the current generation), and a "bestIndividual" method (that returns the 
//Puzzle with the highest fitness).
#pragma once
#include "Puzzle.h"

class Population
{
   //This is a virtual method. It is implemented in SudokuPopulation
   //This method eliminates 90% of the least fit members in the population
   //Precondition: There are puzzles in the population
   //Postconditon: 90% of the puzzles in the population are deleted
   virtual void cull(int percent) = 0;

   //This is a virtual method. It is implemented in SudokuPopulation
   //This method Produces a new generation with 9 individuals for every single individual
   // in the old generation—normally happens after the old generation is culled. 
   //Precondition: 90% of the population is gone and there are puzzles in the population
   //Postcondition: Mutated copies of the leftover puzzles in the population are added 
   //into the population and the population size is the max number
   virtual void newGeneration(int percent) = 0;

   //This is a virtual method. It is implemented in SudokuPopulation
   //This method returns the best fitness number in the population
   //Precondition: none
   //Postcondition: Best fitness number is returned
   virtual int getBestFitness() = 0;

   //This is a virtual method. It is implemented in SudokuPopulation
   //This method returns the puzzle with the best fitness number in the population
   //Precondition: none
   //Postcondition: Puzzle with the best fitness number is returned
   virtual Puzzle*& getBestIndividual() = 0;
};