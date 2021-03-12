//SudokuFactory.cpp
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//Implementation of SudokuFactory.h
//The SudokuFactory uses a SudokuOffspring object and implements 
//"createPuzzle" to produce new Puzzle objects.
#include "SudokuFactory.h"
#include "Sudoku.h"

//Constructor. Accepts a reproduction object and turns it 
//into a SudokuOffspring object. This is used to call the method "makeOffspring"
SudokuFactory::SudokuFactory(Reproduction*& offspringCreator)
{
   offspringCreator_ = *((SudokuOffspring *) offspringCreator);
}
//This method sses the offspringCreator data member to create and return a new puzzle
//Precondition: None
//Postcondition: Returns a puzzle created from the sudokuoffspring object
Puzzle* SudokuFactory::createPuzzle(Puzzle*& sudokuPuzzle)
{
   //Sudoku *s = new Sudoku();
   //s = (Sudoku*) offspringCreator_.makeOffspring(sudokuPuzzle);
   return offspringCreator_.makeOffspring(sudokuPuzzle);
}
