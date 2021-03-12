//SudokuPopulation.cpp
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//This is the implementation of SudokuPopulation.h
//This is the container for holding a large number of puzzle objects
//It uses a Fitness strategy to evaluate the quality of a Puzzle.
//It can "cull" Puzzles from the population (based on their fitness).
//It can use a PuzzleFactory and a Reproduction strategy to produce a new 
//generation of Puzzles from the most fit members of the old generation.
//It performs these operations when commanded by the main GeneticAlgorithm.
//The SudokuPopulation class implements all Population methods for Sudoku 
//objects, using a SudokuFitness object to accomplish its tasks.
#include "SudokuPopulation.h"

//Constructor. Takes in the size of the population and the puzzle inputted from 
//the console. Uses SudokuFitness, Reproduction, and SudokuFactory to create new
// mutated puzzles, then find the fitness numbers of the puzzle. Uses the fitness
// number and Puzzle to create a new Node object, then adds the node object to 
// the vector. Sorts the vector after the population is maxed out.
SudokuPopulation::SudokuPopulation(int populationSize, Puzzle*& firstPuzzle)
{
   SudokuFitness fitnessCalculator; //SudokuFitness object to find the fitness 
   //number
   Reproduction* offspringCreator; //Reproduction Object to create offspring 
   //in the factory
   SudokuFactory factory = SudokuFactory(offspringCreator); //Factory to create
   // new puzzles
   
   for(int  i= 0; i < populationSize; i++){
      //Invariant: The population isn't full yet
      Puzzle* puzzle = factory.createPuzzle(firstPuzzle); //New puzzle from the
      // factory
      int fitnessNum = fitnessCalculator.howFit(puzzle); //Fitness number of the
      // new puzzle
      Node* node = new Node(fitnessNum, puzzle); //New node created to add to
      // the population
      this->population_.push_back(node);
   }
	
	//Sorts the population from lowest fitness number to greatest fitness number
   sortPopulation(this->population_, 0, this->population_.size()-1); 
}

//Destructor. Deletes each node in the vector
SudokuPopulation::~SudokuPopulation()
{
   while(!population_.empty()){
      delete this->population_.back();
      this->population_.pop_back();
   }
}

//This method eliminates 90% of the least fit members in the population
//Precondition: There are puzzles in the population
//Postconditon: 90% of the puzzles in the population are deleted
void SudokuPopulation::cull(int percent)
{
   int cullAmount = this->population_.size() * ((double)percent/(double)100);
   int count = 0;
   while (!this->population_.empty() && count != cullAmount){
		//Invariant: 90% of the least fit puzzles haven't been deleted yet
      delete this->population_.back();
      this->population_.pop_back();
      ++count;
   }
}

//This method Produces a new generation with 9 individuals for every single 
//individual in the old generation—normally happens after the old generation
//in is culled. 
//Precondition: 90% of the population is gone and there are puzzles in the 
//population
//Postcondition: Mutated copies of the leftover puzzles in the population are 
//added into the population and the population size is the max number
void SudokuPopulation::newGeneration(int numberOfNewOffspring)
{
   vector<Node*> temp = this->population_; //Temporary vector holding the 
   //leftover puzzles after culling
   Reproduction* offspringCreator; //Reproduction Object to create offspring
   // in the factory
   SudokuFactory factory = SudokuFactory(offspringCreator); //Factory to create
   // new puzzles
   SudokuFitness fitnessCalculator; //SudokuFitness object to find the fitness
   // number
   while(!temp.empty()){
		//Invariant: There are still puzzles from the last generation that need
      //offspring
      for(int i = 0; i < numberOfNewOffspring; i++){
			//Invariant: Puzzle from the last generation doesn't have enough 
         //offspring

         //New puzzle from the factory
         Puzzle* puzzle = factory.createPuzzle(temp[temp.size()-1]->getPuzzle());
         int fitnessNum = fitnessCalculator.howFit(puzzle); //Fitness number of 
         //the new puzzle
         Node* node = new Node(fitnessNum, puzzle); //New node created to add 
         //to the population
         this->population_.push_back(node);
      }
      temp.pop_back();
   }

	//Sorts the population from lowest fitness number to greatest fitness number
   sortPopulation(this->population_, 0, this->population_.size()-1);
}

