#ifndef GENETIC_ALGORITHM_HPP
#define GENETIC_ALGORITHM_HPP

#include "Solution.hpp"

class GeneticAlgorithm
{
public:
  virtual ~GeneticAlgorithm() { }

  virtual void Run() = 0;
  virtual std::shared_ptr<Solution> GetBestSolution() = 0;
  
protected:
  GeneticAlgorithm() { }
};

#endif