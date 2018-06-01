#ifndef SIMPLE_GENETIC_ALGORITHM_HPP
#define SIMPLE_GENETIC_ALGORITHM_HPP

#include "GeneticAlgorithm.hpp"
#include "vector"

typedef std::vector<std::shared_ptr<Solution>> Generation;

class SimpleGeneticAlgorithm : public GeneticAlgorithm
{
public:
  SimpleGeneticAlgorithm();
  ~SimpleGeneticAlgorithm();

  virtual void                      Run()             ;
  virtual std::shared_ptr<Solution> GetBestSolution() ;

private:
  Generation                 mGeneration;  
  std::shared_ptr<Solution>  mpCurrentBestResult;

  /* End condition */
  int                        mMaxIteration;
  double                     mMinSatisfiesResult;

  /* Params */
  double                     mMutationProbability;

  bool MakeSelection();
  bool MakeMutation();
  bool MakeCrossOver();

  void Sort();


};

#endif