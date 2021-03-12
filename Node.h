//Node.h
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
/*This class is a Node class. It is meant to used by the container that holds
the population. The Node contains a pointer to a puzzle and a fitness numer.
This header file contains the method declrations for the Node class such as
the constructor, comparison operator overloads, getters for the data members, 
and the destructor.*/

#pragma once

#include "Puzzle.h"
#include "Sudoku.h"

class Node{

   /*Purpose: 
        Parameters: 
        Preconditions: 
        Postconditions: 
        Return value: 
        Functions called: 
      */
   friend ostream& operator<<(ostream& outstream, const Node*& node)
   {
      Puzzle* puzzle = node->puzzle_;
      Sudoku *temp = (Sudoku *) puzzle;
      cout << *temp << endl;
      cout << "Fitness number: " << node->fitnessNumber_ << endl;
      return outstream;
   }
   public:

      /*Purpose: 
        Parameters: 
        Preconditions: 
        Postconditions: 
        Return value: 
        Functions called: 
      */
      Node(int fitnessNumber, Puzzle*& puzzle);

      /*Purpose: 
        Parameters: 
        Preconditions: 
        Postconditions: 
        Return value: 
        Functions called: 
      */
      Node(Node& newNode);

      /*Purpose: 
        Parameters: 
        Preconditions: 
        Postconditions: 
        Return value: 
        Functions called: 
      */
      ~Node();

      /*Purpose: 
        Parameters: 
        Preconditions: 
        Postconditions: 
        Return value: 
        Functions called: 
      */
      bool operator<(const Node& node) const;

      /*Purpose: 
        Parameters: 
        Preconditions: 
        Postconditions: 
        Return value: 
        Functions called: 
      */
      bool operator>(const Node& node) const;

      /*Purpose: 
        Parameters: 
        Preconditions: 
        Postconditions: 
        Return value: 
        Functions called: 
      */
      Puzzle*& getPuzzle();

      /*Purpose: 
        Parameters: 
        Preconditions: 
        Postconditions: 
        Return value: 
        Functions called: 
      */
      int getFitnessNumber();

      /*Purpose: 
        Parameters: 
        Preconditions: 
        Postconditions: 
        Return value: 
        Functions called: 
      */
      Node& operator=(Node &newNode);
      

   private:
      //
      int fitnessNumber_;

      //
      Puzzle* puzzle_;
};