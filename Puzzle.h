
#pragma once
#include<iostream>
#include <vector>
using namespace std;

class Puzzle
{
	friend istream& operator>>(istream& instream, Puzzle& puzzle);
	friend ostream& operator<<(ostream& outstream, const Puzzle& puzzle);

public:

   Puzzle()
   {
      
   }

   virtual int getFitness() const = 0;
   virtual bool setFitnessNumber(int num) = 0;
   virtual vector<vector<int>> getSudokuArray() const = 0;

};