#include "Sudoku.h"
#include <iostream>
#include "SudokuOffspring.h"
#include "SudokuFitness.h"
#include "SudokuFactory.h"

using namespace std;

int main()
{
   Sudoku s;
   //Puzzle p;
   srand(time(NULL));
   Puzzle *puz = &s;
   SudokuFitness sf;
   cin >> s;
   cout << s;
   sf.howFit(puz);
   cout << s.getFitness() << endl;

   // so.createPuzzle(puz);
   // cout << s;
   // so.createPuzzle(puz);
   // cout << s;
   // so.createPuzzle(puz);
   // cout << s;
   // so.createPuzzle(puz);
   // cout << s;
   // so.createPuzzle(puz);
   // cout << s;
   // so.createPuzzle(puz);
   // cout << s;
   // so.createPuzzle(puz);
   // cout << s;
   // so.createPuzzle(puz);
   // cout << s;
   // so.createPuzzle(puz);
   // cout << s;
   // so.createPuzzle(puz);
   // cout << s;

   for (int i = 0; i < 10; i++)
   {
      SudokuOffspring so;
      so.makeOffspring(puz);
      cout << s;
   }
}