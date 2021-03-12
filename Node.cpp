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
