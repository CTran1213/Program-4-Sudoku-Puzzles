#include "Sudoku.h"
#include <iostream>
#include "SudokuOffspring.h"

using namespace std;

int main()
{
   Sudoku *s = new Sudoku();
   cin >> *s;
   cout << *s;

   SudokuOffspring so;
   cout << *so.makeOffspring(s) << endl;
   cout << *so.makeOffspring(s)<< endl;
   cout << *so.makeOffspring(s)<< endl;
   cout << *so.makeOffspring(s)<< endl;
   cout << *so.makeOffspring(s)<< endl;
   cout << *so.makeOffspring(s)<< endl;
   cout << *so.makeOffspring(s)<< endl;
   cout << *so.makeOffspring(s)<< endl;
   cout << *so.makeOffspring(s)<< endl;

}