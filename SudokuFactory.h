//SudokuFactory.h
//3/11/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//The SudokuFactory uses a SudokuOffspring object and implements 
//"createPuzzle" to produce new Puzzle objects.
#pragma once
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "SudokuOffspring.h"
#include "Reproduction.h"

class SudokuFactory : public PuzzleFactory
{
   public:
      //Constructor. Accepts a reproduction object and turns it 
      //into a SudokuOffspring object. This is used to call the method 
      //"makeOffspring"
      SudokuFactory(Reproduction*& offspringCreator);
      
      //This method sses the offspringCreator data member to create and return
      // a new puzzle
      //Precondition: None
      //Postcondition: Returns a puzzle created from the sudokuoffspring object
      Puzzle* createPuzzle(Puzzle*& sudokuPuzzle);

   private:
      //This object is used to create new mutated puzzles. It is used in the 
      //createPuzzle method
      SudokuOffspring offspringCreator_;
};
