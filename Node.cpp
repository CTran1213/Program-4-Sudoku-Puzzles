//Node.cpp
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
/*This class is a Node class. It is meant to used by the container that holds
the population. The Node contains a pointer to a puzzle and a fitness numer.
This cpp file contains the method implementation for the Node class such as
the constructor, comparison operator overloads, getters for the data members, 
and the destructor.*/
#include "Node.h"

/*Purpose: Constructs a Node
        Parameters: an int, pointer reference to Puzzle
        Preconditions: A Node doesn't exist
        Postconditions: A Node exists
        Return value: None
        Functions called: None
      */
Node::Node(int fitnessNumber, Puzzle*& puzzle)
{
   this->fitnessNumber_ = fitnessNumber;
   this->puzzle_ = puzzle;
}

 /*Purpose: Copy constructor 
        Parameters: a reference to a Node
        Preconditions: None
        Postconditions: this equals the parameter
        Return value: None
        Functions called: operator=
      */
Node::Node(Node& newNode)
{
   *this = newNode;
}

/*Purpose: Destroys a node
        Parameters: None
        Preconditions: A Node exists
        Postconditions: A Node doesn't exist
        Return value: None
        Functions called: delete
      */
Node::~Node()
{
   //deletes the puzzle
   delete (Sudoku*)this->puzzle_;
   //makes pointer null
   this->puzzle_ = nullptr;
}

/*Purpose: Checks is this is less then parameter
        Parameters: A reference to a Node
        Preconditions: None
        Postconditions: None
        Return value: Boolean
        Functions called: < for int
      */
bool Node::operator<(const Node& node) const
{
   return this->fitnessNumber_ < node.fitnessNumber_;
}

/*Purpose: Checks is this is greater then parameter
        Parameters: A reference to a Node
        Preconditions: None
        Postconditions: None
        Return value: Boolean
        Functions called: > for int
      */
bool Node::operator>(const Node& node) const
{
   return this->fitnessNumber_ > node.fitnessNumber_;
}

/*Purpose: Gets the puzzle pointer
        Parameters: None
        Preconditions: Puzzle is not had
        Postconditions: Pointer to puzzle is aqcuired
        Return value: reference to a Puzzle pointer
        Functions called: None
      */
Puzzle*& Node::getPuzzle() 
{
   return this->puzzle_;
}

/*Purpose: Gets the fitness number
        Parameters: None
        Preconditions: Puzzle is not had
        Postconditions: Pointer to puzzle is aqcuired
        Return value: reference to a Puzzle pointer
        Functions called: None
      */
int Node::getFitnessNumber() 
{
   return this->fitnessNumber_;
}

/*Purpose: Assigns parameter to this
        Parameters: a reference to Node
        Preconditions: None
        Postconditions: this equals to parameter
        Return value: reference to this
        Functions called: getFitnessNumber and getPuzzle
      */
Node& Node::operator=(Node& newNode)
{
   //assigns the data members to "this"'s data members 
   this->fitnessNumber_ = newNode.getFitnessNumber();
   this->puzzle_ = newNode.getPuzzle();
   return *this;
}

