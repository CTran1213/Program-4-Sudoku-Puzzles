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

Node::Node(int fitnessNumber, Puzzle*& puzzle)
{
   this->fitnessNumber_ = fitnessNumber;
   this->puzzle_ = puzzle;
}

Node::Node(Node& newNode)
{
   *this = newNode;
}

Node::~Node()
{
   delete (Sudoku*)this->puzzle_;
   this->puzzle_ = nullptr;
}

bool Node::operator<(const Node& node) const
{
   return this->fitnessNumber_ < node.fitnessNumber_;
}

bool Node::operator>(const Node& node) const
{
   return this->fitnessNumber_ > node.fitnessNumber_;
}

Puzzle*& Node::getPuzzle() 
{
   return this->puzzle_;
}

int Node::getFitnessNumber() 
{
   return this->fitnessNumber_;
}

Node& Node::operator=(Node& newNode)
{
   this->fitnessNumber_ = newNode.getFitnessNumber();
   this->puzzle_ = newNode.getPuzzle();
   return *this;
}