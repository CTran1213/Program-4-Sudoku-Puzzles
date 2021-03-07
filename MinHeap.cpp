
// /* MinHeap.cpp
//    @author: Faduma Farah
//    @studentID: 1727406
//    2/20/2021
//    Description: The main function of this class is to operate as a Priority 
//    Queue for Puzzle object pointers only, implemented as a Minimum Heap. This 
//    file contains the implementation of the methods of this class declared in
//    the header file. It contains methods such as insert(), pop(), query methods
//    such as peef_front and isEmpty, and it contains helper methods such as 
//    bubbleUp and bubbleDown.
// */

// #include "MinHeap.h"

// /*Purpose: Creates a MinHeap object
//         Parameters: None
//         Preconditions: A MinHeap has been initialized
//         Postconditions: A MinHeap has been created
//         Return value: None
//         Functions called: None
//       */
// MinHeap::MinHeap()
// {
//    //initializes the vector heap 
//    vector<Puzzle*> heap_;
// }

// /*Purpose: Tells user whether a MinHeap is empty
//         Parameters: None
//         Preconditions: A MinHeap exists
//         Postconditions: None
//         Return value: boolean
//         Functions called: vector::empty
//       */
// bool MinHeap::isEmpty()
// {
//    //calls empty function and returns it's resulting value
//    return (heap_.empty());
// }

// /*Purpose: Returns the smallest value
//         Parameters: None
//         Preconditions: MinHeap is not empty
//         Postconditions: None
//         Return value: reference to Puzzle pointer
//         Functions called: vector::front
//       */
// Puzzle*& MinHeap::peek_front()
// {
//    //gets the first item in the heap by calling front and returning it's 
//    //resulting value
//    return heap_.front();
// }

// /*Purpose: Adds an item to the MinHeap
//         Parameters: reference to Puzzle pointer
//         Preconditions: Miheap contains items
//         Postconditions: MinHeap is 1 less item more before (unless empty)
//         Return value: boolean
//         Functions called: vector::push_back, vector::size, MinHeap::bubbleUp 
//       */
// bool MinHeap::insert(Puzzle*& item)
// {
//    /*Inserts the parameter puzzle into the vecotr*/
//    this->heap_.push_back(item);

//    /*sets the index to the heap size less then 1*/
//    int index = this->heap_.size() - 1;

//    //bubbles up the item at index
//    bubbleUp(index);

//    return true;
// }

// /*Purpose: Removes an item from the MinHeap
//         Parameters: None
//         Preconditions: Miheap contains items
//         Postconditions: MinHeap is 1 less item more before (unless empty)
//         Return value: None
//         Functions called: vector::back, vector::pop_back, vector::size, 
//          MinHeap::bubbleDown
//       */
// void MinHeap::pop()
// {
//    /*Checks if the heap size is zero and if so prints an error message*/
//    if (this->heap_.size() == 0){
//       cerr << "Heap is empty. No items to pop." << endl;
//    }

//    /*Sets the first item as the item as the back*/
//    this->heap_[0] = this->heap_.back();

//    //pops the item form the back and bubbles down the item at 0
//    this->heap_.pop_back();
//    bubbleDown(0);
// }

// /*Purpose: Returns the parents index for item i
//         Parameters: integer
//         Preconditions: Item is not the first in vector
//         Postconditions: None
//         Return value: Int
//         Functions called: None
//       */
// int MinHeap::parent(int i)
// {
//    /*sets value index to be returned as the quotient of i-2 and 2
//       returns index */
//    int index = (i - 1) / 2;
//    return index;
// }

// /*Purpose: Returns the left child index of parameter
//         Parameters: int
//         Preconditions: Vector contains more then 1 item
//         Postconditions: None
//         Return value: int
//         Functions called: None
//       */
// int MinHeap::left(int i)
// {
//     /*sets value index to be returned as the sum of 2 multplied by i and 1
//       returns index */
//    int index = (2*i + 1);
//    return index;
// }

// /*Purpose: Returns the right child index of parameter
//         Parameters: int
//         Preconditions: Vector contains more then 1 item
//         Postconditions: None
//         Return value: int
//         Functions called: None
//       */
// int MinHeap::right(int i)
// {
//    /*sets value index to be returned as the sum of 2 multplied by i and 2
//       returns index */
//    int index = (2*i + 2);
//    return index;
// }

// /*Purpose: Takes in an index and moves it up in the MinHeap vector until
//          it is properly positioned 
//         Parameters: Integer index
//         Preconditions: Vector contains more then 1 item
//         Postconditions: Index is moved up vector
//         Return value: None
//         Functions called: MinHeap::parent, algorithm::swap, MinHeap::bubbleUp
//       */
// void MinHeap::bubbleUp(int index)
// {
//    /*Checks if the parent item is greater then the item*/
//    if(*(this->heap_[parent(index)]) > *(this->heap_[index]))
//    {
//       /*swaps the two items and continues bubbling up the Puzzle*/
//       swap(this->heap_[index], this->heap_[parent(index)]);
//       bubbleUp(parent(index));
//    }
// }

// /*Purpose: Takes in an index and moves it down in the MinHeap vector until
//          it is properly positioned 
//         Parameters: Integer index
//         Preconditions: Vector contains more then 1 item
//         Postconditions: Index is moved down vector
//         Return value: None
//         Functions called: MinHeap::right, MinHeap::left, algorithm::swap, 
//          vecotr::size, MinHeap::bubbleDown
//       */
// void MinHeap::bubbleDown(int index)
// {
//    /*Gets the right and left child indexes. Assumes index parameter is the
//     smallest. */
//    int r = right(index);
//    int l = left(index);
//    int smallest = index;

//    /*Checks if left child is less then heap size and the item in the heap is less 
//       then it's parent*/
//    if (l < this->heap_.size() && *(this->heap_[l]) < *(this->heap_[index])){

//       /*if do, sets the left child as the smallest*/
//       smallest = l;
//    }
 
//    /*Checks if right child is less then heap size and the item in the heap is less 
//       then it's parent*/
//    if (r < this->heap_.size() && *(this->heap_[r]) < *(this->heap_[smallest])){

//       /*if do, sets the right child as the smallest*/
//       smallest = r;
//    }
 
//    /*Checks that the index is still not the smallest*/
//    if (smallest != index){

//       /*swaps the item in index and smallest, and continues bubbling down*/
//       swap(this->heap_[index], this->heap_[smallest]);
//       bubbleDown(smallest);
//    }
// }