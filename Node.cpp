#include "Node.h"

 Node::Node(int fitnessNumber, Puzzle*& puzzle)
 {
    this->fitnessNumber_ = fitnessNumber;
    this->puzzle_ = puzzle;
 }

// Node::~Node()
// {

// }

bool Node::operator<(const Node*& node) const
{
   return this->fitnessNumber_ < node->fitnessNumber_;
}

bool Node::operator>(const Node*& node) const
{
    return this->fitnessNumber_ > node->fitnessNumber_;
}

Puzzle*& Node::getPuzzle() 
{
   return this->puzzle_;
}

int Node::getFitnessNumber() 
{
   return this->fitnessNumber_;
}
