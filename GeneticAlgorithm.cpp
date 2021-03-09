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
   //Puzzle *x = new Sudoku();
   //x = puz;
   SudokuFitness sf;
   Puzzle *puz = &s;
   Sudoku *y = (Sudoku *) puz;
   cin >> s;

   Puzzle *puz2 = &s2;
   Sudoku *y2 = (Sudoku *) puz2;
   cin >> s2;

   sf.howFit(puz);
   cout << y->getFitness() << endl;
   cout << *y;

   sf.howFit(puz2);
   cout << y2->getFitness() << endl;
   cout << *y2;

   cout << (y->getFitness() < y2->getFitness()) << endl;
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