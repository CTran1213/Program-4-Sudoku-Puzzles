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

   /*Purpose: Output the contents of a puzzle
        Parameters: a refernce to an ostream and a reference to a node pointer
        Preconditions: A pointer contains a puzzle
        Postconditions: The contents of the node are printed
        Return value: ostream refernce
        Functions called: operator<< for Sudoku
      */
   friend ostream& operator<<(ostream& outstream, const Node*& node)
   {
      //gets the pointer
      Puzzle* puzzle = node->puzzle_;

      //converts the pointer to a Sudoku pointer
      Sudoku *temp = (Sudoku *) puzzle;

      //prints out the Sudoku and fitness numbers
      cout << *temp << endl;
      cout << "Fitness number: " << node->fitnessNumber_ << endl;
      return outstream;//returns the ostream
   }

   public:
        /*Purpose: Constructs a Node
        Parameters: an int, pointer reference to Puzzle
        Preconditions: A Node doesn't exist
        Postconditions: A Node exists
        Return value: None
        Functions called: None
      */
      Node(int fitnessNumber, Puzzle*& puzzle);

      /*Purpose: Copy constructor 
        Parameters: a reference to a Node
        Preconditions: None
        Postconditions: this equals the parameter
        Return value: None
        Functions called: operator=
      */
      Node(Node& newNode);

      /*Purpose: Destroys a node
        Parameters: None
        Preconditions: A Node exists
        Postconditions: A Node doesn't exist
        Return value: None
        Functions called: delete
      */
      ~Node();

      /*Purpose: Checks is this is less then parameter
        Parameters: A reference to a Node
        Preconditions: None
        Postconditions: None
        Return value: Boolean
        Functions called: < for int
      */
      bool operator<(const Node& node) const;

      /*Purpose: Checks is this is greater then parameter
        Parameters: A reference to a Node
        Preconditions: None
        Postconditions: None
        Return value: Boolean
        Functions called: > for int
      */
      bool operator>(const Node& node) const;

      /*Purpose: Gets the puzzle pointer
        Parameters: None
        Preconditions: Puzzle is not had
        Postconditions: Pointer to puzzle is aqcuired
        Return value: reference to a Puzzle pointer
        Functions called: None
      */
      Puzzle*& getPuzzle();

      /*Purpose: Gets the fitness number
        Parameters: None
        Preconditions: Puzzle is not had
        Postconditions: Pointer to puzzle is aqcuired
        Return value: reference to a Puzzle pointer
        Functions called: None
      */
      int getFitnessNumber();

      /*Purpose: Assigns parameter to this
        Parameters: a reference to Node
        Preconditions: None
        Postconditions: this equals to parameter
        Return value: reference to this
        Functions called: getFitnessNumber and getPuzzle
      */
      Node& operator=(Node &newNode);
      

   private:
      //the fitness number
      int fitnessNumber_;

      //pointer to puzzle
      Puzzle* puzzle_;
};