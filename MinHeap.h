
/* MinHeap.h
   @author: Faduma Farah
   @studentID: 1727406
   2/20/2021
   Description: The main function of this class is to operate as a Priority 
   Queue for Sudoku object pointers only, implemented as a Minimum Heap. This 
   header file declares the data members and methods of this class. The only
   data member is an STL vector templatized for Sudoku pointers. It contains
   methods such as insert(), pop(), query methods such as peef_front and isEmpty,
   and it contains helper methods such as bubbleUp and bubbleDown.
*/

#pragma once

#include "Puzzle.h"
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include "Sudoku.h"
using namespace std;

class MinHeap
{
   public:
       /*Purpose: Creates a MinHeap object
        Parameters: None
        Preconditions: A MinHeap has been initialized
        Postconditions: A MinHeap has been created
        Return value: None
        Functions called: None
      */
      MinHeap();

       /*Purpose: Tells user whether a MinHeap is empty
        Parameters: None
        Preconditions: A MinHeap exists
        Postconditions: None
        Return value: boolean
        Functions called: vector::empty
      */
      bool isEmpty();

       /*Purpose: Returns the smallest value
        Parameters: None
        Preconditions: MinHeap is not empty
        Postconditions: None
        Return value: reference to Sudoku pointer
        Functions called: vector::front
      */
      Puzzle*& peek_front();

       /*Purpose: Adds an item to the MinHeap
        Parameters: reference to Puzzle pointer
        Preconditions: Miheap contains items
        Postconditions: MinHeap is 1 less item more before (unless empty)
        Return value: boolean
        Functions called: vector::push_back, vector::size, MinHeap::bubbleUp 
      */
      bool insert(Puzzle*& item);

       /*Purpose: Removes an item from the MinHeap
        Parameters: None
        Preconditions: Miheap contains items
        Postconditions: MinHeap is 1 less item more before (unless empty)
        Return value: None
        Functions called: vector::back, vector::pop_back, vector::size, 
         MinHeap::bubbleDown
      */
      void pop();

   protected:

       /*Purpose: Returns the parents index for item i
        Parameters: integer
        Preconditions: Item is not the first in vector
        Postconditions: None
        Return value: Int
        Functions called: None
      */
      int parent(int i);

       /*Purpose: Returns the left child index of parameter
        Parameters: int
        Preconditions: Vector contains more then 1 item
        Postconditions: None
        Return value: int
        Functions called: None
      */
      int left(int i);

       /*Purpose: Returns the right child index of parameter
        Parameters: int
        Preconditions: Vector contains more then 1 item
        Postconditions: None
        Return value: int
        Functions called: None
      */
      int right(int i);

       /*Purpose: Takes in an index and moves it up in the MinHeap vector until
         it is properly positioned 
        Parameters: Integer index
        Preconditions: Vector contains more then 1 item
        Postconditions: Index is moved up vector
        Return value: None
        Functions called: MinHeap::parent, algorithm::swap, MinHeap::bubbleUp
      */
      void bubbleUp(int index);

       /*Purpose: Takes in an index and moves it down in the MinHeap vector until
         it is properly positioned 
        Parameters: Integer index
        Preconditions: Vector contains more then 1 item
        Postconditions: Index is moved down vector
        Return value: None
        Functions called: MinHeap::right, MinHeap::left, algorithm::swap, 
         vecotr::size, MinHeap::bubbleDown
      */
      void bubbleDown(int index);

   private:
      //Container for the Puzzle pointers
      //acts as the array for the Minimum Heap
      vector<Puzzle*> heap_;
};