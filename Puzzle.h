
#pragma once
#include<iostream>
using namespace std;

class Puzzle
{
	virtual friend istream& operator>>(istream& instream, Puzzle& p);
	virtual friend ostream& operator<<(ostream& outstream, const Puzzle& p);

public:

   virtual Puzzle();

};