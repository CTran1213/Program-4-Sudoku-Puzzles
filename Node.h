#pragma once

#include "Puzzle.h"
#include "Sudoku.h"

class Node{

   friend ostream& operator<<(ostream& outstream, const Node*& node)
   {
      Puzzle* puzzle = node->puzzle_;
      Sudoku *temp = (Sudoku *) puzzle;
      cout << *temp << endl;
      cout << "Fitness number: " << node->fitnessNumber_ << endl;
      return outstream;
   }
   public:
      Node(int fitnessNumber, Puzzle*& puzzle);
      ~Node();
      bool operator<(const Node*& node) const;
      bool operator>(const Node*& node) const;
      Puzzle*& getPuzzle();
      int getFitnessNumber();
      

   private:
      int fitnessNumber_;
      Puzzle* puzzle_;
};