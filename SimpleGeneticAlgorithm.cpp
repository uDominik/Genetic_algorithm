#include <random>
#include <algorithm>
#include "SimpleGeneticAlgorithm.hpp"



SimpleGeneticAlgorithm::SimpleGeneticAlgorithm()
{

}

SimpleGeneticAlgorithm::~SimpleGeneticAlgorithm()
{

}

void 
SimpleGeneticAlgorithm::Run()
{
  if(mGeneration.size() == 0)
    return;

  Sort();
  mpCurrentBestResult = mGeneration[0];

  int generation_counter = 0;
  while(
            generation_counter < mMaxIteration 
        &&  mpCurrentBestResult->CalcRank() < mMinSatisfiesResult
        )
  {
    MakeSelection();
    MakeMutation();
    MakeCrossOver();

    Sort();

    mpCurrentBestResult = mGeneration[0];
  }
}

std::shared_ptr<Solution> 
SimpleGeneticAlgorithm::GetBestSolution()
{
  return mpCurrentBestResult;
}

bool 
SimpleGeneticAlgorithm::MakeSelection()
{
  return true;
}
bool 
SimpleGeneticAlgorithm::MakeMutation()
{
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0,99);

  auto random = std::bind ( distribution, generator );

  for(auto solution : mGeneration)
  {
    if(random() < mMutationProbability)
    {
      solution->Mute();
    }
  }
  return true;
}
bool 
SimpleGeneticAlgorithm::MakeCrossOver()
{
  return true;
}

void 
SimpleGeneticAlgorithm::Sort()
{
  std::sort(
              mGeneration.begin(), 
              mGeneration.end(), 
              [](std::shared_ptr<Solution> a, std::shared_ptr<Solution> b)
              {
                return a->CalcRank() < b->CalcRank();
              }
            );
}