//This method is an insertionSort algorithm. The vector is split into a 
      //sorted and unsorted side. The left hand side is sorted, and the right 
      //hand side is unsorted. The algorithm starts on the left sorting the 
      //numbers one by one. When the algorithm finds a number that is unsorted, 
      //it compares it to it's predecessor, sees if its in the right position, 
      //then moves it in the correct position in the sorted area if its not.
      //This method accepts a vector to sort and the beginning and end position 
      //it wants to sort
      //Precondition: None
      //Postcondition: Vector is sorted in O(N^2) time. Returns true.
bool SudokuPopulation::insertionSort(vector<Node*>& item_vector, 
   int first, int last)
{
	for (int i = first; i < last + 1; i++)
	{
		//Invariant: There are still numbers left to sort
		Node* next_item = item_vector[i];
		int count = i;

		//Moves Nodes that are greater than next_item to one position ahead of 
         //their current position
		while ((count > first) && (*(item_vector[count - 1]) > *next_item))
		{
			//Invariant: The node isn't in the right position yet. It's moving 
         //through the sorted side to see where it needs to be.
			item_vector[count] = item_vector[count - 1];
			count--;
		}
		item_vector[count] = next_item;
	}
   return true;
}

//This method is a QuickSort algorithm. This algorithm is a recursive 
      //algorithm that takes the midpoint as the pivot and partitions the given
      // vector around the pivot.This method accepts a vector to sort and the
      // beginning and end position it wants to sort. Uses the insertionSort 
      //method to quickly sort vector lengths that are less than 4
      //Precondition: none
      //Postcondition: Vector is sorted in O(nlogn) time. Returns true;
bool SudokuPopulation::sortPopulation(vector<Node*>& item_vector, 
   int first, int last)
{
	//Calls insertionSort when the given vector's size is less than 4
	if (last - first < 4)
	{
		insertionSort(item_vector, first, last);
		return true;
	}

	//pivot point
	int mid = (first + last) / 2;

	//Swaps nodes where the beginning is greater than the end
	if (*(item_vector[first]) > *(item_vector[last]))
	{
		swap(item_vector[first], item_vector[last]);
	}

	//Swaps nodes where the beginning is greater than the middle
	if (*(item_vector[first]) > *(item_vector[mid]))
	{
		swap(item_vector[first], item_vector[mid]);
	}

	//Swaps nodes where the middle is greater than the end
	if (*(item_vector[mid]) > *(item_vector[last]))
	{
		swap(item_vector[mid], item_vector[last]);
	}

	//Pivot Node
	Node* pivot = item_vector[mid];

	//Swaps the middle and 2nd to last element
	swap(item_vector[mid], item_vector[last - 1]);

	//Pointers that will indicate if a node on the left side is greater than 
   //the pivot or if a node on the right side is less than the pivot
	int left = first + 1;
	int right = last - 2;

	bool done = false;
	while (!done)
	{
		//Invariant: right and left pointers aren't at the same place
		while (*(item_vector[left]) < *pivot)
		{
			left++; //Left pointer moves to the right if current node is less than 
         //pivot
		}
		while (*(item_vector[right]) > *pivot)
		{
			right--; //right pointer moves to the left if current node is greater 
         //than pivot
		}
		if (right > left) //Swaps right and left nodes since they're greater than
      // or less than pivot
		{
			swap(item_vector[left], item_vector[right]);
			right--;
			left++;
		}
		else
		{
			done = true;
		}
	}
	swap(item_vector[left], item_vector[last - 1]);

	//Recursively quicksorts the left side
	sortPopulation(item_vector, first, left - 1);

	//Recursively quicksorts the right side
	sortPopulation(item_vector, left + 1, last);
   return true;
}

//This method returns the best fitness number in the population
//Precondition: none
//Postcondition: Best fitness number is returned
int SudokuPopulation::getBestFitness()
{
   return this->population_[0]->getFitnessNumber();
}

//This method returns the puzzle with the best fitness number in the population
//Precondition: none
//Postcondition: Puzzle with the best fitness number is returned
Puzzle*& SudokuPopulation::getBestIndividual()
{
   if(this->population_.empty())
   {
      cerr << "ERROR: Population is empty." << endl;
   }
   return this->population_[0]->getPuzzle();
}