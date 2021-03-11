
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
   virtual vector<vector<int>> getSudokuArray() const = 0;

};