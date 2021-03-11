//SudokuFactory.cpp
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//Implementation of SudokuFactory.h
//The SudokuFactory uses a SudokuOffspring object and implements 
//"createPuzzle" to produce new Puzzle objects.
#include "SudokuFactory.h"

//Constructor. Accepts a reproduction object and turns it 
//into a SudokuOffspring object. This is used to call the method "makeOffspring"
SudokuFactory::SudokuFactory(Reproduction*& offspringCreator)
{
   SudokuOffspring* temp = (SudokuOffspring *) offspringCreator;
   this->offspringCreator_ = temp;
}

//This method sses the offspringCreator data member to create and return a new puzzle
//Precondition: None
//Postcondition: Returns a puzzle created from the sudokuoffspring object
Puzzle*& SudokuFactory::createPuzzle(Puzzle*& sudokuPuzzle)
{
   SudokuOffspring offspringCreator;
   offspringCreator.makeOffspring(sudokuPuzzle);
   return sudokuPuzzle;
}
