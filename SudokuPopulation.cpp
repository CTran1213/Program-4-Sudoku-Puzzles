#include "SudokuPopulation.h"
#include <bits/stdc++.h> 

SudokuPopulation::SudokuPopulation(int populationSize, Puzzle*& firstPuzzle)
{
   SudokuFitness fitnessCalculator;
   Reproduction* offspringCreator;
   SudokuFactory factory = SudokuFactory(offspringCreator);
   
   for(int i=0; i<populationSize; i++){
      
      Puzzle* puzzle = factory.createPuzzle(firstPuzzle);
      int fitnessNum = fitnessCalculator.howFit(puzzle);
      Node* node = new Node(fitnessNum, puzzle);
      this->population_.push_back(node);
   }
   sortPopulation(this->population_, 0, this->population_.size()-1);
}

SudokuPopulation::~SudokuPopulation()
{
   while(!population_.empty())
   {
      delete this->population_.back();
      this->population_.pop_back();
   }
}

void SudokuPopulation::cull(int percent)
{
   int cullAmount = this->population_.size() * ((double)percent/(double)100);
   int count = 0;
   while (!this->population_.empty() && count != cullAmount){
      delete this->population_.back();
      this->population_.pop_back();
      ++count;
   }
}

void SudokuPopulation::newGeneration(int numberOfNewOffspring)
{
   vector<Node*> temp = this->population_;
   Reproduction* offspringCreator;
   SudokuFactory factory = SudokuFactory(offspringCreator);
   SudokuFitness fitnessCalculator;
   while(!temp.empty()){
      for(int i = 0; i < numberOfNewOffspring; i++){
         Puzzle* puzzle = factory.createPuzzle(temp[temp.size()-1]->getPuzzle());
         int fitnessNum = fitnessCalculator.howFit(puzzle);
         Node* node = new Node(fitnessNum, puzzle);
         this->population_.push_back(node);
      }
      temp.pop_back();
   }
   sortPopulation(this->population_, 0, this->population_.size()-1);
}


bool SudokuPopulation::insertionSort(vector<Node*>& item_vector, int first, int last)
{
	for (int i = first; i < last + 1; i++)
	{
		Node* next_item = item_vector[i];
		int count = i;
		while ((count > first) && (*(item_vector[count - 1]) > *next_item))
		{
			item_vector[count] = item_vector[count - 1];

			count--;
		}
		item_vector[count] = next_item;
	}
   return true;
}

bool SudokuPopulation::sortPopulation(vector<Node*>& item_vector, int first, int last)
{
	if (last - first < 4)
	{
		insertionSort(item_vector, first, last);
		return true;
	}

	int mid = (first + last) / 2;

	if (*(item_vector[first]) > *(item_vector[last]))
	{
		swap(item_vector[first], item_vector[last]);
	}
	if (*(item_vector[first]) > *(item_vector[mid]))
	{
		swap(item_vector[first], item_vector[mid]);
	}
	if (*(item_vector[mid]) > *(item_vector[last]))
	{
		swap(item_vector[mid], item_vector[last]);
	}
	Node* pivot = item_vector[mid];
	swap(item_vector[mid], item_vector[last - 1]);

	int left = first + 1;
	int right = last - 2;
	bool done = false;
	while (!done)
	{
		while (*(item_vector[left]) < *pivot)
		{
			left++;
		}
		while (*(item_vector[right]) > *pivot)
		{
			right--;
		}
		if (right > left)
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
	sortPopulation(item_vector, first, left - 1);
	sortPopulation(item_vector, left + 1, last);
   return true;
}

int SudokuPopulation::getBestFitness()
{
   return this->population_[0]->getFitnessNumber();
}

Puzzle*& SudokuPopulation::getBestIndividual()
{
   if(this->population_.empty())
   {
      cerr << "ERROR: Population is empty." << endl;
   }
   return this->population_[0]->getPuzzle();
}