
#pragma once
#include<iostream>
using namespace std;

class Puzzle
{
	friend istream& operator>>(istream& instream, Puzzle& puzzle);
	friend ostream& operator<<(ostream& outstream, const Puzzle& puzzle);

public:

   Puzzle()
   {
      
   }

};