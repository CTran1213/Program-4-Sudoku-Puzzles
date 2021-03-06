#pragma once 

class Fitness
{
   public:
      Fitness()
      {

      }

      virtual int howFit(int sudoku[9][9]) const = 0;
   
};