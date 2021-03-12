/*Main.cpp
3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//This is the main file where the client faces the program. This program
runs the genetic algorithm using the various classes created such as Population, 
Puzzle, Fitness, etc. It takes in a command line arguments for the population size 
and number of generations, template puzzle, from it creates the first generation, 
creates multiple generations until the fitness number of the best puzzle is zero, or 
the max number of generations has been reached. At the end, it outputs the 
best puzzle and it's fitness number. */

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
   
   //Ensures that the population size is a multiple of zero, or prints out an
   //error message
   int populationSize = atoi(argv[1]);
   if(populationSize % 10 != 0){
      cout << "Error: Population size not multiple of ten." << endl;
   }
   //gets the second command line arguments for the max number of generations
   int maxNumberGenerations = atoi(argv[2]);

   /*Gets the template puzzle from cin and creates a Sudoku object*/
   Sudoku input;
   cin >> input;

   //Creates a puzzle pointer from the sudoku object
   Puzzle* puzzle = &input;

   //initializes srand for random number generation
   srand(time(NULL));
  
   //initializes the SudokuPopulation to be used, passing in the arguments 
   SudokuPopulation population = SudokuPopulation(populationSize, puzzle);

   int generationCounter = 0;//initializes the generation counter

   /*Loops until the max number of generations has been reached or the best 
   fitness number in the population is 0*/
   while(generationCounter < maxNumberGenerations && 
      population.getBestFitness() != 0){
      population.cull(90);//culls the puzzle by 90%
      population.newGeneration(9);//creates a new generation by creating 9 
      //new puzzles
      //existing one
      ++generationCounter;
   }

   /*Outputs the best puzzle and it's fitness number. Program then ends*/
   Sudoku *bestPuzzle = (Sudoku *) population.getBestIndividual();
   cout << "Best Puzzle: \n" << *bestPuzzle << endl;
   cout << "Best Fitness Number: " << population.getBestFitness() << endl;
   cout << "Counter: " << generationCounter << endl;
   return 0;
};
