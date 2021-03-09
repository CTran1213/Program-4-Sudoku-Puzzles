#include "Sudoku.h"
#include <iostream>
#include "SudokuOffspring.h"
#include "SudokuFitness.h"
#include "SudokuFactory.h"

using namespace std;

int main()
{
   Sudoku s;
   Sudoku s2;
   //Puzzle p;
   srand(time(NULL));
   Puzzle *puz = &s;
   //Puzzle *x = new Sudoku();
   //x = puz;
   Sudoku *y = (Sudoku *) puz;
   SudokuFitness sf;
   cin >> s;
   cout << s;

   sf.howFit(puz);
   cout << y->getFitness() << endl;

   cout << *y;
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

   // for (int i = 0; i < 10; i++)
   // {
   //    SudokuOffspring so;
   //    so.makeOffspring(puz);
   //    cout << s;
   // }
}