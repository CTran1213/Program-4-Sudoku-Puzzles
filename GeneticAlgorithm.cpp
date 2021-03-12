#include "Sudoku.h"
#include <iostream>
#include "SudokuOffspring.h"
#include "SudokuFitness.h"
#include "SudokuFactory.h"
#include "SudokuPopulation.h"
#include <random>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <cmath>
#include <ctime>


using namespace std;

int main(int argc, char* argv[])
{
   if(argc < 3){

      /*Prints an error message and ends program*/
      cout << "Error: Too few arguments." << endl;
      return -1;
      exit(-1);
   }
   /*Checks if the arguments entered are greater then 5*/
   else if(argc > 3){

      /*Prints an error message and ends program*/
      cout << "Error: Too many arguments." << endl;
      return -1;
      exit(-1);
   }
   
   int populationSize = atoi(argv[1]);
   if(populationSize % 10 != 0){
      cout << "Error: Population size not multiple of ten." << endl;
   }
   int maxNumberGenerations = atoi(argv[2]);

   Sudoku input;
   cin >> input;
   cout << input;
   Puzzle* puzzle = &input;

   srand(time(NULL));
  
   SudokuPopulation population = SudokuPopulation(populationSize, puzzle);

   int generationCounter = 0;
   while(generationCounter < maxNumberGenerations && population.getBestFitness() != 0){
      population.cull(90);
      population.newGeneration(9);
      ++generationCounter;
   }
   Sudoku *bestPuzzle = (Sudoku *) population.getBestIndividual();
   cout << "Best Puzzle: \n" << *bestPuzzle << endl;
   cout << "Best Fitness Number: " << population.getBestFitness() << endl;
   cout << "Counter: " << generationCounter << endl;
   return 0;
}