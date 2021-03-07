#pragma once 
#include <vector>
using namespace std;

class Fitness
{
   public:
      Fitness()
      {

      }

      virtual int howFit(vector<vector<int>> sudoku) const = 0;
   
};